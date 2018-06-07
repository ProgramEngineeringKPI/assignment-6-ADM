#include "simpleRayTracing.h"
#include <iostream>
#include <cmath>
#include "kd-tree.h"
#include "limits.h"

using namespace std;

void simpleRayTracing(
        DisplayControl* dc,
        Point &min,
        Point &max,
        vector<Point>& vertexes,
        vector<vector<int>>& figures,
        bitmap_image* bmp
) {
    Point* min_ = &min;
    Point* max_ = &max;
    node* root = new node(0, min_, max_);
    vector<flat*> v = createFlatArray(vertexes, figures);

    int *count = new int;
    *count = 0;
    build_tree(v, root, 0, count);


    cout << "Built " << *count << " nodes" << endl;


    double x, y, z, dx, dy, dz;
    x = dc->canvas[0][0];
    y = dc->canvas[0][1];
    z = dc->canvas[1][2];

    dx = dc->dx; dy = dc->dy; dz = dc->dz;
    Point camera = dc->camera;

    for (int i = 0 ; i < dc->heightPx ; i++) {
        double curX = x; double curY = y;
        for (int j = 0 ; j < dc->widthPx ; j++) {
            curX += dx; curY += dy;
            Point curP(curX, curY, z);
            vector<flat*> resFlats;

            if(ray_in_box(&camera, &curP, root -> min, root -> max)!= INT_MAX){
               resFlats = search_in_tree(&camera, &curP, root);
            }

            Point curPoint(curX, curY,z);

            for (int k = 0 ; k < resFlats.size() ; k++) {
                if (rayIntersectTriangle(dc->camera, curPoint, resFlats[k])) {
                    //cout << "Intersection" << endl;
                    bmp->set_pixel(j, i, 0, 0, 0);
                    break;
                }
            }

//            vector<double> curPoint(3, 0);
//            curX += dx; curY += dy;
//            curPoint[0] = curX;
//            curPoint[1] = curY;
//            curPoint[2] = z;

//            for (int k = 0 ; k < figures.size() ; k++) {
//                if (rayIntersectTriangle(dc->camera, curPoint, vertexes, figures[k])) {
//                    bmp->set_pixel(j, i, 0, 0, 0);
//                    break;
//                }
//            }
        }
        z -= dz;
    }
}

vector<flat*> createFlatArray(vector<Point> &vertices,
                              vector<vector<int>> &flats)
{
    vector<flat*> elements(flats.size(), nullptr);
    for (int i = 0 ; i < flats.size() ; i++) {
        Point p1(vertices[flats[i][0]][0],
                 vertices[flats[i][0]][1],
                 vertices[flats[i][0]][2]);
        Point p2(vertices[flats[i][1]][0],
                 vertices[flats[i][1]][1],
                 vertices[flats[i][1]][2]);
        Point p3(vertices[flats[i][2]][0],
                 vertices[flats[i][2]][1],
                 vertices[flats[i][2]][2]);
        elements[i] = new flat(&p1,&p2,&p3);
    }
    return elements;
}


bool rayIntersectTriangle(
        Vector &rayOrigin,
        Vector &rayVector,
        flat* triangle
) {
    const double E = 0.0000001;
    Point vertex0 = *triangle->p1;
    Point vertex1 = *triangle->p2;
    Point vertex2 = *triangle->p3;

    Vector edge1 = vertex1 - vertex0;
    Vector edge2 = vertex2 - vertex0;
    Vector dir = rayVector - rayOrigin;

    Vector h = crossProduct(dir, edge2);
    double a = dotProduct(edge1, h);
    if (a > -E && a < E) return false;

    double f = 1/a;
    Vector s = rayOrigin - vertex0;
    double u = f * dotProduct(s, h);
    if (u < 0 || u > 1) return false;

    Vector q = crossProduct(s, edge1);
    double v = f * dotProduct(dir, q);
    if (v < 0 || u + v > 1) return false;

    double t = f * dotProduct(edge2, q);

    return abs(t) > E;
}

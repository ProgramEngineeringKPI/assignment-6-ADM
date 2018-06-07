#include <iostream>
#include <vector>
#include "DisplayControl.h"
#include "bitmap_image.hpp"
#include "simpleRayTracing.h"
#include "readObj.h"

using namespace std;


int main() {
    vector<Point> vertices;
    vector<vector<int>> flats;

    Point minCoordinate;
    Point maxCoordinate;

    readObj("../teapot.obj", minCoordinate, maxCoordinate, &vertices, &flats);

    DisplayControl* DC = new DisplayControl(minCoordinate, maxCoordinate, "sd");
    bitmap_image *image = new bitmap_image(DC->widthPx,DC->heightPx);
    image->set_all_channels(255, 255, 255);
    simpleRayTracing(DC, minCoordinate, maxCoordinate, vertices, flats, image);
    image->save_image("../pictures/output.bmp");

    return 0;
}

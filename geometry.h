#ifndef ASSIGNMENT_6_ADM_GEOMETRY_H
#define ASSIGNMENT_6_ADM_GEOMETRY_H


#include <vector>
#include <climits>
#include "flat.h"
#include <cmath>
#include "sort.h"
#include "Vector.h"

using namespace std;

double dotProduct(Point& v1, Point& v2);
Vector crossProduct(Vector&, Vector&);
void swap_(float*, float*);
float ray_in_box(Point*, Point*, Point*, Point*);
int SAH(vector<flat*>, float, float, int);


#endif //ASSIGNMENT_6_ADM_GEOMETRY_H

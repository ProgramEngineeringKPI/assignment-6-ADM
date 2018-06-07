#ifndef ASSIGNMENT_6_ADM_SIMPLERAYTRACING_H
#define ASSIGNMENT_6_ADM_SIMPLERAYTRACING_H

#include <vector>
#include "geometry.h"
#include "DisplayControl.h"
#include "bitmap_image.hpp"
#include "flat.h"
#include "Vector.h"

using namespace std;

void simpleRayTracing(
                DisplayControl*,
                Point&,
                Point&,
                vector<Point>&,
                vector<vector<int>>&,
                bitmap_image*
);

vector<flat*> createFlatArray(vector<Point>&, vector<vector<int>>&);

//bool rayIntersectTriangle(
//                vector<double>&,
//                vector<double>&,
//                vector<vector<double>>&,
//                vector<int>&
//);

bool rayIntersectTriangle(
        Vector&,
        Vector&,
        flat*
);


#endif //ASSIGNMENT_6_ADM_SIMPLERAYTRACING_H

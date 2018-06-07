#ifndef ASSIGNMENT_6_ADM_CREATECANVAS_H
#define ASSIGNMENT_6_ADM_CREATECANVAS_H

#include <vector>
#include <string>
#include "Vector.h"

using namespace std;

class DisplayControl {
public:
    DisplayControl(Point&, Point&, string);
    Point camera;
    vector<Point> canvas;
    unsigned int widthPx;
    unsigned int heightPx;
    double width;
    double height;
    double dx;
    double dy;
    double dz;
    ~DisplayControl();
};


#endif //ASSIGNMENT_6_ADM_CREATECANVAS_H

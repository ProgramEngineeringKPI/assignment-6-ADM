#ifndef ASSIGNMENT_6_ADM_FLAT_H
#define ASSIGNMENT_6_ADM_FLAT_H

#include <iostream>
#include "Vector.h"

float comparator(float, float, float, int);

struct flat{
    Point* p1;
    Point* p2;
    Point* p3;
    Point* min_p;
    Point* max_p;
    flat(Point* _p1, Point* _p2, Point* _p3){
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;

    Point min(comparator(_p1 -> x, _p2 -> x, _p3 -> x, 0),
              comparator(_p1 -> y, _p2 -> y, _p3 -> y, 0),
              comparator(_p1 -> z, _p2 -> z, _p3 -> z, 0));

        Point max(comparator(_p1 -> x, _p2 -> x, _p3 -> x, 1),
                  comparator(_p1 -> y, _p2 -> y, _p3 -> y, 1),
                  comparator(_p1 -> z, _p2 -> z, _p3 -> z, 1));
    min_p = &min;
    max_p = &max;
  }
};

#endif //ASSIGNMENT_6_ADM_FLAT_H

#include "geometry.h"

double dotProduct(Point& v1, Point& v2) {
  double res = 0;
  res += v1.x*v2.x;
  res += v1.y*v2.y;
  res += v1.z*v2.z;
  return res;
};

Vector crossProduct(Vector& v1, Vector& v2) {
    Vector res;
    res.x = v1.y*v2.z - v1.z*v2.y;
    res.y = v1.z*v2.x - v1.x*v2.z;
    res.z = v1.x*v2.y - v1.y*v2.x;
    return res;
};

void swap_(float* el1, float* el2){
  float swap = *el1;
  *el1 = *el2;
  *el2 = swap;
}

float ray_in_box(Point* A, Point* B, Point* min, Point* max){

  float x0 = min->x;
  float y0 = min->y;
  float z0 = min->z;

  float x1 = max->x;
  float y1 = max->y;
  float z1 = max->z;

  float x = A->x;
  float y = A->y;
  float z = A->z;

  Vector vector;

  float swap;
  float len = 0;


  vector = (B - A);
  vector = vector.normalized();

  float Tnear = - INT_MAX;
  float Tfar = INT_MAX;

  if (vector.x == 0){
    if (x > x1 || x < x0){
      return INT_MAX;
    }
  } else {
    Tnear = (x0 - x) / vector.x;
    Tfar = (x1 - x) / vector.x;
    if (Tnear > Tfar) swap_(&Tnear, &Tfar);
  }

  if (vector.y == 0){
    if (y > y1 || y < y0){
      return INT_MAX;
    }
  } else {
    float T1y = (y0 - y) / vector.y;
    float T2y = (y1 - y) / vector.y;

    if (T1y > T2y) swap_(&T1y, &T2y);
    if (T1y > Tnear) Tnear = T1y;
    if (T2y < Tfar) Tfar = T2y;
  }

  if (Tnear > Tfar || Tfar < 0) return INT_MAX;

  if (vector.z == 0){
    if (z > z1 || z < z0){
      return INT_MAX;
    }
  } else {
    float T1z = (z0 - z) / vector.z;
    float T2z = (z1 - z) / vector.z;

    if (T1z > T2z) swap_(&T1z, &T2z);
    if (T1z > Tnear) Tnear = T1z;
    if (T2z < Tfar) Tfar = T2z;
  }

  if (Tnear > Tfar || Tfar == 0) return INT_MAX;

  return Tnear;

}


int SAH(vector<flat*> elms, float min, float max, int axis){
  int count = elms.size();
  int answer = 0;
  float result = INT_MAX;
  quick_sort_first(elms, 0, elms.size() - 1, axis);
  int curr;
  for (int i = 0; i < count; i++){
    curr = (elms[i] -> min_p -> coordinate(axis) - min)*i + (max - elms[i] -> max_p -> coordinate(axis))*(count - i);
    if (curr < result){
      result = curr;
      answer = i;
    }
  }
  return answer;
}

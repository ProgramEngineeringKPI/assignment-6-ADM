#include <vector>
#include <climits>
#include "flat.h"
#include <cmath>
#include <unistd.h>
#include "sort.h"
#include "geometry.h"
#include "kd-tree.h"

void build_tree(vector<flat*> elms, node* obj, int axis, int *count){
  (*count)++;
  quick_sort_first(elms, 0, elms.size() - 1, axis);
  int middle = elms.size() / 2;
  obj -> delimiter = elms[middle] -> min_p -> coordinate(axis);
  vector<flat*> l;
  vector<flat*> r;
  for (int i = 0; i < elms.size(); i++){
    if (elms[i] -> max_p -> coordinate(axis) <= obj -> delimiter){
      l.push_back(elms[i]);
    }
    if (elms[i] -> min_p -> coordinate(axis) >= obj -> delimiter){
      r.push_back(elms[i]);
    }
    if (elms[i] -> min_p -> coordinate(axis) < obj -> delimiter && elms[i] -> max_p -> coordinate(axis) > obj -> delimiter){
      l.push_back(elms[i]);
      r.push_back(elms[i]);
    }
  }

  if ((l.size() != 0 || r.size() != 0)  && l.size() != elms.size() && r.size() != elms.size() ){

    Point *middle_l = obj -> max;
    Point *middle_r = obj -> min;

    middle_l -> coordinate(axis) = obj -> delimiter;
    middle_r -> coordinate(axis) = obj -> delimiter;

    int n_ax = axis == 2 ? 0 : (axis + 1);
    obj -> left = new node(n_ax, obj -> min, middle_l);
    obj -> right = new node(n_ax, middle_r, obj -> max);

    build_tree(l, obj -> left, n_ax, count);
    build_tree(r, obj -> right, n_ax, count);

  } else obj -> elements = elms;
}

vector<flat*> search_in_tree(Point* A, Point* B, node* obj){
  if (obj -> left == nullptr && obj -> right == nullptr){
    return obj -> elements;
  }
  vector<flat*> res1;
  vector<flat*> res2;
  if (obj -> left != nullptr && ray_in_box(A, B, obj -> left -> min, obj -> left -> max) != INT_MAX){
    res1 = search_in_tree(A, B, obj -> left);
  }
  if (obj -> right != nullptr && ray_in_box(A, B, obj -> right -> min, obj -> right -> max) != INT_MAX ){
    res2 = search_in_tree(A, B, obj -> right);
    res1.insert(res1.end(), res2.begin(), res2.end());
  }
  return res1;
}

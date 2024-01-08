#ifndef MY_HEADER_H
#define MY_HEADER_H

const int SET_SIZE = 100;

class unionFind {
 public:
  int p[SET_SIZE + 1], size[SET_SIZE + 1];
  int n;

  void union_find_init(int n);
  int find(int x);
  void union_sets(int s1, int s2);
  bool same_component(int s1, int s2);
};

#endif
#include "unionFind.hpp"

void unionFind::union_find_init(int n) {
  for (int i = 1; i <= n; i++) {
    this->p[i] = i;
    this->size[i] = 1;
  }
  this->n = n;
}

int unionFind::find(int x) {
  if (this->p[x] == x) {
    return (x);
  }
  return find(this->p[x]);
}

void unionFind::union_sets(int s1, int s2) {
  int r1{find(s1)}, r2{find(s2)};
  if (r1 == r2) return;
  if (this->size[r1] >= this->size[r2]) {
    this->size[r1] += this->size[r2];
    this->p[r2] = r1;
  } else {
    this->size[r2] += this->size[r1];
    this->p[r1] = r2;
  }
}

bool unionFind::same_component(int s1, int s2) { return find(s1) == find(s2); }
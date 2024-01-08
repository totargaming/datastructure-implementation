#include <algorithm>
#include <iostream>
#include <queue>

#include "unionFind.hpp"
const int MAXV = 100;
class EdgeNode {
 public:
  int y;
  int weight;
  EdgeNode* next;
  EdgeNode(int y, int weight, EdgeNode* next = nullptr)
      : y(y), weight(weight), next(next) {}
};

class EdgePair {
 public:
  int x, y;
  int weight;

  EdgePair() : x(0), y(0), weight(0) {}  // Default constructor

  EdgePair(int x, int y, int weight)
      : x(x), y(y), weight(weight) {}  // Parameterized constructor

  bool operator<(const EdgePair& rhs) const { return weight < rhs.weight; }
};

class Graph {
 public:
  EdgeNode* edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
  bool processed[MAXV + 1];
  bool discovered[MAXV + 1];
  int parent[MAXV + 1];
  int time;
  int entry_time[MAXV + 1];
  int exit_time[MAXV + 1];
  bool finished;
  void initialize_graph(bool directed) {
    int i;
    this->time = 0;
    this->nvertices = 0;
    this->nedges = 0;
    this->directed = directed;
    for (i = 1; i <= MAXV; i++) {
      this->degree[i] = 0;
      this->edges[i] = nullptr;
      this->entry_time[i] = 0;
      this->exit_time[i] = 0;
    }
  }
  void read_graph(bool directed) {
    int m, x, y;
    this->initialize_graph(directed);
    std::cin >> this->nvertices >> m;
    for (int i = 1; i <= m; i++) {
      std::cin >> x >> y;
      this->insert_edge(x, y, directed);
    }
  }
  void insert_edge(int x, int y, bool directed) {
    EdgeNode* p = new EdgeNode(y, 0, this->edges[x]);
    this->edges[x] = p;
    if (!directed) {
      insert_edge(y, x, true);
    } else {
      this->nedges++;
    }
  }
  void to_edge_array(EdgePair* e[]) {
    int index = 0;
    for (int src = 1; src <= nvertices; src++) {
      EdgeNode* edgeNode = edges[src];
      while (edgeNode != nullptr) {
        e[index++] = new EdgePair(src, edgeNode->y, edgeNode->weight);
        edgeNode = edgeNode->next;
      }
    }
  }
  void print_graph() {
    EdgeNode* p;
    for (int i = 1; i <= this->nvertices; i++) {
      std::cout << i << std::endl;
      p = this->edges[i];
      while (p != nullptr) {
        std::cout << p->y << std::endl;
        p = p->next;
      }
      std::cout << "/n";
    }
  }
  void initialize_search() {
    for (int i = 1; i <= this->nvertices; i++) {
      processed[i] = false;
      discovered[i] = false;
      parent[i] = -1;
    }
  }
  void bfs(int start) {
    std::queue<int> q;
    int v, y;
    EdgeNode* p;
    q.push(start);
    discovered[start] = true;
    while (!q.empty()) {
      v = q.front();
      q.pop();
      processed[v] = true;
      p = this->edges[v];
      while (p != nullptr) {
        y = p->y;
        if (!processed[y] || this->directed) {
        }
        if (!discovered[y]) {
          q.push(y);
          discovered[y] = true;
          parent[y] = v;
        }
        p = p->next;
      }
    }
  }
  void find_path(int start, int end) {
    if (start == end) {
      std::cout << start << std::endl;

    } else if (end != -1) {
      find_path(start, this->parent[end]);
      std::cout << end << std::endl;
    }
  }
  void connected_component() {
    int c{0};
    this->initialize_graph(false);
    for (int i = 1; i <= this->nvertices; i++) {
      if (!discovered[i]) {
        ++c;
        std::cout << "Component " << c << " : " << std::endl;
        bfs(i);
        std::cout << "/n";
      }
    }
  }
  void dfs(int v) {
    EdgeNode* p;
    int y;
    if (finished) {
      return;
    }
    discovered[v] = true;
    time++;
    entry_time[v] = time;
    p = this->edges[v];
    while (p != nullptr) {
      y = p->y;
      if (!discovered[y]) {
        parent[y] = v;
        this->process_edge(v, y);
        this->dfs(y);

      } else if ((!processed[y] && parent[v] != y) || this->directed) {
        this->process_edge(v, y);
      }
      if (finished) {
        return;
      }
      p = p->next;
    }
    time++;
    exit_time[v] = time;
    processed[v] = true;
  }
  void process_edge(int x, int y) {
    if (parent[y] != x) {
      std::cout << "Cycle from " << x << "to" << y << " : ";
      this->find_path(y, x);
      finished = true;
    }
  }

  int prim(int start) {
    EdgeNode* p;
    bool intree[MAXV + 1];
    int distance[MAXV + 1];
    int v, y, dist;
    int weight = 0;
    for (int i = 1; i <= this->nvertices; i++) {
      intree[i] = false;
      distance[i] = INT_MAX;
      parent[i] = -1;
    }
    distance[start] = 0;
    v = start;

    while (!intree[v]) {
      intree[v] = true;
      if (v != start) {
        std::cout << "Edge (" << parent[v] << "," << v << ") in tree \n"
                  << std::endl;
        weight += dist;
      }
      p = this->edges[v];
      while (p != nullptr) {
        y = p->y;
        if ((p->weight < distance[y]) && (!intree[y])) {
          distance[y] = p->weight;
          parent[y] = v;
        }
        p = p->next;
      }
      for (int i = 0; i < this->nvertices; i++) {
        if (!intree[i] && (distance[i] < dist)) {
          dist = distance[i];
          v = i;
        }
      }
    }
    return weight;
  }
  void sort_edges(EdgePair* e[], int size) {
    std::sort(e, e + size, [](const EdgePair* a, const EdgePair* b) {
      return a->weight < b->weight;
    });
  }
  int kruskal(int start) {
    unionFind s;
    EdgePair* e[MAXV + 1];  // Change MAXV to MAXE
    int weight = 0;
    s.union_find_init(this->nvertices);
    this->to_edge_array(e);
    this->sort_edges(e, this->nedges);
    for (int i = 0; i < this->nedges; i++) {
      if (!s.same_component(e[i]->x, e[i]->y)) {
        std::cout << "Edge (" << e[i]->x << "," << e[i]->y << ") in MST \n"
                  << std::endl;
        weight += e[i]->weight;
        s.union_sets(e[i]->x, e[i]->y);
      }
      delete e[i];  // Free memory
    }
    return weight;
  }
};

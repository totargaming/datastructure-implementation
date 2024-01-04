#include <iostream>
const int MAXV = 100;
class EdgeNode {
 public:
  int y;
  int weight;
  EdgeNode* next;
  EdgeNode(int y, int weight, EdgeNode* next = nullptr)
      : y(y), weight(weight), next(next) {}
};

class Graph {
 public:
  EdgeNode* edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;

  void initialize_graph(bool directed) {
    int i;
    this->nvertices = 0;
    this->nedges = 0;
    this->directed = directed;
    for (i = 1; i <= MAXV; i++) {
      this->degree[i] = 0;
    }
    for (i = 1; i <= MAXV; i++) {
      this->edges[i] = nullptr;
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
};

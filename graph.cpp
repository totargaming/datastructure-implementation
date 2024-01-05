#include <iostream>
#include <queue>
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
        this->dfs(y);

      } else if ((!processed[y] && parent[v] != y) || this->directed) {
        // process_edge(v,y)
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
};

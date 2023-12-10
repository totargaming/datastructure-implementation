class Node {
 public:
  int data;
  Node* next;
  Node(int data) : data(data) { this->next = nullptr; }
};
class linkedlist {
 public:
  Node* head;
  linkedlist() { head = nullptr; }
  void insert(int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
  }
  void deleteNode(Node* node) {
    Node* nodeToDelete = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete nodeToDelete;
  }
};

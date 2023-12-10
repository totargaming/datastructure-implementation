#include <iostream>

class linkedlist {
 public:
  int value;
  linkedlist* next;
};

linkedlist* searchList(linkedlist* head, int val) {
  if (head == nullptr) {
    return nullptr;
  }
  if (head->value == val) {
    return head;
  } else {
    return searchList(head->next, val);
  }
}
void insertList(linkedlist** head, int val) {
  linkedlist* ptr = new linkedlist;
  ptr->value = val;
  ptr->next = *head;
  *head = ptr;
}
linkedlist* listAhead(linkedlist* head, linkedlist* x) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  if (head->next == x) {
    return head;
  } else {
    return listAhead(head->next, x);
  }
}
void deleteList(linkedlist** head, linkedlist** x) {
  linkedlist* ptr = new linkedlist;
  linkedlist* pred = new linkedlist;
  ptr = *head;
  pred = listAhead(*head, *x);
  if (pred == nullptr) {
    *head = ptr->next;
  } else {
    pred->next = (*x)->next;
  }
  delete *x;
}
void reverse(linkedlist** head) {
  linkedlist *curr, *prev, *next;
  prev = nullptr;
  curr = *head;
  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}
void printNode(linkedlist* head) {
  while (head != nullptr) {
    std::cout << head->value << std::endl;
    printNode(head->next);
  }
}
void revNode(linkedlist* node, linkedlist** head) {
  if (node->next == nullptr) {
    *head = node;
  }
  revNode(node->next, head);
  linkedlist* next = node->next;
  next->next = node;
  node->next = nullptr;
}
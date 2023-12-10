#include <cstring>
#include <iostream>

class Node {
 private:
  int key;
  Node *left, *right;

 public:
  Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = nullptr;
    return temp;
  }
  Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
  }
  Node* leftRotation(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
  }
  Node* splay(Node* root, int key) {
    if (root->key == key || root == nullptr) {
      return root;
    }
    if (root->key < key) {
      if (root->right == nullptr) return root;
      if (root->right->key < key) {
        root->right->right = splay(root->right->right, key);
        root = leftRotation(root);
      } else if (root->right->key > key) {
        root->right->left = splay(root->right->left, key);
        if (root->right->left != nullptr) {
          root->right = rightRotate(root->right);
        }
      }
      return (root->right == nullptr) ? root : leftRotation(root);
    } else {
      if (root->left == nullptr) return root;
      if (root->left->key > key) {
        root->left->left = splay(root->left->left, key);
        root = rightRotate(root);
      } else if (root->left->key < key) {
        root->left->right = splay(root->left->right, key);
        if (root->left->right != nullptr) {
          root->left = leftRotation(root->left);
        }
      }
      return (root->left == nullptr) ? root : rightRotate(root);
    }
  }
};

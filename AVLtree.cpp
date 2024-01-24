class Node {
 public:
  int key, height;
  Node *left, *right;
  Node(int key) : left(nullptr), right(nullptr), height(1) { this->key = key; }
};

int height(Node* N) {
  if (N == nullptr) {  // use == instead of =
    return 0;
  }
  return N->height;
}

int max(int a, int b) { return (a > b) ? a : b; }
Node* newNode(int key) { return new Node(key); }
Node* rightRotate(Node* root) {
  Node* x = root->left;
  root->left = x->right;
  x->right = root;
  x->height = max(height(x->left), height(x->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;
  return x;
}
Node* leftRotate(Node* root) {
  Node* x = root->right;
  root->right = x->left;
  x->left = root;
  x->height = max(height(x->left), height(x->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;
  return x;  // return the new root
}

int getBalanceFactor(Node* N) {
  if (N == nullptr) {
    return 0;
  }
  return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
  if (node == nullptr) {
    return (newNode(key));
  }
  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  } else
    return node;

  node->height = max(height(node->left), height(node->right)) + 1;
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (getBalanceFactor(node->left) >= 0) {
      return rightRotate(node);
    } else {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(node->right) <= 0) {
      return leftRotate(node);
    } else {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

Node* minimumValue(Node* node) {
  Node* current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

Node* deleteNode(Node* node, int key) {
  if (node == nullptr) {
    return node;
  }
  if (key < node->key) {
    node->left = deleteNode(node->left, key);
  } else if (key > node->key) {
    node->right = deleteNode(node->right, key);
  } else {
    if (node->left == nullptr || node->right == nullptr) {
      Node* temp = node->left ? node->left : node->right;
      if (temp == nullptr) {
        temp = node;
        node = nullptr;
      } else {
        *node = *temp;
      }
      delete temp;
    } else {
      Node* temp = minimumValue(node->right);
      node->key = temp->key;
      node->right = deleteNode(node->right, temp->key);
    }
  }

  if (node == nullptr) return node;
  node->height = 1 + max(height(node->left), height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (getBalanceFactor(node->left) >= 0) {
      return rightRotate(node);
    } else {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(node->right) <= 0) {
      return leftRotate(node);
    } else {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}
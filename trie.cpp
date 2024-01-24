#include <map>
#include <string>

class TrieNode {
 public:
  std::map<char, TrieNode*> children;
  bool EndOfWord;

  TrieNode() : EndOfWord(false) {}

  TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    return node;
  }

  void insert(std::string word) {
    TrieNode* node = this;
    for (char c : word) {
      if (node->children.count(c) == 0) {
        node->children[c] = getNode();
      }
      node = node->children[c];
    }
    node->EndOfWord = true;
  }
  bool search(std::string word) {
    TrieNode* node = this;
    for (char c : word) {
      if (node->children.count(c) == 0) {
        return false;
      }
      node = node->children[c];
    }
    return node->EndOfWord;
  }
};
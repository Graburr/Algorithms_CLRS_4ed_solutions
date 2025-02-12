#include <iostream>
#include <memory>

template <typename T> struct LRNode {
  T key;
  std::unique_ptr<LRNode> left_child = nullptr;
  std::unique_ptr<LRNode> right_sibling = nullptr;

  explicit LRNode(T k) : key(k) {}
};

template <typename T> void PrintTreeKeys(LRNode<T> *node) {
  if (node == nullptr) {
    return;
  }

  std::cout << node->key << ", ";
  PrintTreeKeys(node->left_child.get());
  PrintTreeKeys(node->right_sibling.get());
}

int main() {
  auto root = std::make_unique<LRNode<int>>(1);

  root->left_child = std::make_unique<LRNode<int>>(2);
  root->left_child->right_sibling = std::make_unique<LRNode<int>>(3);
  root->left_child->right_sibling->right_sibling = std::make_unique<LRNode<int>>(4);

  root->left_child->left_child = std::make_unique<LRNode<int>>(5);
  root->left_child->left_child->right_sibling = std::make_unique<LRNode<int>>(6);

  // Hijo de 3: 7
  root->left_child->right_sibling->left_child = std::make_unique<LRNode<int>>(7);

  PrintTreeKeys(root.get());
  std::cout << std::endl;
}
#include <iostream>
#include <memory>
#include <stack>

template <typename T> struct BTNode {
  T key;
  std::unique_ptr<BTNode> left = nullptr;
  std::unique_ptr<BTNode> right = nullptr;

  BTNode(T k) : key(k) {}
  BTNode(BTNode &&other)
      : key(other.key), left(std::move(other.left)), right(std::move(other.right)) {}
};

template <typename T> void PrintAllKeys(BTNode<T> &root) {
  std::stack<BTNode<T> *> keys;
  keys.push(&root);

  while (!keys.empty()) {
    BTNode<T> *aux = keys.top();
    keys.pop();
    std::cout << aux->key << ", ";

    if (aux->left != nullptr) {
      keys.push(aux->left.get());
    }
    if (aux->right != nullptr) {
      keys.push(aux->right.get());
    }
  }
}

int main() {
  std::unique_ptr<BTNode<int>> root = std::make_unique<BTNode<int>>(1);

  // first childs
  root->left = std::make_unique<BTNode<int>>(2);
  root->right = std::make_unique<BTNode<int>>(3);

  // second childs (left1)
  root->left->left = std::make_unique<BTNode<int>>(4);
  root->left->right = std::make_unique<BTNode<int>>(5);

  // second childs (right 2)
  root->right->left = std::make_unique<BTNode<int>>(6);
  root->right->right = std::make_unique<BTNode<int>>(7);

  PrintAllKeys(*root);
  std::cout << std::endl;

  return 0;
}
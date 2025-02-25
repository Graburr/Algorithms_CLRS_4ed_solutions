#ifndef RBT_H
#define RBT_H
#include <iostream>
#include <memory>

enum class NodeColor {
  BLACK,
  RED,
};

struct RBTNode {
  NodeColor color;
  int key;
  std::shared_ptr<RBTNode> p = nullptr;
  std::shared_ptr<RBTNode> l = nullptr;
  std::shared_ptr<RBTNode> r = nullptr;

  explicit RBTNode(int k, NodeColor co) : key(k), color(co) {}

  RBTNode(const RBTNode &other)
      : color(other.color), key(other.key), p(other.p), l(other.l), r(other.r) {}

  RBTNode(RBTNode &&o)
      : color(o.color), key(o.key), p(std::move(o.p)), l(std::move(o.l)),
        r(std::move(o.r)) {}
};

struct RBTree {
  std::shared_ptr<RBTNode> root;

  RBTree() = default;

  void printTree(RBTNode *node, int indent = 0) {
    if (!node)
      return;
    if (node->r)
      printTree(node->r.get(), indent + 4);
    std::cout << std::string(indent, ' ') << node->key
              << (node->color == NodeColor::RED ? "R" : "B") << "\n";
    if (node->l)
      printTree(node->l.get(), indent + 4);
  }

  void print() {
    printTree(root.get());
    std::cout << "-----------------------\n";
  }
};

void LeftRotate(RBTree *tree, std::shared_ptr<RBTNode> &node);
void RightRotate(RBTree *tree, std::shared_ptr<RBTNode> &node);

void Insert(RBTree *tree, std::shared_ptr<RBTNode> &node);
void InsertFixup(RBTree *tree, std::shared_ptr<RBTNode> &node);

#endif
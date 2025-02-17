#ifndef BST_H
#define BST_H
#include <memory>

struct NodeBST {
  int key;
  std::unique_ptr<NodeBST> p = nullptr;
  std::unique_ptr<NodeBST> l = nullptr;
  std::unique_ptr<NodeBST> r = nullptr;

  explicit NodeBST(int k) : key(k) {}
  NodeBST(NodeBST &&o)
      : key(o.key), p(std::move(o.p)), l(std::move(o.l)), r(std::move(o.r)) {}
};

void InorderTreeWalk(NodeBST *node);
void InorderTreeWalkIt(NodeBST *node);
void PostorderTreeWalk(NodeBST *node);
void PreorderTreeWalk(NodeBST *node);

#endif
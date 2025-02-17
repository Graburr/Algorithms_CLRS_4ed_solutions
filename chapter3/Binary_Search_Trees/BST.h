#ifndef BST_H
#define BST_H
#include <memory>

struct NodeBST {
  int key;
  std::unique_ptr<NodeBST> l = nullptr;
  std::unique_ptr<NodeBST> r = nullptr;

  explicit NodeBST(int k) : key(k) {}
  NodeBST(NodeBST &&o) : key(o.key), l(std::move(o.l)), r(std::move(o.r)) {}
};

void InorderTreeWalk(NodeBST *node);
void InorderTreeWalkIt(NodeBST *node);
void PostorderTreeWalk(NodeBST *node);
void PreorderTreeWalk(NodeBST *node);

NodeBST *TreeSearch(NodeBST *node, int k);
NodeBST *TreeSearchIt(NodeBST *node, int k);

NodeBST *TreeMinimum(NodeBST *node);
NodeBST *TreeMaximum(NodeBST *node);

NodeBST *TreeSucesor(NodeBST *root, NodeBST *node);
NodeBST *TreePredecesor(NodeBST *root, NodeBST *node);

#endif
#include "RBT.h"

void LeftRotate(RBTree *tree, std::shared_ptr<RBTNode> &node) {
  std::shared_ptr<RBTNode> y = node->r;
  node->r = y->l;

  if (y->l) {
    y->l->p = node;
  }

  y->p = node->p;

  if (!node->p) {
    tree->root = y;
  } else if (node == node->p->l) {
    node->p->l = y;
  } else {
    node->p->r = y;
  }

  y->l = node;
  node->p = y;
}

void RightRotate(RBTree *tree, std::shared_ptr<RBTNode> &node) {
  std::shared_ptr<RBTNode> x = node->l;
  node->l = x->r;

  if (x->r) {
    x->r->p = node;
  }
  x->p = node->p;

  if (!node->p) {
    tree->root = x;
  } else if (node == node->p->r) {
    node->p->r = x;
  } else {
    node->p->l = x;
  }

  x->r = node;
  node->p = x;
}

int main() {
  RBTree tree;

  auto root = std::make_shared<RBTNode>(10, NodeColor::BLACK);
  auto node5 = std::make_shared<RBTNode>(5, NodeColor::RED);
  auto node3 = std::make_shared<RBTNode>(3, NodeColor::BLACK);
  auto node6 = std::make_shared<RBTNode>(6, NodeColor::BLACK);
  auto node7 = std::make_shared<RBTNode>(7, NodeColor::BLACK);

  auto node15 = std::make_shared<RBTNode>(15, NodeColor::RED);
  auto node12 = std::make_shared<RBTNode>(12, NodeColor::BLACK);
  auto node18 = std::make_shared<RBTNode>(18, NodeColor::BLACK);

  root->l = node5;
  node5->p = root;
  node5->l = node3;
  node3->p = node5;
  node5->r = node7;
  node7->p = node5;
  node7->l = node6;

  root->r = node15;
  node15->p = root;
  node15->l = node12;
  node12->p = node15;
  node15->r = node18;
  node18->p = node15;

  tree.root = root;

  std::cout
      << "Árbol antes de la rotación izquierda sobre el hijo izquierdo de la raíz:\n";
  tree.print();

  LeftRotate(&tree, node5);

  std::cout << "Árbol después de la rotación izquierda:\n";
  tree.print();

  RightRotate(&tree, node7);
  std::cout << "Árbol después de la rotación derecha:\n";
  tree.print();

  return 0;
}

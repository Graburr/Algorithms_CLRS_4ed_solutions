#include "BST.h"
#include <iostream>
#include <stack>

void InorderTreeWalk(NodeBST *node) {
  if (node) {
    InorderTreeWalk(node->l.get());
    std::cout << node->key << " ";
    InorderTreeWalk(node->r.get());
  }
}

void InorderTreeWalkIt(NodeBST *node) {
  std::stack<NodeBST *> nodes_stored;
  NodeBST *aux = node;

  while (aux || !nodes_stored.empty()) {

    while (aux) {
      nodes_stored.push(aux);
      aux = aux->l.get();
    }

    aux = nodes_stored.top();
    nodes_stored.pop();

    std::cout << aux->key << " ";

    aux = aux->r.get();
  }
}

void PostorderTreeWalk(NodeBST *node) {
  if (node) {
    PostorderTreeWalk(node->l.get());
    PostorderTreeWalk(node->r.get());
    std::cout << node->key << " ";
  }
}

void PreorderTreeWalk(NodeBST *node) {
  if (node) {
    std::cout << node->key << " ";
    PostorderTreeWalk(node->l.get());
    PostorderTreeWalk(node->r.get());
  }
}

int main() {
  NodeBST root(10);

  // height 1
  root.l = std::make_unique<NodeBST>(4);
  root.r = std::make_unique<NodeBST>(17);

  // height 2
  root.l->l = std::make_unique<NodeBST>(1);
  root.l->r = std::make_unique<NodeBST>(5);
  root.r->l = std::make_unique<NodeBST>(16);
  root.r->r = std::make_unique<NodeBST>(21);

  std::cout << "Inorder:\n";
  InorderTreeWalk(&root);
  std::cout << "\nPostorder:\n";
  PostorderTreeWalk(&root);
  std::cout << "\nPreorder:\n";
  PreorderTreeWalk(&root);
  std::cout << std::endl;

  return 0;
}
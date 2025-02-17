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

NodeBST *TreeSearch(NodeBST *node, int k) {
  if (!node || k == node->key) {
    return node;
  }

  if (k < node->key) {
    return TreeSearch(node->l.get(), k);
  } else {
    return TreeSearch(node->r.get(), k);
  }
}

// On most computers this algorithm is faster than recursive one.
NodeBST *TreeSearchIt(NodeBST *node, int k) {
  while (!node && node->key != k) {
    if (k < node->key) {
      node = node->l.get();
    } else {
      node = node->r.get();
    }
  }

  return node;
}

NodeBST *TreeMinimum(NodeBST *node) {
  while (!node) {
    node = node->l.get();
  }

  return node;
}

NodeBST *TreeMaximum(NodeBST *node) {
  while (!node) {
    node = node->r.get();
  }

  return node;
}

NodeBST *TreeSucesor(NodeBST *root, NodeBST *node) {
  if (node->r) {
    return TreeMinimum(node->r.get());
  } else { // Implemented without using the parent attribute as the book says.
    NodeBST *sucessor = nullptr;
    NodeBST *current = root;

    while (current != nullptr) {
      if (node->key < current->key) {
        sucessor = current;
        current = current->l.get();
      } else if (node->key > current->key) {
        current = current->r.get();
      } else {
        break;
      }
    }

    return sucessor;
  }
}

NodeBST *TreePredecesor(NodeBST *root, NodeBST *node) {
  if (node->l) {
    return TreeMaximum(node->l.get());
  } else {
    NodeBST *predecesor = nullptr;
    NodeBST *current = root;

    while (current != nullptr) {
      if (node->key > current->key) {
        predecesor = current;
        current = current->r.get();
      } else if (node->key < current->key) {
        current = current->l.get();
      } else {
        break;
      }
    }

    return predecesor;
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

  std::cout << TreeSucesor(&root, root.l->r.get())->key << ", "
            << TreePredecesor(&root, root.l->r.get())->key << std::endl;

  return 0;
}
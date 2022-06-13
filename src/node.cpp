#include "node.hpp"

using namespace discrete;

Node::Node(unsigned int idx, void* data) 
{
  this->idx = idx;
  this->data = data;
}

void Node::add_node(Node* n)
{
  if (this->is_adjacent(n)) return;
  this->nodes.push_back(n);
}

void Node::add_edge(Edge* e)
{
  if (!e->contains(this)) return;
  for (auto edge : this->edges)
    if (edge == e)
      return;
  this->edges.push_back(e);
}

bool Node::is_adjacent(Node* n)
{
  for (auto node: this->nodes)
    if (node == n)
      return true;
  return false; 
}

Node::~Node() {}

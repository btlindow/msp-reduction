#include "node.hpp"

using namespace discrete;

Node::Node(unsigned int idx, void* data) 
{
  this->idx = idx;
  this->data = data;
}

void Node::add_node(Node* n)
{
  this->nodes[n->idx] = n;
}

void Node::add_edge(Edge* e)
{
  this->edges[e->idx] = e;
}

bool Node::is_adjacent(Node* n)
{
  return this->nodes.find(n->idx) != this->nodes.end();
}

void Node::remove_self()
{
  for (auto& [idx, edge]: this->edges)
    edge->remove_self();
}

Node::~Node() {}

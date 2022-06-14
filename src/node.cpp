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

void Node::remove(Node* n, Edge* e)
{
  this->nodes.erase(n->idx);
  this->edges.erase(e->idx);
}

void Node::remove_self()
{
  for (auto& [idx, edge]: this->edges)
  {
    Node* n = (edge->node0 == this) ? edge->node1 : edge->node0;
    n->remove(this, edge);
  }
}

Node::~Node() {}

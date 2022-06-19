#include <iostream>
#include "node.hpp"

using namespace std;
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

void Node::remove_node(Node* n)
{
  if (!this->is_adjacent(n)) return;
  Edge* e = nullptr;
  for (auto &[idx, edge]: this->edges)
  {
    if (edge->contains(n))
    {
      e = edge;
      break;
    }
  } 
  this->nodes.erase(n->idx);
  this->edges.erase(e->idx);
}

bool Node::is_adjacent(Node* n)
{
  return this->nodes.find(n->idx) != this->nodes.end();
}

void Node::remove_self()
{
  for (auto &[idx, node]: this->nodes)
    node->remove_node(this);
}

Node::~Node() {}

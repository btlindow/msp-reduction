#include "edge.hpp"

using namespace discrete;

Edge::Edge(unsigned int idx, Node* node0, Node* node1)
{
  this->idx = idx;
  this->node0 = node0;
  this->node1 = node1;
}

bool Edge::contains(Node* n)
{
  return (n == this->node0 || n == this->node1);
}

void Edge::remove_self()
{
  this->node0->nodes.erase(this->node1->idx);
  this->node1->nodes.erase(this->node0->idx);
  this->node0->edges.erase(this->idx);
  this->node1->edges.erase(this->idx);
}

Edge::~Edge() {}

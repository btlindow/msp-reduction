#include "edge.hpp"

using namespace discrete;

Edge::Edge(Node* node0, Node* node1)
{
  this->node0 = node0;
  this->node1 = node1;
}

bool Edge::contains(Node* n)
{
  return (n == this->node0 || n == this->node1);
}

Edge::~Edge() {}

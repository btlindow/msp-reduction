#include "edge.hpp"

using namespace discrete;

Edge::Edge() {}

bool Edge::contains(Node* n)
{
  return (n == this->node0 || n == this->node1);
}

Edge::~Edge() {}

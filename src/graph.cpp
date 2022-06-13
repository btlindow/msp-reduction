#include "graph.hpp"

using namespace discrete;

Graph::Graph() {}

void Graph::add_node(Node* n)
{
  this->nodes.push_back(n);
}

void Graph::add_edge(Edge* e)
{
  this->edges.push_back(e);
}

Graph::~Graph() {}

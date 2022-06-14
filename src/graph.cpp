#include "graph.hpp"

using namespace discrete;

Graph::Graph() {}

void Graph::add_node(Node* n)
{
  this->nodes[n->idx] = n;
}

void Graph::add_edge(Edge* e)
{
  this->edges[e->idx] = e;
}

void Graph::remove_node(Node* n)
{
  n->remove_self();
  for (auto& [idx, edge]: n->edges)
    this->edges.erase(edge->idx);
  this->nodes.erase(n->idx);
}

void Graph::remove_edge(Edge* e)
{
  e->node0->remove(e->node1, e);
  e->node1->remove(e->node0, e);
  this->edges.erase(e->idx);
}

Graph::~Graph() {}

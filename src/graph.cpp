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
  for (auto& [idx, edge]: n->edges)
    this->edges.erase(edge->idx);
  this->nodes.erase(n->idx);
  n->remove_self();
}

void Graph::remove_edge(Edge* e)
{
  e->remove_self();
  this->edges.erase(e->idx);
}

Graph::~Graph() 
{
  for (auto n: this->nodes)
    delete n.second;
  for (auto e: this->edges)
    delete e.second;
}

#include <iostream>
#include "graph.hpp"

using namespace std;
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

void Graph::print()
{
  size_t num_nodes = this->nodes.size();
  size_t num_edges = this->edges.size();
  size_t max_edges = ((num_nodes) * (num_nodes -1)) / 2;
  cout << "nodes.size(): " << num_nodes << endl;
  cout << "edges.size(): " << num_edges << endl;
  cout << "max_edges: " <<  max_edges << endl;
  cout << "desnity: " << ((double) num_edges) / max_edges << endl;
}

Graph::~Graph() 
{
  for (auto n: this->nodes)
    delete n.second;
  for (auto e: this->edges)
    delete e.second;
}

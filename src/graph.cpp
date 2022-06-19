#include <iostream>
#include "graph.hpp"

using namespace std;
using namespace discrete;

Graph::Graph() {}

Graph::Graph(Graph* t)
{
  for (auto &[idx, node]: t->nodes)
    this->add_node(new Node(idx, nullptr));
  for (auto &[idx, edge]: t->edges)
  {
     Node* n0 = this->nodes[edge->node0->idx];
     Node* n1 = this->nodes[edge->node1->idx];
     Edge* e = new Edge(edge->idx, n0, n1);
     n0->add_node(n1);
     n0->add_edge(e);
     n1->add_node(n0);
     n1->add_edge(e);
     this->add_edge(e);
  }
}

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
  for (auto &[idx, edge]: n->edges)
    this->edges.erase(edge->idx);
  this->nodes.erase(n->idx);
  n->remove_self();
  delete n;
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
  int count = 0;
  cout << "------------------------" << endl;
  cout << "nodes.size():\t" << num_nodes << endl;
  cout << "edges.size():\t" << num_edges << endl;
  cout << "max_edges:\t" <<  max_edges << endl;
  cout << "desnity:\t" << ((double) num_edges) / max_edges << endl;
  cout << "nodes: " << "\n\t\t";
  for (auto &[idx, node]: this->nodes)
  {
    count++;
    cout << idx;
    if (count % 10 == 0)
      cout << "\n\t\t";
    else
      cout << " ";
  }
  cout << "\n------------------------" << endl;
}

Graph::~Graph() 
{
  for (auto n: this->nodes)
    delete n.second;
  for (auto e: this->edges)
    delete e.second;
}


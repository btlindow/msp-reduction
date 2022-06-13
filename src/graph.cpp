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

void Graph::erase_node(Node* n)
{
  std::vector<Edge*>::iterator it_e = this->edges.begin();
  while (it_e != this->edges.end())
  {
    Edge* e = *it_e;
    if (e->contains(n))
      it_e = this->edges.erase(it_e);
    else
      ++it_e;
  }

  std::vector<Node*>::iterator it_n = this->nodes.begin();
  while (it_n != this->nodes.end())
  {
    Node* node = *it_n;
    node->erase_node(n);
  }

  delete n; 
}

void Graph::erase_edge(Edge* e)
{
  //iterate through nodes and erase all edge references
  //iterate through edges and erase this one edge
}

Node* Graph::get_node_by_idx(unsigned int idx)
{
  if (idx >= this->nodes.size()) return nullptr;
  return this->nodes.at(idx); 
}

Graph::~Graph() {}

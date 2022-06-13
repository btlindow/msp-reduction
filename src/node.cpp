#include "node.hpp"

using namespace discrete;

Node::Node(unsigned int idx, void* data) 
{
  this->idx = idx;
  this->data = data;
}

void Node::add_node(Node* n)
{
  if (this->is_adjacent(n)) return;
  this->nodes.push_back(n);
}

void Node::add_edge(Edge* e)
{
  if (!e->contains(this)) return;
  for (auto edge : this->edges)
    if (edge == e)
      return;
  this->edges.push_back(e);
}

bool Node::is_adjacent(Node* n)
{
  for (auto node: this->nodes)
    if (node == n)
      return true;
  return false; 
}

void Node::erase_node(Node* n)
{
  std::vector<Edge*>::iterator it_e = this->edges.begin();
  while (it_e != this->edges.end())
  {
    Edge* e = *it_e;
    if (e->contains(n))
    {
      this->edges.erase(it_e);
      break;
    }
    else
      ++it_e;
  }
  
  std::vector<Node*>::iterator it_n = this->nodes.begin();
  while (it_n != this->nodes.end())
  {
    Node* node = *it_n;
    if (node == n)
    {
      this->nodes.erase(it_n);
      return;
    }
    else
      ++it_n;
  }
}

Node::~Node() {}

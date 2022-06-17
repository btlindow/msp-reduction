#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdlib.h>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

static Graph* parse_file(char* filename);
static Graph* parse_el_file(char* filename);
static Graph* parse_al_file(char* filename);
static Graph* parse_m_file(char* filename);

void discrete::find_msc(char* filename)
{
  Graph* g = parse_file(filename);
  if (!g)
  {
    cout << "Couldn't parse file" << endl;
    return;
  }
}

Graph* parse_file(char* filename)
{
  string fn(filename);
  string ext = fn.substr(fn.find_last_of(".") + 1);
  if (ext == "el")
    return parse_el_file(filename);
  else if (ext == "al")
    return parse_al_file(filename);
  else if (ext == "m")
    return parse_m_file(filename);
  return nullptr;
}

Graph* parse_el_file(char* filename)
{
  Graph* g = new Graph();
  ifstream graph_file(filename);
  int lidx, ridx;
  unsigned int edge_count = 0;
  while(graph_file >> lidx >> ridx)
  {
    Node* n0 = g->nodes[lidx];
    Node* n1 = g->nodes[ridx];
    if(!n0)
    {
      n0 = new Node(lidx, nullptr);
      g->add_node(n0);
    }
    if (!n1)
    {
      n1 = new Node(ridx, nullptr);
      g->add_node(n1);
    }
    Edge* e = new Edge(edge_count++, n0, n1);
    n0->add_node(n1);
    n0->add_edge(e);
    n1->add_node(n0);
    n1->add_edge(e);
    g->add_edge(e);
  }
  cout << "g->nodes.size(): " << g->nodes.size() << endl;
  cout << "g->edges.size(): " << g->edges.size() << endl;
  return g;
}

Graph* parse_al_file(char* filename)
{
  Graph* g = new Graph();
  ifstream graph_file(filename);
  string line;
  unsigned int edge_count = 0;
  while (getline(graph_file, line))
  {
    Node* base_node = nullptr;
    unsigned int idx;
    istringstream ss(line);
    while (ss >> idx)
    {
      Node* n;
      if (!g->nodes[idx])
      {
        n = new Node(idx, nullptr);
        g->add_node(n);
      }
      else
        n = g->nodes[idx];
      if (!base_node)
        base_node = n;
      else
      {
        if (!base_node->is_adjacent(n))
        {
          Edge* e = new Edge(edge_count++, base_node, n);
          base_node->add_node(n);
          base_node->add_edge(e);
          n->add_node(base_node);
          n->add_edge(e);
          g->add_edge(e);
        }
      }
    }
  }
  cout << "g->nodes.size(): " << g->nodes.size() << endl;
  cout << "g->edges.size(): " << g->edges.size() << endl;
  return g;
}

Graph* parse_m_file(char* filename)
{
  Graph* g = new Graph();
  ifstream graph_file(filename);
  string line;
  unsigned int node_count = 0;
  while (getline(graph_file, line))
    g->add_node(new Node(node_count++, nullptr));
  graph_file.clear();
  graph_file.seekg(0);
  unsigned int idx = 0; 
  unsigned int edge_count = 0;
  while (getline(graph_file, line))
  {
    int exists = 0;
    unsigned int to_idx = 0;
    istringstream ss(line);
    while (ss >> exists)
    {
      if (idx != to_idx)
      {
        Node* n0 = g->nodes[idx];
        Node* n1 = g->nodes[to_idx];
        if (exists && !n0->is_adjacent(n1))
        {
          Edge* e = new Edge(edge_count++, n0, n1);
          n0->add_node(n1);
          n0->add_edge(e);
          n1->add_node(n0);
          n1->add_edge(e);
          g->add_edge(e);
        }
      }
      to_idx++;
    }
    idx++; 
  }
  cout << "g->nodes.size(): " << g->nodes.size() << endl;
  cout << "g->edges.size(): " << g->edges.size() << endl;
  return g;
}

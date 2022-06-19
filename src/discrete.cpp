#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <map>
#include <set>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

static bool initialized = false;

Graph* discrete::generate_random_graph(int number_nodes, int density)
{
  if (!initialized) 
  {
    initialized = true;
    srand(time(NULL));
  }
  int max_edges = (number_nodes * (number_nodes - 1)) / 2;
  int min_edges = number_nodes - 1;
  density = (density < 20 || density > 90) ? 50 : density;
  double add_edges = (double)(max_edges - min_edges);
  int num_edges = min_edges + (int)(add_edges * (double)(density) / 100);
  unsigned int count = 0;
  Graph* g = new Graph();
 
  /* Add Nodes To Graph */
  for (int i = 0; i < number_nodes; i++)
    g->add_node(new Node(i, nullptr));
  
  /* Make Graph Complete */
  for (int i = 0; i < number_nodes; i++)
  {
    for (int j = i + 1; j < number_nodes; j++)
    {
      Node* n0 = g->nodes[i];
      Node* n1 = g->nodes[j];
      Edge* e = new Edge(count++, n0, n1);
      n0->add_node(n1);
      n1->add_node(n0);
      n0->add_edge(e);
      n1->add_edge(e);
      g->add_edge(e);
    }
  }

  /* Remove Random Edges From Graph */
  for (int i = 0; i < max_edges - num_edges; i++)
  {
    int ridx = rand() % g->edges.size();
    auto it = g->edges.begin();
    std::advance(it, ridx);
    g->remove_edge(it->second);
  }
  return g; 
}

bool discrete::is_graph_connected(Graph* g)
{
  map<Node*, bool> node_map;
  stack<Node*> node_stack;
  node_stack.push(g->nodes[0]);
  node_map[g->nodes[0]] = true;
  while(!node_stack.empty())
  {
    Node* top_node = node_stack.top();
    node_stack.pop();
    for (auto& [idx, node] : top_node->nodes)
    {
      if (!node_map[node])
      {
        node_map[node] = true;
        node_stack.push(node);
      }
    }
  }
  return g->nodes.size() == node_map.size(); 
}

void discrete::write_graph_file_el(Graph* g, const char* filename)
{
  ofstream graph_file;
  graph_file.open(filename);
  map<Edge*, bool> edge_map;
  for (auto &[idx, edge]: g->edges)
  {
    if (!edge_map[edge])
    {
      graph_file << edge->node0->idx << " " << edge->node1->idx << endl;
      edge_map[edge] = true;
    }
  }
  graph_file.close();
}


void discrete::write_graph_file_al(Graph* g, const char* filename)
{
  ofstream graph_file;
  graph_file.open(filename);
  for (auto &[idx, node]: g->nodes)
  {
    graph_file << node->idx;
    for (auto &[sidx, n]: node->nodes)
      graph_file << " " << n->idx; 
    graph_file << endl;
  }
  graph_file.close();
}
  
void discrete::write_graph_file_m(Graph* g, const char* filename)
{
  ofstream graph_file;
  graph_file.open(filename);
  for (int i = 0; i < g->nodes.size(); i++)
  {
    for (int j = 0; j < g->nodes.size(); j++)
    {
      if (i == j)
        graph_file << "0 ";
      else if (g->nodes[i]->is_adjacent(g->nodes[j]))
        graph_file << "1 ";
      else
        graph_file << "0 ";
    }
    graph_file << endl;
  }
  graph_file.close();
}

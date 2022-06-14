#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

void discrete::generate_graph_file(int number_nodes, char* filename)
{
  srand(time(NULL));
  int max_edges = (number_nodes * (number_nodes - 1)) / 2;
  int min_edges = number_nodes - 1;
  int num_edges = rand() % max_edges + min_edges;
  unsigned int count = 0;
  Graph g;
 
  /* Add Nodes To Graph */
  for (int i = 0; i < number_nodes; i++)
    g.add_node(new Node(i, nullptr));
  
  /* Make Graph Complete */
  for (int i = 0; i < number_nodes; i++)
  {
    for (int j = i + 1; j < number_nodes; j++)
    {
      Node* n0 = g.nodes[i];
      Node* n1 = g.nodes[j];
      Edge* e = new Edge(count++, n0, n1);
      n0->add_node(n1);
      n1->add_node(n0);
      n0->add_edge(e);
      n1->add_edge(e);
      g.add_edge(e);
    }
  }

  /* Remove Random Edges From Graph */
  for (int i = 0; i < num_edges; i++)
  {
    int ridx = rand() % g.edges.size();
    auto it = g.edges.begin();
    std::advance(it, ridx);
    g.remove_edge(it->second);
  }

  /* Ensure Graph Is Connected */
  //todo  
  
  ofstream graph_file;
  graph_file.open(filename);
  graph_file << "testing 1 2 3 4" << endl;
  graph_file.close();
}

void discrete::find_msc(char* filename)
{
  ifstream graph_file(filename); 
}

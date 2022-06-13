#ifndef DISCRETE_HPP
#define DISCRETE_HPP

#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{
  class Graph;
  class Node;
  class Edge;

  void generate_graph_file(int, char*); 
  void find_msc(char*);
}

#endif

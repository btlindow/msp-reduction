#ifndef DISCRETE_HPP
#define DISCRETE_HPP

#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{
  Graph* generate_graph(int); 
  void find_msc(char*);
  bool is_graph_connected(Graph*);
}

#endif

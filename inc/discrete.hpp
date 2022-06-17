#ifndef DISCRETE_HPP
#define DISCRETE_HPP

#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{
  Graph* generate_random_graph(int); 
  void find_msc(char*);
  bool is_graph_connected(Graph*);
  void write_graph_file_el(Graph*, char*);
  void write_graph_file_al(Graph*, char*);
  void write_graph_file_m(Graph*, char*);
}

#endif

#ifndef DISCRETE_HPP
#define DISCRETE_HPP

#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{
  Graph* generate_random_graph(int, int); 
  void find_msc(char*);
  bool is_graph_connected(Graph*);
  void write_graph_file_el(Graph*, const char*);
  void write_graph_file_al(Graph*, const char*);
  void write_graph_file_m(Graph*, const char*);
}

#endif

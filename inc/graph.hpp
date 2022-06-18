#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{ 
  class Graph
  {
  public:
    Graph();
    Graph(const Graph &) = default;
    ~Graph();
    void add_node(Node*);
    void remove_node(Node*);
    void add_edge(Edge*);
    void remove_edge(Edge*);
    void print();
    std::map<unsigned int, Node*> nodes;
    std::map<unsigned int, Edge*> edges;
  };
}


#endif

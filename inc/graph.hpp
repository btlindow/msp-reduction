#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include "node.hpp"
#include "edge.hpp"

namespace discrete
{ 
  class Graph
  {
  public:
    Graph();
    Graph(Graph &&) = default;
    Graph(const Graph &) = default;
    Graph &operator=(Graph &&) = default;
    Graph &operator=(const Graph &) = default;
    ~Graph();
    void add_node(Node*);
    void add_edge(Edge*);

  private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    
  };
}


#endif

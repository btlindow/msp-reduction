#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

namespace discrete
{
  class Node;
  class Edge
  {
  public:
    Edge();
    Edge(Edge &&) = default;
    Edge(const Edge &) = default;
    Edge &operator=(Edge &&) = default;
    Edge &operator=(const Edge &) = default;
    ~Edge();
    bool contains(Node*);

  private:
    Node* node0;
    Node* node1;
    
  };

}


#endif

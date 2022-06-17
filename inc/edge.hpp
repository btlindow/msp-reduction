#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

namespace discrete
{
  class Node;
  class Edge
  {
  public:
    Edge(unsigned int, Node*, Node*);
    Edge(const Edge &) = default;
    ~Edge();
    bool contains(Node*);
    void remove_self();
    unsigned int idx;
    Node* node0;
    Node* node1;
    
  };

}


#endif

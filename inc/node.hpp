#ifndef NODE_HPP
#define NODE_HPP

#include <map>
#include "edge.hpp"

namespace discrete
{
  class Edge;
  class Node
  {
  public:
    Node(unsigned int, void*);
    Node(const Node &) = default;
    ~Node();
    void add_node(Node*);
    void add_edge(Edge*);
    void remove(Node*, Edge*);
    bool is_adjacent(Node*);
    void remove_self();
    unsigned int idx;
    void* data;
    std::map<unsigned int, Node*> nodes;
    std::map<unsigned int, Edge*> edges;
    
  };

}

#endif

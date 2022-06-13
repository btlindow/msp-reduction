#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "edge.hpp"


namespace discrete
{
  class Edge;
  class Node
  {
  public:
    Node(unsigned int, void*);
    Node(Node &&) = default;
    Node(const Node &) = default;
    Node &operator=(Node &&) = default;
    Node &operator=(const Node &) = default;
    ~Node();
    void add_node(Node*);
    void add_edge(Edge*);
    bool is_adjacent(Node*);
    void erase_node(Node*);

  private:
    unsigned int idx;
    void* data;
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    
  };

}

#endif

#ifndef NODE_HPP
#define NODE_HPP

namespace discrete
{
  class Node
  {
  public:
    Node();
    Node(Node &&) = default;
    Node(const Node &) = default;
    Node &operator=(Node &&) = default;
    Node &operator=(const Node &) = default;
    ~Node();

  private:
    
  };

  Node::Node()
  {
  }

  Node::~Node()
  {
  }
}

#endif

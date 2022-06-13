#ifndef EDGE_HPP
#define EDGE_HPP

namespace discrete
{
  class Edge
  {
  public:
    Edge();
    Edge(Edge &&) = default;
    Edge(const Edge &) = default;
    Edge &operator=(Edge &&) = default;
    Edge &operator=(const Edge &) = default;
    ~Edge();

  private:
    
  };

}


#endif

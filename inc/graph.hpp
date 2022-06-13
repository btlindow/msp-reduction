#ifndef GRAPH_HPP
#define GRAPH_HPP

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

  private:
    
  };
}


#endif

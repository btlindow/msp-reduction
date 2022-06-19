#include <iostream>
#include <stdlib.h>
#include <set>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

static int find_starting_k(Graph*);
static set<Node*> get_exclusion_set(Graph*, int);
static void reduce_graph(Graph*, int);

void discrete::find_msc(Graph* g)
{
  int k = find_starting_k(g);
  if (k < 0)
  {
    cout << "couldn't find clique" << endl;
    return;
  }
  for (int i = k-1; i > 2; i--)
  {
    Graph a(g);
    reduce_graph(&a, i);    
    cout << "~~~~ " << i << " ~~~~" << endl;
    a.print();
    cout << "~~~~ " << i << " ~~~~" << endl;
  }
}

int find_starting_k(Graph* g)
{
  int* degrees = (int*) calloc(g->nodes.size(), sizeof(unsigned int));
  int node_count = 0;
  for (auto &[idx, node]: g->nodes)
    degrees[node->nodes.size()]++;
  for (int i = g->nodes.size() - 1; i >= 0; i--)
  {
    node_count += degrees[i];
    if (node_count >= i-1) return i;
  }
  return -1;
}

set<Node*> get_exclusion_set(Graph* g, int d)
{
  set<Node*> exclusion_set;
  for (auto &[idx, node]: g->nodes)
    if (node->nodes.size() < d)
      exclusion_set.insert(node);
  return exclusion_set;
}

void reduce_graph(Graph* g, int d)
{
  set<Node*> exclusion_set = get_exclusion_set(g, d);
  while(exclusion_set.size() > 0)
  {
    for (auto node : exclusion_set)
      g->remove_node(node);
    exclusion_set = get_exclusion_set(g, d);
  }
}

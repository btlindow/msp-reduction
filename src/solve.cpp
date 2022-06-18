#include <iostream>
#include <stdlib.h>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

static int find_starting_k(Graph*);

void discrete::find_msc(Graph* g)
{
  int k = find_starting_k(g);
  if (k < 0)
  {
    cout << "couldn't find clique" << endl;
    return;
  }
  cout << "starting k:\t" << k << endl;
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
    if (node_count > i) return i;
  }
  return -1;
}

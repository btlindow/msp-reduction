#include <iostream>
#include <stdlib.h>
#include <set>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

static int find_starting_k(Graph*);
static set<Node*> get_exclusion_set(Graph*, int);
static void reduce_graph(Graph*, int);
static bool is_clique(set<Node*>);
static bool find_clique(Graph*, int);
static void print_metrics(Graph* g, Graph* a, int k);
static long long combination(int, int);
static long long factorial(int);

void discrete::find_msc(Graph* g)
{
  int k = find_starting_k(g);
  int first_search_k = -1;
  if (k < 0)
  {
    cout << "couldn't find clique" << endl;
    return;
  }
  for (int i = k-1; i > 2; i--)
  {
    Graph a(g);
    reduce_graph(&a, i);    
    if (a.nodes.size() > 0)
    {
      if (first_search_k < 0) first_search_k = i+1;
      if (find_clique(&a, i+1)) 
      {
        print_metrics(g, &a, first_search_k);
        return;
      }
    }
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

bool is_clique(set<Node*> node_set)
{
  for (auto n0 : node_set)
    for (auto n1 : node_set)
      if (n0 != n1 && !n0->is_adjacent(n1))
        return false;
  return true;
}

bool find_clique(Graph* g, int k)
{
  string bitmask(k, 1);
  bitmask.resize(g->nodes.size(), 0);
  unsigned int* node_idx = (unsigned int*) malloc(sizeof(unsigned int) * g->nodes.size());
  int idx = 0;
  for (auto &[nidx, node]: g->nodes)
    node_idx[idx++] = nidx; 
  do
  {
    set<Node*> node_set;
    for (int i = 0; i < g->nodes.size(); ++i)
    {
      if (bitmask[i])
      {
        node_set.insert(g->nodes[node_idx[i]]);
      }
    }
    if (is_clique(node_set))
    {
      cout << "Clique: ";
      for (auto n : node_set)
        cout << n->idx << " ";
      cout << endl;
      return true;
    }
  } while (prev_permutation(bitmask.begin(), bitmask.end()));
  return false;
}

void print_metrics(Graph* g, Graph* a, int k)
{
  long long g_comb = 0;
  long long a_comb = 0;
  for (int i = 1; i <= g->nodes.size(); i++)
    g_comb += combination(g->nodes.size(), i);
  for (int i = 1; i <= k; i++)
    a_comb += combination(a->nodes.size(), i);
  cout << "Input Graph Combinations: " << g_comb << endl;
  cout << "Reduced Graph Combinations: " << a_comb << endl;
  double reduction_percentage = (((double) g_comb - a_comb) / g_comb) * 100;
  cout << "Reduction Percentage: " << reduction_percentage << "%" << endl;
  cout << "\nInput Graph Metrics" << endl;
  g->print();
  cout << "\nSubgraph Metrics" << endl;
  a->print();
}

long long combination(int n, int k)
{
  long long n_fact = factorial(n);
  long long nsk_fact = factorial(n - k);
  long long k_fact = factorial(k);
  long long result = ((n_fact / nsk_fact) / k_fact);
  return result;
}

long long factorial(int f)
{
  long long result = 1;
  for (int i = 2; i <= f; i++)
    result *= i;
  return result;
}

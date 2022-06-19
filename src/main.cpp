#include <iostream>
#include <string.h>
#include <fstream>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

void parse_args(int, char*[]);
void print_help(void);
void run_msc(int, char*[]);
void generate_graph(int, char*[]);

int main(int argc, char* argv[])
{
  parse_args(argc, argv);
  return 0;
}

void parse_args(int argc, char* argv[])
{
  if (argc <= 1) print_help();
  else if (strcmp(argv[1], "--msc") == 0) run_msc(argc, argv);
  else if (strcmp(argv[1], "--generate") == 0) generate_graph(argc, argv);
}

void print_help(void)
{
  cout << "usage:" << endl;
  cout << "\tgraph --generate <number_nodes> <density:20-90>" << endl;
  cout << "\tgraph --msc <input_file>" << endl;
}

void run_msc(int argc, char* argv[])
{
  if (argc != 3)
  {
    cout << "invalid number of arguments" << endl;
    return;
  }
  
  ifstream graph_file (argv[2]);
  if (!graph_file.is_open())
  {
    cout << "input file not found" << endl;
    return;
  }
  graph_file.close();
  Graph* g = parse_graph_file(argv[2]);
  find_msc(g);
}

void generate_graph(int argc, char* argv[])
{
  if (argc != 4)
  {
    cout << "invalid number of arguments" << endl;
    return;
  }

  int number_nodes = 0;
  int density = 0;
  try
  {
    number_nodes = stoi(argv[2]);
    density = stoi(argv[3]);
  }
  catch (const std::exception&)
  {
    cout << "invalid number of nodes or density" << endl;
    return;
  }
  
  Graph* g = generate_random_graph(number_nodes, density);
  while(!is_graph_connected(g))
  {
    delete g;
    g = generate_random_graph(number_nodes, density);
  }
  write_graph_file_el(g, "graph.el");
  write_graph_file_al(g, "graph.al");
  write_graph_file_m(g, "graph.m");
  g->print();
}

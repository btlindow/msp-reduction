#include <iostream>
#include <string.h>
#include <fstream>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

void parse_args(int, char*[]);
void print_help(void);
void run_msr(int, char*[]);
void generate_graph(int, char*[]);

int main(int argc, char* argv[])
{
  parse_args(argc, argv);
  return 0;
}

void parse_args(int argc, char* argv[])
{
  if (argc <= 1) print_help();
  else if (strcmp(argv[1], "--msr") == 0) run_msr(argc, argv);
  else if (strcmp(argv[1], "--generate") == 0) generate_graph(argc, argv);
}

void print_help(void)
{
  cout << "usage:" << endl;
  cout << "\tgraph --generate <number_nodes> <output_file>" << endl;
  cout << "\tgraph --msr <input_file" << endl;
}

void run_msr(int argc, char* argv[])
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
  find_msc(argv[2]);
}

void generate_graph(int argc, char* argv[])
{
  if (argc != 4)
  {
    cout << "invalid number of arguments" << endl;
    return;
  }

  int number_nodes = 0;
  try
  {
    number_nodes = stoi(argv[2]);
  }
  catch (const std::exception&)
  {
    cout << "invalid number of nodes" << endl;
    return;
  }
  
  generate_graph_file(number_nodes, argv[3]);
}

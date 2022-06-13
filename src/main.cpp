#include <iostream>
#include <string.h>
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
  cout << "running msr" << endl;
}

void generate_graph(int argc, char* argv[])
{
  cout << "generating graph" << endl; 
}

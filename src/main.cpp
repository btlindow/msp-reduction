#include <iostream>
#include "discrete.hpp"

using namespace std;
using namespace discrete;

int main(int argc, char* argv[])
{
  Node n0(0, nullptr);
  Node n1(1, nullptr);
  n0.add_node(&n1);
  cout << "n0a: " << n0.is_adjacent(&n1) << endl;
  return 0;
}

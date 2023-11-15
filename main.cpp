#include "core/Utility.h"
#include "function_parser.h"
#include <iostream>
using namespace functions;
using namespace operations;

int main() {
  auto ptr = std::make_shared<add>(std::make_shared<constant>(1),
      std::make_shared<constant>(2));
  std::cout << ptr->eval(0) << std::endl;
}

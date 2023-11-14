#include "function_parser.h"
using namespace functions;
using namespace operations;

binary_operation::binary_operation(std::shared_ptr<evaluation_t>&& left, std::shared_ptr<evaluation_t>&& right) : left(std::move(left)), right(std::move(right)) {}


double binary_operation::eval(double x) const {
  return calc(left->eval(x), right->eval(x));
}

constant::constant(double x) : x(x) {}

double constant::eval(double v) const {
  return x;
}

double variable::eval(double x) const {
  return x;
}
 
double add::calc(double x, double y) const {
  return x + y;
}

double sub::calc(double x, double y) const {
  return x - y;
}


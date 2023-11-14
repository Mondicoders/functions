#pragma once
#include <memory>

namespace functions {

struct evaluation_t {
public:
  virtual double eval(double x) const = 0;
};

struct binary_operation : evaluation_t {
  binary_operation(std::shared_ptr<evaluation_t>&& left, std::shared_ptr<evaluation_t>&& right);

  virtual ~binary_operation() = default;

  double eval(double x) const override;
private:
  virtual double calc(double x, double y) const = 0;

  std::shared_ptr<evaluation_t> left;
  std::shared_ptr<evaluation_t> right;
};

namespace operations {

struct constant : evaluation_t {
  constant() = default;
  constant(double x);

  double eval(double v) const override;
private:
  double x{};
};

struct variable : evaluation_t {
private:
  double eval(double x) const override;
};

struct add : binary_operation {
  using binary_operation::binary_operation;
  ~add() override = default;
private:
  double calc(double x, double y) const override;
};

struct sub : binary_operation {
  using binary_operation::binary_operation;
  ~sub() override = default;
private:
  double calc(double x, double y) const override;
};
} // namespace operations
} // namespace functions

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include <iostream>
#include <stdexcept>

namespace MathOperations {

// Addition - with multiple parameter combinations
class Addition {
private:
    double result;
public:
    Addition(int a, int b) : result(a + b) {} //Inline implementation of func, 成员初始化列表
    Addition(double a, double b) : result(a + b) {}
    Addition(double a, double b, double c) : result(a + b + c) {}
    Addition(int a, double b) : result(a + b) {}
    Addition(double a, int b) : result(a + b) {}
    
    double getResult() const { return result; }
};

// Substraction - with multiple parameter combinations
class Subtraction {
private:
    double result;
public:
    Subtraction(int a, int b) : result(a - b) {}
    Subtraction(double a, double b) : result(a - b) {}
    Subtraction(int a, double b) : result(a - b) {}
    Subtraction(double a, int b) : result(a - b) {}
    
    double getResult() const { return result; }
};

// Multiplication - with multiple parameter combinations
class Multiplication {
private:
    double result;
public:
    Multiplication(int a, int b) : result(a * b) {}
    Multiplication(double a, double b) : result(a * b) {}
    Multiplication(double a, double b, double c) : result(a * b * c) {}
    Multiplication(int a, double b) : result(a * b) {}
    Multiplication(double a, int b) : result(a * b) {}
    
    double getResult() const { return result; }
};

// Division - with multiple parameter combinations
class Division {
private:
    double result;
public:
    Division(int a, int b) { //初始化列表无法进行条件检查
        if (b == 0) throw std::invalid_argument("The divisor cannot be zero");
        result = static_cast<double>(a) / b;
    }
    
    Division(double a, double b) {
        if (b == 0) throw std::invalid_argument("The divisor cannot be zero");
        result = a / b;
    }
    
    Division(int a, double b) {
        if (b == 0) throw std::invalid_argument("The divisor cannot be zero");
        result = a / b;
    }
    
    Division(double a, int b) {
        if (b == 0) throw std::invalid_argument("The divisor cannot be zero");
        result = a / b;
    }
    
    double getResult() const { return result; }
};

} // namespace MathOperations

#endif // MATH_OPERATIONS_H
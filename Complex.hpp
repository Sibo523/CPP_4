#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
class Complex
{
public:
    Complex(double real, double imag);

    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    Complex operator=(const Complex &c);
    Complex operator+=(const Complex &c);
    Complex operator-=(const Complex &c);
    Complex operator*=(const Complex &c);
    Complex operator/=(const Complex &c);
    bool operator<(const Complex &c);
    bool operator>(const Complex &c);
    bool operator==(const Complex &c);
    bool operator!=(const Complex &c);
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    double getReal();
    double getImag();

private:
    double real;
    double imag;
};
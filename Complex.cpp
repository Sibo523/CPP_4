#include "Complex.hpp"
#include <iostream>

Complex::Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

// important
bool Complex::operator<(const Complex &c)
{
    return (real < c.real) || (real == c.real && imag < c.imag);
}

bool Complex::operator>(const Complex &c)
{
    return (real > c.real) || (real == c.real && imag > c.imag);
}

bool Complex::operator==(const Complex &c)
{
    return real == c.real && imag == c.imag;
}

bool Complex::operator!=(const Complex &c)
{
    return !(*this == c);
}
Complex Complex::operator=(const Complex &c)
{
    real = c.real;
    imag = c.imag;
    return *this;
}

// for fun not asked for
Complex Complex::operator+(const Complex &c)
{
    return Complex(real + c.real, imag + c.imag);
}
Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex &c)
{
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator/(const Complex &c)
{
    double denominator = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

Complex Complex::operator+=(const Complex &c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}

Complex Complex::operator-=(const Complex &c)
{
    real -= c.real;
    imag -= c.imag;
    return *this;
}

Complex Complex::operator*=(const Complex &c)
{
    double tempReal = real * c.real - imag * c.imag;
    imag = real * c.imag + imag * c.real;
    real = tempReal;
    return *this;
}

Complex Complex::operator/=(const Complex &c)
{
    double denominator = c.real * c.real + c.imag * c.imag;
    double tempReal = (real * c.real + imag * c.imag) / denominator;
    imag = (imag * c.real - real * c.imag) / denominator;
    real = tempReal;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << c.real << "+" << c.imag << "i";
    return os;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImag()
{
    return imag;
}

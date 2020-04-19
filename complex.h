#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    double re, im;
public:
    Complex();
    Complex(double, double);
    void show() const;
    void set();
    double get_real() const;
    double get_imagine() const;

    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
};

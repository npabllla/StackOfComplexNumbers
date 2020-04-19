#include "complex.h"
#include <assert.h>

Complex::Complex() {
    this->re = 0;
    this->im = 0;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

void Complex::show() const{
    cout << this->re;
    if (this->im != 0) {
        if (this->im > 0)
            cout << "+";
        else
            cout << "-";
        cout << abs(this->im) << "i" << endl;
    }
}

void Complex::set() {
    cout << "Input real part: ";
    cin >> this->re;
    cout << "Input image part: ";
    cin >> this->im;
}
double Complex::get_real() const
{
    return re;
}
double Complex::get_imagine() const
{
    return im;
}
Complex Complex::operator+(Complex other) {
    Complex c = Complex(this->re + other.re, this->im + other.im);
    return c;
}

Complex Complex::operator-(Complex other) {
    Complex c = Complex(this->re - other.re, this->im - other.im);
    return c;
}

Complex Complex::operator*(Complex other) {
    Complex c = Complex(this->re * other.re - this->im * other.im, this->re * other.im + other.re * this->im);
    return c;
}

Complex Complex::operator/(Complex other) {
    assert(other.re || other.im);
    Complex c = Complex((this->re * other.re + this->im*other.im) / (other.re * other.re + other.im * other.im),
        (this->im * other.re - this->re * other.im)/ (other.re * other.re * +other.im * other.im));
    return c;
}

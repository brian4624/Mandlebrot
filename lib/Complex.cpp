#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
#include "Complex.h"

// constructors -------------------------------------------
Complex::Complex() {
    r = 0;
    i = 0;
}

Complex::Complex( double r, double i ) {
    this->r = r;
    this->i = i;
}

Complex::Complex( double r ) {
    this->r = r;
    i = 0;
}

// accessors ----------------------------------------------
string Complex::toString( void ) {
    ostringstream  tmp;
    tmp << r <<  "+" << i << "i";
    return tmp.str();
}

// operators ----------------------------------------------
Complex Complex::operator + ( const Complex &rhs ) {
    Complex temp;
    temp.r = r + rhs.r;
    temp.i = i + rhs.i;
    return temp;
}

Complex Complex::operator - ( const Complex &rhs ) {
    Complex temp;
    temp.r = r - rhs.r;
    temp.i = i - rhs.i;
    return temp;
}

Complex Complex::operator * ( const Complex &rhs ) {
    Complex temp;
    temp.r = (r*rhs.r) - (i*rhs.i);
    temp.i = (r*rhs.i) + (i*rhs.r);
    return temp;
}

Complex Complex::operator / ( const Complex &rhs ) {
    Complex temp;
    temp.r = ((r*rhs.r) + (i*rhs.i)) / ((rhs.r*rhs.r) + (rhs.i*rhs.i));
    temp.i = ((i*rhs.r) - (r*rhs.i)) / ((rhs.r*rhs.r) - (rhs.i*rhs.i));
    return temp;
}

Complex operator + ( double lhs, const Complex &rhs) {
    Complex temp;
    temp.r = lhs + rhs.r;
    temp.i = rhs.i;
    return temp;
}
Complex operator + ( const Complex &lhs, double rhs) {
    Complex temp;
    return temp;
}


Complex operator - ( double lhs, const Complex & rhs) {
    Complex temp;
    temp.r = lhs - rhs.r;
    temp.i = rhs.i;
    return temp;
}

Complex operator - ( const Complex & lhs, double rhs) {
    Complex temp;
    return temp;
}

Complex operator * ( double lhs, const Complex & rhs) {
    Complex temp;
    temp.r = lhs * rhs.r;
    temp.i = lhs * rhs.i;
    return temp;
}

Complex operator / ( double rhs, const Complex & lhs) {
    Complex temp;
    temp.r = lhs.r / rhs;
    temp.i = lhs.i / rhs;
    return temp;
}

ostream & operator << ( ostream & lhs, const Complex & rhs ) {
    if(rhs.i >= 0)
    {
        lhs << rhs.r << '+' << rhs.i << 'i';
        return lhs;
    }
    else
    {
        lhs << rhs.r << rhs.i << 'i';
        return lhs;
    }
}

// calculates the magnitude of the complex number
double Complex::magnitude(void) {
    double z = this->r*(this->r) + this->i*(this->i);
    long double zmag = sqrt(z);
    return zmag;
}







#include <iostream>
#include <sstream>
using namespace std;
#include "Complex.h"
#include <cmath>


// constructors -------------------------------------------
Complex::Complex() {
    this->r = 0;
    this->i = 0;
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

double Complex::magnitude( void ) {
    return sqrt( this->r * this->r + this->i * this->i );
}

// operators ----------------------------------------------
Complex Complex::operator + ( const Complex & rhs ) {
    Complex temp;
    temp.r = this->r + rhs.r;
    temp.i = this->i + rhs.i;
    return temp;
}

Complex Complex::operator - ( const Complex & rhs ) {
    Complex temp;
    temp.r = this->r + rhs.r;
    temp.i = this->i + rhs.i;
    return temp;
}

Complex Complex::operator * ( const Complex & rhs ) {
    Complex temp;
    temp.r = this->r * rhs.r - this->i * rhs.i;
    temp.i = this->r * rhs.i + this->i * rhs.r;    
    return temp;
}

Complex Complex::operator / ( const Complex & rhs ) {
    Complex temp;
    double  demon = rhs.i * rhs.i + rhs.r * rhs.r;
    temp.r = (this->r * rhs.r + this->i * rhs.i )/demon;
    temp.i = (this->i * rhs.r - this->r * rhs.i)/demon;
    return temp;
}

ostream & operator << ( ostream & lhs, const Complex & rhs ) {
    lhs << rhs.r << '+' << rhs.i << 'i';
    return lhs;
}

Complex operator + ( double lhs, const Complex & rhs ){
    return rhs;
}

Complex operator + ( Complex & lhs, const double rhs ) {
    Complex temp;
    return temp;
}


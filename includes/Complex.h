// Complex.h - complex number class
#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        double r;       // real part
        double i;       // imaginary part

    public:
        Complex();      // default constructor
        Complex( double r, double i );  // normal constructor
        Complex( double r );            // alternate constructor
        
        string toString( void );
        Complex operator + ( const Complex & rhs );
        Complex operator - ( const Complex & rhs );
        Complex operator * ( const Complex & rhs );
        Complex operator / ( const Complex & rhs );
        friend Complex operator + ( double lhs, const Complex & rhs);       // adding to a constant
        friend Complex operator + ( double rhs, const Complex & lhs);       // adding by a constant
        friend Complex operator - ( double lhs, const Complex & rhs);       // subtracting from a constant
        friend Complex operator - ( double rhs, const Complex & lhs);       // subtracting by a constant
        friend Complex operator * ( double lhs, const Complex & rhs);       // multiplying by a constant
        friend Complex operator / ( double rhs, const Complex & lhs);       // dividing by a constant
        friend ostream & operator << ( ostream &lhs, const Complex & rhs );
        double magnitude(void);
};



#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool biggerThan (void);
        bool smallerThan (void);
        bool biggerEqual (void);
        bool smallerEqual (void);
        bool equalTo (void);
        bool different (void);
        float sum(int a, int b);
        float substract(int a, int b);
        float multiplicate(int a, int b);
        float divide(int a, int b);
        float increment(Fixed& a);
        float decrement(Fixed& a);
        static Fixed& min (Fixed& a, Fixed& b);
        static Fixed& minConst (const Fixed& a, const Fixed& b);
        static Fixed& max (Fixed& a, Fixed& b);
        static Fixed& maxConst (const Fixed& a, const Fixed& b);




};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
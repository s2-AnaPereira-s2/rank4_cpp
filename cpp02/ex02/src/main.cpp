#include "Fixed.hpp"
#include <iostream>


int main( void ) 
{
    {
        Fixed a;
        Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        std::cout << b << std::endl;

        std::cout << Fixed::max(a, b) << std::endl;
    }
    {
        std::cout << "\n=== Testing arithmetic operators ===" << std::endl;
	    Fixed x(10);
	    Fixed y(3);

	    std::cout << "x = 10" << std::endl;
	    std::cout << "y = 3" << std::endl;
	    std::cout << "\nx + y = " << x + y << std::endl;
	    std::cout << "x - y = " << x - y << std::endl;
	    std::cout << "x * y = " << x * y << std::endl;
	    std::cout << "x / y = " << x / y << std::endl;
    }
    {
	    std::cout << "\n=== Testing precision ===" << std::endl;
	    Fixed p(0.1f);
	    Fixed q(0.2f);

	    std::cout << "p = 0.1f" << std::endl;
	    std::cout << "q = 0.2f" << std::endl;
	    std::cout << "\np + q = " << p + q << std::endl;
    }
    {
	    std::cout << "\n=== Testing comparison operator ===" << std::endl;
	    Fixed a1(5);
	    Fixed a2(5);
	    Fixed a3(10);

	    std::cout << "a1 = 5" << std::endl;
	    std::cout << "a2 = 5" << std::endl;
	    std::cout << "a3 = 10" << std::endl;
	    std::cout << "\na1 == a2 = " << (a1 == a2) << std::endl;
	    std::cout << "a1 != a3" <<(a1 != a3) << std::endl;
	    std::cout << "a1 < a3" << (a1 < a3) << std::endl;
	    std::cout << "a3 > a2" <<(a3 > a2) << std::endl;
	    std::cout << "a1 <= a2" << (a1 <= a2) << std::endl;
	    std::cout << "a3 >= a1" << (a3 >= a1) << std::endl;
    }
    {
	    std::cout << "\n=== Testing comparison operator (1 = true and 0 = false)===" << std::endl;
	    Fixed a1(5);
	    Fixed a2(5);
	    Fixed a3(10);

	    std::cout << "a1 = 5" << std::endl;
	    std::cout << "a2 = 5" << std::endl;
	    std::cout << "a3 = 10" << std::endl;
	    std::cout << "\na1 == a2 = " << (a1 == a2) << std::endl;
	    std::cout << "a1 != a3 = " <<(a1 != a3) << std::endl;
	    std::cout << "a1 < a3 = " << (a1 < a3) << std::endl;
	    std::cout << "a3 > a2 = " <<(a3 > a2) << std::endl;
	    std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
	    std::cout << "a3 >= a1 = " << (a3 >= a1) << std::endl;
		std::cout << "a1 == a3 = " << (a1 == a3) << std::endl;
		std::cout << "a1 > a3 = " << (a1 > a3) << std::endl;
    }
    {
	    std::cout << "\n=== Testing min/max ===" << std::endl;
	    std::cout << "using non-const" << std::endl;
	    Fixed b1(1);
	    Fixed b2(2);
	
	    std::cout << "b1 = 1" << std::endl;
	    std::cout << "b2 = 2" << std::endl;
	    std::cout << "\nmin " << Fixed::min(b1, b2) << std::endl;
	    std::cout << "max " << Fixed::max(b1, b2) << std::endl;

	    Fixed &m = Fixed::max(b1, b2);
	    std::cout << "Change bigger one to 42" << std::endl;
	    m = Fixed(42); // change the bigger one
	    std::cout << "After modification, b1 = " << b1 << ", b2 = " << b2 << std::endl;


	    std::cout << "\nusing const" << std::endl;
	    Fixed const c1(3);
	    Fixed const c2(4);

	    std::cout << "\nc1 = 3" << std::endl;
	    std::cout << "c2 = 4" << std::endl;
	    std::cout << "\nmin " << Fixed::min(c1, c2) << std::endl;
	    std::cout << "max " << Fixed::max(c1, c2) << std::endl;
    }
    {
	    std::cout << "\n=== Testing negative numbers ===" << std::endl;
	    Fixed n1(-5);
	    Fixed n2(2);

	
	    std::cout << "\nn1 = -5" << std::endl;
	    std::cout << "n2 = 2" << std::endl;
	    std::cout << "n1 + n2 = " << n1 + n2 << std::endl;
	    std::cout << "n1 * n2 = " << n1 * n2 << std::endl;
    }

    return 0;
}
//
//
//

#include <iostream>
#include "Fraction.h"

int main() {
	Fraction f1(8, 22);
	Fraction f2(4, 11);

	std::cout << f1._numerator << "/ " << f1._denominator << "\n";
	std::cout << f2._numerator << "/ " << f2._denominator << "\n";
}

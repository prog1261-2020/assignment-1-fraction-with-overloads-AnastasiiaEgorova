/**
* Fraction.cpp
* Fraction Lib
*
* Created by Anastasiia Egorova on 2020-01-19
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Implementation of Fraction class' methods
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*
*/

#include "Fraction.h"
#include <iostream>
#include <sstream>

//constructor
Fraction::Fraction() {
}

//another constructor
Fraction::Fraction(int n) : _numerator(n), _denominator(1) {
}


//one more constructor
Fraction::Fraction(int n, int d) : _numerator(n), _denominator(d) {
	if (_denominator == 0)
		_denominator = 1;

	negativeDenominator();

	reduce();
}

//checks if fraction is in (x,-y) format, change it to (-x,y)
void Fraction::negativeDenominator() {
	if (_denominator < 0) {
		_numerator *= -1;
		_denominator *= -1;
	}
}

//reduce fraction
void Fraction::reduce() {
	if (_numerator != 0 && _denominator != 0) {
		int d = abs(gcd(_numerator, _denominator));
		_numerator /= d;
		_denominator /= d;
	}
}

//finds GCD 
int Fraction::gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

//overloading == operator
bool Fraction::operator==(const Fraction& rhs) const {
	return (_numerator == rhs._numerator) && (_denominator == rhs._denominator);
}

//overloading != operator
bool Fraction::operator!=(const Fraction& rhs) const {
	return !(*this == rhs);
}

//overloading < operator
bool operator<(const Fraction& lhs, const Fraction& rhs) {
	return (lhs._numerator * rhs._denominator < rhs._numerator * lhs._denominator);
}

//overloading <= operator
bool operator<=(const Fraction& lhs, const Fraction& rhs) {
	return (lhs < rhs) || (lhs == rhs);
}

//overloading > operator
bool operator>(const Fraction& lhs, const Fraction& rhs) {
	return !(lhs < rhs);
}

//overloading >= operator
bool operator>=(const Fraction& lhs, const Fraction& rhs) {
	return (lhs > rhs) || (lhs == rhs);
}

//overloading + operator
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	Fraction newFr(lhs._numerator * rhs._denominator + rhs._numerator * lhs._denominator,
		lhs._denominator * rhs._denominator);
	newFr.reduce();
	return newFr;
}

//overloading += operator
Fraction& Fraction::operator+=(const Fraction& rhs) {
	_numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
	_denominator = _denominator * rhs._denominator;
	reduce();
	return *this;
}

//overloading - operator
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	Fraction newFr(lhs._numerator * rhs._denominator - rhs._numerator * lhs._denominator,
		lhs._denominator * rhs._denominator);
	newFr.reduce();
	return newFr;
}

//overloading -= operator
Fraction& Fraction::operator-=(const Fraction& rhs) {
	_numerator = _numerator * rhs._denominator - rhs._numerator * _denominator;
	_denominator = _denominator * rhs._denominator;
	reduce();
	return *this;
}

//overloading * operator
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	Fraction newFr(lhs._numerator * rhs._numerator, lhs._denominator * rhs._denominator);
	newFr.reduce();
	return newFr;
}

//overloading *= operator
Fraction& Fraction::operator*=(const Fraction& rhs) {
	_numerator = _numerator * rhs._numerator;
	_denominator = _denominator * rhs._denominator;
	reduce();
	return *this;
}

//overloading / operator
Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	Fraction newFr(lhs._numerator * rhs._denominator, rhs._numerator * lhs._denominator);
	newFr.reduce();
	return newFr;
}

//overloading /= operator
Fraction& Fraction::operator/=(const Fraction& rhs) {
	_numerator = _numerator * rhs._denominator;
	_denominator = _denominator * rhs._numerator;
	negativeDenominator();
	reduce();
	return *this;
}

//overloading << operator
std::ostream& operator<<(std::ostream& os, const Fraction& rhs) {
	os << rhs._numerator << "/" << rhs._denominator;
	return os;
}

//overloading >> operator
std::istream& operator>>(std::istream& is, Fraction& rhs) {
	char L;
	is >> rhs._numerator >> L >> rhs._denominator;
	rhs.negativeDenominator();
	return is;
}
#include "rational.h"
#include <cmath>
#include <utility>

using namespace std;

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(int number) {
    numer = number;
    denom = 1;
}

Rational::Rational(int n, int d) {
    numer = n;
    denom = d;
    simplify();
}

int Rational::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void Rational::simplify() {
    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
    int g = gcd(numer, denom);
    if (g > 1) {
        numer /= g;
        denom /= g;
    }
}
//алгоритм евклида
Rational& Rational::operator +=(const Rational& r) {
    numer = (numer * r.denom + denom * r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator +(const Rational &r) const {
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const {
    return Rational(-numer, denom);
}

Rational& Rational::operator -=(const Rational& r) {
    return (*this += (-r));
}

Rational Rational::operator -(const Rational &r) const {
    Rational res(*this);
    return res -= r;
}

Rational& Rational::operator *=(const Rational& r) {
    numer *= r.numer;
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator *(const Rational &r) const {
    Rational res(*this);
    return res *= r;
}

Rational& Rational::operator /=(const Rational& r) {
    numer *= r.denom;
    denom *= r.numer;
    simplify();
    return *this;
}

Rational Rational::operator /(const Rational &r) const {
    Rational res(*this);
    return res /= r;
}

Rational& Rational::operator ++() {
    numer += denom;
    return *this;
}

Rational Rational::operator ++(int) {
    Rational r(*this);
    numer += denom;
    return r;
}

bool Rational::operator ==(const Rational& r) const {
    return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const {
    return !(*this == r);
}

Rational::operator int() const {
    return numer / denom;
}

Rational::operator double() const {
    return ((double)numer) / denom;
}

istream& operator >>(istream& in, Rational& r) {
    in >> r.numer >> r.denom;
    r.simplify();
    return in;
}

ostream& operator <<(ostream& out, const Rational& r) {
    out << r.numer << "/" << r.denom;
    return out;
}
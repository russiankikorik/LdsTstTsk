#include "Vector3D.hpp"
#include <stdexcept>

double myround(double value) {
    if (std::abs(value * 10e12) == std::numeric_limits<double>::infinity()) {
        throw std::overflow_error("overflow on rounding");
    }
    return std::round(value * 10e12) / 10e12;
}

Vector3D::Vector3D() : _X(0), _Y(0), _Z(0) {}

Vector3D::Vector3D(double x, double y, double z) : _X(x), _Y(y), _Z(z) {}

Vector3D& Vector3D::operator=(const Vector3D& v) {
    _X = v._X;
    _Y = v._Y;
    _Z = v._Z;
    return *this;
}

bool Vector3D::operator==(const Vector3D& v) const {
    return (_X == v._X && _Y == v._Y && _Z == v._Z);
}

double Vector3D::operator[](const int idx) const {
    if (idx == 0) return _X;
    if (idx == 1) return _Y;
    if (idx == 2) return _Z;
    else throw std::out_of_range("Vector3D index out of range");
}

Vector3D operator-(const Vector3D& u, const Vector3D& v) {
    return Vector3D(myround(u.X() - v.X()),
        myround(u.Y() - v.Y()),
        myround(u.Z() - v.Z()));
}

double scalar_mul(const Vector3D& u, const Vector3D& v) {
    return myround(u.X() * v.X() + u.Y() * v.Y() + u.Z() * v.Z());
}

Vector3D vector_mul(const Vector3D& u, const Vector3D& v) {
    return Vector3D(myround(u.Y() * v.Z() - v.Y() * u.Z()),
        myround(-(u.X() * v.Z() - v.X() * u.Z())),
        myround(u.X() * v.Y() - v.X() * u.Y()));
}

std::ostream& operator<<(std::ostream& out, const Vector3D& u) {
    out << u._X << ' ' << u._Y << ' ' << u._Z;
    return out;
}

std::istream& operator>>(std::istream& in, Vector3D& u) {
    in >> u._X >> u._Y >> u._Z;
    return in;
}
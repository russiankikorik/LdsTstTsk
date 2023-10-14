#pragma once
#include <iostream>

class Vector3D {
    double _X;
    double _Y;
    double _Z;
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    double X() const { return _X; };
    double Y() const { return _Y; };
    double Z() const { return _Z; };
    Vector3D& operator=(const Vector3D& v);
    bool operator==(const Vector3D& v) const;
    double operator[](const int idx) const;
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& u);
    friend std::istream& operator>>(std::istream& in, Vector3D& u);
};

Vector3D operator-(const Vector3D& u, const Vector3D& v);

double scalar_mul(const Vector3D& u, const Vector3D& v);

Vector3D vector_mul(const Vector3D& u, const Vector3D& v);

double myround(double value);
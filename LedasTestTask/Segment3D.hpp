#pragma once
#include "Vector3D.hpp"

class Segment3D {
    Vector3D _start;
    Vector3D _end;
    Vector3D _vector;
public:
    Segment3D();
    Segment3D(const Vector3D& u, const Vector3D& v);
    Vector3D start() const { return _start; };
    Vector3D end() const { return _end; };
    Vector3D vector() const { return _vector; };
    friend std::ostream& operator<<(std::ostream& out, const Segment3D& seg);
    friend std::istream& operator>>(std::istream& in, Segment3D& seg);
};

Vector3D intersect(const Segment3D& seg1, const Segment3D& seg2);
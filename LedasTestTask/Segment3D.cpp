#include "Segment3D.hpp"

Segment3D::Segment3D() {
    _start = Vector3D();
    _end = Vector3D();
    _vector = Vector3D();
}

Segment3D::Segment3D(const Vector3D& u, const Vector3D& v) {
    _start = u;
    _end = v;
    _vector = v - u;
}

std::ostream& operator<<(std::ostream& out, const Segment3D& seg) {
    out << seg._start << std::endl << seg._end << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Segment3D& seg) {
    in >> seg._start >> seg._end;
    seg._vector = seg._end - seg._start;
    return in;
}
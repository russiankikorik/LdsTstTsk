#include "Segment3D.hpp"

namespace {
    double _calculate(int number, const Segment3D& seg1, const Segment3D& seg2) {
        Vector3D v1 = seg1.vector();
        Vector3D v2 = seg2.vector();
        Vector3D v1v2 = vector_mul(v1, v2);
        Vector3D start1 = seg1.start();
        Vector3D start2 = seg2.start();
        for (int i = 0; i < 3; i += 1) {
            if (i != number && v1v2[i] != 0) {
                int idx = 3 - i - number;
                double value = (start1[number] * v1[idx] * v2[number]
                    - start2[number] * v2[idx] * v1[number]
                    + (start2[idx] - start1[idx]) * v1[number] * v2[number])
                    / (v1[idx] * v2[number] - v2[idx] * v1[number]);
                return myround(value);
            }
        }
        return 0;
    }
}

//-inf -inf -inf - no intersection
//inf inf inf - all points are on the same line

Vector3D intersect(const Segment3D& seg1, const Segment3D& seg2) {
    Vector3D neg_inf = Vector3D(-std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity());
    if (seg1.vector() == Vector3D() && seg2.vector() == Vector3D()) {
        if (seg1.start() == seg2.start()) {
            return seg1.start();
        }
        return neg_inf;
    }
    if (seg1.vector() == Vector3D()) {
        if (vector_mul(seg2.vector(), seg2.start() - seg1.start()) == Vector3D()) {
            return seg1.start();
        }
        else return neg_inf;
    }
    else if (seg2.vector() == Vector3D()) {
        if (vector_mul(seg1.vector(), seg1.start() - seg2.start()) == Vector3D()) {
            return seg2.start();
        }
        else return neg_inf;
    }
    Vector3D delta = seg2.start() - seg1.start();
    Vector3D v1v2 = vector_mul(seg1.vector(), seg2.vector());
    if (v1v2 == Vector3D()) {
        if (vector_mul(delta, seg1.vector()) == Vector3D()) {
            return Vector3D(std::numeric_limits<double>::infinity(),
                std::numeric_limits<double>::infinity(),
                std::numeric_limits<double>::infinity());
        }
        return neg_inf;
    }
    if (scalar_mul(delta, v1v2) != 0) {
        return neg_inf;
    }
    double x = _calculate(0, seg1, seg2);
    double y = _calculate(1, seg1, seg2);
    double z = _calculate(2, seg1, seg2);
    return Vector3D(x, y, z);
}
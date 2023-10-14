#include <iostream>
#include "Segment3D.hpp"

int main()
{
    //-inf -inf -inf - no intersection
    //inf inf inf - all points are on the same line
    Segment3D seg1, seg2;
    std::cin >> seg1 >> seg2;
    try {
        Vector3D intersection = intersect(seg1, seg2);
        std::cout << intersection;
    }
    catch (std::overflow_error& err) {
        std::cout << err.what();
    }    
}
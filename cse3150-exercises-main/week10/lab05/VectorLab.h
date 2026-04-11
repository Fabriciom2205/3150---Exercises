#ifndef VECTOR_LAB_H
#define VECTOR_LAB_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

struct DataPoint {
    std::vector<double> dimensions;
    std::string identifier;
};

struct ProximityMatch {
    std::string idA;
    std::string idB;
    double distance;
};

class VectorLab {
public:
    static double getCosineDistance(const std::vector<double>& a, const std::vector<double>& b);
    static bool sortByDistance(const ProximityMatch& a, const ProximityMatch& b);
};

#endif
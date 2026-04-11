#include "VectorLab.h"

double VectorLab::getCosineDistance(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = 0.0, magA = 0.0, magB = 0.0;

    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
        magA += a[i] * a[i];
        magB += b[i] * b[i];
    }

    if (magA == 0 || magB == 0) return 1.0;

    double similarity = dot / (std::sqrt(magA) * std::sqrt(magB));
    return 1.0 - similarity; 
}

bool VectorLab::sortByDistance(const ProximityMatch& a, const ProximityMatch& b) {
    return a.distance < b.distance; 
}
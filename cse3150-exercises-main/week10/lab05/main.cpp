#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "VectorLab.h"

int main() {
    std::vector<DataPoint> dataset;
    std::ifstream file("vectors.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::stringstream ss(line);
            DataPoint point;
            double val;
            
            ss >> point.identifier;
            while (ss >> val) {
                point.dimensions.push_back(val);
            }
            dataset.push_back(point);
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open vectors.txt" << std::endl;
        return 1;
    }

    std::vector<ProximityMatch> results;
    for (size_t i = 0; i < dataset.size(); ++i) {
        for (size_t j = i + 1; j < dataset.size(); ++j) {
            double dist = VectorLab::getCosineDistance(dataset[i].dimensions, dataset[j].dimensions);
            results.push_back({dataset[i].identifier, dataset[j].identifier, dist});
        }
    }

    std::sort(results.begin(), results.end(), VectorLab::sortByDistance);

    std::cout << "--- Vector Proximity ---" << std::endl;
    for (const auto& r : results) {
        std::cout << r.idA << " <-> " << r.idB << " | Distance: " << r.distance << std::endl;
    }

    return 0;
}
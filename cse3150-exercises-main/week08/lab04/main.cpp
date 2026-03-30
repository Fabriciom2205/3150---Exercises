#include <iostream>
#include <iomanip>
#include "Vehicles.h"

int main() {
    HybridVehicle aHybrid;

    double miles = 300.0;
    aHybrid.setMiles(miles);
    aHybrid.setTotalkWh(70.0);

    double mpge = aHybrid.calcMPGe();
    std::cout << "MPGe: " << std::fixed << std::setprecision(2) << mpge << std::endl;

    double costOfOneGallon = 3.10;
    double averageCostPerMile = aHybrid.costPerMile(costOfOneGallon);
    
    std::cout << "Average cost per mile: $" << averageCostPerMile << std::endl;

    return 0;
}
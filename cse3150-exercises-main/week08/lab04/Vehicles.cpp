#include "Vehicles.h"

double ElectricVehicle::calcMPGe() {
    if (totalkWh == 0) return 0;
    return (miles / totalkWh) * 33.7;
}

double HybridVehicle::costPerMile(double costOfOneGallon) {
    double mpge = calcMPGe();
    if (mpge == 0) return 0;
    return costOfOneGallon / mpge;
}
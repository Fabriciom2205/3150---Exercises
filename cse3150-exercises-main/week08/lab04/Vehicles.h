#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>

class Vehicle {
protected:
    double miles;
public:
    Vehicle() : miles(0) {}
    virtual void setMiles(double m) { miles = m; }
};

class ElectricVehicle : virtual public Vehicle {
protected:
    double totalkWh;
public:
    ElectricVehicle() : totalkWh(0) {}
    void setTotalkWh(double k) { totalkWh = k; }
    double calcMPGe();
};

class GasolineVehicle : virtual public Vehicle {
protected:
    double mpg;
public:
    GasolineVehicle() : mpg(0) {}
    void setMPG(double m) { mpg = m; }
};

class HybridVehicle : public ElectricVehicle, public GasolineVehicle {
public:
    double costPerMile(double costOfOneGallon);
};

#endif
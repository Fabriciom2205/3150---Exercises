#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vehicles.h"

TEST_CASE("Testing HybridVehicle Efficiency Calculations") {
    HybridVehicle testCar;

    SUBCASE("Standard MPGe Calculation") {
        testCar.setMiles(300.0);
        testCar.setTotalkWh(70.0);

        CHECK(testCar.calcMPGe() == doctest::Approx(144.428).epsilon(0.001));
    }

    SUBCASE("Cost Per Mile Calculation") {
        testCar.setMiles(300.0);
        testCar.setTotalkWh(70.0);
        double gasPrice = 3.10;

        CHECK(testCar.costPerMile(gasPrice) == doctest::Approx(0.0214).epsilon(0.001));
    }

    SUBCASE("Edge Case: Zero kWh") {
        testCar.setMiles(100.0);
        testCar.setTotalkWh(0.0);

        CHECK(testCar.calcMPGe() == 0.0);
    }
}
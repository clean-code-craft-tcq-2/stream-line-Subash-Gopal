#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "SocSensor.h"

TEST_CASE("Fetch and test the data of soc - Low Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData >= 0);
}

TEST_CASE("Fetch and test the data of soc - High Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData <= 100);
}

TEST_CASE("Fetch and test the data of Temperature - High Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData <= -40);
}

TEST_CASE("Fetch and test the data of Temperature - High Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData <= 40);
}

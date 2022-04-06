#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "SocSensor.h"

TEST_CASE("Fetch and test the data of soc - Low Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData() >= 0);
    delete socSensorData;
}

TEST_CASE("Fetch and test the data of soc - High Limit Test") {
    SocSensor *socSensorData = new SocSensor;
    REQUIRE(socSensorData->fetchSensorData() <= 100);
    delete socSensorData;
}

TEST_CASE("Fetch and test the data of Temperature - High Limit Test") {
    TempSensor *tempSensorData = new TempSensor;
    REQUIRE(tempSensorData->fetchSensorData() <= -40);
    delete tempSensorData;
}

TEST_CASE("Fetch and test the data of Temperature - High Limit Test") {
    TempSensor *tempSensorData = new TempSensor;
    REQUIRE(tempSensorData->fetchSensorData() <= 40);
    delete tempSensorData;
}

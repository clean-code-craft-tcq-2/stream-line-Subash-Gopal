#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "SocSensor.h"
#include "TempSensor.h"
#include "Sender.cpp"


TEST_CASE("Fetches data from a sensor and writtens to CSV FilE") {
    Sender sender;
    REQUIRE(sender.sendBMSSensorData() == true);
}

TEST_CASE("Fetch and test the data of soc - Low Limit Test") {
    SocSensor *socSensorData1 = new SocSensor;
    REQUIRE(socSensorData1->fetchSensorData() >= 0);
    delete socSensorData1;
}

TEST_CASE("Fetch and test the data of soc - High Limit Test") {
    SocSensor *socSensorData2 = new SocSensor;
    REQUIRE(socSensorData2->fetchSensorData() <= 100);
    delete socSensorData2;
}

TEST_CASE("Fetch and test the data of Temperature - Low Limit Test") {
    TempSensor *tempSensorData3 = new TempSensor;
    REQUIRE(tempSensorData3->fetchSensorData() >= -40);
    delete tempSensorData3;
}

TEST_CASE("Fetch and test the data of Temperature - High Limit Test") {
    TempSensor *tempSensorData4 = new TempSensor;
    REQUIRE(tempSensorData4->fetchSensorData() <= 40);
    delete tempSensorData4;
}

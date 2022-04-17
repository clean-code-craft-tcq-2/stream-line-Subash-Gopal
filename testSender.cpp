#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "Sender/SocSensor.h"
#include "Sender/TempSensor.h"
#include "Sender/Sender.cpp"
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

vector<vector<string>> content;

void readSensorDataFromCSV()
{
    string fname = "BmsSendorData.csv";
    vector<string> row;
    string line, word;

    try
    {
        fstream file(fname);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row.clear();
                stringstream str(line);
                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
    }
    catch (std::exception const &e)
    {
        std::cout << "There was an error: " << e.what() << std::endl;
    }
}

TEST_CASE("Fetches data from a sensor and writtens to CSV FilE and tests the values reading from the CSV file ") {
    Sender sender;
    sender.sendBMSSensorData();    
    readSensorDataFromCSV();
    int count, valueSOC, valueTemp, headingTitle = 1; 
    int numberOfEntries=50 + headingTitle;
    int numberOfSensor = 2;
    for(int i=1;i<numberOfEntries;i++)
    {
	for(int j=0;j<=numberOfSensor;j++)
	{  	    
            std::istringstream(content[i][0]) >> count;
            REQUIRE(count >= 0);
	    REQUIRE(count <= 49);
		
            std::istringstream(content[i][1]) >> valueSOC;
            REQUIRE(valueSOC <= 100);
	    REQUIRE(valueSOC >= 0);
	    
            std::istringstream(content[i][2]) >> valueTemp;	
            REQUIRE(valueTemp >= -40);
	    REQUIRE(valueTemp <= 40);
	}
    }
}

//Below test cases helps us to check sensor funtionality 
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

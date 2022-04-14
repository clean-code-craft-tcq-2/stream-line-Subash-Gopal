#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "SocSensor.h"
#include "TempSensor.h"
#include "Sender.cpp"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

TEST_CASE("Fetches data from a sensor and writtens to CSV FilE") {
    Sender sender;
    REQUIRE(sender.sendBMSSensorData() == true);
    
    string fname = "BmsSendorData.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
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
    else
    {
    }
    
    for(int i=1;i<51;i++)
    {
	for(int j=0;j<3;j++)
	{  
	    int count;
            std::istringstream(content[i][0]) >> count;
            REQUIRE(count >= 0);
	    REQUIRE(count <= 49);
		
	    int valueSOC;
            std::istringstream(content[i][1]) >> valueSOC;
            REQUIRE(valueSOC <= 100);
	    REQUIRE(valueSOC >= 0);
	    
	    int valueTemp;
            std::istringstream(content[i][2]) >> valueTemp;	
            REQUIRE(valueTemp >= -40);
	    REQUIRE(valueTemp <= 40);
	}
    }
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

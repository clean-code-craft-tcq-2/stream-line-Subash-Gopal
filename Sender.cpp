#include "BMSParameters.h"
#include "TempSensor.h"
#include "SocSensor.h"
#include <iostream>
#include <string>
#include <fstream>

class WriteDataToCSV
{
private:
    std::ofstream BmsSendorDataFile;

public:
    WriteDataToCSV()
    {
        BmsSendorDataFile.open("BmsSendorData.csv", std::ios::out | std::ios::trunc);
        BmsSendorDataFile << "Count, SOC Sensor Data, Temperature Sensor Data \n";
    }

    ~WriteDataToCSV()
    {
        BmsSendorDataFile.flush();
        BmsSendorDataFile.close();
    }

    void printBMSSenderData(int i, int currentsocValueData, int currentTempValueData)
    {
        BmsSendorDataFile << i << "," << currentsocValueData << "," << currentTempValueData << "\n";
    }
};
class Sender
{
private:
    const int streamingLimit = 50;

public:
    void sendBMSSensorData()
    {
        WriteDataToCSV writeData;
        for (int iterator = 0; iterator < streamingLimit; iterator++)
        {
            BMSParameters *BMSParameters1 = new TempSensor;
            BMSParameters *BMSParameters2 = new SocSensor;
            writeData.printBMSSenderData(iterator, BMSParameters1->fetchSensorData(), BMSParameters2->fetchSensorData());
        }
    }
};

int main()
{
    Sender a;
    a.sendBMSSensorData();
    return 0;
}

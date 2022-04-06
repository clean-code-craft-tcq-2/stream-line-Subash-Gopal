#ifndef _BMSPARAMETERS_H_
#define _BMSPARAMETERS_H_
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
#endif
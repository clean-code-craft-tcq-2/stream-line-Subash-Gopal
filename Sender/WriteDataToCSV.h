#ifndef _WRITEDATATOCSV_H_
#define _WRITEDATATOCSV_H_
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
        std::cout<<"Opened the CSV file to write the data \n";
        BmsSendorDataFile.open("BmsSendorData.csv", std::ios::out | std::ios::trunc);
        BmsSendorDataFile << "Count, SOC Sensor Data, Temperature Sensor Data \n";
    }

    ~WriteDataToCSV()
    {
        std::cout<<"Closed the CSV file \n";
        BmsSendorDataFile.flush();
        BmsSendorDataFile.close();
    }

    void printBMSSenderData(int i, int currentsocValueData, int currentTempValueData)
    {
        std::cout<< i << "," << currentsocValueData << "," << currentTempValueData << "\n";
        BmsSendorDataFile << i << "," << currentsocValueData << "," << currentTempValueData << "\n";
    }
};
#endif

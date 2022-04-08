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
        std::cout<<"Opened the CSV file to write the data"
        BmsSendorDataFile.open("BmsSendorData.csv", std::ios::out | std::ios::trunc);
        BmsSendorDataFile << "Count, SOC Sensor Data, Temperature Sensor Data \n";
    }

    ~WriteDataToCSV()
    {
        std::cout<<"Closed the CSV file"
        BmsSendorDataFile.flush();
        BmsSendorDataFile.close();
    }

    void printBMSSenderData(int i, int currentsocValueData, int currentTempValueData)
    {
        BmsSendorDataFile << i << "," << currentsocValueData << "," << currentTempValueData << "\n";
    }
};
#endif

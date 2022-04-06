#include "BMSParameters.h"
#include "WriteDataToCSV.h"
#include "TempSensor.h"
#include "SocSensor.h"
#include <iostream>

class Sender
{
private:
    const int streamingLimit = 50;

public:
    bool sendBMSSensorData()
    {
        WriteDataToCSV writeData;
        int validateCount = 1;
        for (int iterator = 0; iterator < streamingLimit; iterator++)
        {
            BMSParameters *BMSParameterSoc = new TempSensor;
            BMSParameters *BMSParameterTemp = new SocSensor;
            writeData.printBMSSenderData(iterator, BMSParameterSoc->fetchSensorData(), BMSParameterTemp->fetchSensorData());
            validateCount++;
            cout<<"subash"<<validateCount;
        }
        return (validateCount == streamingLimit)?  true :false;
    }
};

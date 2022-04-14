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
    void sendBMSSensorData()
    {
        WriteDataToCSV writeData;
        for (int iterator = 0; iterator < streamingLimit; iterator++)
        {
            BMSParameters *BMSParameterSoc = new SocSensor;
            BMSParameters *BMSParameterTemp = new TempSensor;
            writeData.printBMSSenderData(iterator, BMSParameterSoc->fetchSensorData(), BMSParameterTemp->fetchSensorData());
        }
    }
};

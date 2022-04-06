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
            BMSParameters *BMSParameters1 = new TempSensor;
            BMSParameters *BMSParameters2 = new SocSensor;
            writeData.printBMSSenderData(iterator, BMSParameters1->fetchSensorData(), BMSParameters2->fetchSensorData());
        }
    }
};

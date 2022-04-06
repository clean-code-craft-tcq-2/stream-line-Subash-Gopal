#ifndef _TEMPSENSOR_H_
#define _TEMPSENSOR_H_
#include "BMSParameters.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class TempSensor : public BMSParameters
{
private:
    int currentTempValue;
    const int maxLimit = 40;
    const int delimeter = 80;

public:
    TempSensor()
    {
        currentTempValue = (rand() % delimeter) - maxLimit;
    }
    int fetchSensorData()
    {
        return currentTempValue;
    }
};
#endif

#ifndef _SOCSENSOR_H_
#define _SOCSENSOR_H_
#include "BMSParameters.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class SocSensor : public BMSParameters
{
private:
    int currentSocValue;
    const int maxLimit = 100;

public:
    SocSensor()
    {
        currentSocValue = (rand() % maxLimit);
    }
    int fetchSensorData()
    {
        return currentSocValue;
    }
};
#endif

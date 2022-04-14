#ifndef _BMSPARAMETERS_H_
#define _BMSPARAMETERS_H_

class BMSParameters
{
public:
    virtual ~BMSParameters() {}
    virtual int fetchSensorData() = 0;
};
#endif

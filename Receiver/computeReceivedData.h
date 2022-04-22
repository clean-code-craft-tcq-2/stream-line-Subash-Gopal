#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SENSOR_READINGS 50  

typedef enum {
  OK,
  NOK
} FileAccess;

extern int buffSize, Count;
extern FileAccess readSenderData();
extern FileAccess computeSenderData();
extern int Temperature[MAX_SENSOR_READINGS]; //buffer to store BMS Temperature value
extern int SoC[MAX_SENSOR_READINGS];  //buffer to store BMS SoC value

extern void findTempMinMaxValues(int Count);
extern void findSoCMinMaxValues(int Count);
extern void findParamMinValue(int sensorValue[], int Count, int *minSensorVal);
extern void findParamMaxValue(int sensorValue[], int Count, int *minSensorVal);
extern float calculateSMA(int sensorValue[], int Count);
extern float calculateSMAforTemp(int Count);
extern float calculateSMAforSoC(int Count);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SENSOR_READINGS 50  
#define BATT_PARAMETERS 3

typedef enum {
  NOK,
  OK
} FileAccess;

extern FileAccess readSenderData();
extern FileAccess computeSenderData();
extern int ReadingCount[MAX_SENSOR_READINGS];
extern int Temperature[MAX_SENSOR_READINGS]; //buffer to store BMS Temperature value
extern int SoC[MAX_SENSOR_READINGS];  //buffer to store BMS SoC value
extern int minVal[BATT_PARAMETERS];
extern int maxVal[BATT_PARAMETERS];

extern void findTempMinMaxValues(int entriesCount);
extern void findSoCMinMaxValues(int entriesCount);
extern void findParamMinValue(int sensorValue[MAX_SENSOR_READINGS], int Count, int *minSensorVal);
extern void findParamMaxValue(int sensorValue[MAX_SENSOR_READINGS], int Count, int *maxSensorVal);
extern float calculateSMA(int sensorValue[MAX_SENSOR_READINGS], int Count);
extern float calculateSMAforTemp(int entriesCount);
extern float calculateSMAforSoC(int entriesCount);

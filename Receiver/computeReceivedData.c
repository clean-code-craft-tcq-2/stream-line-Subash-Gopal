#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "computeReceivedData.h"

int minVal[BATT_PARAMETERS] = {100,100};
int maxVal[BATT_PARAMETERS] = {0,0};

int ReadingCount[]={};
int Temperature[]={};
int SoC[]={};
int entriesCount=0;

/* Function to read the sensor readings from "SenderDataFromConsole.txt" file and store into a buffer */
FileAccess readSenderData()
{
  FILE *sensData_fp;
  int line=1;
  FileAccess ReadData = NOK;
  sensData_fp=fopen("./Receiver/SenderDataFromConsole.txt", "r");
  if (sensData_fp!=NULL)
    {
    int Count=0,ReadTemperature=0,ReadSoC=0,Idx=0;
    printf("File opened successfully\n");
	while(line != EOF)
	{
	line=fscanf(sensData_fp,"%d %d %d",&Count, &ReadTemperature, &ReadSoC);
	ReadingCount[Idx]=Count;
	Temperature[Idx]=ReadTemperature;
	SoC[Idx]=ReadSoC;
	Idx++;
	}
	entriesCount = Idx;
	ReadData = OK;
	}	
	fclose(sensData_fp);
	return ReadData;
}

/* Function to find minimum and maximum Temperature value from sender readings */
void findTempMinMaxValues(int Count)
{
 findParamMinValue(Temperature, Count, &minVal[0]);
 findParamMaxValue(Temperature, Count, &maxVal[0]);
 printf("Minimum and Maximum Temperature values from Sender are %d degC and %d degC\n",minVal[0],maxVal[0]);
}


/* Function to find minimum and maximum SoC value from sender readings */
void findSoCMinMaxValues(int Count)
{
 findParamMinValue(SoC, Count, &minVal[1]);
 findParamMaxValue(SoC, Count, &maxVal[1]);
 printf("Minimum and Maximum SoC values from Sender are %d%%  and %d%% \n",minVal[1],maxVal[1]);
}

/* Function to find minimum value of battery parameter */
void findParamMinValue(int sensorValue[], int Count, int *minSensorVal)
 {
   for(int i=0; i< Count; i++)
   {
    if(sensorValue[i] < *minSensorVal)
    *minSensorVal = sensorValue[i];
   }   
 }

/* Function to find maximum value of battery parameter */ 
void findParamMaxValue(int sensorValue[], int Count, int *maxSensorVal)
 {
   for(int i=0; i< Count; i++)
   {
    if(sensorValue[i] > *maxSensorVal)
    *maxSensorVal = sensorValue[i];
   }   
 }
 
/* Function to calculate SMA for last 5 Temperature readings */
float calculateSMAforTemp(int Count)
{
float temperatureSMA = calculateSMA(Temperature, Count);
printf("Simple moving average of last five temperature readings %0.2f\n", temperatureSMA);
return temperatureSMA;
}

/* Function to calculate SMA for last 5 SoC readings */
float calculateSMAforSoC(int Count)
{
float socSMA = calculateSMA(SoC, Count);
printf("Simple moving average of last five SoC readings %0.2f\n", socSMA);
return socSMA;
}

/* Function to calculate SMA */ 
float calculateSMA(int sensorValue[], int Count)
{
float sum, average=0.0;
for(int i=(Count-5); i<Count; i++)
{
   sum += (float)sensorValue[i];     
}
   average = sum/5;
   return average;  
}

FileAccess computeSenderData()
{
FileAccess ReadData = NOK;
ReadData = readSenderData();
  if(ReadData)
    {
      findTempMinMaxValues(entriesCount);
      findSoCMinMaxValues(entriesCount);
      calculateSMAforTemp(entriesCount);
      calculateSMAforSoC(entriesCount);
    }
return ReadData;
}

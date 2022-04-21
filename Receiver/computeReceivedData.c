#include "computeReceivedData.h"

int minVal[entries] = {50,50};
int maxVal[entries] = {0,0};

FileAccess ReadData, WriteData;
int buffSize=0;
int ReadingCount[]={};
int Temperature[]={};
int SoC[]={};

/* Function to read the sensor readings from "SenderDataFromConsole.txt" file and store into a buffer */
FileAccess readSenderData()
{
  FILE *sensData_fp;
  int line=1, Idx=0;
  FileAccess ReadData= NOK;

  sensData_fp=fopen("./Receiver/SenderData.txt", "r");
  if (sensData_fp==NULL)
    {
    printf("Unable to open the file\n");
    }	
  else
    {
	int ReadTemperature=0,ReadSoC=0;
    printf("File opened successfully\n");
	while(line != EOF)
	{
	line=fscanf(sensData_fp,"%d %d %d",&Count, &ReadTemperature, &ReadSoC);
	ReadingCount[Idx]=Count;
	Temperature[Idx]=ReadTemperature;
	SoC[Idx]=ReadSoC;
	Idx++;
	}
	buffSize= Idx;
	ReadData= OK;
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
 printf("Minimum and Maximum SoC values from Sender are %d%%  and %d%% \n",minVal[0],maxVal[0]);
}

/* Function to find minimum value of battery parameter */
void findParamMinValue(int sensorValue[], int Count, float *minSensorVal)
 {
   for(int i=0; i< Count; i++)
   {
    if(sensorValue[i] < *minSensorVal)
    *minSensorVal = sensorValue[i];
   }   
 }

/* Function to find maximum value of battery parameter */ 
void findParamMaxValue(int sensorValue[], int Count, float *maxSensorVal)
 {
   for(int i=0; i< Count; i++)
   {
    if(sensorValue[i] > *maxSensorVal)
    *maxSensorVal = sensorValue[i];
   }   
 }
 
/* Function to calculate SMA */ 
float calculateSMA(int sensorValue[], int Count)
{
int sum=0;
float average=0;
for(int i=(Count-5); i< Count; i++)
{
   sum += sensorValue[i];     
}
   average = sum/5;
   return average;  
}

/* Function to calculate SMA for last 5 Temperature readings */
float calculateSMAforTemp(int sensorValue[], int Count)
{
float temperatureSMA = calculateSMA(Temperature, Count);
printf("Simple moving average of last 5 temperature readings\n", temperatureSMA);
return temperatureSMA;
}

/* Function to calculate SMA for last 5 SoC readings */
float calculateSMAforSoC(int sensorValue[], int Count)
{
float socSMA = calculateSMA(SoC, Count);
printf("Simple moving average of last 5 SoC readings\n", socSMA);
return socSMA;
}

FileAccess computeSenderData()
{
FileAccess ReadData = NOK;
ReadData = readSenderData();
  if(ReadData==OK)
    {
      findTempMinMaxValues(Count);
      findSoCMinMaxValues(Count);
      calculateSMAforTemp(sensorValue, Count);
      calculateSMAforSoC(sensorValue, Count);
    }
return ReadData;
}

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "computeReceivedData.h"

TEST_CASE("To check if file is successfully opened for read data access") 
{
 FILE *sensData_fp=fopen("./Receiver/SenderDataFromConsole.txt", "r"); 
 REQUIRE_NOTHROW(readSenderData()== OK); 
}

TEST_CASE("To check Minimum, Maximum and SMA of Temperature and SoC data from a file") 
{
  REQUIRE_NOTHROW(computeSenderData()== OK);  
}

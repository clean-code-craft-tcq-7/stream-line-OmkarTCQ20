// stream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "Test/catch.hpp"
#include <iostream>
#include <sstream>
#include <cassert>
#include "Sender.hpp"
using namespace std;

extern const int STANDARD_NUMBER_OF_SAMPLES = 50;
extern std::stringstream ActualSenderOutput[STANDARD_NUMBER_OF_SAMPLES], ExpectedSenderOutput[STANDARD_NUMBER_OF_SAMPLES];


    TEST_CASE("PASSING TEST CASE 1") {

    int Temperature_Sensor_Readings [STANDARD_NUMBER_OF_SAMPLES] = { 0 };
    int State_Of_Charge [STANDARD_NUMBER_OF_SAMPLES] = { 0 };
    GenerateRandomTemperNumbers(Temperature_Sensor_Readings, STANDARD_NUMBER_OF_SAMPLES);
    GenerateRandomSOCNumbers(State_Of_Charge, STANDARD_NUMBER_OF_SAMPLES);
    CallSender(Temperature_Sensor_Readings, State_Of_Charge);
    REQUIRE(TestSenderOutput(Temperature_Sensor_Readings, State_Of_Charge) == true);
}

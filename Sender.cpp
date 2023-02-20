#include <iostream>
#include <iomanip>
#include "Sender.hpp"
#include <assert.h>
using namespace std;

const int STANDARD_NUMBER_OF_SAMPLES = 50;
std::stringstream ActualSenderOutput[STANDARD_NUMBER_OF_SAMPLES], ExpectedSenderOutput[STANDARD_NUMBER_OF_SAMPLES];

void CallExpectedSenderOutput(int f_Temperature_Sensor_Readings[], int f_State_Of_Charge[]) {
    int index, buffer_index = 0;
    for (index = 0; index < STANDARD_NUMBER_OF_SAMPLES; index++) {
        ExpectedSenderOutput[buffer_index]
            << left << setw(5) << "Temperature_Sensor_Reading : " << f_Temperature_Sensor_Readings[index]
            << left << setw(5) << "State_Of_Charge : " << f_State_Of_Charge[index]
            << std::endl;
        ++buffer_index;
    }
}

void CallSender(int f_Temperature_Sensor_Readings[], int f_State_Of_Charge[]) {
    int index, buffer_index = 0;
    for (index = 0; index < STANDARD_NUMBER_OF_SAMPLES; index++) {

        cout << left << setw(5) << "  Temperature_Sensor_Reading : " << f_Temperature_Sensor_Readings[index]
            << left << setw(5) << "  State_Of_Charge : " << f_State_Of_Charge[index]
            << std::endl;


        ActualSenderOutput[buffer_index]
            << left << setw(5) << "Temperature_Sensor_Reading : " << f_Temperature_Sensor_Readings[index]
            << left << setw(5) << "State_Of_Charge : " << f_State_Of_Charge[index]
            << std::endl;

        ++buffer_index;
    }
}

bool TestSenderOutput(int f_Temperature_Sensor_Readings[], int f_State_Of_Charge[]) {

    CallExpectedSenderOutput(f_Temperature_Sensor_Readings, f_State_Of_Charge);
    for (int index = 0; index < STANDARD_NUMBER_OF_SAMPLES; index++) {
        if (ActualSenderOutput[index].str() != ExpectedSenderOutput[index].str()) {
            return false;
            break;
        }
    }
    return true;
}

void GenerateRandomTemperNumbers(int* f_ToBeGenerated_arr, int f_size_arr) {

    srand(time(NULL));

    for (int index = 0; index < f_size_arr; index++)
    {
        f_ToBeGenerated_arr[index] = rand();
    }

}

void GenerateRandomSOCNumbers(int* f_ToBeGenerated_arr, int f_size_arr) {

    srand(time(NULL));

    for (int index = 0; index < f_size_arr; index++)
    {
        int num = rand();
        f_ToBeGenerated_arr[index] = num % 10;
    }

}

/*
 * Gabriel Talbert Bunt
 * CS 211
 * M3 Assignment
 * 04/25/22
 *
 * Description:
 * This program asks the user for a trip length and prints the process of that trip
 * utilizing objects. If the fuel amount drops below 1gal, it prints an additional
 * warning.
 * At the end of the program execution it prints whether they arrived or ran out of fuel.
 *
 * Not too much actually goes on from the user's perspective, but if they
 * believed that not much was done under the hood they would be sorely mistaken.
 * The use of objects for the problem made it magnitudes more complicated, but it
 * doesn't really since the entire point of the assignment was to learn how to use objects,
 * complexity be darned.
 *
 * /------------------------------------\
 * | Test Data:                         ||
 * |------------------------------------|/
 * | Output key:                        |
 * | m# = The final current mile output |
 * | f# = The final fuel left output    |
 * | A  = Arrived                       |
 * | O  = Out of fuel                   |
 * |------------------------------------|
 * | Input | Output       | Passed?     |
 * |-------|--------------|-------------|
 * | 10    | m10,  f30, A | y           |
 * | 32    | m32,  f29, A | y           |
 * | 64    | m64,  f28, A | y           |
 * | 1000  | m960, f0,  O | y           |
 * | 960   | m960, f0,  A | y           |
 * | 0     |            A | y           |
 * |------------------------------------|
 * | Other tests:                       |
 * |-Letter inputs are rejected.        |
 * |-Empty input is ignored.            |
 * |-Negative numbers are rejected.     |
 * |-Decimal numbers are truncated.     |
 * |-The first acceptable number of an  |\
 * | input is taken (e.g. 1 from 1abc). ||
 * \------------------------------------/
 */

#include <iostream>
#include <limits>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;

int promptPositiveInt();
void printPrettyProgressBar(int, double);

int main() {
    short DEFAULT_MAX_FUEL_AMOUNT = 30;

    auto* fuelGauge = new FuelGauge(DEFAULT_MAX_FUEL_AMOUNT);
    auto* odometer = new Odometer(fuelGauge);

    // Fill up the tank
    while (fuelGauge->addFuel() > 0);
    
    cout << "How many miles long is the trip?" << endl;
    int tripLength = promptPositiveInt();

    int miles = odometer->getMiles();
    double fuel = fuelGauge->getFuel();

    // There is a funny bug here where if the odometer rolled over
    // (which isn't possible in this particular program)
    // the trip progress would be reset
    // (and thus the end-condition would only be running out of gas).
    // I'm going to leave it here because I think the idea of
    // some hypothetical person getting hopelessly lost after
    // they drove more than 999,999 miles funny.
    while ((miles < tripLength) & odometer->drive())
    {
        cout << endl;

        miles = odometer->getMiles();
        double tripProgress = double(miles) / tripLength;

        printPrettyProgressBar(40, tripProgress);
        cout << " Current mile: " << miles << endl;

        fuel = fuelGauge->getFuel();

        printPrettyProgressBar(40, fuel / fuelGauge->getMaxFuel());
        cout << " Fuel left: " << fuel << "gal.";
        if (fuel <= 1)
        {
            cout << " *LOW FUEL*";
        }
        cout << endl;
    }

    // Determine the outcome of the trip
    if (miles == tripLength)
    {
        cout << "Arrived at destination!";
    }
    else if (fuel == 0)
    {
        cout << "Out of fuel.";
    }
    else
    {
        cout << "You are hopelessly lost. Sorry!";
    }

    delete fuelGauge;
    delete odometer;

    return 0;
}

/**
 * A very insistent prompt that validates that the user entered a positive integer.
 *
 * @return the user number
 */
int promptPositiveInt() {
    bool enteredNumber = false;
    int userNumber;
    while (!enteredNumber) {
        cin >> userNumber;
        if (cin.fail() | (userNumber < 0)) {
            cout << "Invalid entry, try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            enteredNumber = true;
        }
    }
    return userNumber;
}

/**
 * Prints out a progress bar consisting of = and -.
 * 
 * @param length length of the progress bar
 * @param progress a decimal percentage of how much of the bar should use =
 */
void printPrettyProgressBar(int length, double progress)
{
    for (int i = 1; i <= length; i++)
    {
        if (i <= progress * length)
        {
            cout << "=";
        }
        else
        {
            cout << '-';
        }
    }
}
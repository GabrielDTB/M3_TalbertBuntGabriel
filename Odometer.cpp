#include "Odometer.h"
#include "FuelGauge.h"

const short Odometer::DEFAULT_FUEL_ECONOMY = 32;
const int Odometer::DEFAULT_MILES = 0;
const int Odometer::DEFAULT_MAX_MILES = 999999;
const int Odometer::DEFAULT_DRIVE_STEP = 1;

/**
 * Construct an Odometer object with a corresponding FuelGauge object.
 * Optionally, starting miles, fuel economy, and max miles can be specified.
 *
 * @param fg pointer to a FuelGauge object
 * @param fe how many miles to the gallon it gets
 * @param mi starting miles
 * @param ma max miles before rolling over to 0
 */
Odometer::Odometer(FuelGauge* fg, short fe, int mi, int ma) :
gauge(fg), fuelEconomy(fe), miles(mi), maxMiles(ma)
{
}

/**
 * Gets the current miles driven.
 *
 * @return current miles driven
 */
int Odometer::getMiles() const
{
    return miles;
}

/**
 * An intermediary function between drive and miles that does as the name implies.
 * It is here for theoretical (nonexistent) future-proofing.
 *
 * @param step how much to increment miles by
 */
void Odometer::incrementMiles(int step)
{
    miles += step;
    newMiles += step;
    if (miles > maxMiles)
    {
        miles -= maxMiles;
    }
}

/**
 * Simulates 'driving' by increasing the miles driven and burning fuel.
 *
 * @return success or failure
 */
int Odometer::drive()
{
    if (gauge->getFuel() > 0)
    {
        incrementMiles();
        for (short i = fuelEconomy; newMiles >= i; )
        {
            newMiles -= i;
            (*gauge)--;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
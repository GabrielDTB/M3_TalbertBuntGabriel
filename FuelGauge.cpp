#include "FuelGauge.h"

const double FuelGauge::DEFAULT_FUEL = 0;
const double FuelGauge::DEFAULT_ADD_FUEL_VOLUME = 0.1;
const double FuelGauge::DEFAULT_BURN_FUEL_VOLUME = 1;

/**
 * Constructs a FuelGauge object with a max fuel value.
 * Optionally, starting fuel can be specified.
 *
 * @param mf max fuel that can be stored
 * @param fs starting fuel amount
 */
FuelGauge::FuelGauge(short mf, double fs) :
maxFuel(mf), fuel(fs)
{
}

/**
 * Gets the max fuel that can be held.
 *
 * @return max fuel amount
 */
short FuelGauge::getMaxFuel() const
{
    return maxFuel;
}

/**
 * Gets the current fuel amount.
 *
 * @return current fuel amount
 */
double FuelGauge::getFuel() const
{
    return fuel;
}

/**
 * Adds an amount of fuel up to the maximum amount that can be held.
 *
 * @param volume how much fuel to add
 * @return how much fuel was added
 */
double FuelGauge::addFuel(double volume)
{
    if ((fuel + volume) < maxFuel)
    {
        fuel += volume;
        return volume;
    }
    else
    {
        double added = maxFuel - fuel;
        fuel = maxFuel;
        return added;
    }
}

/**
 * Removes an amount of fuel up to the amount remaining.
 *
 * @param volume how much fuel to burn
 * @return how much fuel was burned
 */
double FuelGauge::burnFuel(double volume)
{
    if (volume < fuel)
    {
        fuel -= volume;
        return volume;
    }
    else
    {
        double burned = fuel;
        fuel = 0;
        return burned;
    }
}

/**
 * More or less just calls burnFuel but gives a (usually) less useful return.
 * However, if equality/comparison operators were also overloaded,
 * it could be significantly more useful.
 *
 * @return a copy of the old FuelGauge object
 */
const FuelGauge FuelGauge::operator--(int)
{
    FuelGauge const temp = *this;
    this->burnFuel();
    return temp;
}
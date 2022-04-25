#include "FuelGauge.h"

// Static consts
const double FuelGauge::DEFAULT_FUEL = 0;
const double FuelGauge::DEFAULT_FUEL_ECONOMY = 32;
const double FuelGauge::DEFAULT_ADD_FUEL_VOLUME = 0.1;
const double FuelGauge::DEFAULT_BURN_FUEL_VOLUME = 1;

/**
 * Constructs a FuelGauge object with a max fuel amount and, optionally, a starting fuel amount.
 *
 * @param m max fuel that can be held
 * @param f starting fuel amount
 */
FuelGauge::FuelGauge(double mf, double fs, double fe) :
maxFuel(mf), fuel(fs), fuelEconomy(fe)
{
}

/**
 * Gets the current fuel amount.
 *
 * @return the current fuel amount
 */
double FuelGauge::getFuel() const
{
    return fuel;
}

/**
 * Adds an amount of fuel to the FuelGauge, up to the maximum amount that can be held.
 *
 * @param volume how much fuel to add
 * @return how much fuel was left over
 */
double FuelGauge::addFuel(double volume)
{
    if ((fuel + volume) < maxFuel)
    {
        fuel += volume;
        return 0;
    }
    else if (fuel < maxFuel)
    {
        double leftOver = volume - (maxFuel - fuel);
        fuel = maxFuel;
        return leftOver;
    }
    else
    {
        return volume;
    }
}

/**
 * Removes an amount of fuel from the FuelGauge, up to the amount remaining in it.
 *
 * @param volume how much fuel to burn
 * @return how much fuel that could not be burned
 */
double FuelGauge::burnFuel(double volume)
{
    if (fuel < volume)
    {
        double deficit = volume - fuel;
        fuel = 0;
        return deficit;
    }
    else
    {
        fuel -= volume;
        return 0;
    }
}
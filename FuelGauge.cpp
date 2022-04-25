#include "FuelGauge.h"

// Static consts
const long double FuelGauge::DEFAULT_FUEL = 0;
const double FuelGauge::DEFAULT_FUEL_ECONOMY = 32;
const long double FuelGauge::DEFAULT_ADD_FUEL_VOLUME = 0.1;
const long double FuelGauge::DEFAULT_BURN_FUEL_VOLUME = 1;

/**
 * Constructs a FuelGauge object with a max fuel amount and, optionally, a starting fuel amount.
 *
 * @param m max fuel that can be held
 * @param f starting fuel amount
 */
FuelGauge::FuelGauge(double mf, long double fs, double fe) :
maxFuel(mf), fuel(fs), fuelEconomy(fe)
{
}

/**
 * Gets the current fuel amount.
 *
 * @return the current fuel amount
 */
long double FuelGauge::getFuel() const
{
    return fuel;
}

/**
 * Adds an amount of fuel to the FuelGauge, up to the maximum amount that can be held.
 *
 * @param volume how much fuel to add
 * @return how much fuel was added
 */
long double FuelGauge::addFuel(long double volume)
{
    if ((fuel + volume) < maxFuel)
    {
        fuel += volume;
        return volume;
    }
    else
    {
        long double added = maxFuel - fuel;
        fuel = maxFuel;
        return added;
    }
}

/**
 * Removes an amount of fuel from the FuelGauge, up to the amount remaining in it.
 *
 * @param volume how much fuel to burn
 * @return how much fuel that was burned
 */
long double FuelGauge::burnFuel(long double volume)
{
    if (fuel < volume)
    {
        long double burned = fuel;
        fuel = 0;
        return burned;
    }
    else
    {
        fuel -= volume;
        return volume;
    }
}

double FuelGauge::getFuelEconomy() const
{
    return fuelEconomy;
}

FuelGauge FuelGauge::operator--()
{
    FuelGauge temp = *this;
    burnFuel();
    return temp;
}
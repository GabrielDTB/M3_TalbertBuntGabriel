#include "Odometer.h"
#include "FuelGauge.h"

const long double Odometer::DEFAULT_MILEAGE = 0;
const int Odometer::DEFAULT_MAX_MILES = 999999;
const long double Odometer::DEFAULT_DRIVE_DISTANCE = 1;

Odometer::Odometer(FuelGauge* fg, long double mi, int ma) :
gauge(fg), mileage(mi), maxMiles(ma)
{
}

int Odometer::getMileage() const
{
    return int(mileage);
}

void Odometer::incrementMileage(long double increment)
{
    mileage += increment;
    if (mileage > maxMiles)
    {
        mileage -= maxMiles;
    }
}

long double Odometer::drive(long double distance)
{
    long double gasNeeded = distance / gauge->getFuelEconomy();
    long double gasBurned = gauge->burnFuel(gasNeeded);
    if (gasBurned < gasNeeded)
    {
        long double distanceDrove = gasBurned * gauge->getFuelEconomy();
        incrementMileage(distanceDrove);
        return (distanceDrove);
    }
    else
    {
        incrementMileage(distance);
        return distance;
    }
}
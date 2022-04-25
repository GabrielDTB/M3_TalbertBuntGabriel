#include "Odometer.h"

Odometer::Odometer(double mi, int ma) :  // Defaults are 0
mileage(mi), maxMiles(ma)
{
}

int Odometer::getMileage() const
{
    return int(mileage);
}

void Odometer::incrementMileage(double increment)  // Default is 1
{
    mileage += increment;
    if (mileage > maxMiles)
    {
        mileage -= maxMiles;
    }
}
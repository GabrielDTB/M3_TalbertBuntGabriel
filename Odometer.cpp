#include "Odometer.h"
#include "FuelGauge.h"

Odometer::Odometer(FuelGauge* fg, double mi, int ma) :  // Defaults are 0
gauge(fg), mileage(mi), maxMiles(ma)
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

double Odometer::drive(double miles)  // Default is 1
{
    if (!gauge->burnFuel(miles / gauge->))
}

Odometer operator++(Odometer self)
{
    self.drive();
}
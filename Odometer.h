#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer
{
    private:
      static const short DEFAULT_FUEL_ECONOMY;
      static const int DEFAULT_MILES;
      static const int DEFAULT_MAX_MILES;
      static const int DEFAULT_DRIVE_STEP;

      FuelGauge* gauge;
      short fuelEconomy;
      int miles;
      int maxMiles;
      int newMiles = 0;

      void incrementMiles(int = DEFAULT_DRIVE_STEP);

    public:
      explicit Odometer(FuelGauge*, short = DEFAULT_FUEL_ECONOMY, int = DEFAULT_MILES, int = DEFAULT_MAX_MILES);

      int getMiles() const;
      int drive();
};

#endif //ODOMETER_H

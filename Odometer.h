#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer
{
    private:
      static const double DEFAULT_MILEAGE;
      static const double DEFAULT_MAX_MILES;
      static const double DEFAULT_DRIVE_DISTANCE;

      // I put this as long double so that I lose as little
      // precision as possible for decimal mileages.
      long double mileage;
      int maxMiles;
      FuelGauge* gauge;

      void incrementMileage(double = 1);

    public:
      explicit Odometer(FuelGauge*, double = 0, int = 999999);
      int getMileage() const;
      double drive(double = 1);
};

#endif //ODOMETER_H

#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer
{
    private:
      // Everything that touches "mileage" directly is set to long double for max precision
      static const long double DEFAULT_MILEAGE;
      static const int DEFAULT_MAX_MILES;
      static const long double DEFAULT_DRIVE_DISTANCE;

      long double mileage;  // Long double for max precision
      int maxMiles;
      FuelGauge* gauge;

      void incrementMileage(long double = DEFAULT_DRIVE_DISTANCE);

    public:
      explicit Odometer(FuelGauge*, long double = DEFAULT_MILEAGE, int = DEFAULT_MAX_MILES);
      int getMileage() const;
      long double drive(long double = DEFAULT_DRIVE_DISTANCE);
};

#endif //ODOMETER_H

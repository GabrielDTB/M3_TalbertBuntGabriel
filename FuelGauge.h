#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge
{
    private:
      // Everything that touches "fuel" directly is set to long double for max precision
      static const long double DEFAULT_FUEL;
      static const double DEFAULT_FUEL_ECONOMY;
      static const long double DEFAULT_ADD_FUEL_VOLUME;
      static const long double DEFAULT_BURN_FUEL_VOLUME;

      double maxFuel;
      long double fuel;  // Long double for max precision
      double fuelEconomy;  // Distance per volume

    public:
      explicit FuelGauge(double, long double = DEFAULT_FUEL, double = DEFAULT_FUEL_ECONOMY);
      long double getFuel() const;
      long double addFuel(long double = DEFAULT_ADD_FUEL_VOLUME);
      double getFuelEconomy() const;
      long double burnFuel(long double = DEFAULT_BURN_FUEL_VOLUME);
      FuelGauge operator--(int);
};

#endif //FUELGAUGE_H

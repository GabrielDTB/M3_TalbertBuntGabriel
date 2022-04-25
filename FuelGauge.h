#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge
{
    private:
      static const double DEFAULT_FUEL;
      static const double DEFAULT_FUEL_ECONOMY;
      static const double DEFAULT_ADD_FUEL_VOLUME;
      static const double DEFAULT_BURN_FUEL_VOLUME;

      double maxFuel;
      double fuel;
      double fuelEconomy;  // Distance per volume

      double burnFuel(double = DEFAULT_BURN_FUEL_VOLUME);

    public:
      explicit FuelGauge(double, double = DEFAULT_FUEL, double = DEFAULT_FUEL_ECONOMY);
      double getFuel() const;
      double addFuel(double = DEFAULT_ADD_FUEL_VOLUME);

      friend class Odometer;
};

#endif //FUELGAUGE_H

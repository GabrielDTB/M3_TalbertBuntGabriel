#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge
{
    private:
      static const double DEFAULT_FUEL;
      static const double DEFAULT_ADD_FUEL_VOLUME;
      static const double DEFAULT_BURN_FUEL_VOLUME;

      short maxFuel;
      double fuel;

    public:
      explicit FuelGauge(short, double = DEFAULT_FUEL);
      short getMaxFuel() const;
      double getFuel() const;
      double addFuel(double = DEFAULT_ADD_FUEL_VOLUME);
      double burnFuel(double = DEFAULT_BURN_FUEL_VOLUME);
      const FuelGauge operator--(int);
};

#endif //FUELGAUGE_H

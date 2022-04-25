#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge
{
    private:
      double maxFuel;
      double fuel;

    public:
      explicit FuelGauge(double, double = 0);
      double getFuel() const;
      double addFuel(double = 0.1);
      double burnFuel(double = 1);
};

#endif //FUELGAUGE_H

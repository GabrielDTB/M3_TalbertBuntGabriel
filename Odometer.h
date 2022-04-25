#ifndef ODOMETER_H
#define ODOMETER_H

class Odometer
{
    private:
      // I put this as long double so that I lose as little
      // precision as possible for decimal mileages.
      long double mileage;
      int maxMiles;
    public:
      explicit Odometer(double = 0, int = 999999);
      int getMileage() const;
      void incrementMileage(double = 1);
};

#endif //ODOMETER_H

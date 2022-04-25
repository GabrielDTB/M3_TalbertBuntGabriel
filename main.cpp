#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"
using namespace std;

int main() {
    FuelGauge gauge(2);
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel(10) << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.addFuel() << endl;
    cout << gauge.getFuel() << endl;

    cout << endl;
    cout << gauge.burnFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.burnFuel(0.5) << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.burnFuel() << endl;
    cout << gauge.getFuel() << endl;
    cout << gauge.burnFuel() << endl;
    cout << gauge.getFuel() << endl;

    return 0;
}

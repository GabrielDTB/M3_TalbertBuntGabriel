#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"
using namespace std;

int main() {
    auto* fg = new FuelGauge(20);
    auto* od = new Odometer(fg);

    fg->addFuel(10);
    for (short i=0; i<32; i++)
    {
        cout << od->drive(1) << endl;
    }
    cout << fg->getFuel() << endl;

    (*fg)--;
    cout << fg->getFuel();

    delete fg;
    delete od;

    return 0;
}

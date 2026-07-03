#include <iostream>
#include "GeoUtils.h"

using namespace std;

int main()
{
    GeoUtils geo;
    Position p;

    double latH, latM, latS;
    double lonH, lonM, lonS;

    cout << "Enter latitude H,M,S: " << endl;
    cin >> latH >> latM >> latS;

    cout << "Enter lonitude H,M,S: " << endl;
    cin >> lonH >> lonM >> lonS;

    p = geo.ConvertHMStoDD(latH,latM,latS,lonH,lonM,lonS);
    cout << "The coordinate in decimal degrees: " << p.lat << ", " << p.lon << endl;

    return 0;
}

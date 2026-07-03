#include <iostream>
#include "GeoUtils.h"

using namespace std;

int main()
{
    GeoUtils geo;
    Position p;

    // variables to store data given by cin
    double latH, latM, latS;
    double lonH, lonM, lonS;
    
    // prompt user to enter data
    cout << "Enter latitude H,M,S: " << endl;
    
    // take input using cin
    cin >> latH >> latM >> latS;

    cout << "Enter lonitude H,M,S: " << endl;
    cin >> lonH >> lonM >> lonS;
    
    // calculate decimal degrees
    p = geo.ConvertHMStoDD(latH,latM,latS,lonH,lonM,lonS);
    
    // print the converted data
    cout << "The coordinate in decimal degrees: " << p.lat << ", " << p.lon << endl;

    return 0;
}

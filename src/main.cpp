#include <iostream>
#include "GeoUtils.h"

using namespace std;

int main()
{
    GeoUtils geo;
    GeoPoint p;

    // variables to store data given by cin
    double latD, latM, latS;
    double lonD, lonM, lonS;
    
    // prompt user to enter data
    cout << "Enter latitude D,M,S: " << endl;
    
    // take input using cin
    cin >> latD >> latM >> latS;

    cout << "Enter lonitude D,M,S: " << endl;
    cin >> lonD >> lonM >> lonS;
    
    // calculate decimal degrees
    p = geo.ConvertHMStoDD(latD,latM,latS,lonD,lonM,lonS);
    
    // print the converted data
    cout << "The coordinate in decimal degrees: " << p.lat << ", " << p.lon << endl;

    return 0;
}

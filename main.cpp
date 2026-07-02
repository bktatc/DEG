#include <iostream>
#include "GeoUtils.h"

using namespace std;

int main()
{
    GeoUtils geo;
    Position p = geo.ConvertHMStoDD(35,41,20,51,18,53);

    cout << p.lat << ", " << p.lon << endl;

    return 0;
}

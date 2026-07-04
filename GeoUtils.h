#ifndef GEOUTILS_H
#define GEOUTILS_H

#include "GeoPoint.h"

class GeoUtils
{
public:
    GeoUtils();
    GeoPoint ConvertHMStoDD(double latH, double latM, double latS,
                            double lonH, double lonM, double lonS);
};

#endif // GEOUTILS_H

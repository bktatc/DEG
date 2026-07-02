#ifndef GEOUTILS_H
#define GEOUTILS_H

#include "Position.h"

class GeoUtils
{
public:
    GeoUtils();
    Position ConvertHMStoDD(double latH, double latM, double latS,
                            double lonH, double lonM, double lonS);
};

#endif // GEOUTILS_H

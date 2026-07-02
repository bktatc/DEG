#include "GeoUtils.h"

GeoUtils::GeoUtils() {}

Position GeoUtils::ConvertHMStoDD(double latH, double latM, double latS,
                                  double lonH, double lonM, double lonS)
{
    double latDD = latH + (latM / 60) + (latS / 3600);
    double lonDD = lonH + (lonM / 60) + (lonS / 3600);

    Position P;
    P.lat = latDD;
    P.lon = lonDD;

    return P;
}

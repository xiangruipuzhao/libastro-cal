#include "asteroid.h"

double ac_asteroid_diameter(double abs_mag, double albedo)
{
    return 2;
}
double ac_asteroid_apparent_diameter(double true_diameter, double asteroid_earth_dist)
{
    return 1.3788 * true_diameter / asteroid_earth_dist;
}


#include <math.h>
#include "asteroid.h"

double ac_asteroid_diameter(double abs_mag, double albedo)
{
    return 1000 * pow(10, 3.12 - abs_mag / 5.0 - 0.217147 * log10( 223.2 ));  
}

double ac_asteroid_apparent_diameter(double true_diameter, double asteroid_earth_dist)
{
    return 1.3788 * true_diameter / asteroid_earth_dist;
}


/**
 * @file asteroid.h
 * @author faraco
 * @brief Asteroid diameter operations
 */
#ifndef asteroid_h
#define asteroid_h

/**
 * @brief Calculate asteroid diameter
 * @param abs_mag Absolute magnitude of the asteroid
 * @param albedo Reflective power of the asteroid
 * @return diameter of the asteroid in meters
 */
double ac_asteroid_diameter(double abs_mag, double albedo);

/**
 * @brief Calculate the apparent diameter of an asteroid
 * @param true_diameter true diameter of an asteroid in kilometers (km)
 * @param asteroid_earth_dist Asteroid to Earth distance in Astronomical Unit (AU)
 * @return apparent diameter of the asteroid in meters
 */
double ac_asteroid_apparent_diameter(double true_diameter, double asteroid_earth_dist);

#endif

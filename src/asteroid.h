/*
    libastro-cal - Astronomical algorithm library.
    Copyright (C) 2017 faraco

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file asteroid.h
 * @author faraco
 * @brief Header file for asteroid diameter operations.
 */

#ifndef asteroid_h
#define asteroid_h

/**
 * @brief Calculate asteroid diameter.
 * @param abs_mag Absolute magnitude of the asteroid.
 * @param albedo Reflective power of the asteroid.
 *
 * @return diameter of the asteroid in meters.
 */
double
ac_asteroid_diameter(double abs_mag, double albedo);

/**
 * @brief Calculate the apparent diameter of an asteroid.
 * @param true_diameter true diameter of an asteroid in kilometers (km).
 * @param asteroid_earth_dist Asteroid to Earth distance in Astronomical Unit (AU).
 *
 * @return apparent diameter of the asteroid in meters.W
 */
double
ac_asteroid_aprnt_diameter(double true_diameter, double asteroid_earth_dist);

#endif


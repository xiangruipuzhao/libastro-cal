/*
    libastro-cal - Astronomical algorithm library.
    Copyright (C) 2017-2019 Momozor

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
 * @file asteroid.c
 * @author faraco
 * @brief Source file for asteroid operations.
 */

#include <math.h>
#include "asteroid.h"

double
ac_asteroid_diameter(double abs_mag, double albedo)
{
    return 1000 * pow(10, 3.12 - abs_mag / 5.0 - 0.217147 * log10( 223.2 ));
}

double
ac_asteroid_aprnt_diameter(double true_diameter, double asteroid_earth_dist)
{
    return 1.3788 * true_diameter / asteroid_earth_dist;
}


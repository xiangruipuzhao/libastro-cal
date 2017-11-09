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
 * @file angle.h
 * @author faraco
 * @brief Header file for angle operations.
 */

#ifndef angle_h
#define angle_h

#include <stdint.h>

/**
 * \typedef
 * 
 */
typedef struct _Arc {
    int64_t hour;
    int64_t degree;
    int64_t minute;
    double seconds;
} Arc_t;

/**
 * @brief M_PI*2.0
 */
extern const double TWO_PI;

/**
 * @brief Calculate the angular separation between two points.
 *
 * @param p1a1 Angle 1 of point 1 in radians.
 * @param p1a2 Angle 2 of point 1 in radians.
 * @param p2a1 Angle 1 of point 2 in radians.
 * @param p2a2 Angle 2 of point 2 in radians.
 *
 * Angle 1 may be right ascension or longitude.<br>
 * Angle 2 may be declination or latitude.
 * 
 * \todo Document return value.
 */
double ac_angle_anglr_sepr(double p1a1, double p1a2, double p2a1, double p2a2);

/**
 * @brief Computes an angle in degrees with decimals,
 * from an angle expressed in degrees, arcminutes and arcseconds.
 *
 * @param deg Degrees
 * @param min Arcminutes
 * @param sec Arcseconds
 *
 * @return Angle in degrees with decimals.
 */
double ac_angle_deg_frm_dms(int64_t deg, int64_t min, double sec);

/**
 * @brief Computes an angle expressed in degrees, arcminutes and
 * arcseconds, from an angle in degrees with decimals.
 * 
 * @param deg Angle in degrees with decimals.
 *
 * @return Arc_t struct (degree, minute, seconds)
 *
 * degree : Degrees
 * minute : Arcminutes
 * seconds : Arcseconds
 */
Arc_t ac_angle_dms_from_deg(double deg);

/**
 * @brief Computes an angle in degrees with decimals, from an angle
 * expressed in hours, minutes and seconds.
 *
 * @param hour Hours
 * @param min Minutes
 * @param sec Seconds
 *
 * \todo Document return value.
 */
double ac_angle_deg_frm_hms(int64_t hour, int64_t min, double sec);

/**
 * @brief Computes an angle expressed in hours, minutes and
 * seconds, from an angle in degrees with decimals.
 * 
 * @param deg Angle in degrees with decimals.
 * 
 * @return Arc_t struct (hour, minute, seconds)
 *
 * hour : Hours
 * min : Minutes
 * sec : Seconds
 */
Arc_t ac_angle_hms_from_deg(double deg);

/**
 * @brief Computes the equivalent angle in [0, 360] degree range.
 *
 * @param angl Angle in degrees.
 * 
 * \todo Document return value.
 * 
 */
double ac_angle_limit_to_360(double angl);

/**
 * @brief Computes the equivalent angle in [0, 2π] radian range.
 *
 * @param angl Angle in radians.
 *
 * \todo Document return value.
 */
double ac_angle_limit_to_two_PI(double angl);

#endif

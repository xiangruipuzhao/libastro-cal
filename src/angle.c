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
 * @file angle.c
 * @author faraco
 * @brief Source file for angle operations.
 *
 */

#include <math.h>
#include <stdlib.h>
#include "angle.h"

const double TWO_PI = 2.0 * M_PI;

double ac_angle_anglr_sepr(double p1a1, double p1a2, double p2a1, double p2a2)
{
    return acos(
               sin(p1a2) * sin(p2a2) + cos(p1a2) * cos(p2a2) * cos(p1a1 - p2a1)
           );
}

double ac_angle_deg_frm_dms(int64_t deg, int64_t min, double sec)
{   

    int64_t M;
    double S;

    if (deg < 0) {
        M = llabs(-min);
        S = llabs(-sec);
    }

    else {
        M = min;
        S = sec;
    }

    return (double)deg + (double)M / 60.0 + S/3600.0;
}

struct Arc ac_angle_dms_from_deg(double deg)
{
    struct Arc data;

    data.degree = (double)deg;
    double minutes = (deg - ((double)data.degree)) * 60.0;

    data.minute = (int64_t)minutes;
    data.seconds = (minutes - ((double)data.minute)) * 60.0;

    return data;
}

double ac_angle_deg_frm_hms(int64_t hour, int64_t min, double sec)
{
    return 15.0 * (((double)hour) + ((double)min)/60.0 + sec/3600.0);
}

struct Arc ac_angle_hms_from_deg(double deg)
{
    struct Arc data;

    double hours = deg / 15.0;
    data.hour = hours;

    double minutes = (hours - ((double)data.hour)) * 60.0;
    data.minute = (int64_t)minutes;

    data.seconds = (minutes - ((double)data.minute)) * 60.0;

    return data;
}

double ac_angle_limit_to_360(double angl)
{
    int64_t n = (angl / 360.0);
    double limited_angl = angl - (360.0 * ((double)n));

    if (limited_angl < 0.0) {
        return limited_angl += 360.0;
    }

    else {
        return limited_angl;
    }
}

double ac_angle_limit_to_two_PI(double angl)
{
    int64_t n = (angl / TWO_PI);
    double limited_angl = angl - (TWO_PI * ((double)n));

    if (limited_angl < 0.0) {
        return limited_angl += TWO_PI;
    }

    else {
        return limited_angl;
    }
}
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
 * @file time.h
 * @author faraco
 * @brief Header file for time operations.
 */

#ifndef time_h
#define time_h

#include <stdint.h>
#include "angle.h"

enum CalType {
    Gregorian,
    Julian
};

enum Month {
    Jan = 1,
    Feb 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

// \todo Learn how to use enum inside a struct
typedef struct _Date {
    int16_t year;

} Date;

#endif
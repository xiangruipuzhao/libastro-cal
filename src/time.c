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

#include <math.h>
#include "time.h"


/**
 \todo fill in docs
 */

double
ac_time_julian_day(struct Date *date)
{
    uint8_t month = date->month;
    double y;
    double m;

    if (month == 1 || month == 2)
    {
        y = (double)date->year - 1;
        m = (double)month + 12;
    }

    else
    {
        y = (double)date->year;
        m = (double)month;
    }

    double a = floor(y / 100.0);
    double b;

    enum CalType g = Gregorian;
    enum CalType j = Julian;

    if (date->cal_type == g)
    {
            b = 2.0 - a + floor(a / 4.0);
    }

    else if (date->cal_type == j)
    {
            b = 0.0;
    }

    return  floor(365.25 * (y + 4716.0))
          + floor(30.6001 * (m + 1.0))
          + date->decimal_day
          + b
          - 1524.5;
}

/**
 * \todo Fill in logic.
 */
enum Weekday
ac_time_weekday_frm_date(struct Date *date)
{
    return 2;
}

double
ac_time_decimal_day(struct DayOfMonth *day)
{
    return  (double)day->day
          + (double)day->hr / 24.0
          + (double)day->min / 60.0
          + day->sec / 60.0
          - day->time_zone / 24.0;
}


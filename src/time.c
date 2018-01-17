/*
    libastro-cal - Astronomical algorithm library.
    Copyright (C) 2017-2018 faraco

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

#include <stdio.h>
#include <math.h>
#include "time.h"

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

enum Weekday
ac_time_weekday_frm_date(struct Date *date)
{
    struct Date date_0UT;
    enum CalType cal_type_1 = Gregorian;

    date_0UT = (struct Date)
    {
        .year = date->year,
        .decimal_day = (int64_t)floor(date->decimal_day),
        .month = date->month,
        .cal_type = cal_type_1
    };

    double JD = ac_time_julian_day(&date_0UT);
    int64_t wd = (int64_t)(JD + 1.5) % 7;

    enum Weekday wday;
    switch(wd)
    {
        case 0:
            return wday = Sunday;
        case 1:
            return wday = Monday;
        case 2:
            return wday = Tuesday;
        case 3:
            return wday = Wednesday;
        case 4:
            return wday = Thursday;
        case 5:
            return wday = Friday;
        case 6:
            return wday = Saturday;
        default:
            printf("ac_time_weekday_from_date error.\n");
    }
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

int
ac_time_is_leap_year(int16_t year, enum CalType *cal_type)
{
    enum CalType julian_c = Julian;
    enum CalType gregorian_c = Gregorian;

    if (julian_c)
    {
        return year % 4 == 0;
    }

    else if (gregorian_c)
    {
        if ((year % 100) == 0)
        {
            return year % 400 == 0;
        }

        else
        {
            return year % 4 == 0;
        }
    }
}

double
ac_time_decimal_year(struct Date *date)
{
    int y = 0;
    double days = 365.0;
    uint8_t month = (uint8_t)date->month;

    if (month > 1)
    {
        y += 31;
    }

    if (month > 2)
    {
        y += 28;
        if (ac_time_is_leap_year(date->year, &date->cal_type))
        {
            y += 1;
            days += 1.0;
        }
    }

    if (month >  3) { y += 31; }
    if (month >  4) { y += 30; }
    if (month >  5) { y += 31; }
    if (month >  6) { y += 30; }
    if (month >  7) { y += 31; }
    if (month >  8) { y += 31; }
    if (month >  9) { y += 30; }
    if (month > 10) { y += 31; }
    if (month > 11) { y += 30; }

    return ((double)date->year) + ((double)y + date->decimal_day)/days;
}

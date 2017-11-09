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

#include "minunit.h"
#include <stdio.h>

#include "../src/asteroid.h"
#include "../src/angle.h"

MU_TEST(test_check)
{
    /* asteroid */
    mu_check(ac_asteroid_diameter(30.32, 223.2) <= 0.351551);
    mu_check(ac_asteroid_aprnt_diameter(20, 30) == 0.919200);

    /* angle */
    mu_check(ac_angle_anglr_sepr(20.2, 32.1, 13.2, 22.2) >= 0.666738);
    mu_check(ac_angle_deg_frm_dms(203, 14, 12.3) <= 203.236750);

    Arc_t result;

    result = ac_angle_dms_from_deg(20.2);
    mu_check(result.degree == 20);
    mu_check(result.minute == 11);
    mu_check(result.seconds <= 60.00000);

    mu_check(ac_angle_deg_frm_hms(12, 20, 32.0) >= 185.13);

    Arc_t result2;

    result2 = ac_angle_hms_from_deg(3021.2);
    mu_check(result2.hour == 201);
    mu_check(result2.minute == 24);
    mu_check(result2.seconds <= 48.000000);

    mu_check(ac_angle_limit_to_360(-2.231) <= 357.769000);
    mu_check(ac_angle_limit_to_two_PI(-2.123) >= 4.160185);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_check);
}

int main(int argc, char **argv)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return 0;
}

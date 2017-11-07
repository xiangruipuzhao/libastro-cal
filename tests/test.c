#include "minunit.h"
#include <stdio.h>

#include "../src/asteroid.h"
#include "../src/angle.h"

MU_TEST(test_check)
{
    /* asteroid */
    mu_check(ac_asteroid_diameter(30.32, 223.2) <= 0.351551);
    mu_check(ac_asteroid_apparent_diameter(20, 30) == 0.919200);

    /* angle */
    mu_check(ac_angle_anglr_sepr(20.2, 32.1, 13.2, 22.2) >= 0.666738);
    mu_check(ac_angle_deg_frm_dms(203, 14, 12.3) <= 203.236750);
    mu_check(ac_angle_dms_frm_deg(203.2) == 0);
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

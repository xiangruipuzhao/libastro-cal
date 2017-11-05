#include "minunit.h"
#include <stdio.h>
#include "../src/asteroid.h"

/* asteroid  */
MU_TEST(test_check)
{
    mu_check(ac_asteroid_apparent_diameter(20, 30) == 0.919200);
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

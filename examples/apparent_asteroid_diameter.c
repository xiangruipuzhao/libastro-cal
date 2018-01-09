#include <stdio.h>
#include "../src/asteroid.h"

int
main(void)
{
    printf("Apparent diameter of an asteroid based on the given true diameter in km and asteroid to earth distance in AU is equal to %lfm.\n", ac_asteroid_aprnt_diameter(9232.2, 33382.2));

    return 0;
}


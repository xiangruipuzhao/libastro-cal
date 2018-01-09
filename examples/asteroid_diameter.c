#include <stdio.h>
#include "../src/asteroid.h"

int
main(void)
{
    printf("Diameter of the asteroid is %lfm.\n", ac_asteroid_diameter(30.32, 223.2));
    return 0;
}


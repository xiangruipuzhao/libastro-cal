#include <math.h>
#include <stdint.h>
#include "angle.h"

const double TWO_PI = 2.0 * M_PI;

double ac_angle_anglr_sepr(double p1a1, double p1a2, double p2a1, double p2a2)
{
    return acos
        (
            sin(p1a2) * sin(p2a2) + cos(p1a2) * cos(p2a2) * cos(p1a1 - p2a1)
        );
}

double ac_angle_deg_frm_dms(int64_t deg, int64_t min, double sec)
{   
    // TODO add logic
    return 2;
}

/**
 * @file angle.h
 * @author faraco
 * @brief Angles operations.
 */
#ifndef angle_h
#define angle_h

#include <stdint.h>

/**
 * @brief Calculate the angular separation between two points.
 *
 * @param p1a1 Angle 1 of point 1 in radians.
 * @param p1a2 Angle 2 of point 1 in radians.
 * @param p2a1 Angle 1 of point 2 in radians.
 * @param p2a2 Angle 2 of point 2 in radians.
 *
 * Angle 1 may be right ascension or longitude.<br>
 * Angle 2 may be declination or latitude.
 * 
 * \todo Document return value.
 */
double ac_angle_anglr_sepr(double p1a1, double p1a2, double p2a1, double p2a2);

/**
 * @brief Computes an angle in degrees with decimals,
 * from an angle expressed in degrees, arcminutes and arcseconds.
 *
 * @param deg Degrees
 * @param min Arcminutes
 * @param sec Arcseconds
 *
 * @return Angle in degrees with decimals.
 */
double ac_angle_deg_frm_dms(int64_t deg, int64_t min, double sec);

/**
 * @brief Computes an angle expressed in degrees, arcminutes and
 * arcseconds, from an angle in degrees with decimals.
 * 
 * @param deg Angle in degrees with decimals.
 *
 * @return (*deg, *min, *sec)
 *
 * *deg : Degrees
 * *min : Arcminutes
 * *sec : Arcseconds
 */
double ac_angle_dms_from_deg(double deg);

#endif

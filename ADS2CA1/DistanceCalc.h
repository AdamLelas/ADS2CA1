/***************************************************************************************
*    Title: Calculating the distance between 2 latitudes and longitudes that are saved in a text file?
*    Author: Stackoverflow users: MrTJ and Edward
*    Date accessed: 04/03/2017
*    Availability: http://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a*
***************************************************************************************/

/**************************************
*	
*	Adam Lelas
*	X00106580
*
***************************************/

#ifndef DISTANCE_CALC
#define DISTANCE_CALC

#include<cmath>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0



// This function converts decimal degrees to radians
double deg2rad(double deg);
//  This function converts radians to decimal degrees
double rad2deg(double rad);
/**
* Returns the distance between two points on the Earth.
* Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
* @param lat1d Latitude of the first point in degrees
* @param lon1d Longitude of the first point in degrees
* @param lat2d Latitude of the second point in degrees
* @param lon2d Longitude of the second point in degrees
* @return The distance between the two points in kilometers
*/
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

#endif // !DISTANCE_CALC


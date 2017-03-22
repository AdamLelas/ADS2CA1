#include "City.h"

ostream& operator<<(ostream& out, const City& c)
{
	out << setw(10) << c.name << setw(10) << c.GPS.first << setw(10) << c.GPS.second;
	return out;
}

bool City::operator<(const City & city2) const
{
	return (name < city2.name);
}

City::City()
{
	name = "EmptyCity";
	GPS.first = 0;
	GPS.second = 0;
}

City::City(string nameIn, double latitude, double longitude)
{
	//GPS = make_pair(longitude, latitude);
	name = nameIn;
	GPS.first = latitude;
	GPS.second = longitude;
}

string City::getName()
{
	return name;
}

double City::getLon() const
{
	return GPS.second;
}

double City::getLat() const
{
	return GPS.first;
}



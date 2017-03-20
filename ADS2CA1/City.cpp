#include "City.h"

ostream& operator<<(ostream& out, const City& c)
{
	out << c.name << "\t" << c.GPS.first << "," << c.GPS.second;
	return out;
}

bool City::operator<(const City & city2) const
{
	return (name < city2.name);
}

City::City()
{
	name = "";
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



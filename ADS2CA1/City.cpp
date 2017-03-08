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

City::City(string nameIn, double longitude, double latitude)
{
	//GPS = make_pair(longitude, latitude);
	name = nameIn;
	GPS.first = longitude;
	GPS.second = latitude;
}

string City::getName()
{
	return name;
}

double City::getLon() const
{
	return GPS.first;
}

double City::getLat() const
{
	return GPS.second;
}



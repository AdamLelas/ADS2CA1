#include "City.h"

ostream& operator<<(ostream& out, const City& c)
{
	out << c.name << "\t" << c.GPS.first << "," << c.GPS.second;
	return out;
}
  
bool City::operator<(const City & city2) const
{
	
}

City::City()
{
	name = "";
	GPS.first = 0;
	GPS.second = 0;
}

City::City(int longtitude, int latitude, string nameIn)
{
	//GPS = make_pair(longtitude, latitude);
	name = nameIn;
	GPS.first = longtitude;
	GPS.second = latitude;
}



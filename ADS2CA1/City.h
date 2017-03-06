#ifndef CITY_H
#define CITY_H

#include<string>
#include<ostream>
#include"DistanceCalc.h"
using namespace std;


class City {
public:
	friend ostream& operator<<(ostream & out, const City& c);
	bool operator<(const City& city2) const;
	City(); //default constructor
	City(int longtitude, int latitude, string nameIn);
private:
	pair<double, double> GPS;
	string name;
};



#endif // !CITY_H

#ifndef CITY_H
#define CITY_H

#include<string>
#include<ostream>
using namespace std;


class City {
public:
	friend ostream& operator<<(ostream & out, const City& c);
	City(); //default constructor
	City(int longtitude, int latitude, string n);
private:
	pair<int, int> GPS;
	string name;
};



#endif // !CITY_H

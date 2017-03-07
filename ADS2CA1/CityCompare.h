#ifndef CITY_COMPARE
#define CITY_COMPARE
#include"City.h"

class CityCompare {
public:
	bool operator()(const City& city1, const City& city2);
};



#endif // !CITY_COMPARE

#ifndef NODE_H
#define NODE_H
#include"City.h"

/**************************************
*
*	Adam Lelas
*	X00106580
*
***************************************/

struct Node {

	bool isLeaf(); //returns true if the node is a leaf node, otherwise returns false
	Node() { city = City(); left = NULL; right = NULL; };
	City city;
	Node * left;
	Node * right;
};
#endif // !NODE_H



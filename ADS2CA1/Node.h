#ifndef NODE_H
#define NODE_H

#include"City.h"
struct Node {

	bool isLeaf(); //returns true if the node is a leaf node, otherwise returns false
	Node() { city = City(); left = NULL; right = NULL; };
	int test;
	City city;
	Node * left;
	Node * right;
};
#endif // !NODE_H



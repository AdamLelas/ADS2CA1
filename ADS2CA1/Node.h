#ifndef NODE_H
#define NODE_H

#include"City.h"
struct Node {

	bool isLeaf(); //returns true if the node is a leaf node, otherwise returns false
	Node() { city = NULL; left = NULL; right = NULL; };

	//City c;
	int city;
	Node * left;
	Node * right;
};
#endif // !NODE_H



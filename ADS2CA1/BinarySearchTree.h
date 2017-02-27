#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include<iostream>
#include"Node.h"
#include"City.h"
using namespace std;
class BinarySearchTree {
public:
	BinarySearchTree(); //default constructor 
	bool isEmpty();
	int height(); //returns the height of the tree

	/*======CURRENTLY AN INT CHANGE TO CITY/STRING======*/
	void insert(int); //insert a new node

	void delCity(string); //delete a node by city name
	Node* searchName(string); //search a city by name
	Node* searchCoord(int, int); //search a city by GPS co-ords
	void display(); //prints the whole tree to the console
	void displayInDist(City, double); //displays cities within distance from city input
private:
	void display(Node * nodeptr);
	void insert(Node *toAdd, Node *addHere);
	Node * root;
};

#endif // BINARY_SEARCH_TREE_H

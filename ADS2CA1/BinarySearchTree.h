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

	void insert(string, double, double); //insert a new node -------- creates instance of city 

	void delCity(string); //delete a node by city name
	Node * replacementNode(Node * ); //travels to the right most node of a the subtree of the node to be deleted
	Node* searchName(string); //search a city by name
	Node* searchCoord(int, int); //search a city by GPS co-ords
	void display(); //prints the whole tree to the console
	void displayInDist(City, double); //displays cities within distance from city input
private:
	Node* searchName(string, Node*);
	Node* searchCoord(int, int, Node*);
	void display(Node * nodeptr); //display function for recursion
	void insert(Node *toAdd, Node *addHere); //insert function for recursion
	Node * root;
};

#endif // BINARY_SEARCH_TREE_H

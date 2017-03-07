#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include<iostream> //cout
// #include<cmath> //
#include<queue> //priority queue
#include"Node.h"
#include"City.h"
using namespace std;
class BinarySearchTree {
public:
	BinarySearchTree(); //default constructor 
	bool isEmpty();
	int height(); //returns the height of the tree	
	void insert(string name, double lon, double lat); //insert a new node -------- creates instance of city 
	void delCity(string); //delete a node by city name
	City searchName(string); //search a city by name
	Node* searchCoord(int lon, int lat); //search a city by GPS co-ords
	void display(); //prints the whole tree to the console
	void displayInDist(double maxDist, double lon, double lat); //displays cities within distance from co-ordinates provided within a maximum distance


private:
	int getHeight(Node * passedNode);
	void delCity(string, Node *); //Private delCity, so access to root in protected
	void deleteThis(Node *); //deletes the node and resets pointers so BST remains intact
	Node * largest(Node * passedNode);
	Node* searchName(string, Node*);
	Node* searchCoord(int, int, Node*);	
	void makeQueue(Node* passedNode, double maxDist, double lon, double lat, priority_queue<City>& pq); //makes the priority queue for displayInDist
	void display(Node * passedNode); //display function for recursion
	void insert(Node *toAdd, Node *addHere); //insert function for recursion
	void displayQueue(priority_queue<City>& pq);


	//variables
	Node * root;
};

#endif // BINARY_SEARCH_TREE_H

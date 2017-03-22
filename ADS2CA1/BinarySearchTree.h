#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include<iostream>
#include<queue>
#include<iomanip>
#include"Node.h"
#include"City.h"
using namespace std;

struct DoublePriority
{
	bool operator() (const pair<string, double> &lhs, const pair<string, double> &rhs) const {
		if (lhs.second > rhs.second) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

class BinarySearchTree {
public:
	BinarySearchTree(); //default constructor 
	bool isEmpty();
	void insert(string name, double lat, double lon); //insert a new node -------- creates instance of city 
	bool delCity(string); //delete a node by city name
	City searchName(string); //search a city by name and returns a city

	bool boolSearchName(string searchKey); //returns true if name found otherwise false
	City searchCoord(double lat, double lon); //search a city by GPS co-ords
	bool boolSearchCoord(double lat, double lon);


	void displayInOrder(); //prints the whole tree to the console
	void displayPostOrder();
	void displayPreOrder();
	void displayInDist(double maxDist, string cityin); //displays cities within distance from co-ordinates provided within a maximum distance

	int height(); //returns the height of the tree	

private:
	int getHeight(Node * passedNode);
	bool delCity(string, Node *&); //Private delCity, so access to root is protected
	void makeDeletion(Node *& nodeptr);
	Node * largest(Node * passedNode);

	Node* searchName(string, Node*);
	bool boolSearchName(string searchKey, Node * passedNode);

	Node* searchCoord(double, double, Node*);	
	bool boolSearchCoord(double lat, double lon, Node * passedNode);


	void makeQueue(Node* passedNode, double maxDist, City cityin, priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority>& pq);
	void displayInOrder(Node * nodeptr);
	//makes the priority queue for displayInDist
	void displayPostOrder(Node * nodeptr);
	void displayPreOrder(Node * nodeptr);
	void display(Node * passedNode); //display function for recursion
	void insert(Node *toAdd, Node *addHere); //insert function for recursion
	void showIt(priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority> pq) const;

	
	//variables
	Node * root;
};




#endif // BINARY_SEARCH_TREE_H

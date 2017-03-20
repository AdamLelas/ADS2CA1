#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include<iostream> //cout
// #include<cmath> //
#include<queue> //priority queue
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
	void insert(string name, double lon, double lat); //insert a new node -------- creates instance of city 
	void delCity(string); //delete a node by city name

	City searchName(string); //search a city by name
	Node* searchCoord(int lon, int lat); //search a city by GPS co-ords

	void display(); //prints the whole tree to the console
	void displayInDist(double maxDist, City cityin); //displays cities within distance from co-ordinates provided within a maximum distance

	int height(); //returns the height of the tree	

private:
	int getHeight(Node * passedNode);
	void delCity(string, Node *&); //Private delCity, so access to root in protected

	void makeDeletion(Node *& nodeptr);

	Node * largest(Node * passedNode);


	Node* searchName(string, Node*);
	Node* searchCoord(int, int, Node*);	

	void makeQueue(Node* passedNode, double maxDist, City cityin, priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority>& pq); //makes the priority queue for displayInDist
	void display(Node * passedNode); //display function for recursion
	void insert(Node *toAdd, Node *addHere); //insert function for recursion
	void showIt(priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority> pq) const;

	
	//variables
	Node * root;
};




#endif // BINARY_SEARCH_TREE_H

#include<string>
#include<map>
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

struct Node {
public:
	bool isLeaf(); //returns true if the node is a leaf node, otherwise returns false
	Node();
private:
	City c;
	Node * left;
	Node * right;
};

class BinarySearchTree {
public:
	int height(); //returns the height of the tree
	BinarySearchTree(); //default constructor 
	void insert(); //insert a new node
	void delCity(City); //delete a node by City
	Node* searchName(string); //search a city by name
	Node* searchCoord(int, int); //search a city by GPS co-ords
	void display(); //prints the whole tree to the console
	void displayInDist(City, double); //displays cities within distance from city input
private:
	Node * root;
};
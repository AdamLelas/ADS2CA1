#include "BinarySearchTree.h"


/*CONSTRUCTOR*/
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

bool BinarySearchTree::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

void BinarySearchTree::insert(string name, double longitude, double latitude)
{
	Node *temp = new Node;
	temp->city = City(name, longitude, latitude);
	temp->left = NULL;
	temp->right = NULL;
	if (!isEmpty()) 
	{
		//calls private insert function
		insert(temp, root);
	}
	else
	{
		root = temp;
	}
}

/**
* private function
* "toAdd" is the node being added
* "addHere" is the node where it will be added or if addHere
* already has a value then it is used in the recursive function call
*/
void BinarySearchTree::insert(Node * toAdd, Node * addHere)
{
	if (toAdd->city < addHere->city)
	{
		if (addHere->left != NULL)
		{
			insert(toAdd, addHere->left);
		}
		else
		{
			//addHere->left = new Node;
			addHere->left = toAdd;
		}
	}
	else 
	{
		if (addHere->right != NULL)
		{
			insert(toAdd, addHere->right);
		}
		else 
		{
			addHere->right = toAdd;
		}
	}
}



//public and private display functions
void BinarySearchTree::display()
{
	if (isEmpty()) 
	{
		cout << "BTree is empty";
	}
	else
	{
		cout << root->city;
		if (root->left != NULL)
		{
			cout << "Left" << endl;
			display(root->left);
		}
		if (root->right != NULL) 
		{
			cout << "right" << endl;
			display(root->right);
		}
	}
}

/**
* displays cities within given distance of given city
*/
void BinarySearchTree::displayInDist(double maxDist, City cityin)
{
	if (!isEmpty()) 
	{
		priority_queue<pair<string,double>> pq;
		makeQueue(root, maxDist, cityin, pq);
		displayQueue(pq);
	}
}

void BinarySearchTree::displayQueue(priority_queue<pair<string, double>>& pq)
{
	while (!pq.empty())
	{
	//	cout << pq.top();
		pq.pop();
	}
}

void BinarySearchTree::makeQueue(Node * passedNode, double maxDist, City cityin, priority_queue<pair<string, double>>& pq)
{

	/**
	* TODO : FIX THIS TO WORK WITH A PAIR<STRING,DOUBLE> NOT CITY
	*/
	double citylon, citylat, calcDist;
	citylon = passedNode->city.getLon();
	citylat = passedNode->city.getLat();
	calcDist = distanceEarth(cityin.getLat(), cityin.getLon(), citylat, citylon);
	if (calcDist <= maxDist)
	{
		pq.push(passedNode->city);
	}
	if (passedNode->left != NULL) 
	{
		makeQueue(passedNode->left, maxDist, cityin, pq);
	}
	if (passedNode->right != NULL) 
	{
		makeQueue(passedNode->right, maxDist, cityin, pq);
	}
}

void BinarySearchTree::display(Node * nodeptr)
{
	cout << nodeptr->city;
	if (nodeptr->left != NULL)
	{
		cout << "Left" << endl;
		display(nodeptr->left);
	}
	if (nodeptr->right != NULL)
	{
		cout << "right" << endl;
		display(nodeptr->right);
	}
}


void BinarySearchTree::delCity(string n)
{
	if (!isEmpty())
	{
		delCity(n, root);
	}
}

void BinarySearchTree::delCity(string n, Node * parent)
{
	if (n == parent->city.getName())
	{
		return deleteThis(parent);
	}
	else if (n < parent->city.getName())
	{
		return deleteThis(parent->left);
	}
	else
	{
		return deleteThis(parent->right);
	}

}

void BinarySearchTree::deleteThis(Node * parent)
{
	Node *temp;
	temp = parent;
	if (parent->left == NULL)  //no left subtree
	{
		parent = parent->right;
		delete(temp);
	}
	else if (parent->right == NULL) //no right subtree
	{ 
		parent = parent->left;
		delete(temp);
	}
	else // both left and right subtrees exist
	{
		temp = largest(parent);
		parent->city = temp->city;
		delCity(parent->city.getName(), temp);
	}
}

Node* BinarySearchTree::largest(Node* passedNode) 
{
	if (passedNode->right == NULL)
	{
		return passedNode;
	}
	else
	{
		return largest(passedNode->right);
	}
}


//This function exists just to set off the recursive function without the user needing access to root
City BinarySearchTree::searchName(string searchKey) 
{
	Node* temp;
	temp = searchName(searchKey, root);	
	return temp->city;
}

//traverses the BTree until it finds the searchKey or not
Node * BinarySearchTree::searchName(string searchKey, Node * passedNode)
{
	if (passedNode != NULL)
	{
		if (searchKey == passedNode->city.getName())
		{
			return passedNode;
		}
		if (searchKey < passedNode->city.getName())
		{
			return searchName(searchKey, passedNode->left);
		}
		else
		{
			return searchName(searchKey, passedNode->right);
		}
	}
	else
	{
		return NULL;
	}

}

//This function exists just to set off the recursive function without the user needing access to root
Node * BinarySearchTree::searchCoord(int lon, int lat)
{
	return searchCoord(lon, lat, root);
}

Node * BinarySearchTree::searchCoord(int lon, int lat, Node * passedNode)
{
	if (passedNode != NULL) 
	{
		if ((passedNode->city.getLon() == lon) && passedNode->city.getLat() == lat)
		{
			return passedNode;
		}
		else
		{
			if (passedNode->left != NULL)
			{
				return searchCoord(lon, lat, passedNode->left);
			}
			if (passedNode->right != NULL)
			{
				return searchCoord(lon, lat, passedNode->right);
			}
		}
	}
	return;
}

int BinarySearchTree::height()
{
	if (!isEmpty()) 
	{
		return getHeight(root);
	}
	else
	{
		return -1;
	}
}

int BinarySearchTree::getHeight(Node* passedNode)
{
	if (passedNode == NULL) {
		return 0;
	}
	else
	{
		int left = getHeight(passedNode->left);
		int right = getHeight(passedNode->right);

		if (left > right) 
		{
			return 1 + left;
		}
		else 
		{
			return 1 + right;
		}
	}
}


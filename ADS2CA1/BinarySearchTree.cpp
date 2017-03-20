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

void BinarySearchTree::insert(string name, double latitude, double longitude)
{
	Node *temp = new Node;
	temp->city = City(name, latitude, longitude);
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
* private fucntion
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
	else {
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
	else {
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

void BinarySearchTree::displayInDist(double maxDist, City cityin) //takes a maximum range in kilometers and a city and outputs cities in order of closest to furthest within that range
{
	if (!isEmpty()) 
	{
		priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority> pq;		
		makeQueue(root, maxDist, cityin, pq);	
		showIt(pq);
	}
}

void BinarySearchTree::showIt(priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority> pq) const
{
	pq.pop(); // pops first city off the list
	while (!pq.empty())
	{
		cout << pq.top().first << ": " << pq.top().second << " km" <<endl;
		pq.pop();
	}
}

void BinarySearchTree::makeQueue(Node * passedNode, double maxDist, City cityin, priority_queue< pair<string, double>, vector<pair<string, double>>, DoublePriority>& pq) {
	double citylon, citylat, calcDist;
	citylon = passedNode->city.getLon();
	citylat = passedNode->city.getLat();

	calcDist = distanceEarth(citylat, citylon, cityin.getLat(), cityin.getLon());
	if (calcDist <= maxDist) 
	{
		pq.push(make_pair(passedNode->city.getName(),calcDist));
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

void BinarySearchTree::delCity(string n, Node *& parent)
{
	if (n < parent->city.getName())
	{
		if (parent->left != NULL) 
		{
			delCity(n, parent->left);
		}
		else
		{
			cout << n << " not in tree" << endl;
		}
	}
	else if (n > parent->city.getName()) 
	{
		if (parent->right != NULL) 
		{
			delCity(n, parent->right);
		}
		else
		{
			cout << n << " not in tree" << endl;
		}
	}
	else 
	{
		makeDeletion(parent);
	}

}

void BinarySearchTree::makeDeletion(Node *&nodeptr)
{
	Node *temp = new Node();
	if (nodeptr->right == NULL)  //left subtrees only
	{ 
		temp = nodeptr;
		nodeptr = nodeptr->left;
		delete temp;
	}
	else if (nodeptr->left == NULL) //right subtrees only
	{ 
		temp = nodeptr;
		nodeptr = nodeptr->right;
		delete temp;
	}
	else //both subtrees
	{ 
		Node* largestValue = largest(nodeptr->left);
		delCity(largestValue->city.getName(), nodeptr );
		nodeptr->city = largestValue->city;
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
		return largest(passedNode);
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
	return NULL;
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
	if (passedNode == NULL)
	{
		return -1;
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


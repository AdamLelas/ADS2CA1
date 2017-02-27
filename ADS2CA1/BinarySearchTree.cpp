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


void BinarySearchTree::insert(int input)
{
	Node *temp = new Node;
	temp->city = input;
	temp->left = NULL;
	temp->right = NULL;
	if (!isEmpty()) {
		insert(temp, root);
	}
	else
	{
		root = new Node;
		root->city = input;
		root->left = NULL;
		root->right = NULL;
	}
}

//private
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
		if (addHere->right != NULL) {
			insert(toAdd, addHere->right);
		}
		else {
			addHere->right = toAdd;
		}
	}

}


/*
void BinarySearchTree::delCity(City)
{
}
*/



void BinarySearchTree::delCity(string)
{
}

Node * BinarySearchTree::searchName(string)
{
	return nullptr;
}

Node * BinarySearchTree::searchCoord(int, int)
{
	return nullptr;
}

void BinarySearchTree::display()
{
}

void BinarySearchTree::displayInDist(City, double)
{
}



int BinarySearchTree::height()
{
	return 0;
}




//iterative insert
//void BinarySearchTree::insert(int input)
//{
//	Node *t = new Node; //create a temp node
//
//	/*fill temp_node with values*/
//	t->city = input;
//	t->left = NULL;
//	t->right = NULL;
//
//	Node *parent;
//	parent = NULL;
//	
//	if (isEmpty()) {
//		root = t;
//	}
//	else 
//	{
//		Node *curr;
//		curr = root;
//		while (curr) 
//		{
//			parent = curr;
//			if (t->city > curr->city)
//			{
//				curr = curr->right;
//			}
//			else
//			{
//				curr = curr->left;
//			}
//		} //end while
//		if (t->city < parent->city)
//		{
//			parent->left = t;
//		}
//		else {
//			parent->right = t;
//		}
//	}
//}
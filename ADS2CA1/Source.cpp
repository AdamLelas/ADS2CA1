#include<string>
#include<map>
#include"BinarySearchTree.h"
#include"City.h"
#include"Node.h"
using namespace std;


int main() {

	BinarySearchTree citytree;
	
	citytree.insert(7);
	citytree.insert(2);
	citytree.insert(5);
	citytree.insert(9);
	citytree.insert(4);
	citytree.insert(6);
	citytree.insert(8);

	//citytree.insert(5);
	//citytree.insert(3);
	//citytree.insert(2);
	//citytree.insert(4);
	//citytree.insert(1);

	//citytree.insert(8);
	//citytree.insert(6);
	//citytree.insert(7);
	//citytree.insert(9);

	citytree.display();

	system("pause");
	return 0;
}


//
//REF : BinaryTree
//http://www.cprogramming.com/tutorial/lesson18.html
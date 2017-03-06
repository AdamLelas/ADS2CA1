#include<string>
#include<map>
#include"BinarySearchTree.h"
#include"City.h"
#include"Node.h"
using namespace std;


int main() {

	BinarySearchTree citytree;

	citytree.insert("Dublin", 25, 66);
	citytree.insert("Edinburgh", 120 , 98);
	citytree.insert("Moscow",12 ,33 );
	citytree.insert("Venice", 90 ,54 );
	citytree.insert("Atlanta",60 ,38 );

	cout << "SEARCH NAME HAPPENING NOW" <<endl;
	cout << citytree.searchName("Dublin");
	cout << "\n\n\n";




	
	

	citytree.display();

	system("pause");
	return 0;
}


//
//REF : BinaryTree
//http://www.cprogramming.com/tutorial/lesson18.html
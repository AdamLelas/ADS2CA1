#include<string>
#include<map>
#include"BinarySearchTree.h"
#include"City.h"
#include"Node.h"


using namespace std;


int main() {


	BinarySearchTree citytree;

	citytree.insert("Dublin", 53.3498, -6.2603);
	citytree.insert("Edinburgh", 55.9533, -3.1883);
	citytree.insert("Paris", 48.8566, 2.3522);
	citytree.insert("Sydney", -33.8688, 151.2093);
	citytree.insert("New York", 40.7128 , -74.0059);
	citytree.insert("Atlanta", 33.7490, -84.3880);
	citytree.insert("Cork", 51.8969, -8.4863);
	citytree.insert("Glasgow", 55.8642, -4.2518);
	citytree.insert("Tokyo", 35.6895, -139.6917);

	cout << "SEARCH NAME HAPPENING NOW" <<endl;
	cout << citytree.searchName("Dublin");
	cout << "\n\n\n";

	double distanceLimit = 500;
	string citytosearch = "Dublin";

	cout << "Citys within " << distanceLimit << "km of "  << citytosearch << endl;
	citytree.displayInDist(distanceLimit, citytree.searchName(citytosearch));


	
	cout << "\n\n\n";
	citytree.display();

	system("pause");
	return 0;
}


//
//REF : BinaryTree
//http://www.cprogramming.com/tutorial/lesson18.html
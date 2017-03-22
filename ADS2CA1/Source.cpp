#include<string>
#include<map> //pair
#include<iomanip> // setw
#include"BinarySearchTree.h"
#include"City.h"
#include"Node.h"


using namespace std;

int main() {

	BinarySearchTree citytree;

	//citytree.insert("dublin", 53.3498, -6.2603);
	//citytree.insert("EDINBURGH", 55.9533, -3.1883);
	//citytree.insert("PARIS", 48.8566, 2.3522);
	//citytree.insert("SYDNEY", -33.8688, 151.2093);
	//citytree.insert("NEW YORK", 40.7128, -74.0059);
	//citytree.insert("ATLANTA", 33.7490, -84.3880);
	//citytree.insert("CORK", 51.8969, -8.4863);
	//citytree.insert("GLASGOW", 55.8642, -4.2518);
	//citytree.insert("TOKYO", 35.6895, -139.6917);

	//citytree.displayInOrder();
	//cout << "\n\n\n";

	//citytree.delCity("Atlanta");

	//cout << "\n\n\n";

	//double distanceLimit = 500;
	//string citytosearch = "dublin";

	//cout << "Citys within " << distanceLimit << "km of " << citytosearch << endl;
	//citytree.displayInDist(distanceLimit, citytosearch);

	//cout << "Citys within " << distanceLimit << "km of " << "Atlanta" << endl;
	//citytree.displayInDist(distanceLimit, "Atlanta");


	//cout << "\n\n\n";
	//citytree.displayInOrder();

	//=================================
	//Pretty display bullshit
	//=================================
	City c1;
	string namein;
	double lat, lon;
	int selection = 0;
	while (selection != -1) {
		cout << "\n\n\nEnter 1-10\t-1 to Exit\tInputs not case sensitive" << endl
			<< "==============================================================" << endl
			<< "1) Enter new city " << endl
			<< "2) Search a city by name" << endl
			<< "3) Search a city by coordinates" << endl
			<< "4) Delete a city " << endl
			<< "5) Display the tree in-order" << endl
			<< "6) Display the tree post-order" << endl
			<< "7) Display the tree pre-order" << endl
			<< "8) Display the height of the tree" << endl
			<< "9) Display all cities within a range of a city" << endl
			<< "==============================================================" << endl << endl
			<< "Selection: ";
		cin >> selection;
		switch (selection) {
		case 1:			
			cout << "Enter values" << endl
				<< "City name: ";
			cin >> namein;
			cout << "Latitude: ";
			cin >> lat;
			cout << "Longitude: ";
			cin >> lon;
			citytree.insert(namein, lat, lon);
				break;
		case 2:
			cout << "Enter values" << endl
				<< "City name: ";
			cin >> namein;
			if (citytree.boolSearchName(namein)) {
				c1 = citytree.searchName(namein);
				cout << c1 << endl;
			}
			else
			{
				cout << namein << " not found in tree" << endl;
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			citytree.displayInOrder();
			break;
		case 6:
			//citytree.displayPostOrder();
			break;
		case 7:
			//citytree.displayPreOrder();
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			break;

		}//switch ends
	}//while ends
	cout << "Exiting..." << endl;




	system("pause");
	return 0;
}


//
//REF : BinaryTree
//http://www.cprogramming.com/tutorial/lesson18.html
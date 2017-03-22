#include"timer.h"
#include <stdlib.h>/* srand, rand */
#include<string>
#include<map> //pair<>
//#include<iomanip> // setw()
#include"BinarySearchTree.h"
#include"City.h"
#include"Node.h"
#include<chrono>
#include<random>


using namespace std;

char intToAlphabet(int i)
{
	int	ra = rand() % 4;
	if (ra == 2) {
		return static_cast<char>('A' - 6 + i);
	}
	else if (ra == 1) {
		return static_cast<char>('A' - 3 + i);
	}
	else if (ra == 3)
		return static_cast<char>('A' - 5 + i);
	else
		return static_cast<char>('A' - 17 + i);

}


string convertIntToString(int seed) {
	string str, str2;
	int rand_int;
	minstd_rand0 generator(seed);
	rand_int = generator();
	str = to_string(rand_int);
	for (int i = 0; i < str.length(); ++i)
		str2 = str2 + intToAlphabet(str.at(i));
	return str2;
}


int main() {

	BinarySearchTree citytree;

	/*citytree.insert("dublin", 53.3498, -6.2603);
	citytree.insert("EDINBURGH", 55.9533, -3.1883);
	citytree.insert("PARIS", 48.8566, 2.3522);
	citytree.insert("SYDNEY", -33.8688, 151.2093);
	citytree.insert("NEW YORK", 40.7128, -74.0059);
	citytree.insert("ATLANTA", 33.7490, -84.3880);
	citytree.insert("CORK", 51.8969, -8.4863);
	citytree.insert("GLASGOW", 55.8642, -4.2518);
	citytree.insert("TOKYO", 35.6895, -139.6917);*/

	//citytree.displayInOrder();
	
	//citytree.delCity("Atlanta");

	//cout << "\n\n\n";

	//double distanceLimit = 500;
	//string citytosearch = "dublin";

	//cout << "Citys within " << distanceLimit << "km of " << citytosearch << endl;
	//citytree.displayInDist(distanceLimit, citytosearch);

	//cout << "Citys within " << distanceLimit << "km of " << "Atlanta" << endl;
	//citytree.displayInDist(distanceLimit, "Atlanta");


	//======================================================================
	//  RANDOM GENERATOR FOR DATA
	//======================================================================

	typedef chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();

	// obtain a seed from the timer
	myclock::duration d = myclock::now() - beginning;
	unsigned seed2 = d.count();

	minstd_rand0 generator(seed2); // minstd_rand0 is a standard linear_congruential_engine

	//======================================================================
	//  ^^^^^^^^^^^^^^^^^^^ RANDOM GENERATOR FOR DATA ^^^^^^^^^^^^^^^^^^^^^
	//======================================================================

	citytree.insert("mmmmmmmmm", 0.5, 4.2); //forces first node to be almost in the middle of the alphabet
	for (int i = 0; i < 3000; i++) {
		citytree.insert(convertIntToString(generator()), ((rand() % 360) - 180), ((rand() % 360) - 180));
	}
	citytree.insert("zzzzzzzzzzzzzzz", 0.1, 4.53);
	citytree.insert("aaaaaaaaaaaaaaa", 0.1, 4.3);
	

	//  Start Timers
	double wall0 = get_wall_time();
	double cpu0 = get_cpu_time();

	//height
	//citytree.height();

	//pre order
	//citytree.displayPreOrder();


	//post order
	//citytree.displayPostOrder();

	//in order only
	//citytree.displayInOrder();

	//dispInDist
	citytree.displayInDist(500, "zzzzzzzzzzzzzzz");


	//del randomly generated string
	//citytree.delCity(convertIntToString(generator()));


	//just delete root
	//citytree.delCity("mmmmmmmmm");
	//just delete leaf
	//citytree.delCity("zzzzzzzzzzzzzzz");


	//just boolsearchname
	//if (citytree.boolSearchName("zzzzzzzzzzzzzzz") == 1)
	//	cout << "found" << endl;
	//else


	////just insert
	//citytree.insert("mmmmmmmmm", 0.5, 4.2); //forces first node to be almost in the middle of the alphabet
	//for (int i = 0; i < 3000; i++) {
	//	citytree.insert(convertIntToString(generator()), ((rand() % 360) - 180), ((rand() % 360) - 180));
	//}
	//citytree.insert("zzzzzzzzzzzzzzz", 0.1, 4.3);
	//citytree.insert("aaaaaaaaaaaaaaa", 0.1, 4.3);
	

	////ALL OPERATIONS
	//citytree.insert("mmmmmmmmm", 0.5, 4.2); //forces first node to be almost in the middle of the alphabet
	//for (int i = 0; i < 30000; i++) {
	//	citytree.insert(convertIntToString(generator()), ((rand() % 360) - 180), ((rand() % 360) - 180));
	//}
	//citytree.insert("zzzzzzzzzzzzzzz", 0.1, 4.3);
	//citytree.insert("aaaaaaaaaaaaaaa", 0.1, 4.3);

	//if (citytree.boolSearchName("zzzzzzzzzzzzzzz") == 1)
	//	cout << "found" << endl;
	//else
	//	cout << "not found" << endl;
	//citytree.delCity("zzzzzzzzzzzzzzz");
	//citytree.delCity("mmmmmmmmm");
	//if (citytree.boolSearchCoord(0.1, 4.3) == 1)
	//	cout << "found" << endl;
	//else
	//	cout << "not found" << endl;

	//citytree.displayInDist(500 ,"zzzzzzzzzzzzzzz");
	//citytree.displayInOrder();
	//citytree.displayPostOrder();
	//citytree.displayPreOrder();

	//citytree.height();


	////  Stop timers
	double wall1 = get_wall_time();
	double cpu1 = get_cpu_time();

	cout << "Wall Time = " << wall1 - wall0 << endl;
	cout << "CPU Time  = " << cpu1 - cpu0 << endl;





	//======================================================================
	//  WORST CASE SEARCHES, DELETE AND DISPLAYS
	//======================================================================

	//  Start Timers
	//double wall0 = get_wall_time();
	//double cpu0 = get_cpu_time();

	//
	//if (citytree.boolSearchName("zzzzzzzzzzzzzzz") == 1)
	//	cout << "found" << endl;
	//else
	//	cout << "not found" << endl;

	////  Stop timers
	//double wall1 = get_wall_time();
	//double cpu1 = get_cpu_time();

	//cout << "Wall Time = " << wall1 - wall0 << endl;
	//cout << "CPU Time  = " << cpu1 - cpu0 << endl;

	//citytree.displayInOrder();


	//cout << "\n\n\n\n\n\n" << citytree.height();


	//  Start Timers
	//double wall0 = get_wall_time();
	//double cpu0 = get_cpu_time();

	////  Perform some computation.
	//citytree.displayInOrder();




	////  Stop timers
	//double wall1 = get_wall_time();
	//double cpu1 = get_cpu_time();

	//cout << "Wall Time = " << wall1 - wall0 << endl;
	//cout << "CPU Time  = " << cpu1 - cpu0 << endl;

	//  Prevent Code Elimination
	






	////Variables required for Switch statement
	//City c1;
	//string namein;
	//double lat, lon, range;
	////Variables required for Switch statement

	//int selection = 0;
	//while (selection != -1) {
	//	cout << "\n\n\nEnter 1-10\t-1 to Exit\tInputs not case sensitive" << endl
	//		<< "==============================================================" << endl
	//		<< " 1) Enter new city " << endl
	//		<< " 2) Search a city by name" << endl
	//		<< " 3) Search a city by coordinates" << endl
	//		<< " 4) Delete a city " << endl
	//		<< " 5) Display the tree in-order" << endl
	//		<< " 6) Display the tree post-order" << endl
	//		<< " 7) Display the tree pre-order" << endl
	//		<< " 8) Display the height of the tree" << endl
	//		<< " 9) Display all cities within a range of a city" << endl
	//		<< "==============================================================" << endl << endl
	//		<< "Selection: ";
	//	cin >> selection;
	//	cout << endl << endl;
	//	switch (selection) {
	//	case 1:			
	//		cout << "Enter values" << endl
	//			<< "City name: ";
	//		cin >> namein;
	//		cout << "Latitude: ";
	//		cin >> lat;
	//		cout << "Longitude: ";
	//		cin >> lon;
	//		citytree.insert(namein, lat, lon);
	//			break;
	//	case 2:
	//		cout << "Enter values" << endl
	//			<< "City name: ";
	//		cin >> namein;
	//		if (citytree.boolSearchName(namein)) {
	//			c1 = citytree.searchName(namein);
	//			cout << c1 << endl;
	//		}
	//		else
	//		{
	//			cout << namein << " not found in tree" << endl;
	//		}
	//		break;
	//	case 3:
	//		cout << "Enter values" << endl;				
	//		cout << "Latitude: ";
	//		cin >> lat;
	//		cout << "Longitude: ";
	//		cin >> lon;
	//		cout << endl << endl;			
	//		if (citytree.boolSearchCoord(lat, lon)) 
	//			cout << citytree.searchCoord(lat, lon);
	//		else
	//			cout << lat << ", " << lon << "not found in database";

	//		break;
	//	case 4:
	//		cout << "-----WARNING DELETION IS PERMANENT-----" << endl
	//			<< "Enter values" << endl
	//			<< "City name: ";
	//		cin >> namein;
	//		if (citytree.delCity(namein))
	//			cout << "Deleted " << namein << " from database" << endl;
	//		break;
	//	case 5:
	//		citytree.displayInOrder();
	//		cout << endl << endl;
	//		break;
	//	case 6:
	//		citytree.displayPostOrder();
	//		cout << endl << endl;
	//		break;
	//	case 7:
	//		citytree.displayPreOrder();
	//		cout << endl << endl;
	//		break;
	//	case 8:
	//		cout << citytree.height();
	//		break;
	//	case 9:
	//		cout << "Enter values" << endl
	//			<< "City name: ";
	//		cin >> namein;
	//		cout << "Maximum distance: ";
	//		cin >> range;
	//		cout << endl << endl;
	//		cout << "Citys within " << range << "km of " << namein << endl;
	//		citytree.displayInDist(range, namein);
	//		break;
	//	default:
	//		break;

	//	}//switch ends
	//}//while ends
	//cout << "Exiting..." << endl;









	system("pause");
	return 0;
}


//
//REF : BinaryTree
//http://www.cprogramming.com/tutorial/lesson18.html

//
//REF : RANDOM GENERATOR
//http://www.cplusplus.com/reference/random/linear_congruential_engine/seed/
//


#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"


using namespace std;



int main()
{
	ArrayList<int> tested(50);


	tested.add(100); 
	tested.add(50);
	tested.add(70);
	tested.add(50);
	tested.add(70);
	tested.add(50);
	tested.add(70);
	tested.add(12,true);
	//tested.add(89);
	//cout <<  << endl;
	tested.set(1,25);
	int *arr = tested.toArray();
	for (size_t i = 0; i < tested.size(); i++)
	{
		cout << arr[i] << endl;
	}
	tested.firstDelete();
	tested.lastDelete();
	cout << endl << tested.isEmpty() << endl << endl;
	int* arr1 = tested.toArray();
	for (size_t i = 0; i < tested.size(); i++)
	{
		cout << arr1[i]<<endl;
	}


	cin.get();


	return 0;
}
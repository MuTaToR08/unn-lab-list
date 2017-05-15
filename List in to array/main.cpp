#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"


using namespace std;



int main()
{
	LinkedList<int> tested;


	tested.add(100); 
	tested.add(50);
	tested.add(70);
	//tested.add(89);
	//cout <<  << endl;
	//tested.set(1,25);
	tested.remove(2);
	cout << tested.isEmpty()<<endl;
	int *arr = tested.toArray();
	for (size_t i = 0; i < tested.size(); i++)
	{
		cout << arr[i]<<endl;
	}/**/


	cin.get();


	return 0;
}
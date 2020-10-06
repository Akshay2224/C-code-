// A C++ program to show that it is wrong to 
// compute size of an array parameter in a function 
#include <iostream> 
using namespace std; 

void findSize(int arr[]) 
{ 
	cout << sizeof(arr) << endl; 
} 

int main() 
{ 
	int a[10]; 
	cout << sizeof(a) << " "; 
	findSize(a); 
	return 0; 
}


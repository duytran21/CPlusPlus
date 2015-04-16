#include <iostream>
#include <stdlib.h>
using namespace std;
void swapSmall(int &a,int &a2);
int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int *arr,*arr2;
	arr=new int[n];
	arr2=new int[n];
	for (int i=0;i<n;i++){
		arr[i]=rand()%n;
		arr2[i]=rand()%n;
	}
	cout << endl;
	cout << "\t----Initializing Arrays----" << endl;
	cout << "Array 1 \tArray 2" << endl;
	for (int i=0;i<n;i++){
		cout << "arr[" << i << "]= " <<arr[i] << " ";
		cout << "\tarr2[" << i << "]= " <<arr2[i] << " " << endl;
	}
	cout << endl;
	cout << "\t----Compare and Swap----" << endl;
	cout << "Array 1 \tArray 2" << endl;
	for(int i=0;i<n;i++){
		if(arr[i]<arr2[i])
			swapSmall(arr[i],arr2[i]);	
	}
	
	for (int i=0;i<n;i++){
		cout << "arr[" << i << "]= " <<arr[i] << " ";
		cout << "\tarr2[" << i << "]= " <<arr2[i] << " " << endl;
	}
	cout << endl;	
	delete [] arr;
	delete [] arr2;
	return 0;
}
void swapSmall(int &a,int &a2){
			int temp;
			temp=a;
			a=a2;
			a2=temp;
}
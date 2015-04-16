#include <iostream>
#include <stdlib.h>
using namespace std;
const int SIZE=5;

float addArrays(float a1[SIZE], float a2[SIZE], float a3[SIZE]);
int main(){
	
	float arr1[SIZE]={1,3,4,7,6};
	float arr2[SIZE]={8,11,2,9,13};
	float arr3[SIZE];
	cout << "Array 1 \tArray 2" << endl;
	for(int i=0;i<SIZE;i++){
		cout << "arr1[" << i << "]= " <<arr1[i] << " ";
		cout << "\tarr2[" << i << "]= " <<arr2[i] << " " << endl;
	}
	cout << "\t----Add arrays----" << endl;
	addArrays(arr1,arr2,arr3);
	cout << "Array 3" << endl;
	for (int i=0;i<SIZE;i++){
		cout << "arr3[" << i << "]= " << arr3[i] << endl;
	}
	return 0;
}

float addArrays(float a1[SIZE], float a2[SIZE], float a3[SIZE]){
	for(int i=0;i<SIZE;i++){
		a3[i]=a1[i]+a2[i];
	}	
	return a3[SIZE];
}
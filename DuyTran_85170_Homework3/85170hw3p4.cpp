#include <iostream>
//#include <stdlib.h>
using namespace std;
const int SIZE=5;

float addArrays(float *a1,float *a2,float *a3);
int main(){
	
	/*float *arr1=new float[SIZE];
	arr1=(float[]){1,2,3,4,5};
	float *arr2=new float[SIZE];
	arr2=(float[]){6,7,8,9,10.5};
	float *arr3=new float[SIZE];*/
	float arr1[]={
		1,3,4,5,6
	};
	float arr2[]={
		3,4,5,6,6
	};
	float arr3[SIZE];
	cout << "Array 1 \tArray 2" << endl;
	for(int i=0;i<SIZE;i++){
		cout << "arr1[" << i << "]= " << *(arr1+i) << " ";
		cout << "\tarr2[" << i << "]= " << *(arr2+i) << " " << endl;
	}
	cout << "\t----Add arrays----" << endl;
	addArrays(arr1,arr2,arr3);
	cout << "Array 3" << endl;
	for (int i=0;i<SIZE;i++){
		cout << "arr3[" << i << "]= " << *(arr3+i) << endl;
	}
	delete [] arr1,arr2,arr3;
	return 0;
}

float addArrays(float *a1, float *a2, float *a3){
	for(int i=0;i<SIZE;i++){
		*(a3+i)=*(a1+i)+*(a2+i);
	}	
	return *a3;
}

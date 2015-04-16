#include <iostream>
#include <fstream>
const char FILE1[]="E:\\carparts.txt";
const int arraysize=14;
using namespace std;	
int main(){
	int m,n;
	char *array;
	char s;
	string ss[arraysize];
	double t;
	
	int pos=0;
	ifstream readFile;
	readFile.open(FILE1);
	if(!readFile){
		cout <<"Error: file cannot be opened. Check Dir again!" << endl;
		exit(1);
	}
	while(!readFile.eof()){
	//	getline(readFile,ss[pos]);
		get(readFile,ss[pos]);
		pos++;
	}
	/*for(int i=0;i<m;i++){
		readFile >> array[i];
		cout << array[i];
	}*/
	
	cout << sizeof(ss)/sizeof(ss[0]);
	cout << endl;
	for(int i=0;i<arraysize;i++){
		cout << ss[i] << endl;
	}
/*	for(int i=0;array[i]!='\0';i++){
		cout << array[i] ;
	}*/
	//cout << endl;
	delete [] array;
	readFile.close();
	return 0;
}
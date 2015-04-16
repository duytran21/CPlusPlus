#include <iostream>
#include <fstream>
using namespace std;
const int array_size=1024;
const char FILE1[]="codetable.txt";
const char FILE2[]="codedmessage.txt";
int main(){
	char *c=new char[array_size];
	char *array=new char[array_size];
	int pos=0;
	int pos1=0;
	ifstream infile,infile2;
	infile.open(FILE1);
	if(!infile){
		cerr << "Error: file could not be opened. Check dir again!" << endl;
		exit(1);
	}
	while(infile.get(array[pos])){
		pos++;
	}
	for(int i=0;array[i]!='\0';i++){
		cout << array[i];
	}
	cout << endl;
	cout << "\t\t\t--Processing Decode--" << endl;
	infile2.open(FILE2);
	if(!infile2){
		cerr << "Error file could not be opened. Check dir again" << endl;
		exit(1);
	}
	while(infile2.get(c[pos1])){
		int j=2;
		do{
			j+=4;
		}while(c[pos1]!=array[j]);
		cout <<	array[j-2];
		pos1++;
	}
	cout << endl;
	cout << "\t\t\t--Message is decoded--!";
	cout << endl;
	infile.close();
	infile2.close();
	return 0;
}
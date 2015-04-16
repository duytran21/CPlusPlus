#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char letter;
	int number;
	float fnumber;
	ifstream inFile("input.txt");
	while(!inFile.eof()){
		inFile >> number >> letter  >> fnumber;
		cout << number << " " << letter << " " << fnumber << endl;	
	}
	cout << "Reading file complete!" << endl;
	inFile.close();
	return 0;
}
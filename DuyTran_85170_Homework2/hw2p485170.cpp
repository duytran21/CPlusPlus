#include <iostream>
#include <fstream>

using namespace std;

int main(){
	unsigned long eNumb;
	string fName,mName,lName;
	
	ofstream outfile("database85170.txt");
	cout << "\t----Input Data in file----" << endl;
	cout << "Enter Information of Employee, enter Employee's id = 0 to finish  :" << endl;
	//outfile <<"Employee's ID\t" << "First Name\t" << "Middle Name\t" << "Last Name" << "\n";
	do{
		cout<< "Employee's ID: "; cin >> eNumb;
		cin.ignore();
		if(eNumb==0)
			break;
		cout<< "First Name: ";
  		getline(cin,fName);//cin >> fName;
		cout<< "Middle Name: ";   
		getline(cin,mName);//cin >> mName;
		cout<< "Last Name: ";     
		getline(cin,lName);//cin >> lName;
			outfile << eNumb << " " << fName << " " << mName << " " << lName << "\n";
	}while(eNumb!=0);
	cout << "File written" << endl;
	outfile.close();
	cout << "\t-----Read File----" << endl;
	ifstream readfile("database85170.txt");
	while(readfile >> eNumb >> fName >> mName >> lName){
		cout << eNumb << " " << fName << " " << mName << " " << lName << "\n";
	}
	cout << "File read\n";
	readfile.close();
	return 0;	
}
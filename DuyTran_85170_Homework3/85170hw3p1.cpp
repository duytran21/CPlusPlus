#include <iostream>
using namespace std;
struct Date{
	int day;
	int month;
	int year;
};

int main(){
	Date d;
	string s;
	string x,y,z;
	char opt;
	size_t pos=0;
	do{
	cout << "Enter Date(mm/dd/yyyy): "; cin >> s; 
	pos=s.find('/');
	x=s.substr(0,pos);
	s.erase(0,pos+1);
	y=s.substr(0,pos);
	z=s.substr(pos+1,string::npos);
	d.month=atof(x.c_str());
	d.day=atof(y.c_str());
	d.year=atof(z.c_str());
		if(d.month > 13 || d.day > 31 ){
			cout << "Entered wrong date format! Do you want to continue(Y/N): ";
			cin >> opt;	
		}
		else{
			cout << "Date entered: " << d.month << "/" << d.day << "/" << d.year << endl;
			break;
		}
	}while(opt=='y'||opt=='Y');
	cout << "Thanks!" << endl;
	return 0;
}
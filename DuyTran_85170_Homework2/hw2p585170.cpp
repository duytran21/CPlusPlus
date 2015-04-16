#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	char op='c';
	string x,y;
	string s;
	string comp;
	size_t pos=0;
	
	while(op!='e'){
		cout << "What operation would you like to perform: add(+), subtract(-), divide(/), multiply(*), moderate(%), less than(<), greater than(>), [e]xit?";
		cin >> op;
		switch(op){
			case '+':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				cout << "Result is: " << atof(x.c_str())+atof(y.c_str()) << endl;
				
				 
	
				break;
			case '-':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				cout << "Result is: " << atof(x.c_str())-atof(y.c_str()) << endl;
				
				break;
			case '*':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				cout << "Result is: " << atof(x.c_str())*atof(y.c_str()) << endl;
				
				break;
			case '/':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				cout << "Result is: " << atof(x.c_str())/atof(y.c_str()) << endl;
				
				break;
			case '%':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				cout << "Result is: " << int(atof(x.c_str()))%int(atof(y.c_str())) << endl;
				
				break;
			case '<':
				
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				comp=(atof(x.c_str()) < atof(y.c_str())) ? "True" : "False";
				cout << "Result is: " << comp << endl;
				
				break;
			case '>':
				cout << "Enter expression: ";
				cin.ignore();
			 	getline(cin,s);
				pos=s.find(op);
				x=s.substr(0,pos);
				y=s.substr(pos+1,string::npos-1);
				comp=(atof(x.c_str()) > atof(y.c_str())) ? "True" : "False";
				cout << "Result is: " << comp << endl;
				
				break;		
			case 'e':
				return 0;
			default:
				cout << "Sorry, try again!" << endl;
		}
	}
	return 0;
}
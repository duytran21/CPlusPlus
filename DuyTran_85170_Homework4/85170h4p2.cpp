#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
const char FILE1[]="carparts.txt";
const int arrsize=14;
class CarPart{
	public:
		CarPart(){
			nameOfCar="";
			cost=0;
			serial="0";
			count++;
		};
		~CarPart(){};
		int getCount(){
			return count;
		}
		void setNameOfCar(string n){
			nameOfCar=n;
		}
		void setCost(double c){
			cost=c;
		}
		void setSerial(string s){
			serial=s;
		}
		string getNameOfCar() const{
			return nameOfCar;
		}
		double getCost() const{
			return cost;
		}
		string getSerial() const{
			return serial;
		}
		void showInfo() const{
			cout << nameOfCar << "\t\t" <<setprecision(2) << fixed << cost << "\t" << serial << endl;
		}
	private:
		string nameOfCar;
		double cost;
		string serial;
		static int count;
		
};

int CarPart::count=0;

int main(){
	string ss;
	string seri;
	string c[arrsize][arrsize];
	int i=0,j;
	int pos=0;
	ifstream readFile;
	readFile.open(FILE1);
	if(!readFile){
		cout <<"Error: file cannot be opened. Check Dir again!" << endl;
		exit(1);
	}	
	while(!readFile.eof()){
		getline(readFile,ss);
		istringstream is(ss);
		j=0;
		while(is){
			is >>c[i][j];
			j++;
		}
		i++;
	}
	CarPart *car=new CarPart[14];
	for(int m=0;m<14;m++){	
 		car[m];
		int n=0;
		double money;
		car[m].setNameOfCar(c[m][n]);
		stringstream(c[m][n+1]) >> money ;
		car[m].setCost(money);
	}
	for(int m=0;m<14;m++){
		cout << car[m].getNameOfCar() << "\t " << setprecision(2) << fixed << car[m].getCost() << endl;	
	}
	cout << "Now we have " << car[1].getCount() << " carparts!" << endl;
	cout << "*************************************************************************" << endl;
	int m=0;
	cout << "Enter the serial number for each carparts (enter serial num = 0 to finish)" << endl;
	do{
		cout << car[m].getNameOfCar() << "\t " << setprecision(2)<< fixed << car[m].getCost() << "\tSerial Number:";
		cin >> seri ;
		car[m].setSerial(seri);
		m++;		
	}while(car[m-1].getSerial()!="0"&&m<14);
	cout << "*************************************************************************" << endl;
	cout << "Name of Carpart \tCost \tSerial"<< endl;
	for (int n=0;n<14;n++){		
		car[n].showInfo();
	}
	return 0;
}
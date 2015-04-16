#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
class bMoney{
	private:
		long double money;
		long double mstold(string ms){
			ms.erase(0,1);
			ms.erase(remove(ms.begin(),ms.end(),','),ms.end());
			stringstream(ms) >> money;
			return money;
		};
		string ldtoms(long double ld){
			ostringstream sld;
		    sld << setprecision(2) << fixed << ld;	 
		    string integral = sld.str(), formatted = "", fractional;
		    int decimalLocation = integral.find('.');
		    fractional = integral.substr(decimalLocation);
		    integral = integral.substr(0 , decimalLocation);
		    int endstring = integral.length(), i;
		    for( i = endstring - 3; i >= 0; i -= 3){
		        if (i > 0) {
		           	formatted =  ","+ integral.substr(i, 3) + formatted ;
		        } 
				else{
		            formatted = integral.substr(i, 3) + formatted;
		        }      
		    }
		    if (i < 0){
		        formatted = "$"+integral.substr(0, 3+i) + formatted ;
		    }
		    return formatted+fractional;
		};
	public:
		bMoney(){
			money=0;
		};
		bMoney(char s[]);
		void madd(bMoney m1,bMoney m2){
			 long double sum = m1.getMoney()+m2.getMoney();
			 
			 cout << ldtoms(sum);
			
			
		};
		void getmoney(){
			cout << "Money Entered: " <<  ldtoms(money) << endl;	
			
		};
		long double getMoney(){
			return money;
		}
		void putmoney(){
			string smoney;
			cout << "Enter string money: "; cin >> smoney;
			money=mstold(smoney);
			
		};	
};

int main(){
	bMoney bM1,bM2,bM3;
	bM1.putmoney();
	bM1.getmoney();
	
	bM2.putmoney();
	bM2.getmoney();
	
	
	cout << "Total: ";
	bM3.madd(bM1,bM2);
	cout << endl;
	return 0;
}
#include <iostream>
using namespace std;
int main(){
	int numb;
	do
	{
		unsigned long fact=1;
		cout << "Enter a number(enter number 0 if you want to exit):";
		cin >> numb;
		if(numb>0){
			for(int j=numb; j>1; j--)
						fact*=j;	
			cout << "Factorial is " << fact << endl;
		}
		else if(numb<0&&numb!=0)
			cout << "Wrong number! User can't enter negative number" << endl;
	}while(numb!=0);
	cout << "Exit" << endl;
	return 0;
}	
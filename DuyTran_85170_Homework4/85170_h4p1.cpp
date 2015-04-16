#include <iostream>

using namespace std;
//const int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const int MONTH=12;

class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date(){
			int month=0;
			int day=0;
			int year=0;
		};
		~Date(){};
		
		void setDate(int mm,int dd,int yy){
			month=mm;
			day=dd;
			year=yy;
		}
		void setMonth(int mm){
			month=mm;
		}
		void setDay(int dd){
			day=dd;
		}
		void setYear(int yy){
			year=yy;
		}
		int getDay() const{
			return day;
		}
		int getMonth() const{
			return month;
		}
		int getYear() const{
			return year;
		}
		void getDate(){
			cout << "Enter Month: "; cin >> month;
			cout << "Enter Day: "; cin >> day;
			cout << "Enter Year: "; cin >> year;
			
		}
		
		void showDate() const{
			cout << "Date entered: " << month << "/" << day << "/" << year << endl;
		}
		//function sumofDate return total of day from January to Date you entered
		int sumOfDate(){
			int a[MONTH]={31,28,31,30,31,30,31,31,30,31,30,31}; //initial array to contain days of month.
			int sumD=0,sum=0;
			if(getYear()%4==0){
				a[1]=29;
				for(int i=0;i<getMonth()-1;i++){
					sum+=a[i];
				}
	 			sumD=sum+getDay();
			}	
			else{
				for(int i=0;i<getMonth()-1;i++){
					sum+=a[i];	
				}
				sumD=sum+getDay();
			}
			return sumD;
}
};

//int sumOfDate(Date d);
int calRemainDay(Date dob,Date cur);
int main(){
	Date dateOfBirth,curDate;
	cout << "\t----Enter Date of Birth----" << endl;
	dateOfBirth.getDate();
	dateOfBirth.showDate();
	cout << endl;
	cout << "\t----Enter Current Date----" << endl;
	curDate.getDate();
	curDate.showDate();
	int r=0;
	r=calRemainDay(dateOfBirth,curDate);
	if(r==0)
		cout << "Today is your birthday!" << endl;
	else
		cout << " Number of days before next your birthday: "<<  r << endl;
//	cout << "Sum of Date: " << t << endl;
	return 0;
}
//function calRemainDay calculates the remain day for next birthday.
int calRemainDay(Date dob,Date cur){
	int rDay=0;	//remain Day hold value of Day next birthday
	if(cur.getMonth()<=dob.getMonth()){
		rDay=dob.sumOfDate()-cur.sumOfDate();	
	}
	else{
		rDay=365-cur.sumOfDate()+dob.sumOfDate();
	}
	
	return rDay;
}


/*int sumOfDate(Date d){
	int a[MONTH]={31,28,31,30,31,30,31,31,30,31,30,31};
	int sumD=0,sum=0;
	if(d.getYear()%4==0){
		a[1]=29;
		for(int i=0;i<d.getMonth()-1;i++){
			sum+=a[i];
		}
	 	sumD=sum+d.getDay();
	}	
	else{
		for(int i=0;i<d.getMonth()-1;i++){
			sum+=a[i];	
		}
		sumD=sum+d.getDay();
	}
	return sumD;
}*/
/*string s,x,y,z;
			int pos=0;
			cout << "Enter Date of Birth(mm/dd/yy): "; cin >> s; 
			pos=s.find('/');
			x=s.substr(0,pos);
			s.erase(0,pos+1);
			y=s.substr(0,pos);
			z=s.substr(pos+1,string::npos);
			month=(int)atof(x.c_str());
			day=(int)atof(y.c_str());
			year=(int)atof(z.c_str());*/
/*void getCurrentDate(){
			cout << "Enter Month: "; cin >> month;
			cout << "Enter Day: "; cin >> day;
			cout << "Enter Year: "; cin >> year;
			string s,x,y,z;
			int pos=0;
			cout << "Enter Current Date(mm/dd/yy): "; cin >> s; 
			pos=s.find('/');
			x=s.substr(0,pos);
			s.erase(0,pos+1);
			y=s.substr(0,pos);
			z=s.substr(pos+1,string::npos);
			month=(int)atof(x.c_str());
			day=(int)atof(y.c_str());
			year=(int)atof(z.c_str());
		}*/
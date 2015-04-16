#include <iostream>
#include <sstream>
#include <ctime>
#include <stdlib.h>
using namespace std;
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
			string sDate="";
			cout << "Enter Date with format mm/dd/yy: "; cin >> sDate;
			string sYear="",sDay="",sMonth="";
			sMonth=sDate.substr(0,2);
			sDay=sDate.substr(3,2);
			sYear=sDate.substr(6,2);
			month=atoi(sMonth.c_str());
			day=atoi(sDay.c_str());
			if(month<=0||month>12||day>31){
				cout << "Enter Wrong date!" << endl;
				exit(1);
			}
			else{
				int temp=0;
				temp=atoi(sYear.c_str());
				if(temp>=0&&temp<15){
					sYear="20"+sYear;
				}
				if(temp>=15){
					sYear="19"+sYear;
				}
			}
			year=atoi(sYear.c_str());
		}
		
		void showDate(){
			stringstream sY,sD,sM;
			sY << year;
			sD << day;
			sM << month;
			string sYear,sDay,sMonth;
			sYear=sY.str();
		 	sYear=sYear.substr(2,2);
		 	sDay=sD.str();
		 	if(day>=1&&day<=9){
		 		sDay="0"+sDay;
		 	}
		 	sMonth=sM.str();
		 	if(month>=1&&month<=9){
		 		sMonth="0"+sMonth;
		 	}
			cout << "Date entered: " << sMonth << "/" << sDay << "/" << sYear << endl;
		}

};
//function sumofDate return total of day from January 1st to Date you entered
int sumOfDate(Date d);
int calRemainDay(Date dob);
int calAge(Date dob);
int getYearNow();
int getMonthNow();
int getDayNow();
int sumOfDateNow();
int main(){
	Date dateOfBirth;
	cout << "\t----Enter Date of Birth----" << endl;
	dateOfBirth.getDate();
	dateOfBirth.showDate();
	cout << endl;
	cout << "Now you are " << calAge(dateOfBirth) << " years old" << endl;
	int r=0;
	r=calRemainDay(dateOfBirth);
	if(r==0)
		cout << "Today is your birthday!" << endl;
	else
		cout << " Number of days before your next birthday: "<<  r << endl;
	return 0;
}
//function calRemainDay calculates the remain day for next birthday.
int calRemainDay(Date dob){
	int rDay=0;		
	if(getMonthNow()<=dob.getMonth()){
		rDay=sumOfDate(dob)-sumOfDateNow();	
	}
	else{
		rDay=365-sumOfDateNow()+sumOfDate(dob);
	}
	
	return rDay;
}
int calAge(Date dob){
	int age;
	age=getYearNow()-dob.getYear();
	return age;
}
int getMonthNow(){
	int mNow=0;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	mNow=1+ltm->tm_mon;
	return mNow;	
}
int getDayNow(){
	int dNow=0;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	dNow=ltm->tm_mday;
	return dNow;	
}
int getYearNow(){
	int yNow=0;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	yNow=1900+ltm->tm_year;
	return yNow;	
}
int sumOfDateNow(){
	int sumD=0;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	sumD=1+ltm->tm_yday;
	return sumD;	
}
int sumOfDate(Date d){
			int a[MONTH]={31,28,31,30,31,30,31,31,30,31,30,31}; //initial array to contain days per month.
			int sumD=0,sum=0;
			if(getYearNow()%4==0){
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
}
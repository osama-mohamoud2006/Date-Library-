#include "clsDate.h";
#include<iostream>
using namespace std;
struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};



stdate CURRENTLOCALTIME()
{
    stdate date;
    time_t epoch_time = time(0);
    tm *date_now = localtime(&epoch_time);
    // d/ m/ y --> 3/9/2025
    date.d = date_now->tm_mday;
    date.m = (date_now->tm_mon) + 1;
    date.y = (date_now->tm_year) + 1900;
    return date;
};
int main() {
//     clsDate d1(12352,2,2025);
//     cout<<d1.FullDate()<<endl;
// d1.DateAfterNumOfDays(325);
//     cout<<d1.FullDate()<<endl;

    clsDate d2(325,2025);

    //cout<<d2.FullDate()<<endl;

    // clsDate::DateAfterNumOfDays(325,2025);
    // cout << clsDate::fullDate()<<endl ;

//     clsDate d4(21,11,2025);
// d4.dateAfterAddingOneDay( );
//     cout<<d4.FullDate();

    // stdate DATETODAY = CURRENTLOCALTIME();
    // cout<<DATETODAY.d<<" / "<<DATETODAY.m<<" / "<<DATETODAY.y<<endl;
    clsDate MYBIRTHDAY (1,8,2006);
    clsDate d6(21,11,2025);
    cout<<"Date 6 is: "<<d6.FullDate()<<endl;
    cout<<"Birthday is: "<<MYBIRTHDAY.FullDate()<<endl;
    cout<<"So i lived for: "<<d6.yourAgeInDays(MYBIRTHDAY)<<endl; 

    clsDate d7;
    cout<<d7.FullDate()<<endl;



}




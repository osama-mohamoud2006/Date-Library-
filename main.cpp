#include "clsDate.h";
#include<iostream>
using namespace std;

int main() {
//     clsDate d1(12352,2,2025);
//     cout<<d1.FullDate()<<endl;
// d1.DateAfterNumOfDays(325);
//     cout<<d1.FullDate()<<endl;

    // clsDate d2(325,2025);

    //cout<<d2.FullDate()<<endl;

    // clsDate::DateAfterNumOfDays(325,2025);
    // cout << clsDate::fullDate()<<endl ;

//     clsDate d4(21,11,2025);
// d4.dateAfterAddingOneDay( );
//     cout<<d4.FullDate();


    //clsDate MYBIRTHDAY (1,8,2006);
   // clsDate d6(3,10,2000);

    // cout<<"Birthday is: "<<MYBIRTHDAY.FullDate()<<endl;
    // cout<<"So i lived for: "<<d6.yourAgeInDays(MYBIRTHDAY)<<endl;

   // clsDate d1 = clsDate::GetCurrentLocalDate();

    // clsDate d2 ;// call the conctructor
    // d2 = clsDate::AddDaysToDate(d2,2); // make temp effect on object
    //
    // cout<<d2.FullDate()<<endl; //

 // أنت عايز بس "تعرف" التاريخ، مش عايز تغير تاريخ ميلادك الحقيقي

//
//     clsDate d7;
//     cout<<"The Date1 before swap: "<<d7.FullDate()<<endl;
//     cout<<"Date before swap  is: "<<d6.FullDate()<<endl;
//
// clsDate::swapDates(d7,d6);
// cout<<"\n__________________\n";
//     cout<<"The Date1 after swap: "<<d7.FullDate()<<endl;
//     cout<<"Date after swap  is: "<<d6.FullDate()<<endl;
    //
    //
    // clsDate d = clsDate(325,2025);
    // cout<<d.FullDate()<<endl;
    // d.dateAfterAddingOneDay();
    // cout<<d.FullDate()<<endl;
    //  clsDate d6(3,10,2000);
    // cout<< "The diff is: "<<d.DiffBetween2DatesInDays(d6 );
// clsDate d4;
//   clsDate::AddOneWeek(d4);
//         cout<< clsDate::PrintFullDateForStatic(d4)<<endl;
   // d4.AddOneWeek();

   // clsDate::AddOneMonth(d4);
    //cout<<clsDate::PrintFullDateForStatic(d4)<<endl;


clsDate d1 ;
    d1= clsDate::DecreaseXYears(2,d1);
    cout<<d1.FullDate()<<endl;







    //cout<< clsDate::PrintFullDateForStatic(clsDate::AddXdays(2,d4));



}




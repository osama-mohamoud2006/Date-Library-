#include "clsDate.h";
#include<iostream>
using namespace std;
int main() {
//     clsDate d1(12352,2,2025);
//     cout<<d1.FullDate()<<endl;
// d1.DateAfterNumOfDays(325);
//     cout<<d1.FullDate()<<endl;

    clsDate d2(325,2025);

    //cout<<d2.FullDate()<<endl;

    // clsDate::DateAfterNumOfDays(325,2025);
    // cout << clsDate::fullDate()<<endl ;

    clsDate d4(21,11,2025);
d4.dateAfterAddingOneDay( );
    cout<<d4.FullDate();

}
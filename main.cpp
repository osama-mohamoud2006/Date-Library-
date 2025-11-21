#include "clsDate.h";
#include<iostream>
using namespace std;
int main() {
    clsDate d1(12352,2,2025);
    cout<<d1.FullDate()<<endl;
d1.DateAfterNumOfDays(325);
    cout<<d1.FullDate()<<endl;



}
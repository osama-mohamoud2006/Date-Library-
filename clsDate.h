#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace  std;
// Abstract class(contract)
class clsDateFunctions {
    virtual string numberToText(int num)=0;
    virtual  bool isLeap(short y)=0;
    virtual short numberOFDays(short y)=0;
    virtual int numberOfHours(short y)=0;
    virtual  int numberOfMin(int y)=0;
    virtual int numberOfSeconds(int y)=0;
    virtual  short NumberOfDaysInMonth(short y, short m)=0;
    virtual  int hoursInMonth(short y, short m)=0;
    virtual  int MinInMonth(short y, short m)=0;
    virtual  int secondsInMonth(short y, short m)=0;
     virtual string FullDate(short y, short m, short d)=0;
    virtual short DayOrder(short year, short month, short day)=0;
    virtual  string DayName(short dayOrder )=0;
     virtual string monthName(short m)=0;
     virtual void printMonthCalnder(short m, short y)=0;
     virtual void PrintYearCalnder(short y)=0;
    virtual int TotalDaysSinceTheD(short y, short m, short d)=0;
    virtual short DayUntillDate(short y, short m, short d)=0;
  virtual void DateAfterNumOfDays(short NOdayUntillDate)=0;



};

class clsDate : private clsDateFunctions  {
private:
    short y ;
    short m;
    short d;

public:
    clsDate(short d , short m , short y) {
        if (d>NumberOfDaysInMonth(y,m)) d=NumberOfDaysInMonth(y,m); // if user entered day bigger than actual days in month
        this->d=d;
        this->m=m;
        this->y=y;
    }
    clsDate() {

    }
    void GetFullDate(){}
//p1
    string numberToText(int num)
    {
        if (num == 0)
            return "";
        if (num >= 1 && num <= 19)
        {
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thriteen", "fourteen", "fivety", "sixteen", "seventeen", "eigtheen", "ninetheen"};

            return arr[num] + " ";
        }

        if (num >= 20 && num <= 99) //(20,30,40,50,60,70,80,90)
        {
            // 33 --> 30+3 --> 30->(20-90) , 3-->(1-19)
            string arr[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

            return arr[num / 10] + " " + numberToText(num % 10);
        }

        if (num >= 100 && num <= 1000)
        {
            // 125 --> 100+25
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

            return arr[num / 100] + " hundered " + numberToText(num % 100);
        }

        if (num >= 1000 && num <= 10000)
        {
            // 2500 --> 2000+500
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            return arr[num/1000]+" thousand "+numberToText(num%1000);
        }
    }

//p2||3
    bool isLeap(short y)
    {
        // if it divided by 400 --> leap
        // if it divided by 4 And not divided by 100 --> leap
        return ((y % 400 == 0)|| (y%4==0 && y%100!=0) );
    }

// 4
    short numberOFDays(short y)
    {
        return (isLeap(y) == true) ? 366 : 365;
    } // number of days  in year

    int numberOfHours(short y)
    {
        return 24 * numberOFDays(y);
    }

    int numberOfMin(int y)
    {
        return numberOfHours(y) * 60;
    }

    int numberOfSeconds(int y)
    {
        return numberOfMin(y) * 60;
    }

    //5 &6
    short NumberOfDaysInMonth(short y, short m){

        if (m<1 || 12<m) return 0;
        // return (m==2)?((isLeap(y)==true)?  29 : 28) : (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) ? 31 : 30;

        short arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        return  (m==2)?((isLeap(y)==true)?  29 : 28):arr[m];
    }

    int hoursInMonth(short y, short m)
    {
        return 24 * NumberOfDaysInMonth(y, m);
    }

    int MinInMonth(short y, short m)
    {
        return 60 * hoursInMonth(y, m);
    }

    int secondsInMonth(short y, short m)
    {
        return MinInMonth(y, m) * 60;
    }

    //7
    string FullDate(short y, short m, short d)
    {
        return (to_string(d) + "/" + to_string(m) + "/" + to_string(y));
    }

    string FullDate( )
    {
        return (to_string(d) + "/" + to_string(m) + "/" + to_string(y));
    }

    short DayOrder(short year, short month, short day)
    {
        short a = ((14 - month) / 12);
        short y = year - a;
        short m = month + 12 * a - 2;

        return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
    }

    string DayName(short dayOrder )
    {
        string Day[]={"sun","mon","tue","wed","thu","fri","sat"};
        return Day[dayOrder];
    }

 //8 & 9
    string monthName(short m)
    {
        string month[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "agu", "sep", "oct", "nov", "dec"};
        return month[m - 1];
    }

    void printMonthCalnder(short m, short y)
    {
        int theLastDayInMonth = NumberOfDaysInMonth(y, m); // the last day
        int currentDay = DayOrder(y, m, 1);

        cout << "\n______________" << monthName(m) << "______________" << endl;

        printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int i = 0; i < currentDay; i++)
        {
            printf("     ");
        }

        for (int d = 1; d <= theLastDayInMonth; d++)
        {
            printf("%4d ", d);
            if ((d + currentDay) % 7 == 0)
                printf("\n");
        }
        printf("\n");

    }

    void PrintYearCalnder(short y)
    {
        for (short i = 1; i <= 12; i++)
        {
            printMonthCalnder(i,y); // print the month
            cout<<endl;
        }

    }

    //10
    int TotalDaysSinceTheD(short y, short m, short d)
    {
        int totalDaysInMonths = 0;

        for (int i = 1; i <= m-1; i++)
        {
            totalDaysInMonths += NumberOfDaysInMonth(y, i); // count the total days untill the current month
        }

        // int the_rest_days_in_month = NumberOfDaysInMonth(y, m) - d;

        return totalDaysInMonths += d;
    } //Number of days from begining of the year is

//11
    short DayUntillDate(short y, short m, short d)
    {
        short totalDays = 0;

        for (short i = 1; i <= m - 1; i++)
        {
            totalDays += NumberOfDaysInMonth(y, i);
        }
        return totalDays + d;
    }

    void DateAfterNumOfDays(short NOdayUntillDate)
    {
        // NOdayUntillDate is the number of days from 1/1 untill your day
        short y =this->y;

      // the year

        short RemainingDays = NOdayUntillDate; // will increment it to get the no.of days
        short m = 1;
        while (true)
        {
            short monthDays = NumberOfDaysInMonth(y, m); // the num of days in month

            if (RemainingDays > monthDays)
            {
                RemainingDays -= monthDays;
                m++;
            }
            else
            {
                this->m = m;
                this->d = RemainingDays;
                break;
            }
        }

    }



};



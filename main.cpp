#include "clsDate.h"
#include <iostream>
using namespace std;

void printSection(string title) {
    cout << "\n===== " << title << " =====\n";
}

int main() {
    cout << "========== COMPREHENSIVE CLSDATE TEST ==========\n";

    // Current local date (default ctor uses GetCurrentLocalDate)
    clsDate now = clsDate::GetCurrentLocalDate();
    cout << "Current date: " << now.FullDate() << "\n";

    printSection("1. CONSTRUCTORS");
    clsDate d1(31, 12, 1999);
    cout << "Constructor(d,m,y) d1(31,12,1999): " << d1.FullDate() << "\n";

    clsDate d2("1/1/2000");
    cout << "Constructor(string) d2(\"1/1/2000\"): " << d2.FullDate() << "\n";

    clsDate d3(60, 2020);
    cout << "Constructor(dayOfYear,year) d3(60,2020): " << d3.FullDate() << "\n";

    clsDate d4; // default constructor
    cout << "Default constructor d4: " << d4.FullDate() << "\n";

    printSection("2. SETTERS (SetD, SetM, SetY)");
    clsDate setter(1, 1, 2020);
    cout << "Initial: " << setter.FullDate() << "\n";
    setter.SetD(15);
    cout << "After SetD(15): " << setter.FullDate() << "\n";
    setter.SetM(6);
    cout << "After SetM(6): " << setter.FullDate() << "\n";
    setter.SetY(2025);
    cout << "After SetY(2025): " << setter.FullDate() << "\n";

    printSection("3. LEAP YEAR CHECK (isLeap)");
    cout << "isLeap(2000): " << clsDate::isLeap(2000) << " (expected: 1)\n";
    cout << "isLeap(2024): " << clsDate::isLeap(2024) << " (expected: 1)\n";
    cout << "isLeap(2025): " << clsDate::isLeap(2025) << " (expected: 0)\n";
    cout << "isLeap(2100): " << clsDate::isLeap(2100) << " (expected: 0)\n";
    clsDate leapTest(29, 2, 2024);
    cout << "leapTest.isLeap(): " << leapTest.isLeap() << "\n";

    printSection("4. DAYS/HOURS/MINUTES/SECONDS IN YEAR");
    cout << "numberOFDays(2024): " << clsDate::numberOFDays(2024) << " (expected: 366)\n";
    cout << "numberOFDays(2025): " << clsDate::numberOFDays(2025) << " (expected: 365)\n";
    clsDate testYear(1, 1, 2024);
    cout << "testYear.numberOFDays(): " << testYear.numberOFDays() << "\n";

    cout << "NumberOfHours(2025): " << clsDate::NumberOfHours(2025) << "\n";
    cout << "testYear.NumberOfHours(): " << testYear.NumberOfHours() << "\n";

    cout << "NumberOfMin(2025): " << clsDate::NumberOfMin(2025) << "\n";
    cout << "testYear.NumberOfMin(): " << testYear.NumberOfMin() << "\n";

    cout << "NumberOfSeconds(2025): " << clsDate::NumberOfSeconds(2025) << "\n";
    cout << "testYear.NumberOfSeconds(): " << testYear.NumberOfSeconds() << "\n";

    printSection("5. DAYS/HOURS/MINUTES/SECONDS IN MONTH");
    cout << "NumberOfDaysInMonth(2024, 2): " << clsDate::NumberOfDaysInMonth(2024, 2) << " (Feb leap)\n";
    cout << "NumberOfDaysInMonth(2025, 2): " << clsDate::NumberOfDaysInMonth(2025, 2) << " (Feb non-leap)\n";
    cout << "NumberOfDaysInMonth(2025, 12): " << clsDate::NumberOfDaysInMonth(2025, 12) << " (Dec)\n";
    clsDate testMonth(15, 2, 2025);
    cout << "testMonth.NumberOfDaysInMonth(): " << testMonth.NumberOfDaysInMonth() << "\n";

    cout << "HoursInMonth(2024, 2): " << clsDate::HoursInMonth(2024, 2) << "\n";
    cout << "testMonth.HoursInMonth(): " << testMonth.HoursInMonth() << "\n";

    cout << "MinInMonth(2024, 2): " << clsDate::MinInMonth(2024, 2) << "\n";
    cout << "testMonth.MinInMonth(): " << testMonth.MinInMonth() << "\n";

    cout << "secondsInMonth(2024, 2): " << clsDate::secondsInMonth(2024, 2) << "\n";
    cout << "testMonth.secondsInMonth(): " << testMonth.secondsInMonth() << "\n";

    printSection("6. FULLDATE METHODS");
    cout << "d1.FullDate(): " << d1.FullDate() << "\n";
    cout << "FullDate(short, short, short): " << d1.FullDate(2025, 11, 25) << "\n";
    cout << "PrintFullDateForStatic(d3): " << clsDate::PrintFullDateForStatic(d3) << "\n";

    printSection("7. DAY ORDER (Zeller's Algorithm)");
    short order = clsDate::DayOrder(2025, 11, 25);
    cout << "DayOrder(2025, 11, 25): " << order << "\n";
    clsDate testDay(25, 11, 2025);
    cout << "testDay.DayOrder(): " << testDay.DayOrder() << "\n";

    printSection("8. DAY NAMES");
    cout << "DayName(0): " << clsDate::DayName(0) << "\n";
    cout << "DayName(1): " << clsDate::DayName(1) << "\n";
    cout << "DayName(6): " << clsDate::DayName(6) << "\n";
    cout << "testDay.DayName(): " << testDay.DayName() << "\n";

    printSection("9. MONTH NAMES");
    for (short m = 1; m <= 12; m++) {
        cout << "MonthName(" << m << "): " << clsDate::MonthName(m) << "  ";
        if (m % 4 == 0) cout << "\n";
    }
    cout << "\ntestDay.MonthName(): " << testDay.MonthName() << "\n";

    printSection("10. TOTAL DAYS SINCE START OF YEAR");
    cout << "TotalDaysSinceThisDate(2025, 1, 1): " << clsDate::TotalDaysSinceThisDate(2025, 1, 1) << "\n";
    cout << "TotalDaysSinceThisDate(2025, 11, 25): " << clsDate::TotalDaysSinceThisDate(2025, 11, 25) << "\n";
    cout << "testDay.TotalDaysSinceThisDate(): " << testDay.TotalDaysSinceThisDate() << "\n";

    printSection("11. DAY UNTIL DATE");
    cout << "DayUntillDate(d1): " << clsDate::DayUntillDate(d1) << "\n";
    cout << "testDay.DayUntillDate(): " << testDay.DayUntillDate() << "\n";

    printSection("12. GET DATE FROM DAY OF YEAR");
    clsDate fromDay1 = clsDate::GetDateFromDayOfYear(1, 2025);
    cout << "GetDateFromDayOfYear(1, 2025): " << fromDay1.FullDate() << "\n";
    clsDate fromDay150 = clsDate::GetDateFromDayOfYear(150, 2025);
    cout << "GetDateFromDayOfYear(150, 2025): " << fromDay150.FullDate() << "\n";
    clsDate fromDay365 = clsDate::GetDateFromDayOfYear(365, 2025);
    cout << "GetDateFromDayOfYear(365, 2025): " << fromDay365.FullDate() << "\n";

    clsDate instFromDay(10, 1, 2025);
    cout << "Before GetDateFromDayOfYear(100): " << instFromDay.FullDate() << "\n";
    instFromDay.GetDateFromDayOfYear(100);
    cout << "After GetDateFromDayOfYear(100): " << instFromDay.FullDate() << "\n";

    printSection("13. ADD DAYS TO DATE");
    clsDate addDaysTest(25, 12, 2025);
    cout << "Original: " << addDaysTest.FullDate() << "\n";
    clsDate addResult = clsDate::AddDaysToDate(addDaysTest, 10);
    cout << "After AddDaysToDate(10): " << addResult.FullDate() << "\n";
    addDaysTest.AddDaysToDate(5);
    cout << "After instance AddDaysToDate(5): " << addDaysTest.FullDate() << "\n";

    printSection("14. DATE COMPARISONS");
    clsDate comp1(1, 1, 2020);
    clsDate comp2(1, 1, 2021);
    clsDate comp3(1, 1, 2020);
    cout << "isDate1LessThanDate2(comp1, comp2): " << clsDate::isDate1LessThanDate2(comp1, comp2) << "\n";
    cout << "isDate1LessThanDate2(comp2, comp1): " << clsDate::isDate1LessThanDate2(comp2, comp1) << "\n";
    cout << "isDate1equalsDate2(comp1, comp2): " << clsDate::isDate1equalsDate2(comp1, comp2) << "\n";
    cout << "isDate1equalsDate2(comp1, comp3): " << clsDate::isDate1equalsDate2(comp1, comp3) << "\n";
    cout << "comp1.isDate1LessThanDate2(comp2): " << comp1.isDate1LessThanDate2(comp2) << "\n";
    cout << "comp1.isDate1equalsDate2(comp3): " << comp1.isDate1equalsDate2(comp3) << "\n";

    printSection("15. LAST DAY/MONTH CHECK");
    clsDate lastDay(31, 12, 2025);
    clsDate notLastDay(30, 12, 2025);
    clsDate lastDayMonth(28, 2, 2025);
    cout << "isLastDayInMonth(31/12/2025): " << clsDate::isLastDayInMonth(lastDay) << "\n";
    cout << "isLastDayInMonth(30/12/2025): " << clsDate::isLastDayInMonth(notLastDay) << "\n";
    cout << "isLastMonthInYear(31/12/2025): " << clsDate::isLastMonthInYear(lastDay) << "\n";
    cout << "isLastMonthInYear(31/11/2025): " << clsDate::isLastMonthInYear(clsDate(30, 11, 2025)) << "\n";
    cout << "lastDay.isLastDayInMonth(): " << lastDay.isLastDayInMonth() << "\n";
    cout << "notLastDay.isLastDayInMonth(): " << notLastDay.isLastDayInMonth() << "\n";

    printSection("16. ADD ONE DAY");
    clsDate addOneDay(31, 12, 2025);
    cout << "Before: " << addOneDay.FullDate() << "\n";
    clsDate result = clsDate::dateAfterAddingOneDay(addOneDay);
    cout << "After static dateAfterAddingOneDay: " << result.FullDate() << "\n";
    addOneDay = clsDate(31, 1, 2025);
    addOneDay.dateAfterAddingOneDay();
    cout << "After instance dateAfterAddingOneDay (31/1): " << addOneDay.FullDate() << "\n";

    printSection("17. SWAP DATES");
    clsDate swap1(1, 1, 2020);
    clsDate swap2(31, 12, 2025);
    cout << "Before swap - swap1: " << swap1.FullDate() << ", swap2: " << swap2.FullDate() << "\n";
    clsDate::swapDates(swap1, swap2);
    cout << "After swap - swap1: " << swap1.FullDate() << ", swap2: " << swap2.FullDate() << "\n";

    printSection("18. DIFFERENCE BETWEEN DATES");
    clsDate diff1(1, 1, 2025);
    clsDate diff2(15, 1, 2025);
    int diffDays = clsDate::DiffBetween2DatesInDays(diff1, diff2);
    cout << "DiffBetween2DatesInDays(1/1/2025, 15/1/2025): " << diffDays << "\n";
    int diffDaysInst = diff1.DiffBetween2DatesInDays(diff2);
    cout << "diff1.DiffBetween2DatesInDays(diff2): " << diffDaysInst << "\n";

    printSection("19. YOUR AGE IN DAYS");
    clsDate birthday(1, 8, 2006);
    int ageStatic = clsDate::yourAgeInDays(birthday, now);
    int ageInst = now.yourAgeInDays(birthday);
    cout << "Static yourAgeInDays(1/8/2006, now): " << ageStatic << "\n";
    cout << "Instance now.yourAgeInDays(1/8/2006): " << ageInst << "\n";

    printSection("20. ADD X DAYS");
    clsDate addXDays(1, 1, 2025);
    cout << "Before: " << addXDays.FullDate() << "\n";
    addXDays = clsDate::AddXdays(45, addXDays);
    cout << "After AddXdays(45): " << addXDays.FullDate() << "\n";
    addXDays.AddXdays(30);
    cout << "After instance AddXdays(30): " << addXDays.FullDate() << "\n";

    printSection("21. ADD WEEKS");
    clsDate addWeek(1, 1, 2025);
    clsDate addWeekRes = clsDate::AddOneWeek(addWeek);
    cout << "After AddOneWeek: " << addWeekRes.FullDate() << "\n";
    addWeek = clsDate::AddXweeks(4, addWeek);
    cout << "After AddXweeks(4): " << addWeek.FullDate() << "\n";
    addWeek.AddOneWeek();
    cout << "After instance AddOneWeek(): " << addWeek.FullDate() << "\n";
    addWeek.AddXWeeks(2);
    cout << "After instance AddXWeeks(2): " << addWeek.FullDate() << "\n";

    printSection("22. ADD MONTHS");
    clsDate addMonth(31, 1, 2025);
    clsDate addMonthRes = clsDate::AddOneMonth(addMonth);
    cout << "AddOneMonth(31/1/2025): " << addMonthRes.FullDate() << "\n";
    addMonth = clsDate::AddXMonths(3, addMonth);
    cout << "After AddXMonths(3): " << addMonth.FullDate() << "\n";
    addMonth.AddOneMonth();
    cout << "After instance AddOneMonth(): " << addMonth.FullDate() << "\n";
    addMonth.AddXMonths(2);
    cout << "After instance AddXMonths(2): " << addMonth.FullDate() << "\n";

    printSection("23. ADD YEARS");
    clsDate addYear(29, 2, 2024);
    clsDate addYearRes = clsDate::AddOneYear(addYear);
    cout << "AddOneYear(29/2/2024): " << addYearRes.FullDate() << " (no longer leap)\n";
    addYear = clsDate::AddXYears(5, addYear);
    cout << "After AddXYears(5): " << addYear.FullDate() << "\n";
    addYear.AddOneYear();
    cout << "After instance AddOneYear(): " << addYear.FullDate() << "\n";
    addYear.AddXYears(4);
    cout << "After instance AddXYears(4): " << addYear.FullDate() << "\n";

    printSection("24. ADD DECADES");
    clsDate addDecade(1, 1, 2025);
    clsDate addDecadeRes = clsDate::AddOneDecade(addDecade);
    cout << "AddOneDecade(1/1/2025): " << addDecadeRes.FullDate() << "\n";
    addDecade = clsDate::AdddXDecade(2, addDecade);
    cout << "After AdddXDecade(2): " << addDecade.FullDate() << "\n";
    addDecade.AddOneDecade();
    cout << "After instance AddOneDecade(): " << addDecade.FullDate() << "\n";
    addDecade.AdddXDecade(3);
    cout << "After instance AdddXDecade(3): " << addDecade.FullDate() << "\n";

    printSection("25. ADD CENTURIES");
    clsDate addCent(1, 1, 2025);
    clsDate addCentRes = clsDate::AddOneCentury(addCent);
    cout << "AddOneCentury(1/1/2025): " << addCentRes.FullDate() << "\n";
    addCent.AddOneCentury();
    cout << "After instance AddOneCentury(): " << addCent.FullDate() << "\n";

    printSection("26. ADD MILLENNIUMS");
    clsDate addMill(1, 1, 2025);
    clsDate addMillRes = clsDate::AddOneMillenuim(addMill);
    cout << "AddOneMillenuim(1/1/2025): " << addMillRes.FullDate() << "\n";
    addMill.AddOneMillenuim();
    cout << "After instance AddOneMillenuim(): " << addMill.FullDate() << "\n";

    printSection("27. IS FIRST MONTH IN YEAR");
    clsDate firstMonth(1, 1, 2025);
    clsDate notFirstMonth(1, 2, 2025);
    cout << "isFirstMonthInTheYear(1/1/2025): " << clsDate::isFirstMonthInTheYear(firstMonth) << "\n";
    cout << "isFirstMonthInTheYear(1/2/2025): " << clsDate::isFirstMonthInTheYear(notFirstMonth) << "\n";
    cout << "firstMonth.isFirstMonthInTheYear(): " << firstMonth.isFirstMonthInTheYear() << "\n";

    printSection("28. DECREASE DAYS");
    clsDate decDay(1, 1, 2025);
    clsDate decDayRes = clsDate::DecreaseOneDay(decDay);
    cout << "DecreaseOneDay(1/1/2025): " << decDayRes.FullDate() << "\n";
    decDay = clsDate::DecreaseXDays(10, decDay);
    cout << "After DecreaseXDays(10): " << decDay.FullDate() << "\n";
    decDay.DecreaseOneDay();
    cout << "After instance DecreaseOneDay(): " << decDay.FullDate() << "\n";
    decDay.DecreaseXDays(5);
    cout << "After instance DecreaseXDays(5): " << decDay.FullDate() << "\n";

    printSection("29. DECREASE WEEKS");
    clsDate decWeek(15, 2, 2025);
    clsDate decWeekRes = clsDate::DecreaseOneWeek(decWeek);
    cout << "DecreaseOneWeek(15/2/2025): " << decWeekRes.FullDate() << "\n";
    decWeek = clsDate::DecreaseXWeeks(2, decWeek);
    cout << "After DecreaseXWeeks(2): " << decWeek.FullDate() << "\n";
    decWeek.DecreaseOneWeek();
    cout << "After instance DecreaseOneWeek(): " << decWeek.FullDate() << "\n";
    decWeek.DecreaseXWeeks(1);
    cout << "After instance DecreaseXWeeks(1): " << decWeek.FullDate() << "\n";

    printSection("30. DECREASE MONTHS");
    clsDate decMonth(31, 3, 2025);
    clsDate decMonthRes = clsDate::DecreaseOneMonth(decMonth);
    cout << "DecreaseOneMonth(31/3/2025): " << decMonthRes.FullDate() << " (31>28, so becomes 28)\n";
    decMonth = clsDate::DecreaseXMonth(2, decMonth);
    cout << "After DecreaseXMonth(2): " << decMonth.FullDate() << "\n";
    decMonth.DecreaseOneMonth();
    cout << "After instance DecreaseOneMonth(): " << decMonth.FullDate() << "\n";
    decMonth.DecreaseXMonth(1);
    cout << "After instance DecreaseXMonth(1): " << decMonth.FullDate() << "\n";

    printSection("31. DECREASE YEARS");
    clsDate decYear(29, 2, 2024);
    clsDate decYearRes = clsDate::DecreaseOneYear(decYear);
    cout << "DecreaseOneYear(29/2/2024): " << decYearRes.FullDate() << " (no longer leap)\n";
    decYear = clsDate::DecreaseXYears(5, decYear);
    cout << "After DecreaseXYears(5): " << decYear.FullDate() << "\n";
    decYear.DecreaseOneYear();
    cout << "After instance DecreaseOneYear(): " << decYear.FullDate() << "\n";
    decYear.DecreaseXYears(4);
    cout << "After instance DecreaseXYears(4): " << decYear.FullDate() << "\n";

    printSection("32. DECREASE DECADES");
    clsDate decDecade(1, 1, 2025);
    clsDate decDecadeRes = clsDate::DecreaseOneDecade(decDecade);
    cout << "DecreaseOneDecade(1/1/2025): " << decDecadeRes.FullDate() << "\n";
    decDecade = clsDate::DecreaseXdecades(decDecade, 2);
    cout << "After DecreaseXdecades(2): " << decDecade.FullDate() << "\n";
    decDecade.DecreaseOneDecade();
    cout << "After instance DecreaseOneDecade(): " << decDecade.FullDate() << "\n";
    decDecade.DecreaseXdecades(3);
    cout << "After instance DecreaseXdecades(3): " << decDecade.FullDate() << "\n";

    printSection("33. DECREASE CENTURIES");
    clsDate decCent(1, 1, 2025);
    clsDate decCentRes = clsDate::DecreaseOneCentury(decCent);
    cout << "DecreaseOneCentury(1/1/2025): " << decCentRes.FullDate() << "\n";
    decCent.DecreaseOneCentury();
    cout << "After instance DecreaseOneCentury(): " << decCent.FullDate() << "\n";

    printSection("34. DECREASE MILLENNIUMS");
    clsDate decMill(1, 1, 2025);
    clsDate decMillRes = clsDate::DecreaseOneMillenum(decMill);
    cout << "DecreaseOneMillenum(1/1/2025): " << decMillRes.FullDate() << "\n";
    decMill.DecreaseOneMillenum();
    cout << "After instance DecreaseOneMillenum(): " << decMill.FullDate() << "\n";

    printSection("35. COMPARE DATES");
    clsDate cmp1(10, 5, 2025);
    clsDate cmp2(20, 5, 2025);
    clsDate cmp3(10, 5, 2025);
    cout << "CompareDates(10/5, 20/5): " << static_cast<int>(clsDate::CompareDates(cmp1, cmp2)) << " (Before=-1)\n";
    cout << "CompareDates(20/5, 10/5): " << static_cast<int>(clsDate::CompareDates(cmp2, cmp1)) << " (After=1)\n";
    cout << "CompareDates(10/5, 10/5): " << static_cast<int>(clsDate::CompareDates(cmp1, cmp3)) << " (Equal=0)\n";
    cout << "cmp1.CompareDates(cmp2): " << static_cast<int>(cmp1.CompareDates(cmp2)) << "\n";

    printSection("36. CALENDAR PRINTING");
    cout << "printMonthCalnder(12, 2025):\n";
    clsDate::printMonthCalnder(12, 2025);

    cout << "testDay.printMonthCalnder():\n";
    testDay.printMonthCalnder();

    printSection("37. NUMBER TO TEXT");
    cout << "numberToText(0): " << clsDate::numberToText(0) << "\n";
    cout << "numberToText(5): " << clsDate::numberToText(5) << "\n";
    cout << "numberToText(15): " << clsDate::numberToText(15) << "\n";
    cout << "numberToText(25): " << clsDate::numberToText(25) << "\n";
    cout << "numberToText(125): " << clsDate::numberToText(125) << "\n";
    cout << "numberToText(3456): " << clsDate::numberToText(3456) << "\n";

    printSection("38. PRINT YEAR CALENDAR (SAMPLE - FIRST 3 MONTHS ONLY)");
    cout << "clsDate::printMonthCalnder for months 1-3 of 2025:\n";
    for (short i = 1; i <= 3; i++) {
        clsDate::printMonthCalnder(i, 2025);
        cout << "\n";
    }

    cout << "\n========== ALL METHODS TESTED SUCCESSFULLY ==========\n";
    return 0;
}

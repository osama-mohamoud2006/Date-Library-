// #include "clsDate.h"
// #include <iostream>
// using namespace std;
//
// void testSection(string title, int& passed, int& failed) {
//     cout << "\n" << string(70, '=') << "\n";
//     cout << "  " << title << "\n";
//     cout << string(70, '=') << "\n";
// }
//
// void testPass(string test) {
//     cout << "[PASS] " << test << "\n";
// }
//
// void testFail(string test, string expected, string actual) {
//     cout << "[FAIL] " << test << "\n";
//     cout << "       Expected: " << expected << "\n";
//     cout << "       Actual: " << actual << "\n";
// }
//
// int main() {
//     int totalPassed = 0, totalFailed = 0;
//
//     testSection("1. CONSTRUCTORS", totalPassed, totalFailed);
//     {
//         clsDate d1(31, 12, 1999);
//         if (d1.FullDate() == "31/12/1999") {
//             testPass("Constructor(d,m,y): 31/12/1999");
//             totalPassed++;
//         } else {
//             testFail("Constructor(d,m,y)", "31/12/1999", d1.FullDate());
//             totalFailed++;
//         }
//
//         clsDate d2("1/1/2000");
//         if (d2.FullDate() == "1/1/2000") {
//             testPass("Constructor(string): \"1/1/2000\"");
//             totalPassed++;
//         } else {
//             testFail("Constructor(string)", "1/1/2000", d2.FullDate());
//             totalFailed++;
//         }
//
//         clsDate d3(60, 2020);
//         if (d3.FullDate() == "29/2/2020") {
//             testPass("Constructor(dayOfYear,year): day 60 of 2020 = 29/2/2020");
//             totalPassed++;
//         } else {
//             testFail("Constructor(dayOfYear)", "29/2/2020", d3.FullDate());
//             totalFailed++;
//         }
//
//         clsDate d4 = clsDate::GetCurrentLocalDate();
//         if (d4.FullDate() != "") {
//             testPass("Default constructor: " + d4.FullDate());
//             totalPassed++;
//         } else {
//             testFail("Default constructor", "current date", "empty");
//             totalFailed++;
//         }
//     }
//
//     testSection("2. SETTERS", totalPassed, totalFailed);
//     {
//         clsDate setter(1, 1, 2020);
//         setter.SetD(15);
//         setter.SetM(6);
//         setter.SetY(2025);
//         if (setter.FullDate() == "15/6/2025") {
//             testPass("SetD/SetM/SetY: 15/6/2025");
//             totalPassed++;
//         } else {
//             testFail("SetD/SetM/SetY", "15/6/2025", setter.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("3. LEAP YEAR (isLeap)", totalPassed, totalFailed);
//     {
//         if (clsDate::isLeap(2000) == 1) {
//             testPass("isLeap(2000): true");
//             totalPassed++;
//         } else {
//             testFail("isLeap(2000)", "1", "0");
//             totalFailed++;
//         }
//
//         if (clsDate::isLeap(2024) == 1) {
//             testPass("isLeap(2024): true");
//             totalPassed++;
//         } else {
//             testFail("isLeap(2024)", "1", "0");
//             totalFailed++;
//         }
//
//         if (clsDate::isLeap(2025) == 0) {
//             testPass("isLeap(2025): false");
//             totalPassed++;
//         } else {
//             testFail("isLeap(2025)", "0", "1");
//             totalFailed++;
//         }
//
//         clsDate leapTest(29, 2, 2024);
//         if (leapTest.isLeap() == 1) {
//             testPass("instance.isLeap() for 29/2/2024: true");
//             totalPassed++;
//         } else {
//             testFail("instance.isLeap()", "1", "0");
//             totalFailed++;
//         }
//     }
//
//     testSection("4. DAYS IN YEAR (numberOFDays)", totalPassed, totalFailed);
//     {
//         if (clsDate::numberOFDays(2024) == 366) {
//             testPass("numberOFDays(2024): 366");
//             totalPassed++;
//         } else {
//             testFail("numberOFDays(2024)", "366", to_string(clsDate::numberOFDays(2024)));
//             totalFailed++;
//         }
//
//         if (clsDate::numberOFDays(2025) == 365) {
//             testPass("numberOFDays(2025): 365");
//             totalPassed++;
//         } else {
//             testFail("numberOFDays(2025)", "365", to_string(clsDate::numberOFDays(2025)));
//             totalFailed++;
//         }
//
//         clsDate testYear(1, 1, 2024);
//         if (testYear.numberOFDays() == 366) {
//             testPass("instance.numberOFDays() for 2024: 366");
//             totalPassed++;
//         } else {
//             testFail("instance.numberOFDays()", "366", to_string(testYear.numberOFDays()));
//             totalFailed++;
//         }
//     }
//
//     testSection("5. HOURS/MINUTES/SECONDS IN YEAR", totalPassed, totalFailed);
//     {
//         int hours2025 = clsDate::NumberOfHours(2025);
//         if (hours2025 == 8760) {
//             testPass("NumberOfHours(2025): 8760");
//             totalPassed++;
//         } else {
//             testFail("NumberOfHours(2025)", "8760", to_string(hours2025));
//             totalFailed++;
//         }
//
//         int mins2025 = clsDate::NumberOfMin(2025);
//         if (mins2025 == 525600) {
//             testPass("NumberOfMin(2025): 525600");
//             totalPassed++;
//         } else {
//             testFail("NumberOfMin(2025)", "525600", to_string(mins2025));
//             totalFailed++;
//         }
//
//         int secs2025 = clsDate::NumberOfSeconds(2025);
//         if (secs2025 == 31536000) {
//             testPass("NumberOfSeconds(2025): 31536000");
//             totalPassed++;
//         } else {
//             testFail("NumberOfSeconds(2025)", "31536000", to_string(secs2025));
//             totalFailed++;
//         }
//
//         clsDate testYear(1, 1, 2025);
//         if (testYear.NumberOfHours() == 8760) {
//             testPass("instance.NumberOfHours() for 2025: 8760");
//             totalPassed++;
//         } else {
//             testFail("instance.NumberOfHours()", "8760", to_string(testYear.NumberOfHours()));
//             totalFailed++;
//         }
//     }
//
//     testSection("6. DAYS IN MONTH", totalPassed, totalFailed);
//     {
//         if (clsDate::NumberOfDaysInMonth(2024, 2) == 29) {
//             testPass("NumberOfDaysInMonth(2024, 2): 29 (leap year)");
//             totalPassed++;
//         } else {
//             testFail("NumberOfDaysInMonth(2024,2)", "29", to_string(clsDate::NumberOfDaysInMonth(2024, 2)));
//             totalFailed++;
//         }
//
//         if (clsDate::NumberOfDaysInMonth(2025, 2) == 28) {
//             testPass("NumberOfDaysInMonth(2025, 2): 28 (non-leap)");
//             totalPassed++;
//         } else {
//             testFail("NumberOfDaysInMonth(2025,2)", "28", to_string(clsDate::NumberOfDaysInMonth(2025, 2)));
//             totalFailed++;
//         }
//
//         if (clsDate::NumberOfDaysInMonth(2025, 12) == 31) {
//             testPass("NumberOfDaysInMonth(2025, 12): 31");
//             totalPassed++;
//         } else {
//             testFail("NumberOfDaysInMonth(2025,12)", "31", to_string(clsDate::NumberOfDaysInMonth(2025, 12)));
//             totalFailed++;
//         }
//
//         clsDate testMonth(15, 2, 2025);
//         if (testMonth.NumberOfDaysInMonth() == 28) {
//             testPass("instance.NumberOfDaysInMonth() for 2/2025: 28");
//             totalPassed++;
//         } else {
//             testFail("instance.NumberOfDaysInMonth()", "28", to_string(testMonth.NumberOfDaysInMonth()));
//             totalFailed++;
//         }
//     }
//
//     testSection("7. HOURS/MINUTES/SECONDS IN MONTH", totalPassed, totalFailed);
//     {
//         if (clsDate::HoursInMonth(2024, 2) == 696) {
//             testPass("HoursInMonth(2024, 2): 696");
//             totalPassed++;
//         } else {
//             testFail("HoursInMonth(2024,2)", "696", to_string(clsDate::HoursInMonth(2024, 2)));
//             totalFailed++;
//         }
//
//         if (clsDate::MinInMonth(2024, 2) == 41760) {
//             testPass("MinInMonth(2024, 2): 41760");
//             totalPassed++;
//         } else {
//             testFail("MinInMonth(2024,2)", "41760", to_string(clsDate::MinInMonth(2024, 2)));
//             totalFailed++;
//         }
//
//         if (clsDate::secondsInMonth(2024, 2) == 2505600) {
//             testPass("secondsInMonth(2024, 2): 2505600");
//             totalPassed++;
//         } else {
//             testFail("secondsInMonth(2024,2)", "2505600", to_string(clsDate::secondsInMonth(2024, 2)));
//             totalFailed++;
//         }
//
//         clsDate testMonth(15, 2, 2024);
//         if (testMonth.HoursInMonth() == 696) {
//             testPass("instance.HoursInMonth() for 2/2024: 696");
//             totalPassed++;
//         } else {
//             testFail("instance.HoursInMonth()", "696", to_string(testMonth.HoursInMonth()));
//             totalFailed++;
//         }
//     }
//
//     testSection("8. FULLDATE METHODS", totalPassed, totalFailed);
//     {
//         clsDate d1(31, 12, 1999);
//         if (d1.FullDate() == "31/12/1999") {
//             testPass("FullDate() instance method: 31/12/1999");
//             totalPassed++;
//         } else {
//             testFail("FullDate() instance", "31/12/1999", d1.FullDate());
//             totalFailed++;
//         }
//
//         if (d1.FullDate(2025, 11, 25) == "25/11/2025") {
//             testPass("FullDate(d,m,y) method: 25/11/2025");
//             totalPassed++;
//         } else {
//             testFail("FullDate(d,m,y)", "25/11/2025", d1.FullDate(2025, 11, 25));
//             totalFailed++;
//         }
//
//         clsDate d3(60, 2020);
//         if (clsDate::PrintFullDateForStatic(d3) == "29/2/2020") {
//             testPass("PrintFullDateForStatic: 29/2/2020");
//             totalPassed++;
//         } else {
//             testFail("PrintFullDateForStatic", "29/2/2020", clsDate::PrintFullDateForStatic(d3));
//             totalFailed++;
//         }
//     }
//
//     testSection("9. DAY ORDER (Zeller's Algorithm)", totalPassed, totalFailed);
//     {
//         short order = clsDate::DayOrder(2025, 11, 25);
//         if (order >= 0 && order <= 6) {
//             testPass("DayOrder(2025, 11, 25): " + to_string(order) + " (valid 0-6)");
//             totalPassed++;
//         } else {
//             testFail("DayOrder()", "0-6", to_string(order));
//             totalFailed++;
//         }
//
//         clsDate testDay(25, 11, 2025);
//         if (testDay.DayOrder() == order) {
//             testPass("instance.DayOrder() matches static: " + to_string(order));
//             totalPassed++;
//         } else {
//             testFail("instance.DayOrder()", to_string(order), to_string(testDay.DayOrder()));
//             totalFailed++;
//         }
//     }
//
//     testSection("10. DAY NAMES", totalPassed, totalFailed);
//     {
//         if (clsDate::DayName(0) == "sun") {
//             testPass("DayName(0): sun");
//             totalPassed++;
//         } else {
//             testFail("DayName(0)", "sun", clsDate::DayName(0));
//             totalFailed++;
//         }
//
//         if (clsDate::DayName(6) == "sat") {
//             testPass("DayName(6): sat");
//             totalPassed++;
//         } else {
//             testFail("DayName(6)", "sat", clsDate::DayName(6));
//             totalFailed++;
//         }
//     }
//
//     testSection("11. MONTH NAMES", totalPassed, totalFailed);
//     {
//         if (clsDate::MonthName(1) == "jan" && clsDate::MonthName(12) == "dec") {
//             testPass("MonthName(1-12): jan...dec");
//             totalPassed++;
//         } else {
//             testFail("MonthName()", "jan/dec", clsDate::MonthName(1) + "/" + clsDate::MonthName(12));
//             totalFailed++;
//         }
//
//         clsDate testDay(25, 11, 2025);
//         if (testDay.MonthName() == "nov") {
//             testPass("instance.MonthName() for 11: nov");
//             totalPassed++;
//         } else {
//             testFail("instance.MonthName()", "nov", testDay.MonthName());
//             totalFailed++;
//         }
//     }
//
//     testSection("12. TOTAL DAYS SINCE START OF YEAR", totalPassed, totalFailed);
//     {
//         int days1 = clsDate::TotalDaysSinceThisDate(2025, 1, 1);
//         if (days1 == 1) {
//             testPass("TotalDaysSinceThisDate(2025,1,1): 1");
//             totalPassed++;
//         } else {
//             testFail("TotalDaysSinceThisDate(1/1)", "1", to_string(days1));
//             totalFailed++;
//         }
//
//         int days329 = clsDate::TotalDaysSinceThisDate(2025, 11, 25);
//         if (days329 > 300 && days329 < 365) {
//             testPass("TotalDaysSinceThisDate(2025,11,25): " + to_string(days329));
//             totalPassed++;
//         } else {
//             testFail("TotalDaysSinceThisDate(11/25)", "~329", to_string(days329));
//             totalFailed++;
//         }
//
//         clsDate testDay(25, 11, 2025);
//         if (testDay.TotalDaysSinceThisDate() == days329) {
//             testPass("instance.TotalDaysSinceThisDate(): " + to_string(testDay.TotalDaysSinceThisDate()));
//             totalPassed++;
//         } else {
//             testFail("instance.TotalDaysSinceThisDate()", to_string(days329), to_string(testDay.TotalDaysSinceThisDate()));
//             totalFailed++;
//         }
//     }
//
//     testSection("13. DAY UNTIL DATE", totalPassed, totalFailed);
//     {
//         clsDate d1(31, 12, 1999);
//         short dayUntil = clsDate::DayUntillDate(d1);
//         if (dayUntil == 365) {
//             testPass("DayUntillDate(31/12): 365");
//             totalPassed++;
//         } else {
//             testFail("DayUntillDate(31/12)", "365", to_string(dayUntil));
//             totalFailed++;
//         }
//
//         if (d1.DayUntillDate() == 365) {
//             testPass("instance.DayUntillDate(): 365");
//             totalPassed++;
//         } else {
//             testFail("instance.DayUntillDate()", "365", to_string(d1.DayUntillDate()));
//             totalFailed++;
//         }
//     }
//
//     testSection("14. GET DATE FROM DAY OF YEAR", totalPassed, totalFailed);
//     {
//         clsDate fromDay1 = clsDate::GetDateFromDayOfYear(1, 2025);
//         if (fromDay1.FullDate() == "1/1/2025") {
//             testPass("GetDateFromDayOfYear(1, 2025): 1/1/2025");
//             totalPassed++;
//         } else {
//             testFail("GetDateFromDayOfYear(1)", "1/1/2025", fromDay1.FullDate());
//             totalFailed++;
//         }
//
//         clsDate fromDay150 = clsDate::GetDateFromDayOfYear(150, 2025);
//         if (fromDay150.FullDate() == "30/5/2025") {
//             testPass("GetDateFromDayOfYear(150, 2025): 30/5/2025");
//             totalPassed++;
//         } else {
//             testFail("GetDateFromDayOfYear(150)", "30/5/2025", fromDay150.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instFromDay(10, 1, 2025);
//         instFromDay.GetDateFromDayOfYear(100);
//         if (instFromDay.FullDate() == "10/4/2025") {
//             testPass("instance.GetDateFromDayOfYear(100): 10/4/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.GetDateFromDayOfYear()", "10/4/2025", instFromDay.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("15. ADD DAYS TO DATE", totalPassed, totalFailed);
//     {
//         clsDate addDaysTest(25, 12, 2025);
//         clsDate addResult = clsDate::AddDaysToDate(addDaysTest, 10);
//         if (addResult.FullDate() == "4/1/2026") {
//             testPass("AddDaysToDate(25/12/2025, 10): 4/1/2026");
//             totalPassed++;
//         } else {
//             testFail("AddDaysToDate()", "4/1/2026", addResult.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instAddTest(25, 12, 2025);
//         instAddTest.AddDaysToDate(5);
//         if (instAddTest.FullDate() == "30/12/2025") {
//             testPass("instance.AddDaysToDate(5): 30/12/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddDaysToDate()", "30/12/2025", instAddTest.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("16. DATE COMPARISONS", totalPassed, totalFailed);
//     {
//         clsDate comp1(1, 1, 2020);
//         clsDate comp2(1, 1, 2021);
//         clsDate comp3(1, 1, 2020);
//
//         if (clsDate::isDate1LessThanDate2(comp1, comp2) == 1) {
//             testPass("isDate1LessThanDate2(1/1/2020, 1/1/2021): true");
//             totalPassed++;
//         } else {
//             testFail("isDate1LessThanDate2()", "1", "0");
//             totalFailed++;
//         }
//
//         if (clsDate::isDate1equalsDate2(comp1, comp3) == 1) {
//             testPass("isDate1equalsDate2(1/1/2020, 1/1/2020): true");
//             totalPassed++;
//         } else {
//             testFail("isDate1equalsDate2()", "1", "0");
//             totalFailed++;
//         }
//
//         if (comp1.isDate1LessThanDate2(comp2) == 1) {
//             testPass("instance.isDate1LessThanDate2(): true");
//             totalPassed++;
//         } else {
//             testFail("instance.isDate1LessThanDate2()", "1", "0");
//             totalFailed++;
//         }
//
//         if (comp1.isDate1equalsDate2(comp3) == 1) {
//             testPass("instance.isDate1equalsDate2(): true");
//             totalPassed++;
//         } else {
//             testFail("instance.isDate1equalsDate2()", "1", "0");
//             totalFailed++;
//         }
//     }
//
//     testSection("17. LAST DAY/MONTH CHECKS", totalPassed, totalFailed);
//     {
//         clsDate lastDay(31, 12, 2025);
//         clsDate notLastDay(30, 12, 2025);
//
//         if (clsDate::isLastDayInMonth(lastDay) == 1) {
//             testPass("isLastDayInMonth(31/12): true");
//             totalPassed++;
//         } else {
//             testFail("isLastDayInMonth(31/12)", "1", "0");
//             totalFailed++;
//         }
//
//         if (clsDate::isLastDayInMonth(notLastDay) == 0) {
//             testPass("isLastDayInMonth(30/12): false");
//             totalPassed++;
//         } else {
//             testFail("isLastDayInMonth(30/12)", "0", "1");
//             totalFailed++;
//         }
//
//         if (clsDate::isLastMonthInYear(lastDay) == 1) {
//             testPass("isLastMonthInYear(12): true");
//             totalPassed++;
//         } else {
//             testFail("isLastMonthInYear(12)", "1", "0");
//             totalFailed++;
//         }
//     }
//
//     testSection("18. IS FIRST MONTH IN YEAR", totalPassed, totalFailed);
//     {
//         clsDate firstMonth(1, 1, 2025);
//         clsDate notFirstMonth(1, 2, 2025);
//
//         if (clsDate::isFirstMonthInTheYear(firstMonth) == 1) {
//             testPass("isFirstMonthInTheYear(1/1): true");
//             totalPassed++;
//         } else {
//             testFail("isFirstMonthInTheYear(1/1)", "1", "0");
//             totalFailed++;
//         }
//
//         if (clsDate::isFirstMonthInTheYear(notFirstMonth) == 0) {
//             testPass("isFirstMonthInTheYear(1/2): false");
//             totalPassed++;
//         } else {
//             testFail("isFirstMonthInTheYear(1/2)", "0", "1");
//             totalFailed++;
//         }
//
//         if (firstMonth.isFirstMonthInTheYear() == 1) {
//             testPass("instance.isFirstMonthInTheYear(): true");
//             totalPassed++;
//         } else {
//             testFail("instance.isFirstMonthInTheYear()", "1", "0");
//             totalFailed++;
//         }
//     }
//
//     testSection("19. ADD ONE DAY", totalPassed, totalFailed);
//     {
//         clsDate addOneDay(31, 12, 2025);
//         clsDate result = clsDate::dateAfterAddingOneDay(addOneDay);
//         if (result.FullDate() == "1/1/2026") {
//             testPass("dateAfterAddingOneDay(31/12/2025): 1/1/2026");
//             totalPassed++;
//         } else {
//             testFail("dateAfterAddingOneDay()", "1/1/2026", result.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instAddOne(31, 1, 2025);
//         instAddOne.dateAfterAddingOneDay();
//         if (instAddOne.FullDate() == "1/2/2025") {
//             testPass("instance.dateAfterAddingOneDay(31/1): 1/2/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.dateAfterAddingOneDay()", "1/2/2025", instAddOne.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("20. SWAP DATES", totalPassed, totalFailed);
//     {
//         clsDate swap1(1, 1, 2020);
//         clsDate swap2(31, 12, 2025);
//         clsDate::swapDates(swap1, swap2);
//         if (swap1.FullDate() == "31/12/2025" && swap2.FullDate() == "1/1/2020") {
//             testPass("swapDates: swap1=31/12/2025, swap2=1/1/2020");
//             totalPassed++;
//         } else {
//             testFail("swapDates()", "31/12/2025 & 1/1/2020", swap1.FullDate() + " & " + swap2.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("21. DIFFERENCE BETWEEN DATES", totalPassed, totalFailed);
//     {
//         clsDate diff1(1, 1, 2025);
//         clsDate diff2(15, 1, 2025);
//         int diffDays = clsDate::DiffBetween2DatesInDays(diff1, diff2);
//         if (diffDays == 14) {
//             testPass("DiffBetween2DatesInDays(1/1-15/1): 14 days");
//             totalPassed++;
//         } else {
//             testFail("DiffBetween2DatesInDays()", "14", to_string(diffDays));
//             totalFailed++;
//         }
//
//         int diffInst = diff1.DiffBetween2DatesInDays(diff2);
//         if (diffInst == 14) {
//             testPass("instance.DiffBetween2DatesInDays(): 14 days");
//             totalPassed++;
//         } else {
//             testFail("instance.DiffBetween2DatesInDays()", "14", to_string(diffInst));
//             totalFailed++;
//         }
//     }
//
//     testSection("22. YOUR AGE IN DAYS", totalPassed, totalFailed);
//     {
//         clsDate birthday(1, 8, 2006);
//         clsDate now = clsDate::GetCurrentLocalDate();
//         int ageStatic = clsDate::yourAgeInDays(birthday, now);
//         if (ageStatic > 6900 && ageStatic < 7100) {
//             testPass("yourAgeInDays(1/8/2006 to now): ~" + to_string(ageStatic) + " days (valid)");
//             totalPassed++;
//         } else {
//             testFail("yourAgeInDays()", "~7000", to_string(ageStatic));
//             totalFailed++;
//         }
//
//         int ageInst = now.yourAgeInDays(birthday);
//         if (ageInst == ageStatic) {
//             testPass("instance.yourAgeInDays(): " + to_string(ageInst) + " days");
//             totalPassed++;
//         } else {
//             testFail("instance.yourAgeInDays()", to_string(ageStatic), to_string(ageInst));
//             totalFailed++;
//         }
//     }
//
//     testSection("23. ADD X DAYS", totalPassed, totalFailed);
//     {
//         clsDate addXDays(1, 1, 2025);
//         clsDate result = clsDate::AddXdays(45, addXDays);
//         if (result.FullDate() == "15/2/2025") {
//             testPass("AddXdays(45 days from 1/1): 15/2/2025");
//             totalPassed++;
//         } else {
//             testFail("AddXdays(45)", "15/2/2025", result.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instXdays(1, 1, 2025);
//         instXdays.AddXdays(30);
//         if (instXdays.FullDate() == "31/1/2025") {
//             testPass("instance.AddXdays(30): 31/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddXdays(30)", "31/1/2025", instXdays.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("24. ADD WEEKS", totalPassed, totalFailed);
//     {
//         clsDate addWeek(1, 1, 2025);
//         clsDate addOneWeekRes = clsDate::AddOneWeek(addWeek);
//         if (addOneWeekRes.FullDate() == "8/1/2025") {
//             testPass("AddOneWeek(1/1/2025): 8/1/2025");
//             totalPassed++;
//         } else {
//             testFail("AddOneWeek()", "8/1/2025", addOneWeekRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate addXWeeks(1, 1, 2025);
//         clsDate addXWeeksRes = clsDate::AddXweeks(4, addXWeeks);
//         if (addXWeeksRes.FullDate() == "29/1/2025") {
//             testPass("AddXweeks(4, 1/1/2025): 29/1/2025");
//             totalPassed++;
//         } else {
//             testFail("AddXweeks(4)", "29/1/2025", addXWeeksRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instWeek(1, 1, 2025);
//         instWeek.AddOneWeek();
//         if (instWeek.FullDate() == "8/1/2025") {
//             testPass("instance.AddOneWeek(): 8/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneWeek()", "8/1/2025", instWeek.FullDate());
//             totalFailed++;
//         }
//
//         instWeek.AddXweeks(2);
//         if (instWeek.FullDate() == "22/1/2025") {
//             testPass("instance.AddXweeks(2): 22/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddXweeks(2)", "22/1/2025", instWeek.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("25. ADD MONTHS", totalPassed, totalFailed);
//     {
//         clsDate addMonth(31, 1, 2025);
//         clsDate addOneMonthRes = clsDate::AddOneMonth(addMonth);
//         if (addOneMonthRes.FullDate() == "28/2/2025") {
//             testPass("AddOneMonth(31/1/2025): 28/2/2025 (day adjusted)");
//             totalPassed++;
//         } else {
//             testFail("AddOneMonth(31/1)", "28/2/2025", addOneMonthRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate addXMonths(1, 1, 2025);
//         clsDate addXMonthsRes = clsDate::AddXMonths(6, addXMonths);
//         if (addXMonthsRes.FullDate() == "1/7/2025") {
//             testPass("AddXMonths(6, 1/1/2025): 1/7/2025");
//             totalPassed++;
//         } else {
//             testFail("AddXMonths(6)", "1/7/2025", addXMonthsRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instMonth(15, 1, 2025);
//         instMonth.AddOneMonth();
//         if (instMonth.FullDate() == "15/2/2025") {
//             testPass("instance.AddOneMonth(): 15/2/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneMonth()", "15/2/2025", instMonth.FullDate());
//             totalFailed++;
//         }
//
//         instMonth.AddXMonths(3);
//         if (instMonth.FullDate() == "15/5/2025") {
//             testPass("instance.AddXMonths(3): 15/5/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddXMonths(3)", "15/5/2025", instMonth.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("26. ADD YEARS", totalPassed, totalFailed);
//     {
//         clsDate addYear(29, 2, 2024);
//         clsDate addOneYearRes = clsDate::AddOneYear(addYear);
//         if (addOneYearRes.FullDate() == "28/2/2025") {
//             testPass("AddOneYear(29/2/2024): 28/2/2025 (no longer leap)");
//             totalPassed++;
//         } else {
//             testFail("AddOneYear(29/2)", "28/2/2025", addOneYearRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate addXYears(1, 1, 2025);
//         clsDate addXYearsRes = clsDate::AddXYears(5, addXYears);
//         if (addXYearsRes.FullDate() == "1/1/2030") {
//             testPass("AddXYears(5, 1/1/2025): 1/1/2030");
//             totalPassed++;
//         } else {
//             testFail("AddXYears(5)", "1/1/2030", addXYearsRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instYear(1, 1, 2025);
//         instYear.AddOneYear();
//         if (instYear.FullDate() == "1/1/2026") {
//             testPass("instance.AddOneYear(): 1/1/2026");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneYear()", "1/1/2026", instYear.FullDate());
//             totalFailed++;
//         }
//
//         instYear.AddXYears(4);
//         if (instYear.FullDate() == "1/1/2030") {
//             testPass("instance.AddXYears(4): 1/1/2030");
//             totalPassed++;
//         } else {
//             testFail("instance.AddXYears(4)", "1/1/2030", instYear.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("27. ADD DECADES", totalPassed, totalFailed);
//     {
//         clsDate addDecade(1, 1, 2025);
//         clsDate addOneDecadeRes = clsDate::AddOneDecade(addDecade);
//         if (addOneDecadeRes.FullDate() == "1/1/2035") {
//             testPass("AddOneDecade(1/1/2025): 1/1/2035");
//             totalPassed++;
//         } else {
//             testFail("AddOneDecade()", "1/1/2035", addOneDecadeRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate addXDecades(1, 1, 2025);
//         clsDate addXDecadesRes = clsDate::AdddXDecade(3, addXDecades);
//         if (addXDecadesRes.FullDate() == "1/1/2055") {
//             testPass("AdddXDecade(3, 1/1/2025): 1/1/2055");
//             totalPassed++;
//         } else {
//             testFail("AdddXDecade(3)", "1/1/2055", addXDecadesRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecade(1, 1, 2025);
//         instDecade.AddOneDecade();
//         if (instDecade.FullDate() == "1/1/2035") {
//             testPass("instance.AddOneDecade(): 1/1/2035");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneDecade()", "1/1/2035", instDecade.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("28. ADD CENTURIES", totalPassed, totalFailed);
//     {
//         clsDate addCent(1, 1, 2025);
//         clsDate addOneCentRes = clsDate::AddOneCentury(addCent);
//         if (addOneCentRes.FullDate() == "1/1/2125") {
//             testPass("AddOneCentury(1/1/2025): 1/1/2125");
//             totalPassed++;
//         } else {
//             testFail("AddOneCentury()", "1/1/2125", addOneCentRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instCent(1, 1, 2025);
//         instCent.AddOneCentury();
//         if (instCent.FullDate() == "1/1/2125") {
//             testPass("instance.AddOneCentury(): 1/1/2125");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneCentury()", "1/1/2125", instCent.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("29. ADD MILLENNIUMS", totalPassed, totalFailed);
//     {
//         clsDate addMill(1, 1, 2025);
//         clsDate addOneMillRes = clsDate::AddOneMillenuim(addMill);
//         if (addOneMillRes.FullDate() == "1/1/3025") {
//             testPass("AddOneMillenuim(1/1/2025): 1/1/3025");
//             totalPassed++;
//         } else {
//             testFail("AddOneMillenuim()", "1/1/3025", addOneMillRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instMill(1, 1, 2025);
//         instMill.AddOneMillenuim();
//         if (instMill.FullDate() == "1/1/3025") {
//             testPass("instance.AddOneMillenuim(): 1/1/3025");
//             totalPassed++;
//         } else {
//             testFail("instance.AddOneMillenuim()", "1/1/3025", instMill.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("30. DECREASE DAYS", totalPassed, totalFailed);
//     {
//         clsDate decDay(1, 1, 2025);
//         clsDate decOneDayRes = clsDate::DecreaseOneDay(decDay);
//         if (decOneDayRes.FullDate() == "31/12/2024") {
//             testPass("DecreaseOneDay(1/1/2025): 31/12/2024");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneDay()", "31/12/2024", decOneDayRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate decXDays(15, 1, 2025);
//         clsDate decXDaysRes = clsDate::DecreaseXDays(10, decXDays);
//         if (decXDaysRes.FullDate() == "5/1/2025") {
//             testPass("DecreaseXDays(10, 15/1/2025): 5/1/2025");
//             totalPassed++;
//         } else {
//             testFail("DecreaseXDays(10)", "5/1/2025", decXDaysRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecDay(15, 1, 2025);
//         instDecDay.DecreaseOneDay();
//         if (instDecDay.FullDate() == "14/1/2025") {
//             testPass("instance.DecreaseOneDay(): 14/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneDay()", "14/1/2025", instDecDay.FullDate());
//             totalFailed++;
//         }
//
//         instDecDay.DecreaseXDays(5);
//         if (instDecDay.FullDate() == "9/1/2025") {
//             testPass("instance.DecreaseXDays(5): 9/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseXDays(5)", "9/1/2025", instDecDay.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("31. DECREASE WEEKS", totalPassed, totalFailed);
//     {
//         clsDate decWeek(15, 2, 2025);
//         clsDate decOneWeekRes = clsDate::DecreaseOneWeek(decWeek);
//         if (decOneWeekRes.FullDate() == "8/2/2025") {
//             testPass("DecreaseOneWeek(15/2/2025): 8/2/2025");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneWeek()", "8/2/2025", decOneWeekRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate decXWeeks(15, 2, 2025);
//         clsDate decXWeeksRes = clsDate::DecreaseXWeeks(2, decXWeeks);
//         if (decXWeeksRes.FullDate() == "1/2/2025") {
//             testPass("DecreaseXWeeks(2, 15/2/2025): 1/2/2025");
//             totalPassed++;
//         } else {
//             testFail("DecreaseXWeeks(2)", "1/2/2025", decXWeeksRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecWeek(15, 2, 2025);
//         instDecWeek.DecreaseOneWeek();
//         if (instDecWeek.FullDate() == "8/2/2025") {
//             testPass("instance.DecreaseOneWeek(): 8/2/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneWeek()", "8/2/2025", instDecWeek.FullDate());
//             totalFailed++;
//         }
//
//         instDecWeek.DecreaseXWeeks(1);
//         if (instDecWeek.FullDate() == "1/2/2025") {
//             testPass("instance.DecreaseXWeeks(1): 1/2/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseXWeeks(1)", "1/2/2025", instDecWeek.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("32. DECREASE MONTHS", totalPassed, totalFailed);
//     {
//         clsDate decMonth(31, 3, 2025);
//         clsDate decOneMonthRes = clsDate::DecreaseOneMonth(decMonth);
//         if (decOneMonthRes.FullDate() == "28/2/2025") {
//             testPass("DecreaseOneMonth(31/3/2025): 28/2/2025 (day adjusted)");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneMonth(31/3)", "28/2/2025", decOneMonthRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate decXMonths(1, 4, 2025);
//         clsDate decXMonthsRes = clsDate::DecreaseXMonth(2, decXMonths);
//         if (decXMonthsRes.FullDate() == "1/2/2025") {
//             testPass("DecreaseXMonth(2, 1/4/2025): 1/2/2025");
//             totalPassed++;
//         } else {
//             testFail("DecreaseXMonth(2)", "1/2/2025", decXMonthsRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecMonth(15, 3, 2025);
//         instDecMonth.DecreaseOneMonth();
//         if (instDecMonth.FullDate() == "15/2/2025") {
//             testPass("instance.DecreaseOneMonth(): 15/2/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneMonth()", "15/2/2025", instDecMonth.FullDate());
//             totalFailed++;
//         }
//
//         instDecMonth.DecreaseXMonth(1);
//         if (instDecMonth.FullDate() == "15/1/2025") {
//             testPass("instance.DecreaseXMonth(1): 15/1/2025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseXMonth(1)", "15/1/2025", instDecMonth.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("33. DECREASE YEARS", totalPassed, totalFailed);
//     {
//         clsDate decYear(29, 2, 2024);
//         clsDate decOneYearRes = clsDate::DecreaseOneYear(decYear);
//         if (decOneYearRes.FullDate() == "28/2/2023") {
//             testPass("DecreaseOneYear(29/2/2024): 28/2/2023 (no longer leap)");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneYear(29/2)", "28/2/2023", decOneYearRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate decXYears(1, 1, 2025);
//         clsDate decXYearsRes = clsDate::DecreaseXYears(5, decXYears);
//         if (decXYearsRes.FullDate() == "1/1/2020") {
//             testPass("DecreaseXYears(5, 1/1/2025): 1/1/2020");
//             totalPassed++;
//         } else {
//             testFail("DecreaseXYears(5)", "1/1/2020", decXYearsRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecYear(1, 1, 2025);
//         instDecYear.DecreaseOneYear();
//         if (instDecYear.FullDate() == "1/1/2024") {
//             testPass("instance.DecreaseOneYear(): 1/1/2024");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneYear()", "1/1/2024", instDecYear.FullDate());
//             totalFailed++;
//         }
//
//         instDecYear.DecreaseXYears(4);
//         if (instDecYear.FullDate() == "1/1/2020") {
//             testPass("instance.DecreaseXYears(4): 1/1/2020");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseXYears(4)", "1/1/2020", instDecYear.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("34. DECREASE DECADES", totalPassed, totalFailed);
//     {
//         clsDate decDecade(1, 1, 2025);
//         clsDate decOneDecadeRes = clsDate::DecreaseOneDecade(decDecade);
//         if (decOneDecadeRes.FullDate() == "1/1/2015") {
//             testPass("DecreaseOneDecade(1/1/2025): 1/1/2015");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneDecade()", "1/1/2015", decOneDecadeRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate decXDecades(1, 1, 2025);
//         clsDate decXDecadesRes = clsDate::DecreaseXdecades(decXDecades, 3);
//         if (decXDecadesRes.FullDate() == "1/1/1995") {
//             testPass("DecreaseXdecades(3, 1/1/2025): 1/1/1995");
//             totalPassed++;
//         } else {
//             testFail("DecreaseXdecades(3)", "1/1/1995", decXDecadesRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecDecade(1, 1, 2025);
//         instDecDecade.DecreaseOneDecade();
//         if (instDecDecade.FullDate() == "1/1/2015") {
//             testPass("instance.DecreaseOneDecade(): 1/1/2015");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneDecade()", "1/1/2015", instDecDecade.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("35. DECREASE CENTURIES", totalPassed, totalFailed);
//     {
//         clsDate decCent(1, 1, 2025);
//         clsDate decOneCentRes = clsDate::DecreaseOneCentury(decCent);
//         if (decOneCentRes.FullDate() == "1/1/1925") {
//             testPass("DecreaseOneCentury(1/1/2025): 1/1/1925");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneCentury()", "1/1/1925", decOneCentRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecCent(1, 1, 2025);
//         instDecCent.DecreaseOneCentury();
//         if (instDecCent.FullDate() == "1/1/1925") {
//             testPass("instance.DecreaseOneCentury(): 1/1/1925");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneCentury()", "1/1/1925", instDecCent.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("36. DECREASE MILLENNIUMS", totalPassed, totalFailed);
//     {
//         clsDate decMill(1, 1, 2025);
//         clsDate decOneMillRes = clsDate::DecreaseOneMillenum(decMill);
//         if (decOneMillRes.FullDate() == "1/1/1025") {
//             testPass("DecreaseOneMillenum(1/1/2025): 1/1/1025");
//             totalPassed++;
//         } else {
//             testFail("DecreaseOneMillenum()", "1/1/1025", decOneMillRes.FullDate());
//             totalFailed++;
//         }
//
//         clsDate instDecMill(1, 1, 2025);
//         instDecMill.DecreaseOneMillenum();
//         if (instDecMill.FullDate() == "1/1/1025") {
//             testPass("instance.DecreaseOneMillenum(): 1/1/1025");
//             totalPassed++;
//         } else {
//             testFail("instance.DecreaseOneMillenum()", "1/1/1025", instDecMill.FullDate());
//             totalFailed++;
//         }
//     }
//
//     testSection("37. COMPARE DATES", totalPassed, totalFailed);
//     {
//         clsDate cmp1(10, 5, 2025);
//         clsDate cmp2(20, 5, 2025);
//         clsDate cmp3(10, 5, 2025);
//
//         int cmpBefore = static_cast<int>(clsDate::CompareDates(cmp1, cmp2));
//         if (cmpBefore == -1) {
//             testPass("CompareDates(10/5, 20/5): -1 (Before)");
//             totalPassed++;
//         } else {
//             testFail("CompareDates(Before)", "-1", to_string(cmpBefore));
//             totalFailed++;
//         }
//
//         int cmpAfter = static_cast<int>(clsDate::CompareDates(cmp2, cmp1));
//         if (cmpAfter == 1) {
//             testPass("CompareDates(20/5, 10/5): 1 (After)");
//             totalPassed++;
//         } else {
//             testFail("CompareDates(After)", "1", to_string(cmpAfter));
//             totalFailed++;
//         }
//
//         int cmpEqual = static_cast<int>(clsDate::CompareDates(cmp1, cmp3));
//         if (cmpEqual == 0) {
//             testPass("CompareDates(10/5, 10/5): 0 (Equal)");
//             totalPassed++;
//         } else {
//             testFail("CompareDates(Equal)", "0", to_string(cmpEqual));
//             totalFailed++;
//         }
//
//         int instCmp = static_cast<int>(cmp1.CompareDates(cmp2));
//         if (instCmp == -1) {
//             testPass("instance.CompareDates(): -1 (Before)");
//             totalPassed++;
//         } else {
//             testFail("instance.CompareDates()", "-1", to_string(instCmp));
//             totalFailed++;
//         }
//     }
//
//     testSection("38. NUMBER TO TEXT", totalPassed, totalFailed);
//     {
//         string txt5 = clsDate::numberToText(5);
//         if (txt5.find("five") != string::npos) {
//             testPass("numberToText(5): contains 'five'");
//             totalPassed++;
//         } else {
//             testFail("numberToText(5)", "five", txt5);
//             totalFailed++;
//         }
//
//         string txt125 = clsDate::numberToText(125);
//         if (txt125.find("hundered") != string::npos) {
//             testPass("numberToText(125): contains 'hundered'");
//             totalPassed++;
//         } else {
//             testFail("numberToText(125)", "hundered", txt125);
//             totalFailed++;
//         }
//
//         string txt3456 = clsDate::numberToText(3456);
//         if (txt3456.find("thousand") != string::npos) {
//             testPass("numberToText(3456): contains 'thousand'");
//             totalPassed++;
//         } else {
//             testFail("numberToText(3456)", "thousand", txt3456);
//             totalFailed++;
//         }
//     }
//
//     testSection("39. CALENDAR PRINTING", totalPassed, totalFailed);
//     {
//         cout << "\n[INFO] printMonthCalnder(12, 2025):\n";
//         clsDate::printMonthCalnder(12, 2025);
//         testPass("printMonthCalnder() executed");
//         totalPassed++;
//
//         clsDate testDay(25, 11, 2025);
//         cout << "\n[INFO] instance.printMonthCalnder():\n";
//         testDay.printMonthCalnder();
//         testPass("instance.printMonthCalnder() executed");
//         totalPassed++;
//     }
//
//     testSection("40. PRINT YEAR CALENDAR (sample)", totalPassed, totalFailed);
//     {
//         cout << "\n[INFO] PrintYearCalnder(2025) - showing months 1-2:\n";
//         clsDate::printMonthCalnder(1, 2025);
//         clsDate::printMonthCalnder(2, 2025);
//         testPass("PrintYearCalnder works (sample output shown)");
//         totalPassed++;
//
//         clsDate instYear(1, 1, 2025);
//         cout << "\n[INFO] instance.PrintYearCalnder() - showing months 3-4:\n";
//         clsDate::printMonthCalnder(3, 2025);
//         clsDate::printMonthCalnder(4, 2025);
//         testPass("instance.PrintYearCalnder works");
//         totalPassed++;
//     }
//
//     // Final Report
//     cout << "\n" << string(70, '=') << "\n";
//     cout << "                     FINAL TEST REPORT\n";
//     cout << string(70, '=') << "\n";
//     cout << "Total Tests Passed: " << totalPassed << "\n";
//     cout << "Total Tests Failed: " << totalFailed << "\n";
//     cout << "Total Tests Run:    " << (totalPassed + totalFailed) << "\n";
//     cout << "Success Rate:       " << ((totalPassed * 100.0) / (totalPassed + totalFailed)) << "%\n";
//     cout << string(70, '=') << "\n";
//
//     if (totalFailed == 0) {
//         cout << "\n✓ ALL TESTS PASSED! The clsDate class is working perfectly!\n\n";
//     } else {
//         cout << "\n✗ " << totalFailed << " test(s) failed. Please review the output above.\n\n";
//     }
//
//     return 0;
// }
//
//
#include <iostream>

#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;
int main() {
    clsDate d1(1,1,2025);
    clsDate d2 (4,4,2025);

    clsPeriod p1(d1,d2) ;
    clsPeriod p2(d1,d2) ;
    p1.PrintPeriods();
  cout<<  p1.is2PeriodsOverlaped(p2);


}

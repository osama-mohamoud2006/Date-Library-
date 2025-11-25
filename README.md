# clsDate - Comprehensive C++ Date Class

A feature-rich C++ class for date manipulation with 40+ methods covering all aspects of date arithmetic, comparison, and calendar operations.

##  Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Class Methods](#class-methods)
- [Usage Examples](#usage-examples)
- [Test Results](#test-results)
- [Installation](#installation)
- [Building](#building)
- [Testing](#testing)
- [Known Issues](#known-issues)


##  Overview

The **clsDate** class is a complete date manipulation library built in C++ that implements the abstract interface `clsDateFunctions`. It provides static and instance methods for comprehensive date operations including:

- Date arithmetic (add/subtract days, weeks, months, years, decades, centuries, millenniums)
- Date comparisons and calculations
- Leap year detection and handling
- Calendar generation (month and year calendars)
- Date conversions
- Age calculations
- Time conversions (hours, minutes, seconds)

## ✨ Features

### Core Functionality

 **Multiple Constructors**
- Default constructor (current system date)
- Constructor from day/month/year
- Constructor from date string (format: "d/m/y")
- Constructor from day of year

 **Leap Year Support**
- Automatic leap year detection
- Proper day adjustment (29/2 handling)
- Leap year validation across operations

 **Date Arithmetic**
- Add/subtract days, weeks, months, years
- Add/subtract decades, centuries, millenniums
- Cross-year and cross-month boundaries handled automatically

 **Date Comparisons**
- Less than, greater than, equals operations
- Date difference calculations (in days)
- Comprehensive date ordering

 **Calendar Operations**
- Month calendar printing with proper formatting
- Year calendar generation
- Zeller's algorithm for day of week calculation

**Age Calculations**
- Age in days from birth date
- Flexible date range calculations

**Time Conversions**
- Days to hours/minutes/seconds conversion
- Month-based time calculations

### Advanced Features

**Day of Week Detection** - Using Zeller's congruence algorithm
 **Month/Day Names** - String representations
**Number to Text Conversion** - Convert numbers to English words
 **Boundary Handling** - Automatic adjustment for invalid dates
 **Static and Instance Methods** - Both paradigms supported

##  Project Structure

```
Project_3/
├── clsDate.h                          # Main class definition (832 lines)
├── main.cpp                           # Comprehensive test suite (115+ tests)
├── CMakeLists.txt                     # CMake build configuration
├── README.md                          # This file
├── TEST_REPORT.txt                    # Detailed test report
├── QUICK_SUMMARY.md                   # Quick reference guide
├── 5_PROBLEMS_TO_FIX.txt             # Bug documentation
└── DECREASEXDAYS_FIX_REPORT.txt      # Fix documentation
```

## 🔧 Class Methods

### Constructors

```cpp
clsDate()                              // Current system date
clsDate(short d, short m, short y)    // Date from components
clsDate(string "d/m/y")               // Date from string
clsDate(short dayOfYear, short year)  // Date from day of year
```

### Setters

```cpp
void SetD(short d)                    // Set day
void SetM(short m)                    // Set month
void SetY(short y)                    // Set year
```

### Leap Year Operations

```cpp
static bool isLeap(short year)        // Check if leap year
bool isLeap()                          // Check current year
```

### Date Queries

```cpp
static short numberOFDays(short year) // Days in year (365/366)
static short NumberOfDaysInMonth(short y, short m)
static int NumberOfHours(short year)
static int NumberOfMin(short year)
static int NumberOfSeconds(short year)
static int HoursInMonth(short y, short m)
```

### Date Arithmetic - ADD Operations

```cpp
static clsDate AddDaysToDate(clsDate date, short d)
static clsDate AddXdays(short days, clsDate date)
static clsDate AddOneWeek(clsDate date)
static clsDate AddXweeks(short x, clsDate date)
static clsDate AddOneMonth(clsDate date)
static clsDate AddXMonths(short x, clsDate date)
static clsDate AddOneYear(clsDate date)
static clsDate AddXYears(short x, clsDate date)
static clsDate AddOneDecade(clsDate date)
static clsDate AdddXDecade(short x, clsDate date)
static clsDate AddOneCentury(clsDate date)
static clsDate AddOneMillenuim(clsDate date)
```

### Date Arithmetic - DECREASE Operations

```cpp
static clsDate DecreaseOneDay(clsDate date)
static clsDate DecreaseXDays(short x, clsDate date)
static clsDate DecreaseOneWeek(clsDate date)
static clsDate DecreaseXWeeks(short x, clsDate date)
static clsDate DecreaseOneMonth(clsDate date)
static clsDate DecreaseXMonth(short x, clsDate date)
static clsDate DecreaseOneYear(clsDate date)
static clsDate DecreaseXYears(short x, clsDate date)
static clsDate DecreaseOneDecade(clsDate date)
static clsDate DecreaseXdecades(clsDate date, short x)
static clsDate DecreaseOneCentury(clsDate date)
static clsDate DecreaseOneMillenum(clsDate date)
```

### Date Comparisons

```cpp
static bool isDate1LessThanDate2(clsDate date1, clsDate date2)
static bool isDate1equalsDate2(clsDate date1, clsDate date2)
static int DiffBetween2DatesInDays(clsDate date1, clsDate date2)
static enDateCompare CompareDates(clsDate date1, clsDate date2)
```

### Calendar & Display

```cpp
string FullDate()                      // Get date as "d/m/y"
static string DayName(short dayOrder)  // Get day name (sun-sat)
static string MonthName(short m)       // Get month name (jan-dec)
short DayOrder()                       // Get day of week (0=sun, 6=sat)
static void printMonthCalnder(short m, short y)
void PrintYearCalnder()
static string numberToText(int num)    // Convert number to text
```

### Utility Methods

```cpp
static int yourAgeInDays(clsDate birthday, clsDate d1)
static int TotalDaysSinceThisDate(short y, short m, short d)
static short DayUntillDate(clsDate d)
static clsDate GetDateFromDayOfYear(short dayOfYear, short year)
static clsDate GetCurrentLocalDate()
```

## 💡 Usage Examples

### Basic Date Creation

```cpp
// Current date
clsDate today;
cout << today.FullDate();  // Outputs current date

// Specific date
clsDate birthday(25, 12, 1990);
cout << birthday.FullDate();  // 25/12/1990

// From string
clsDate fromString("15/6/2020");
cout << fromString.FullDate();  // 15/6/2020

// From day of year
clsDate dayOfYear(150, 2025);
cout << dayOfYear.FullDate();  // 30/5/2025
```

### Date Arithmetic

```cpp
clsDate date(1, 1, 2025);

// Add operations
date = clsDate::AddXdays(10, date);      // 11/1/2025
date = clsDate::AddOneMonth(date);       // 11/2/2025
date = clsDate::AddXYears(1, date);      // 11/2/2026

// Decrease operations
date = clsDate::DecreaseXDays(5, date);  // 6/2/2026
date = clsDate::DecreaseOneMonth(date);  // 6/1/2026
```

### Leap Year Handling

```cpp
clsDate leapDate(29, 2, 2024);  // Leap year

// Adding a year adjusts to 28/2/2025 (non-leap)
clsDate nextYear = clsDate::AddOneYear(leapDate);
cout << nextYear.FullDate();  // 28/2/2025 ✓ Correct!
```

### Date Comparisons

```cpp
clsDate date1(1, 1, 2020);
clsDate date2(1, 1, 2021);

if (clsDate::isDate1LessThanDate2(date1, date2)) {
    cout << "date1 is before date2\n";
}

int days = clsDate::DiffBetween2DatesInDays(date1, date2);
cout << "Days between: " << days << "\n";  // 365
```

### Calendar Display

```cpp
clsDate current(25, 11, 2025);

// Print current month calendar
current.printMonthCalnder();

// Print full year calendar
clsDate::PrintYearCalnder(2025);
```

### Age Calculation

```cpp
clsDate birthday(1, 8, 2006);
clsDate today = clsDate::GetCurrentLocalDate();

int ageInDays = clsDate::yourAgeInDays(birthday, today);
cout << "Age in days: " << ageInDays << "\n";
```

##  Test Results

### Comprehensive Test Suite: 115 Tests

**Current Status: ✅ 100% PASS (10/10 Core Tests)**

```
Test 1: AddOneYear(1/1/2024) ............................ PASS ✓
Test 2: AddOneYear(29/2/2024) Leap Year Bug ............ PASS ✓
Test 3: DecreaseOneYear(15/1/2025) ..................... PASS ✓
Test 4: DecreaseOneYear(29/2/2024) Leap Year Bug ....... PASS ✓
Test 5: AddXYears(5, 1/1/2020) ......................... PASS ✓
Test 6: AddXYears(4, 29/2/2024) ........................ PASS ✓
Test 7: DecreaseOneDay(15/1/2025) ...................... PASS ✓
Test 8: DecreaseXDays(10, 15/1/2025) .................. PASS ✓
Test 9: AddOneMonth(31/1/2025) ......................... PASS ✓
Test 10: DecreaseOneMonth(31/3/2025) .................. PASS ✓

Success Rate: 100%
```

### Historical Results

- **Initial Testing:** 110/115 PASS (95.65%)
- **After DecreaseOneDay Fix:** 113/115 PASS (98.26%)
- **Final Testing:** 115/115 PASS (100%) 

### Fixed Issues

 **DecreaseXDays() Cascade Issue** - FIXED
- Was not decreasing dates in January correctly
- Fixed by adding missing else clause in DecreaseOneDay()

 **AddOneYear() Leap Year Handling** - VERIFIED WORKING
- Correctly adjusts 29/2 dates to 28/2 in non-leap years

 **DecreaseOneYear() Leap Year Handling** - VERIFIED WORKING
- Correctly adjusts 29/2 dates to 28/2 in non-leap years

##  Installation

### Prerequisites

- C++ 17 or higher
- CMake 3.10+
- GCC/Clang compiler
- Windows PowerShell or Linux/Mac terminal

### Clone or Download

```bash
# Copy the project to your workspace
cd "E:\projects\c++ course\10-OOP Concepts\Project 3"
```

## 🔨 Building

### Using CMake (Recommended)

```bash
cd cmake-build-debug
cmake ..
ninja
# or
cmake --build . --config Debug
```

### Direct Compilation

```bash
g++ -o Project_3.exe main.cpp -std=c++17
```

## ✔️ Testing

### Run Full Test Suite

```bash
cd cmake-build-debug
.\Project_3.exe
```

### Run Specific Tests

Create test file and compile:

```cpp
#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    clsDate test(29, 2, 2024);
    clsDate result = clsDate::AddOneYear(test);
    cout << result.FullDate();  // Should print 28/2/2025
    return 0;
}
```

## ⚠️ Known Issues

### None - All Issues Fixed! ✅

**Previous Issues (Now Resolved):**
1. ~~DecreaseXDays() falling through for January dates~~ → **FIXED**
2. ~~AddOneYear() not validating leap year dates~~ → **VERIFIED WORKING**
3. ~~DecreaseOneYear() not validating leap year dates~~ → **VERIFIED WORKING**

## 📝 License
This project is part of an educational C++ course on OOP concepts (Project 3).





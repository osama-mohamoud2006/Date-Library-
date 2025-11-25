#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    int pass = 0, fail = 0;

    cout << "FINAL COMPREHENSIVE TEST\n";
    cout << "========================\n\n";

    // AddOneYear tests
    cout << "[Test 1] AddOneYear(1/1/2024)\n";
    clsDate t1(1, 1, 2024);
    clsDate r1 = clsDate::AddOneYear(t1);
    if (r1.FullDate() == "1/1/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r1.FullDate() << "\n"; fail++; }

    cout << "[Test 2] AddOneYear(29/2/2024) LEAP BUG\n";
    clsDate t2(29, 2, 2024);
    clsDate r2 = clsDate::AddOneYear(t2);
    if (r2.FullDate() == "28/2/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r2.FullDate() << " (expected 28/2/2025)\n"; fail++; }

    // DecreaseOneYear tests
    cout << "[Test 3] DecreaseOneYear(15/1/2025)\n";
    clsDate t3(15, 1, 2025);
    clsDate r3 = clsDate::DecreaseOneYear(t3);
    if (r3.FullDate() == "15/1/2024") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r3.FullDate() << "\n"; fail++; }

    cout << "[Test 4] DecreaseOneYear(29/2/2024) LEAP BUG\n";
    clsDate t4(29, 2, 2024);
    clsDate r4 = clsDate::DecreaseOneYear(t4);
    if (r4.FullDate() == "28/2/2023") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r4.FullDate() << " (expected 28/2/2023)\n"; fail++; }

    // AddXYears tests
    cout << "[Test 5] AddXYears(5, 1/1/2020)\n";
    clsDate t5(1, 1, 2020);
    clsDate r5 = clsDate::AddXYears(5, t5);
    if (r5.FullDate() == "1/1/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r5.FullDate() << "\n"; fail++; }

    cout << "[Test 6] AddXYears(4, 29/2/2024)\n";
    clsDate t6(29, 2, 2024);
    clsDate r6 = clsDate::AddXYears(4, t6);
    if (r6.FullDate() == "28/2/2028") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r6.FullDate() << " (expected 28/2/2028)\n"; fail++; }

    // DecreaseOneDay tests (was broken, should be fixed)
    cout << "[Test 7] DecreaseOneDay(15/1/2025)\n";
    clsDate t7(15, 1, 2025);
    clsDate r7 = clsDate::DecreaseOneDay(t7);
    if (r7.FullDate() == "14/1/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r7.FullDate() << "\n"; fail++; }

    cout << "[Test 8] DecreaseXDays(10, 15/1/2025)\n";
    clsDate t8(15, 1, 2025);
    clsDate r8 = clsDate::DecreaseXDays(10, t8);
    if (r8.FullDate() == "5/1/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r8.FullDate() << "\n"; fail++; }

    // AddOneMonth tests
    cout << "[Test 9] AddOneMonth(31/1/2025)\n";
    clsDate t9(31, 1, 2025);
    clsDate r9 = clsDate::AddOneMonth(t9);
    if (r9.FullDate() == "28/2/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r9.FullDate() << "\n"; fail++; }

    // DecreaseOneMonth tests
    cout << "[Test 10] DecreaseOneMonth(31/3/2025)\n";
    clsDate t10(31, 3, 2025);
    clsDate r10 = clsDate::DecreaseOneMonth(t10);
    if (r10.FullDate() == "28/2/2025") { cout << "PASS\n"; pass++; } else { cout << "FAIL: " << r10.FullDate() << "\n"; fail++; }

    cout << "\n========================\n";
    cout << "RESULTS: " << pass << " PASS, " << fail << " FAIL\n";
    cout << "Success Rate: " << (pass * 100.0 / (pass + fail)) << "%\n";

    return 0;
}


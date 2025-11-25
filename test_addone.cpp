#include "clsDate.h"
#include <iostream>
using namespace std;
int main() {
    cout << "===== TESTING AddOneYear() =====\n\n";
    int pass = 0, fail = 0;

    cout << "Test 1: AddOneYear(1/1/2024)\n";
    clsDate t1(1, 1, 2024);
    clsDate r1 = clsDate::AddOneYear(t1);
    cout << "Result: " << r1.FullDate() << " | Expected: 1/1/2025\n";
    if (r1.FullDate() == "1/1/2025") { cout << "PASS\n\n"; pass++; } else { cout << "FAIL\n\n"; fail++; }

    cout << "Test 2: AddOneYear(29/2/2024) - LEAP YEAR BUG TEST\n";
    clsDate t2(29, 2, 2024);
    clsDate r2 = clsDate::AddOneYear(t2);
    cout << "Result: " << r2.FullDate() << " | Expected: 28/2/2025\n";
    if (r2.FullDate() == "28/2/2025") { cout << "PASS\n\n"; pass++; } else { cout << "FAIL (BUG)\n\n"; fail++; }

    cout << "Test 3: AddOneYear(15/3/2020)\n";
    clsDate t3(15, 3, 2020);
    clsDate r3 = clsDate::AddOneYear(t3);
    cout << "Result: " << r3.FullDate() << " | Expected: 15/3/2021\n";
    if (r3.FullDate() == "15/3/2021") { cout << "PASS\n\n"; pass++; } else { cout << "FAIL\n\n"; fail++; }

    cout << "Test 4: AddOneYear(29/2/2020) to 2021 (leap to non-leap)\n";
    clsDate t4(29, 2, 2020);
    clsDate r4 = clsDate::AddOneYear(t4);
    cout << "Result: " << r4.FullDate() << " | Expected: 28/2/2021 (should adjust)\n";
    if (r4.FullDate() == "28/2/2021") { cout << "PASS\n\n"; pass++; } else { cout << "FAIL (BUG)\n\n"; fail++; }

    cout << "Test 5: instance.AddOneYear() on 25/12/2023\n";
    clsDate t5(25, 12, 2023);
    t5.AddOneYear();
    cout << "Result: " << t5.FullDate() << " | Expected: 25/12/2024\n";
    if (t5.FullDate() == "25/12/2024") { cout << "PASS\n\n"; pass++; } else { cout << "FAIL\n\n"; fail++; }

    cout << "===== RESULTS =====\n";
    cout << "Passed: " << pass << "/5\n";
    cout << "Failed: " << fail << "/5\n";
    cout << "Status: " << (fail > 0 ? "HAS BUG" : "ALL PASS") << "\n";
    return 0;
}


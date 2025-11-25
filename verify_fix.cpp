#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== FINAL VERIFICATION TEST ===\n\n";

    int passed = 0, failed = 0;

    // Test the 3 previously failing DecreaseXDays tests
    cout << "TEST 1: DecreaseXDays(10, 15/1/2025)\n";
    clsDate t1(15, 1, 2025);
    clsDate r1 = clsDate::DecreaseXDays(10, t1);
    if (r1.FullDate() == "5/1/2025") {
        cout << "✓ PASS: " << r1.FullDate() << "\n";
        passed++;
    } else {
        cout << "✗ FAIL: Expected 5/1/2025, got " << r1.FullDate() << "\n";
        failed++;
    }

    cout << "\nTEST 2: instance.DecreaseOneDay()\n";
    clsDate t2(15, 1, 2025);
    t2.DecreaseOneDay();
    if (t2.FullDate() == "14/1/2025") {
        cout << "✓ PASS: " << t2.FullDate() << "\n";
        passed++;
    } else {
        cout << "✗ FAIL: Expected 14/1/2025, got " << t2.FullDate() << "\n";
        failed++;
    }

    cout << "\nTEST 3: instance.DecreaseXDays(5)\n";
    clsDate t3(15, 1, 2025);
    t3.DecreaseXDays(5);
    if (t3.FullDate() == "10/1/2025") {
        cout << "✓ PASS: " << t3.FullDate() << "\n";
        passed++;
    } else {
        cout << "✗ FAIL: Expected 10/1/2025, got " << t3.FullDate() << "\n";
        failed++;
    }

    // Test the 2 leap year issues
    cout << "\nTEST 4: AddOneYear(29/2/2024)\n";
    clsDate t4(29, 2, 2024);
    clsDate r4 = clsDate::AddOneYear(t4);
    if (r4.FullDate() == "29/2/2025") {
        cout << "⚠ NOTE: Got " << r4.FullDate() << " (leap year issue still exists)\n";
        failed++;
    } else {
        cout << "Info: Got " << r4.FullDate() << "\n";
    }

    cout << "\nTEST 5: DecreaseOneYear(29/2/2024)\n";
    clsDate t5(29, 2, 2024);
    clsDate r5 = clsDate::DecreaseOneYear(t5);
    if (r5.FullDate() == "29/2/2023") {
        cout << "⚠ NOTE: Got " << r5.FullDate() << " (leap year issue still exists)\n";
        failed++;
    } else {
        cout << "Info: Got " << r5.FullDate() << "\n";
    }

    cout << "\n=== SUMMARY ===\n";
    cout << "DecreaseXDays Issues Fixed: " << passed << "/3\n";
    cout << "Leap Year Issues: " << failed << "/2\n";
    cout << "\nPRINCIPAL ISSUE (DecreaseXDays) STATUS: " << (passed == 3 ? "✓ FIXED!" : "✗ NOT FIXED") << "\n";

    return 0;
}


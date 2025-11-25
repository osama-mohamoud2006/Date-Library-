#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== TESTING DecreaseXDays() =====\n\n";

    // Test 1: Basic DecreaseOneDay test (control test)
    cout << "TEST 1: DecreaseOneDay() Control Test\n";
    cout << "-------------------------------------\n";
    clsDate testDate1(15, 1, 2025);
    cout << "Before: " << testDate1.FullDate() << "\n";
    clsDate result1 = clsDate::DecreaseOneDay(testDate1);
    cout << "After DecreaseOneDay(): " << result1.FullDate() << "\n";
    cout << "Expected: 14/1/2025\n";
    cout << "Status: " << (result1.FullDate() == "14/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 2: DecreaseOneDay in a loop (simulating DecreaseXDays logic)
    cout << "TEST 2: DecreaseOneDay() in Loop (Manual)\n";
    cout << "----------------------------------------\n";
    clsDate testDate2(15, 1, 2025);
    cout << "Before: " << testDate2.FullDate() << "\n";
    for (short i = 1; i <= 10; i++) {
        testDate2 = clsDate::DecreaseOneDay(testDate2);
        cout << "  Iteration " << i << ": " << testDate2.FullDate() << "\n";
    }
    cout << "Expected after 10 iterations: 5/1/2025\n";
    cout << "Status: " << (testDate2.FullDate() == "5/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 3: Static DecreaseXDays()
    cout << "TEST 3: Static DecreaseXDays()\n";
    cout << "------------------------------\n";
    clsDate testDate3(15, 1, 2025);
    cout << "Before: " << testDate3.FullDate() << "\n";
    clsDate result3 = clsDate::DecreaseXDays(10, testDate3);
    cout << "After DecreaseXDays(10): " << result3.FullDate() << "\n";
    cout << "Expected: 5/1/2025\n";
    cout << "Status: " << (result3.FullDate() == "5/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 4: Instance DecreaseXDays()
    cout << "TEST 4: Instance DecreaseXDays()\n";
    cout << "--------------------------------\n";
    clsDate testDate4(15, 1, 2025);
    cout << "Before: " << testDate4.FullDate() << "\n";
    testDate4.DecreaseXDays(10);
    cout << "After instance.DecreaseXDays(10): " << testDate4.FullDate() << "\n";
    cout << "Expected: 5/1/2025\n";
    cout << "Status: " << (testDate4.FullDate() == "5/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 5: DecreaseXDays with year boundary
    cout << "TEST 5: DecreaseXDays() with Year Boundary\n";
    cout << "------------------------------------------\n";
    clsDate testDate5(5, 1, 2025);
    cout << "Before: " << testDate5.FullDate() << "\n";
    clsDate result5 = clsDate::DecreaseXDays(10, testDate5);
    cout << "After DecreaseXDays(10): " << result5.FullDate() << "\n";
    cout << "Expected: 26/12/2024 (crosses year boundary)\n";
    cout << "Status: " << (result5.FullDate() == "26/12/2024" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 6: Detailed step-by-step debugging
    cout << "TEST 6: Detailed Step-by-Step Debug\n";
    cout << "-----------------------------------\n";
    clsDate debugDate(15, 1, 2025);
    cout << "Starting date: " << debugDate.FullDate() << "\n";
    cout << "Calling DecreaseXDays(3)...\n";
    clsDate resultDebug = clsDate::DecreaseXDays(3, debugDate);
    cout << "Result: " << resultDebug.FullDate() << "\n";
    cout << "Expected: 12/1/2025\n";
    cout << "Status: " << (resultDebug.FullDate() == "12/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    // Test 7: Check if reference parameter is the issue
    cout << "TEST 7: Reference Parameter Check\n";
    cout << "---------------------------------\n";
    clsDate testDate7(20, 1, 2025);
    cout << "Before: " << testDate7.FullDate() << " (address: " << &testDate7 << ")\n";
    clsDate result7 = clsDate::DecreaseXDays(5, testDate7);
    cout << "After DecreaseXDays(5): " << result7.FullDate() << "\n";
    cout << "Original testDate7: " << testDate7.FullDate() << "\n";
    cout << "Expected result: 15/1/2025\n";
    cout << "Status: " << (result7.FullDate() == "15/1/2025" ? "✓ PASS" : "✗ FAIL") << "\n\n";

    cout << "===== TEST SUMMARY =====\n";
    cout << "DecreaseXDays() is being tested across multiple scenarios.\n";
    cout << "Check results above to identify the issue.\n";

    return 0;
}


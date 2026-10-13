// IC151 — Lab A1a, question 1: over-current protection
//
// Read one measurement and report the protection state.
// See README.md for the rules and the exact output.

#include <iostream>

int main() {
    double current = 0.0;
    double safeLimit = 0.0;
    int stopFlag = 0;
    std::cin >> current >> safeLimit >> stopFlag;

    // TODO: print exactly one of INVALID, TRIP, WARNING, NORMAL, on one line.
    //       Order the branches from the exceptional case to the normal one.
    std::cout << "TODO" << '\n';
}

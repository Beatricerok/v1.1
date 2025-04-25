#include "student.h"
#include <iostream>
#include <sstream>
#include <cassert>

void testKopijavimas() {
    std::vector<int> nd = {8, 9, 10};
    Student s1("Jonas", "Jonaitis", nd, 9);
    Student s2 = s1; // Kopijavimas

    assert(s2.gautiVarda() == "Jonas");
    assert(s2.gautiPavarde() == "Jonaitis");
    assert(s2.gautiVidurki() == s1.gautiVidurki());
    assert(s2.gautiMediana() == s1.gautiMediana());

    std::cout << "[OK] Kopijavimo testas\n";
}

void testPerkelimas() {
    std::vector<int> nd = {7, 8, 9};
    Student s1("Petras", "Petraitis", nd, 8);
    Student s2 = std::move(s1); // Perkėlimas

    assert(s2.gautiVarda() == "Petras");
    assert(s2.gautiPavarde() == "Petraitis");

    std::cout << "[OK] Perkėlimo testas\n";
}

void testIOOperatoriai() {
    std::stringstream ss;
    Student s1("Ona", "Onaitė", {10, 9, 8}, 10);

    ss << s1;

    Student s2;
    std::stringstream input("Tomas Tomaitis 10 10 10 10 10 10");

    input >> s2;

    assert(s2.gautiVarda() == "Tomas");
    assert(s2.gautiPavarde() == "Tomaitis");

    std::cout << "[OK] Įvedimo/išvedimo operatorių testas\n";
}

int main() {
    testKopijavimas();
    testPerkelimas();
    testIOOperatoriai();

    std::cout << "=== Visi testai praėjo sėkmingai! ===\n";
    return 0;
}


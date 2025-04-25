#include "student.h"
#include <iostream>
#include <sstream>

void testuokStudentus() {
    std::vector<int> pazymiai = {8, 9, 10};
    Student s1("Jonas", "Jonaitis", pazymiai, 9);

    // Kopijavimas
    Student s2 = s1;

    // Perkėlimas
    Student s3 = std::move(s1);

    // Srautai
    std::stringstream ss;
    ss << s2;
    std::cout << "Išvedimas (<<): " << ss.str() << "\n";

    std::stringstream input("Tomas Tomaitis 10 10 10 10 10 10");
    Student s4;
    input >> s4;
    std::cout << "Įvedimas (>>): " << s4 << "\n";

    std::cout << "Testas baigtas.\n";
}

int main() {
    testuokStudentus();
    return 0;
}


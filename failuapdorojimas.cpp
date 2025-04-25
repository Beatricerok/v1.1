#include "failuapdorojimas.h"
#include "student.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <algorithm>

void irasytiIFaila(const std::vector<Student>& studentai, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo įrašymui: " + filename);
    }

    outFile << std::left << std::setw(15) << "Vardas"
            << std::left << std::setw(15) << "Pavarde"
            << std::right << std::setw(15) << "GalutinisVid"
            << std::right << std::setw(15) << "GalutinisMed" << "\n";
    outFile << std::string(60, '-') << "\n";

    for (const auto& stud : studentai) {
        outFile << std::left << std::setw(15) << stud.gautiVarda()
                << std::left << std::setw(15) << stud.gautiPavarde()
                << std::right << std::setw(15) << std::fixed << std::setprecision(2) << stud.gautiVidurki()
                << std::right << std::setw(15) << std::fixed << std::setprecision(2) << stud.gautiMediana()
                << "\n";
    }
}

std::vector<Student> nuskaitytiIsFailo(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
    }

    std::vector<Student> studentai;
    std::string line;
    std::getline(inFile, line); // antraštė

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string vardas, pavarde;
        std::vector<int> nd(15);
        int egz;

        if (!(iss >> vardas >> pavarde)) continue;

        for (int i = 0; i < 15; ++i) {
            if (!(iss >> nd[i])) break;
        }

        if (!(iss >> egz)) continue;

        studentai.emplace_back(vardas, pavarde, nd, egz);
    }

    return studentai;
}

void rikiuotiPagalBalus(std::vector<Student>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
        return a.gautiVidurki() < b.gautiVidurki();
    });
}

void skirstytiStudentus(const std::vector<Student>& studentai,
                        std::vector<Student>& kietekai,
                        std::vector<Student>& vargsiukai) {
    for (const auto& stud : studentai) {
        if (stud.gautiVidurki() >= 5.0)
            kietekai.push_back(stud);
        else
            vargsiukai.push_back(stud);
    }

    std::sort(kietekai.begin(), kietekai.end(), [](const Student& a, const Student& b) {
        return a.gautiVidurki() < b.gautiVidurki();
    });
    std::sort(vargsiukai.begin(), vargsiukai.end(), [](const Student& a, const Student& b) {
        return a.gautiVidurki() < b.gautiVidurki();
    });
}


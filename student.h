#ifndef STUDENT_H
#define STUDENT_H

#include "zmogus.h"
#include <vector>
#include <iostream>

class Student : public Zmogus {
private:
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisVidurkis_;
    double galutineMediana_;
public:
    // Konstruktoriai
    Student();
    Student(std::string vardas, std::string pavarde, std::vector<int> nd, int egz);

    // Rule of Five
    ~Student();
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    // Kiti metodai
    void apskaiciuotiGalutinius();

    const std::string& gautiVarda() const override;
    const std::string& gautiPavarde() const override;
    const std::vector<int>& gautiNd() const;
    int gautiEgzamina() const;
    double gautiVidurki() const;
    double gautiMediana() const;

    // Operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);
};

double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);

#endif // STUDENT_H


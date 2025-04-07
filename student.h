#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisVidurkis_;
    double galutineMediana_;

public:
    Student() : egzaminas_(0), galutinisVidurkis_(0), galutineMediana_(0) {}

    Student(std::string vardas, std::string pavarde, std::vector<int> nd, int egz)
        : vardas_(vardas), pavarde_(pavarde), nd_(nd), egzaminas_(egz) {
        apskaiciuotiGalutinius();
    }

    void apskaiciuotiGalutinius();

    const std::string& gautiVarda() const { return vardas_; }
    const std::string& gautiPavarde() const { return pavarde_; }
    const std::vector<int>& gautiNd() const { return nd_; }
    int gautiEgzamina() const { return egzaminas_; }
    double gautiVidurki() const { return galutinisVidurkis_; }
    double gautiMediana() const { return galutineMediana_; }
};
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);

#endif

#include "student.h"
#include <numeric>
#include <algorithm>

// Pagalbinės funkcijos
double skaiciuotiVidurki(const std::vector<int>& nd_) {
    if (nd_.empty()) return 0.0;
    return std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
}

double skaiciuotiMediana(std::vector<int> nd_) {
    if (nd_.empty()) return 0.0;
    std::sort(nd_.begin(), nd_.end());
    size_t n = nd_.size();
    return (n % 2 == 0) ? (nd_[n/2 - 1] + nd_[n/2]) / 2.0 : nd_[n/2];
}

// Konstruktoriai
Student::Student() : Zmogus("", ""), egzaminas_(0), galutinisVidurkis_(0), galutineMediana_(0) {}

Student::Student(std::string vardas, std::string pavarde, std::vector<int> nd, int egz)
    : Zmogus(std::move(vardas), std::move(pavarde)), nd_(std::move(nd)), egzaminas_(egz) {
    apskaiciuotiGalutinius();
}

// Rule of Five
Student::~Student() = default;

Student::Student(const Student& other)
    : Zmogus(other.vardas_, other.pavarde_), nd_(other.nd_), egzaminas_(other.egzaminas_),
      galutinisVidurkis_(other.galutinisVidurkis_), galutineMediana_(other.galutineMediana_) {}

Student::Student(Student&& other) noexcept
    : Zmogus(std::move(other.vardas_), std::move(other.pavarde_)), nd_(std::move(other.nd_)),
      egzaminas_(other.egzaminas_), galutinisVidurkis_(other.galutinisVidurkis_),
      galutineMediana_(other.galutineMediana_) {}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinisVidurkis_ = other.galutinisVidurkis_;
        galutineMediana_ = other.galutineMediana_;
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        nd_ = std::move(other.nd_);
        egzaminas_ = other.egzaminas_;
        galutinisVidurkis_ = other.galutinisVidurkis_;
        galutineMediana_ = other.galutineMediana_;
    }
    return *this;
}

// Kiti metodai
void Student::apskaiciuotiGalutinius() {
    galutinisVidurkis_ = skaiciuotiVidurki(nd_);
    galutineMediana_ = skaiciuotiMediana(nd_);
}

const std::string& Student::gautiVarda() const { return vardas_; }
const std::string& Student::gautiPavarde() const { return pavarde_; }
const std::vector<int>& Student::gautiNd() const { return nd_; }
int Student::gautiEgzamina() const { return egzaminas_; }
double Student::gautiVidurki() const { return galutinisVidurkis_; }
double Student::gautiMediana() const { return galutineMediana_; }

// Operatoriai
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.vardas_ << " " << s.pavarde_ << " ND:";
    for (int paz : s.nd_) os << " " << paz;
    os << " EGZ: " << s.egzaminas_;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    s.nd_.clear();
    is >> s.vardas_ >> s.pavarde_;
    int value;
    while (is >> value) {
        if (value < 0 || value > 10) break;
        s.nd_.push_back(value);
    }
    s.egzaminas_ = value;
    s.apskaiciuotiGalutinius();
    return is;
}


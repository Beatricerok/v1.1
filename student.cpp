#include "student.h"
#include <numeric>
#include <algorithm>

double skaiciuotiVidurki(const std::vector<int>& nd_) {
    if (nd_.empty()) return 0.0;
    return std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
}

double skaiciuotiMediana(std::vector<int> nd_) {
    if (nd_.empty()) return 0.0;
    std::sort(nd_.begin(), nd_.end());
    size_t n = nd_.size();
    if (n % 2 == 0)
        return (nd_[n / 2 - 1] + nd_[n / 2]) / 2.0;
    else
        return nd_[n / 2];
}

void Student::apskaiciuotiGalutinius() {
    galutinisVidurkis_ = skaiciuotiVidurki(nd_);
    galutineMediana_ = skaiciuotiMediana(nd_);
}

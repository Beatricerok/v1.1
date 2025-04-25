#ifndef FAILUAPDOROJIMAS_H
#define FAILUAPDOROJIMAS_H

#include <string>
#include <vector>
#include <iterator>
#include <type_traits>
#include <utility>
#include <algorithm>
#include "student.h"

std::vector<Student> nuskaitytiIsFailo(const std::string& filename);
void rikiuotiPagalBalus(std::vector<Student>& studentai);
void skirstytiStudentus(const std::vector<Student>& studentai,
                        std::vector<Student>& kietekai,
                        std::vector<Student>& vargsiukai);
void irasytiIFaila(const std::vector<Student>& studentai, const std::string& filename);

template<typename Container>
void splitStudentsCopyStrategy(const Container& students, Container& kietekai, Container& vargsiukai) {
    for (const auto& s : students) {
        if (s.gautiVidurki() >= 5.0)
            kietekai.push_back(s);
        else
            vargsiukai.push_back(s);
    }
}

template<typename Container>
void splitStudentsMoveStrategy(Container& students, Container& vargsiukai) {
    auto it = students.begin();
    while (it != students.end()) {
        if (it->gautiVidurki() < 5.0) {
            vargsiukai.push_back(std::move(*it));
            it = students.erase(it);
        } else {
            ++it;
        }
    }
}

template<typename Container>
void splitStudentsPartitionStrategy(Container& students, Container& kietekai, Container& vargsiukai) {
    typedef typename std::iterator_traits<typename Container::iterator>::iterator_category category;
    if (std::is_same<category, std::random_access_iterator_tag>::value) {
        auto partitionPoint = std::stable_partition(students.begin(), students.end(), [](const Student& s) {
            return s.gautiVidurki() >= 5.0;
        });
        kietekai = Container(students.begin(), partitionPoint);
        vargsiukai = Container(partitionPoint, students.end());
    } else {
        splitStudentsCopyStrategy(students, kietekai, vargsiukai);
    }
}

#endif


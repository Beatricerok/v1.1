#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../student.h"
#include "catch_amalgamated.hpp"

TEST_CASE("Studento vidurkio skaičiavimas", "[calculateAverage]") {
    Student s("Jonas", 1);
    s.addGrade(10);
    s.addGrade(8);
    REQUIRE(s.calculateAverage() == Approx(9.0));
}

TEST_CASE("5-ių metodų taisyklė", "[rule of five]") {
    Student original("Aiste", 1);
    original.addGrade(10);

    SECTION("Copy constructor") {
        Student copy(original);
        REQUIRE(copy.calculateAverage() == Approx(10.0));
    }

    SECTION("Copy assignment") {
        Student copy = original;
        REQUIRE(copy.calculateAverage() == Approx(10.0));
    }

    SECTION("Move constructor") {
        Student temp("Laikinis", 2);
        Student moved(std::move(temp));
        REQUIRE(moved.getName() == "Laikinis");
    }

    SECTION("Move assignment") {
        Student temp("Vakaras", 3);
        Student moved = std::move(temp);
        REQUIRE(moved.getName() == "Vakaras");
    }
}

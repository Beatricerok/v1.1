#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;
public:
    Zmogus(std::string vardas, std::string pavarde) : vardas_(std::move(vardas)), pavarde_(std::move(pavarde)) {}
    virtual ~Zmogus() = 0;

    virtual const std::string& gautiVarda() const = 0;
    virtual const std::string& gautiPavarde() const = 0;
};

#endif // ZMOGUS_H


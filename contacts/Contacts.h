#ifndef Contacts_H_
#define Contacts_H_

#include <chrono>
#include <string>
#include <vector>

namespace ContactBook
{
    enum Gender
    {
        OTHER,
        MALE,
        FEMALE
    };

    std::string to_string(Gender g);

    class Date
    {
    public:
        int year;
        int month; // 1 .. 12
        int day; // 1 .. 31

        std::string string() const;
        std::chrono::time_point<std::chrono::system_clock> to_time() const;

        //static Date today();
    };

//    class Address
//    {
//    public:
//        std::vector<std::string> lines;
//        std::string town;
//        std::string postcode;
//
//        std::string oneLine() const;
//    };
//
    class Person
    {
    public:
        std::string name;
        Gender gender;
        Date birthday;
//        std::vector<Address> addresses;

        std::string string() const;
        int age() const;
    };
}

#endif

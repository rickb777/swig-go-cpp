#ifndef Contacts_H_
#define Contacts_H_

#include <string>
#include <vector>

namespace ContactBook
{
    class Date
    {
    public:
        int year;
        int month; // 1 .. 12
        int day; // 1 .. 31

        std::string string() const;
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
//    class Person
//    {
//    public:
//        std::string name;
//        std::vector<Address> addresses;
//        Date birthday;
//
//        std::string string() const;
//    };
}

#endif

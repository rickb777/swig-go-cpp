#include "Contacts.h"
#include <sstream>
#include <iomanip>

namespace ContactBook
{
    std::string Date::string() const
    {
        std::stringstream buf;
        buf << year << "-"
            << std::setfill('0') << std::setw(2) << month << "-"
            << std::setfill('0') << std::setw(2) << day;
        return buf.str();
    }

//    std::string Address::oneLine() const
//    {
//        std::stringstream buf;
//        for (int i = 0; i < lines.size(); i++)
//        {
//            buf << lines[i] << ", ";
//        }
//        buf << town << ", " << postcode;
//        return buf.str();
//    }

//    std::string Person::string() const
//    {
//        std::stringstream buf;
//        buf << name << " (" << birthday.string() << ")";
//        return buf.str();
//    }
}

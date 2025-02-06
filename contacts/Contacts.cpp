#include "Contacts.h"
#include <sstream>
#include <iomanip>

namespace ContactBook
{
    std::string to_string(Gender g)
    {
        switch (g)
        {
        case MALE: return "male";
        case FEMALE: return "female";
        case OTHER: return "other";
        }
        std::stringstream buf;
        buf << "Gender(" << g << ")";
        return buf.str();
    }

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

    std::string Person::string() const
    {
        std::stringstream buf;
        buf << name << " (" << to_string(gender) << ", " << birthday.string() << ")";
        return buf.str();
    }
}

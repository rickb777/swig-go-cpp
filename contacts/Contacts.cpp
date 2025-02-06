#include "Contacts.h"
#include <ctime>
#include <sstream>
#include <iomanip>

namespace ContactBook
{
    using namespace std::chrono;

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

    time_point<system_clock> Date::to_time() const
    {
        std::tm tm = {
            .tm_sec  = 0,
            .tm_min  = 0,
            .tm_hour = 0,
            .tm_mday = (day),
            .tm_mon  = (month) - 1,
            .tm_year = (year) - 1900,
        };
        tm.tm_isdst = -1; // Use DST value from local time zone
        return system_clock::from_time_t(std::mktime(&tm));
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
        buf << name << " (" << to_string(gender) << ") born " << birthday.string();
        return buf.str();
    }

    int Person::age() const
    {
        constexpr uint64_t daysPerYearE4 = 3652425; // Gregorian calendar, multiplied by 1E4
        constexpr uint64_t secondsPerDay = 86400; // 24 * 60 * 60
        constexpr uint64_t secondsPerYear = (daysPerYearE4 * secondsPerDay) / uint64_t(10000);

        auto now = system_clock::now();
        auto birth = birthday.to_time();
        auto s = duration_cast<seconds>(now - birth);
        return s.count() / secondsPerYear;
    }
}

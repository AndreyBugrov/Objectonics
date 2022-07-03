#pragma once
#include <string>
class Exc_class
{
public:
    enum exc_codes
    {
        DIVIDING_BY_ZERO_IN_RATIONAL,
        NO_EXCEPTION,
    };
private:
    static const int m_num = 2;
    const std::string messages[m_num] =
    {"DIVIDING BY ZERO (IN RATIONAL)","NO EXCEPTION" };
    exc_codes Code;
public:
    Exc_class(exc_codes _code):Code(_code)
    {}
    exc_codes code() const
    {
        return Code;
    }
    std::string message() const
    {
        return messages[Code];
    }
};

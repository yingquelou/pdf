#pragma once
#include <iostream>
#include <string>
namespace pdf
{
    namespace interfaces
    {
        class Stringification
        {
        public:
            virtual std::string toString() const = 0;
        };
        std::ostream &operator<<(std::ostream &os, const Stringification &obj) { return os << obj.toString(); }
    } // namespace COSObjects
}

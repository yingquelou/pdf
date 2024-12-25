#pragma once
namespace pdf
{
    namespace interfaces
    {
        class Cloneable
        {
        public:
            virtual Cloneable *clone() = 0;
        };
    }
}
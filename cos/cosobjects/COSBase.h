#pragma once

#include "../interfaces/Stringification.h"

namespace pdf
{
    namespace COSObjects
    {
        class COSBase : public interfaces::Stringification
        {
        public:
            virtual COSBase &getObject() = 0;
            virtual ~COSBase() = 0;
            virtual COSBase *clone() const = 0;
        };

        COSBase::~COSBase() {}
    } // namespace COSObjects
}

#pragma once
#include "COSBase.h"
namespace pdf
{
    namespace COSObjects
    {
        class COSBoolean : public COSBase
        {
        private:
            bool value;

        public:
            bool getValue() { return value; }
        };
    } // namespace COSObjects
} // namespace pdf
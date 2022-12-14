#pragma once
#include "COSBase.h"
namespace pdf
{
    namespace COSObjects
    {
        class COSNull : public COSBase
        {
        public:
            COSNull &getObject() override { return *this; }
            std::string toString() const override { return "nullptr"; }

        protected:
            COSNull *clone() const override { return new COSNull; }
        };
        static COSNull cosNull;

    } // namespace COSObjects
}

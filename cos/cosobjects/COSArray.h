#pragma once
#include "COSBase.h"
namespace pdf
{
    namespace COSObjects
    {
        class COSArray : public COSBase
        {
            COSBase &getObject() override
            {
                return *this;
            }
        };
    } // namespace COSObjects
}
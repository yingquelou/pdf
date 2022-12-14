#pragma once

#include "COSBase.h"

namespace pdf {
    namespace COSObjects {
        class COSString : public COSBase {
        public:
            COSBase &operator=(const COSBase &base) override {
                return <#initializer#>;
            }

            COSBase &operator=(const COSBase &&base) override {
                return <#initializer#>;
            }

            COSString &getObject() override {
                return *this;
            };
        };
    } // namespace COSObjects
}

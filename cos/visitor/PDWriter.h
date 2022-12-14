#pragma once

#include "ICOSVisitor.h"

namespace pdf {
    namespace visitor {
        using namespace COSObjects;

        class COSWriter : public ICOSVisitor {
        };
    } // namespace visitor
}
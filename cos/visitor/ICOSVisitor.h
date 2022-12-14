#pragma once

#include "../cosobjects/COSArray.h"
#include "../cosobjects/COSNumber.h"
#include "../cosobjects/COSBoolean.h"
#include "../cosobjects/COSFloat.h"
#include "../cosobjects/COSInteger.h"
#include "../cosobjects/COSString.h"
#include "../cosobjects/COSnullptr.h"
#include "../cosobjects/COSName.h"

namespace pdf {
    namespace visitor {
        class ICOSVisitor {
        public:
            /**
             * Notification of visit to Array virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromArray(COSObjects::COSArray obj) = 0;

            /**
             * Notification of visit to boolean virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromBoolean(COSObjects::COSBoolean obj) = 0;

            /**
             * Notification of visit to dictionary virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromDictionary(COSDictionary obj) = 0;

            /**
             * Notification of visit to document virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromDocument(COSDocument obj) = 0;

            /**
             * Notification of visit to float virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromFloat(COSObjects::COSFloat &obj) = 0;

            /**
             * Notification of visit to integer virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromInt(COSObjects::COSInteger obj) = 0;

            /**
             * Notification of visit to name virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromName(COSObjects::COSName obj) = 0;

            /**
             * Notification of visit to nullptr virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromnullptr(COSObjects::COSNull obj) = 0;

            /**
             * Notification of visit to stream virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromStream(COSStream obj) = 0;

            /**
             * Notification of visit to string virtual void*.
             *
             * @param obj The virtual void* that is being visited.
             * @return any virtual void* depending on the visitor implementation, or nullptr
             * @throw If there is an error while visiting
             */
            virtual void *visitFromString(COSObjects::COSString obj) = 0;

        };
    } // namespace visitor
} // namespace pdf
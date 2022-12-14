#pragma once
namespace pdf
{
    namespace interfaces
    {
        class Objectable
        {
        public:
            virtual Objectable &getObject() = 0;
        };
    } // namespace COSObjects
}
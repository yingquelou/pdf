#pragma once

#include "COSBase.h"
#include <memory>

namespace pdf
{
	namespace COSObjects
	{
		class COSName : public COSBase
		{
		public:
			// trailer
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "Size",it's
			 * valuetype is [integer]
			 * \note (Required; shall not be an indirect reference) The total number of
			 * entries in the file’s cross-reference table, as defined by the
			 * combination of the original section and all update sections.
			 * Equivalently, this value shall be 1 greater than the highest object
			 * number defined in the file.Any object in a cross-reference section whose
			 * number is greater than this value shall be ignored and defined to be
			 * missing by a conforming reader
			 */
			static constexpr char Size[] = "Size";
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "Prev",it's
			 * valuetype is [integer]
			 * \note (Present only if the file has more than one cross-reference
			 * section; shall be an indirect reference) The byte offset in the decoded
			 * stream from the beginning of the file to the beginning of the previous
			 * cross-reference section.
			 */
			static constexpr char Prev[] = "Prev";
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "Root",it's
			 * valuetype is [dictionary]
			 * \note (Required; shall be an indirect reference) The catalog dictionary
			 * for the PDF document (see 7.7.2, "Document Catalog")
			 */
			static constexpr char Root[] = "Root";
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "Encrypt",it's
			 * valuetype is [dictionary]
			 * \note (Required if document is encrypted; PDF 1.1) The document’s
			 * encryption dictionary (see 7.6, "Encryption")
			 */
			static constexpr char Encrypt[] = "Encrypt";
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "Info",it's
			 * valuetype is [dictionary]
			 * \note (Optional; shall be an indirect reference) The document’s
			 * information dictionary (see 14.3.3, "Document Information Dictionary").
			 */
			static constexpr char Info[] = "Info";
			/**
			 * \brief a entry in pdf trailer dictionary,it's key named "ID",it's
			 * valuetype is [array]
			 * \note (Required if an Encrypt entry is present; optional otherwise; PDF
			 * 1.1) An array of two byte-strings constituting a file identifier (see
			 * 14.4, "File Identifiers") for the file. If there is an Encrypt entry
			 * this array and the two byte-strings shall be direct objects and shall be
			 * unencrypted
			 * \note (1)Because the ID entries are not encrypted it is possible to
			 * check the ID key to assure that the correct file is being accessed
			 * without decrypting the file. The restrictions that the string be a
			 * direct object and not be encrypted assure that this is possible.
			 * \note (2)Although this entry is optional, its absence might prevent the
			 * file from functioning in some workflows that depend on files being
			 * uniquely identified
			 * \note (3)The values of the ID strings are used as input to the
			 * encryption algorithm. If these strings were indirect, or if the ID array
			 * were indirect, these strings would be encrypted when written. This would
			 * result in a circular condition for a reader: the ID strings must be
			 * decrypted in order to use them to decrypt strings, including the ID
			 * strings themselves. The preceding restriction prevents this circular
			 * condition
			 */
			static constexpr char ID[] = "ID";

		private:
			std::string *pName;

			void setCosName(const char *name)
			{
				pName->clear();
				pName->append(name);
			}

		public:
			COSName *clone() const override
			{
				return new COSName(pName->c_str());
			}

			COSName(const char *name)
			{
				pName = new std::string(name);
				std::cout << pName << ' ' << *pName << '\n';
			}

			friend size_t COSNameHash(const std::shared_ptr<COSName> &pCosName);

			// size_t COSNameHash(){return std::hash<std::string>()(cosName);};
			bool operator==(const COSName &other) const { return pName == other.pName; }

			std::string toString() const override
			{
				if (nullptr == pName)
					return "";
				return *pName;
			}

			COSName &getObject() override { return *this; }

			~COSName() override;
		};

		size_t COSNameHash(const std::shared_ptr<COSName> &pCosName) { return std::hash<std::string>()(*pCosName->pName); }

		COSName::~COSName()
		{
			if (pName != nullptr)
			{
				// std::cout << pName << ' ' << *pName << ' ' << " de\n";
				delete pName;
				pName = nullptr;
			}
		}
	} // namespace COSObjects
}
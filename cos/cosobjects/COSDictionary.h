#pragma once

#include "COSName.h"
#include "COSNull.h"
#include <unordered_map>

namespace pdf
{
	namespace COSObjects
	{

		class COSDictionary : public COSBase
		{
			using umap = std::unordered_map<std::shared_ptr<COSName>, std::shared_ptr<COSBase>, decltype(&COSNameHash)>;

		protected:
			umap *pItems;
			void setItem(COSName *pKey, COSBase *pValue)
			{
				pItems->try_emplace(std::shared_ptr<COSName>(pKey), std::shared_ptr<COSBase>(pValue));
			}

		public:
			COSDictionary *clone() const override
			{
				auto p = new COSDictionary;
				p->pItems->insert(pItems->cbegin(), pItems->cend());
				return p;
			}
			COSDictionary(int bucket_count = 100) { pItems = new umap(bucket_count, COSNameHash); }

		public:
			COSBase &getDictionaryObject(COSName &key)
			{

				return *(pItems->operator[](std::make_shared<COSName>(key)));
			}

			COSDictionary &getObject() override { return *this; }

			std::string toString() const override
			{
				if (pItems == nullptr)
					return "[]";
				std::string ret;
				for (auto &&entry : *pItems)
				{
					ret.append(entry.first->toString() + ", ");
				}
				if (ret.empty())
					return "[]";
				auto it = ret.end();
				ret.erase(it - 2, it);
				return '[' + ret + ']';
			}

			COSBase &operator[](COSName &key)
			{
				for (auto &i : *pItems)
				{
					if (*i.first == key)
						return *i.second;
				}
			}

			~COSDictionary() override
			{
				if (pItems != nullptr)
				{
					delete pItems;
					pItems = nullptr;
				}
			}

			COSBase *operator[](const COSName &key) const
			{
				return pItems->operator[](std::make_shared<COSName>(key)).get();
			}

			void setItem(COSName &key, COSBase &value)
			{
				setItem(key.clone(), value.clone());
			}
			void setItem(COSName &&key, COSBase &&value)
			{
				setItem(key, value);
			}
		};
	} // namespace COSObjects
} // namespace pdf

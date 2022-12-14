#include <iostream>
#include "./cos/cosobjects/COSDictionary.h"

void test1(pdf::COSObjects::COSDictionary dict)
{
	dict.setItem(pdf::COSObjects::COSName("ID"), pdf::COSObjects::COSName("sdfs"));
}

void test(/*pdf::COSObjects::COSName name*/)
{
	pdf::COSObjects::COSBase &&A = pdf::COSObjects::COSName("ID");
	std::cout << typeid(A).name();
}

int main(int argc, char *argv[])
{
	auto &os = std::cout;
	pdf::COSObjects::COSDictionary dict;
	dict.setItem(pdf::COSObjects::COSName("ID"), pdf::COSObjects::COSName("sdfs"));
	return 0;
}
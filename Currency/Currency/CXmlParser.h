#pragma once
#include "rapidxml_utils.hpp"
#include <string>

using namespace rapidxml;

class CXmlParser {
public:
	CXmlParser();
	~CXmlParser();

	void setDocument(std::wstring wText);
	void getExchangeRate(std::wstring cur_name, std::wstring &sale, std::wstring &bye);

private:
	void getRootNode();

private:
	xml_document<> document;
	xml_node<>* root_node = nullptr;
	std::string text;
};
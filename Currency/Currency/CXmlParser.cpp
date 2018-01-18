#include "pch.h"
#include "CXmlParser.h"

CXmlParser::CXmlParser()
{
}

CXmlParser::~CXmlParser()
{
}

void CXmlParser::setDocument(std::wstring wText)
{
	text = std::string(wText.begin(), wText.end());

	document.parse<0>(&text[0]);

	getRootNode();
}

void CXmlParser::getExchangeRate(std::wstring cur_name, std::wstring & sale, std::wstring & bye)
{
	std::string cur(cur_name.begin(), cur_name.end());;

	for (xml_node<>* row = root_node->first_node("row"); row; row = row->next_sibling()) {
		xml_node<>* exchange = row->first_node("exchangerate");
		xml_attribute<>* attr = exchange->first_attribute();
		if (_strcmpi(cur.c_str(), attr->value())) {
			continue;
		}
		for (; attr; attr = attr->next_attribute()) {
			

			if (!_strcmpi(attr->name(), "sale")) {
				std::string buf = attr->value();
				sale = std::wstring(buf.begin(), buf.end());
			}

			if (!_strcmpi(attr->name(), "buy")) {
				std::string buf = attr->value();
				bye = std::wstring(buf.begin(), buf.end());
			}
		}
	}
}

void CXmlParser::getRootNode()
{
	root_node = document.first_node();
}

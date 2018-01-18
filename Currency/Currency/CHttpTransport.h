#pragma once
#include "pch.h"
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Http;

ref class  CHttpTransport sealed
{
	Uri^ uri;
public:
	CHttpTransport();
	virtual ~CHttpTransport();

	String^ request(String^ url);
};


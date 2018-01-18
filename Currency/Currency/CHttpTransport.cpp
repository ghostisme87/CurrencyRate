#include "pch.h"
#include "CHttpTransport.h"


CHttpTransport::CHttpTransport()
{
}


CHttpTransport::~CHttpTransport()
{
}

String ^ CHttpTransport::request(String ^ url)
{
	uri = ref new Uri(url);
	auto client = ref new HttpClient();
	if (!client) {
		return "";
	}

	auto response = client->GetStringAsync(uri);

	int i = 0;
	String^ buffer = "";
	while (AsyncStatus::Completed != response->Status) {
		Sleep(100);
		if (100 == i++) {
			return "";
		}
	}

	return response->GetResults();
}

//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
//#include <msclr\marshal.h>
//#include <msclr\marshal_cppstd.h>
#include <string>
#include "rapidxml_utils.hpp"
//#include "CHttpTransport.h"
//#include "CXmlParser.h"

using namespace Currency;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Web::Http;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void Currency::MainPage::updateRates()
{
	//Uri^ uri = ref new Uri("https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=5");
	//auto client = ref new HttpClient();

	//auto responce = client->GetStringAsync(uri);
	//

	//String^ str = "";
	//Sleep(1000);
	////	responce->Status;
	//str = responce->GetResults();
	String^ rate;
	switch (rateType->SelectedIndex) {
	case 0:
		rate = ("https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=5");
		break;
	case 1:
		rate = "https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=11";
		break;
	}

	m_pTransport = ref new CHttpTransport();
	String^ str = m_pTransport->request(rate);

	//pin_ptr<WCHAR> content = PtrToStringChars(str);

	std::wstring result(str->Begin());
	if (str->IsEmpty()) {
		//text1->Text = "Can't retrieve data";
		return;
	}
	std::string str2(result.begin(), result.end());

	m_pParser = std::unique_ptr<CXmlParser>(new CXmlParser());
	m_pParser->setDocument(result);

	std::wstring sale;
	std::wstring buy;

	m_pParser->getExchangeRate(L"USD", sale, buy);
	usd_sale->Text = ref new String(sale.c_str());
	usd_buy->Text = ref new String(buy.c_str());

	m_pParser->getExchangeRate(L"EUR", sale, buy);
	eur_sale->Text = ref new String(sale.c_str());
	eur_buy->Text = ref new String(buy.c_str());

	m_pParser->getExchangeRate(L"BTC", sale, buy);
	btc_sale->Text = ref new String(sale.c_str());


	btc_buy->Text = ref new String(buy.c_str());
}

void Currency::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	updateRates();

}


void Currency::MainPage::eur_buy_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void Currency::MainPage::TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//updateRates();
}


void Currency::MainPage::rateType_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	//updateRates();
}

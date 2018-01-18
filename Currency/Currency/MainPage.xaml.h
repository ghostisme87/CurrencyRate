//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "CHttpTransport.h"
#include "CXmlParser.h"
#include <memory>

namespace Currency
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	/*ref class CHttpTransport sealed;
	class CXmlParser;*/
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void updateRates();
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void eur_buy_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

	private:
		//void setTextBlockText()
		void TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void rateType_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

	private:
		CHttpTransport^ m_pTransport;
		std::unique_ptr<CXmlParser> m_pParser = nullptr;
	};
}

//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace Currency
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void eur_buy_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

	private:
		//void setTextBlockText()
		void TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}

﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class TextBlock;
                ref class ComboBox;
                ref class Button;
            }
        }
    }
}

namespace Currency
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::TextBlock^ text1;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ usd_sale;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ usd_buy;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ eur;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ eur_sale;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ eur_buy;
        private: ::Windows::UI::Xaml::Controls::ComboBox^ rateType;
        private: ::Windows::UI::Xaml::Controls::Button^ refresh;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ btc_sale;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ btc_buy;
    };
}


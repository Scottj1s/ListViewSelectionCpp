// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "MainPage.g.h"
#include "MyObject.h"

namespace winrt::ListViewSelectionCpp::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        static winrt::Microsoft::UI::Xaml::DependencyProperty SelectedItemIndexProperty()
        {
            return m_selectedItemIndexProperty;
        }

        int32_t SelectedItemIndex()
        {
            return winrt::unbox_value<int32_t>(GetValue(m_selectedItemIndexProperty));
        }

        void SelectedItemIndex(int32_t value)
        {
            SetValue(m_selectedItemIndexProperty, winrt::box_value(value));
        }

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::ListViewSelectionCpp::MyObject> MyList()
        {
            return m_myList;
        }

        static void OnSelectedItemIndexChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& /* e */);

        void ButtonReplace_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args)
        {
            ButtonReplace_Click_Async(sender, args);
        }

    private:
        static winrt::Microsoft::UI::Xaml::DependencyProperty m_selectedItemIndexProperty;
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::ListViewSelectionCpp::MyObject> m_myList;
        winrt::fire_and_forget ButtonReplace_Click_Async(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&);
    };
}

namespace winrt::ListViewSelectionCpp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}

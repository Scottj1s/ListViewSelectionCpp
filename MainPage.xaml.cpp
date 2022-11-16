// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

#include "wil/cppwinrt_helpers.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::ListViewSelectionCpp::implementation
{
    DependencyProperty MainPage::m_selectedItemIndexProperty =
        DependencyProperty::Register(
            L"SelectedItemIndex",
            xaml_typename<int32_t>(),
            xaml_typename<ListViewSelectionCpp::MainPage>(),
            PropertyMetadata{ winrt::box_value(0), PropertyChangedCallback{ &MainPage::OnSelectedItemIndexChanged } });

    void MainPage::OnSelectedItemIndexChanged(DependencyObject const& /*d*/, DependencyPropertyChangedEventArgs const& e)
    {
        TCHAR buffer[100];
        auto newValue = winrt::unbox_value<int32_t>(e.NewValue());
        swprintf_s(buffer, L"Selected Index: %d", newValue);
        OutputDebugString(buffer);
    }

    MainPage::MainPage()
    {
        m_myList = single_threaded_observable_vector<ListViewSelectionCpp::MyObject>(std::vector{
            winrt::make<MyObject>(1, L"First"),
            winrt::make<MyObject>(2, L"Second"),
            winrt::make<MyObject>(3, L"Third"),
            winrt::make<MyObject>(4, L"Fourth"),
            winrt::make<MyObject>(5, L"Fifth"),
            winrt::make<MyObject>(6, L"Sixth"),
        });
    }

    winrt::fire_and_forget MainPage::ButtonReplace_Click_Async(IInspectable const&, RoutedEventArgs const&)
    {
        if (auto value = ReadLocalValue(SelectedItemIndexProperty()); value != DependencyProperty::UnsetValue())
        {
            auto index = winrt::unbox_value<int32_t>(value);
            auto old_value = m_myList.GetAt(index);
            auto new_text = winrt::hstring(L"New ") + old_value.Text();
            m_myList.SetAt(index, winrt::make<MyObject>(old_value.Id(), new_text));
            co_await wil::resume_foreground(Microsoft::UI::Dispatching::DispatcherQueue::GetForCurrentThread());
            SelectedItemIndex(index);
        }
    }
}

#pragma once
#include "MyObject.g.h"

namespace winrt::ListViewSelectionCpp::implementation
{
    struct MyObject : MyObjectT<MyObject>
    {
        MyObject() = default;

        MyObject(int32_t id, hstring const& text) : m_id(id), m_text(text)
        {
        }
        int32_t Id()
        {
            return m_id;
        }
        void Id(int32_t value)
        {
            m_id = value;
        }
        hstring Text()
        {
            return m_text;
        }
        void Text(hstring const& value)
        {
            m_text = value;
        }

    private:
        int32_t m_id;
        hstring m_text;
        winrt::Microsoft::UI::Xaml::Controls::Frame m_frame{ nullptr };
        winrt::Microsoft::UI::Xaml::Window m_window{ nullptr };
    };
}
namespace winrt::ListViewSelectionCpp::factory_implementation
{
    struct MyObject : MyObjectT<MyObject, implementation::MyObject>
    {
    };
}

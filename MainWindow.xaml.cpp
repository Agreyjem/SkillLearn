#include "pch.h"
#include "MainWindow.xaml.h"
#include "winrt/Microsoft.Windows.AppNotifications.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::Microsoft::Windows::AppNotifications;
using namespace winrt::Microsoft::Windows::AppNotifications::Builder;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::TestingApp::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    // MainWindow.xaml.cpp
    void MainWindow::SendNotificationButton_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        auto appNotification = AppNotificationBuilder()
            .AddArgument(L"action", L"NotificationClick")
            .AddArgument(L"exampleEventId", L"1234")
            .SetAppLogoOverride(winrt::Windows::Foundation::Uri(L"ms-appx:///Assets/Square150x150Logo.png"), AppNotificationImageCrop::Circle)
            .AddText(L"This is text content for an app notification.")
            .AddButton(AppNotificationButton(L"Perform action without launching app")
                .AddArgument(L"action", L"BackgroundAction"))
            .BuildNotification();

        AppNotificationManager::Default().Show(appNotification);
    }
}
    
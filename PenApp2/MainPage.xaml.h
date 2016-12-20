﻿//
// MainPage.xaml.h
// MainPage 클래스의 선언입니다.
//

#pragma once

#include "MainPage.g.h"
#include <string>

namespace flowchart
{
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
	/// </summary>
	public ref class MainPage sealed
	{
	private:
		//int selectedSymbolNumber;

	public:
		MainPage();
		//int getSelectedSymbolNumber();

	private:
		void Image_DragStarting(Windows::UI::Xaml::UIElement^ sender, Windows::UI::Xaml::DragStartingEventArgs^ args);
		void Image_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void Image_DropCompleted(Windows::UI::Xaml::UIElement^ sender, Windows::UI::Xaml::DropCompletedEventArgs^ args);
	};
}

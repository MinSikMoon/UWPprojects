//
// GridContent.xaml.h
// Declaration of the GridContent class
//

#pragma once
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
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::UI;
#include "GridContent.g.h"

namespace UWPPenAppDraft
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GridContent sealed
	{
	public:
		GridContent();
	private:
		int curRowIdx, curColumnIdx;
		
		void makeButton(Grid^ parentGrid, int horizontal, int vertical, int width, int height, int rowIdx, int columnIdx);
		void makeRectangle(Grid^ parentGrid, int width, int height, int rowIdx, int columnIdx);
		void makeGridArray(int rowNum, int columnNum, int rectWidth, int rectHeight);
		void makeImage(Grid^ parentGrid,  int rowIdx, int columnIdx);

		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Rectangle_PointerPressed(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void Rectangle_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		
		void PageGrid_DragOver(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void Rectangle_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void PageGrid_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void Rectangle_DragEnter(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void PageGrid_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void Rectangle_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
	};

	
	
	
}

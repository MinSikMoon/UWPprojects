//
// GridPage.xaml.h
// Dsafeitemname$ 클래스의 선언
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


#include "GridPage.g.h"
#include <String>
#include <list>
#include "SymbolInfo.h"
namespace flowchart
{
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GridPage sealed
	{
	public:
		GridPage();

		//0. gridArray 만들기
		void makeGridArray(Grid^ parentGrid, int rowNum, int columnNum, int rowHeight, int columnWidth);

		//1. rectangle 만들기
		void makeRectangle(Grid^ parentGrid, int rowIndex, int columnIndex);
	private:
		int curRowIndex;
		int curColumnIndex;
		int selectedSymbolNumber;
		std::list<SymbolInfo^> symbolList;

		void makeImage(Grid^ parentGrid, int symbolType, int rowIndex, int columnIndex);
		void showAllSymbols();

		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Rectangle_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void RootGrid_DragOver(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void RootGrid_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void Rectangle_DragEnter(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);

	protected:
		 void OnNavigatedTo(NavigationEventArgs^ e) override;

	
		
	};
}

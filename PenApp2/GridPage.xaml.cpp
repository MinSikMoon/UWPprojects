//
// GridPage.xaml.cpp
// GridPage 클래스의 구현
//

#include "pch.h"
#include "GridPage.xaml.h"
#include "MainPage.xaml.h"
using namespace flowchart;

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
using namespace Windows::ApplicationModel::DataTransfer;
// 빈 페이지 항목 템플릿에 대한 설명은 http://go.microsoft.com/fwlink/?LinkId=234238에 나와 있습니다.

GridPage::GridPage()
{
	
	InitializeComponent();
	makeGridArray(RootGrid, 10, 10, 70, 100);
}



void GridPage::makeGridArray(Grid^ parentGrid, int rowNum, int columnNum, int rowHeight, int columnWidth)
{
	//1. 행을 그린다. 
	for (int i = 0; i < rowNum; i++) {
		RowDefinition^ tempRow = ref new RowDefinition();
		tempRow->Height = rowHeight;
		parentGrid->RowDefinitions->Append(tempRow);
	}

	//2. 열을 그린다. 
	for (int i = 0; i < columnNum; i++) {
		ColumnDefinition^ tempColumn = ref new ColumnDefinition();
		tempColumn->Width = columnWidth;
		parentGrid->ColumnDefinitions->Append(tempColumn);
	}

	//3. rectangle을 채워넣어본다. 
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < columnNum; j++) {
			//1. rectangle 채우기 
			makeRectangle(parentGrid, i, j);
		}
	}
}



void GridPage::makeRectangle(Grid^ parentGrid, int rowIndex, int columnIndex)
{
	Rectangle^ tempRect = ref new Rectangle();
	tempRect->Style = RECTANGLE_STYLE;
	auto dasharray = ref new DoubleCollection;
	dasharray->Append(5);
	tempRect->StrokeDashArray = dasharray;
	tempRect->SetValue(parentGrid->ColumnProperty, columnIndex);
	tempRect->SetValue(parentGrid->RowProperty, rowIndex);
	tempRect->AllowDrop = true;

	tempRect->PointerEntered += ref new Windows::UI::Xaml::Input::PointerEventHandler(this, &flowchart::GridPage::Rectangle_PointerEntered);
	tempRect->DragEnter += ref new Windows::UI::Xaml::DragEventHandler(this, &flowchart::GridPage::Rectangle_DragEnter);
	parentGrid->Children->Append(tempRect);
}


void flowchart::GridPage::Rectangle_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	auto columnIdx = ((Rectangle^)sender)->GetValue(RootGrid->ColumnProperty);
	auto rowIdx = ((Rectangle^)sender)->GetValue(RootGrid->RowProperty);
	
	curRowIndex = safe_cast<int>(rowIdx);
	curColumnIndex = safe_cast<int>(columnIdx);
	gridCheck->Text = curRowIndex + ", " + curColumnIndex;
	
	//symbolCheck->Text = Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MainPage::typeid));
}

void flowchart::GridPage::Rectangle_DragEnter(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{
	auto columnIdx = ((Rectangle^)sender)->GetValue(RootGrid->ColumnProperty);
	auto rowIdx = ((Rectangle^)sender)->GetValue(RootGrid->RowProperty);

	curRowIndex = safe_cast<int>(rowIdx);
	curColumnIndex = safe_cast<int>(columnIdx);
	gridCheck->Text = curRowIndex + ", " + curColumnIndex;
}

//mainPage로 부터 선택된 selectedSymbolNumber받아오는 함수
void flowchart::GridPage::OnNavigatedTo(NavigationEventArgs^ e) 
{
	String^ tempSymbolName = safe_cast<String^>(e->Parameter);
	selectedSymbolNumber = std::stoi(tempSymbolName->Data() + 1);
	symbolCheck->Text = "" + selectedSymbolNumber;
	
}

void flowchart::GridPage::RootGrid_DragOver(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{
	e->AcceptedOperation = DataPackageOperation::Move;
	e->DragUIOverride->Caption = "생성하기";
	e->DragUIOverride->IsGlyphVisible = true;
}


void flowchart::GridPage::RootGrid_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{

}



















//안쓰는 메소드들 
void flowchart::GridPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}




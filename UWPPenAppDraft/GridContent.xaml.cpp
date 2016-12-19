//
// GridContent.xaml.cpp
// Implementation of the GridContent class
//

#include "pch.h"
#include "GridContent.xaml.h"

using namespace UWPPenAppDraft;

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
// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

GridContent::GridContent()
{
	InitializeComponent();
}
void  UWPPenAppDraft::GridContent::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	makeGridArray(10, 10, 100, 70);

}

void UWPPenAppDraft::GridContent::makeGridArray(int rowNum, int columnNum, int rectWidth, int rectHeight) {
	//1. 8개의 행을 그린다. 
	for (int i = 0; i < rowNum; i++) {
		RowDefinition^ tempRow = ref new RowDefinition();
		tempRow->Height = rectHeight;
		PageGrid->RowDefinitions->Append(tempRow);
	}

	//2. 8개의 열을 그린다. 
	for (int i = 0; i < columnNum; i++) {
		ColumnDefinition^ tempColumn = ref new ColumnDefinition();
		tempColumn->Width = rectWidth;
		PageGrid->ColumnDefinitions->Append(tempColumn);
	}

	//3. rectangle을 채워넣어본다. 
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < columnNum; j++) {
			//1. rectangle 채우기 
			makeRectangle(PageGrid, rectWidth, rectHeight, i, j);
		}
	}
}
void UWPPenAppDraft::GridContent::makeButton(Grid^ parentGrid, int horizontal, int vertical, int width, int height, int rowIdx, int columnIdx) {
	Button^ tempButton = ref new Button();
	tempButton->Style = BUTTON_STYLE_ARROW;
	tempButton->Width = width;
	tempButton->Height = height;
	tempButton->SetValue(PageGrid->ColumnProperty, columnIdx);
	tempButton->SetValue(PageGrid->RowProperty, rowIdx);
	tempButton->SetValue(HorizontalAlignmentProperty, horizontal);
	tempButton->SetValue(VerticalAlignmentProperty, vertical);
	parentGrid->Children->Append(tempButton);
}

void  UWPPenAppDraft::GridContent::makeRectangle(Grid^ parentGrid, int width, int height, int rowIdx, int columnIdx) {
	Rectangle^ tempRect = ref new Rectangle();
	tempRect->Height = height;
	tempRect->Width = width;
	tempRect->Style = RECTANGLE_STYLE;
	auto dasharray = ref new DoubleCollection;
	dasharray->Append(5);
	tempRect->StrokeDashArray = dasharray;
	tempRect->SetValue(PageGrid->ColumnProperty, columnIdx);
	tempRect->SetValue(PageGrid->RowProperty, rowIdx);
	tempRect->AllowDrop = true;
	tempRect->Drop += ref new Windows::UI::Xaml::DragEventHandler(this, &UWPPenAppDraft::GridContent::Rectangle_Drop);
	tempRect->PointerEntered += ref new Windows::UI::Xaml::Input::PointerEventHandler(this, &UWPPenAppDraft::GridContent::Rectangle_PointerEntered);
	tempRect->PointerPressed += ref new Windows::UI::Xaml::Input::PointerEventHandler(this, &UWPPenAppDraft::GridContent::Rectangle_PointerPressed);
	tempRect->PointerReleased += ref new Windows::UI::Xaml::Input::PointerEventHandler(this, &UWPPenAppDraft::GridContent::Rectangle_PointerReleased);
	tempRect->DragEnter += ref new Windows::UI::Xaml::DragEventHandler(this, &UWPPenAppDraft::GridContent::Rectangle_DragEnter);
	parentGrid->Children->Append(tempRect);
}





void UWPPenAppDraft::GridContent::Rectangle_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	auto columnIdx = ((Rectangle^)sender)->GetValue(PageGrid->ColumnProperty);
	auto rowIdx = ((Rectangle^)sender)->GetValue(PageGrid->RowProperty);

	curColumnIdx = safe_cast<int>(columnIdx);
	curRowIdx = safe_cast<int>(rowIdx);
	/*String^ s1 = curColumnIdx + "  " + curRowIdx;
	mainTextBox->Text = s1;*/

	
}



void UWPPenAppDraft::GridContent::Rectangle_DragEnter(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{
	auto columnIdx = ((Rectangle^)sender)->GetValue(PageGrid->ColumnProperty);
	auto rowIdx = ((Rectangle^)sender)->GetValue(PageGrid->RowProperty);

	curColumnIdx = safe_cast<int>(columnIdx);
	curRowIdx = safe_cast<int>(rowIdx);
	
	//String^ s1 = curRowIdx + "  " + curColumnIdx;
	//mainTextBox->Text = s1;
}


void UWPPenAppDraft::GridContent::PageGrid_DragOver(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{

	e->DragUIOverride->Caption = "여기 놓으세요.";
	e->DragUIOverride->IsGlyphVisible = false;
	e->AcceptedOperation = DataPackageOperation::Copy;
	
}

void UWPPenAppDraft::GridContent::PageGrid_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{
	
	makeButton(PageGrid, 0, 0, 20, 20, curRowIdx, curColumnIdx);
	makeButton(PageGrid, 0, 2, 20, 20, curRowIdx, curColumnIdx);
	makeButton(PageGrid, 2, 0, 20, 20, curRowIdx, curColumnIdx);
	makeButton(PageGrid, 2, 2, 20, 20, curRowIdx, curColumnIdx);
	PageGrid->UpdateLayout();

}









void UWPPenAppDraft::GridContent::Rectangle_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	

}

void UWPPenAppDraft::GridContent::PageGrid_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	
}

void UWPPenAppDraft::GridContent::Rectangle_Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e)
{

}

void  UWPPenAppDraft::GridContent::Rectangle_PointerPressed(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{

}


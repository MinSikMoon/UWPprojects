//
// GridElem.xaml.cpp
// GridElem 클래스의 구현
//

#include "pch.h"

#include "GridElem.xaml.h"
#include "GridContent.xaml.h"



// 빈 페이지 항목 템플릿에 대한 설명은 http://go.microsoft.com/fwlink/?LinkId=234238에 나와 있습니다.
GridElem::GridElem() {
	InitializeComponent();
}

GridElem::GridElem(int id, int shapeType, Grid^ parentGrid, int rowIdx, int columnIdx)
{
	

	//1. id설정
	this->id = id;

	//2. shapeType설정
	this->shapeType = shapeType;

	//3. row, column index 설정
	this->rowIndex = rowIdx;
	this->columnIndex = columnIdx;

	//4. image, button, textbox만들기
	makeImage(parentGrid, rowIdx, columnIdx);
	makeMemoButton(parentGrid, rowIdx, columnIdx);
	makeConnectorButton(parentGrid, rowIdx, columnIdx);
	//makeTitleBox(parentGrid, rowIdx, columnIdx);
}

void GridElem::makeImage(Grid^ parentGrid, int rowIdx, int columnIdx) {
	shapeImage = ref new Image();
	shapeImage->Style = TEST_IMAGE;
	shapeImage->SetValue(parentGrid->ColumnProperty, columnIdx);
	shapeImage->SetValue(parentGrid->RowProperty, rowIdx);
	parentGrid->Children->Append(shapeImage);
}

void GridElem::makeMemoButton(Grid^ parentGrid, int rowIdx, int columnIdx) {
	memoButton = ref new Button();
	memoButton->Style = BUTTON_STYLE_MEMO;
	memoButton->SetValue(parentGrid->ColumnProperty, columnIdx);
	memoButton->SetValue(parentGrid->RowProperty, rowIdx);
	memoButton->SetValue(HorizontalAlignmentProperty, 2);
	memoButton->SetValue(VerticalAlignmentProperty, 0);
	parentGrid->Children->Append(memoButton);
}
void GridElem::makeConnectorButton(Grid^ parentGrid, int rowIdx, int columnIdx) {
	connectorButton = ref new Button();
	connectorButton->Style = BUTTON_STYLE_CONNECTOR;
	connectorButton->SetValue(parentGrid->ColumnProperty, columnIdx);
	connectorButton->SetValue(parentGrid->RowProperty, rowIdx);
	connectorButton->SetValue(HorizontalAlignmentProperty, 2);
	connectorButton->SetValue(VerticalAlignmentProperty, 2);
	parentGrid->Children->Append(connectorButton);
}
void GridElem::makeTitleBox(Grid^ parentGrid, int rowIdx, int columnIdx) {
	titleBox = ref new TextBox();
	titleBox->Style = TITLE;
	titleBox->SetValue(parentGrid->ColumnProperty, columnIdx);
	titleBox->SetValue(parentGrid->RowProperty, rowIdx);
	parentGrid->Children->Append(titleBox);
}
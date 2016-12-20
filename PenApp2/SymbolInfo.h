#pragma once
using namespace Platform;

enum SymbolType
{
	process = 1,
	decision,
	preparation,
	terminator,
	data,
	document
};

ref class SymbolInfo sealed 
{
	

private:
	int symbolNo = 0;	// symbol의 고유번호
	int rowIndex, columnIndex;	// Grid 내에서 index
	int symbolType;	// symbol의 종류
	String^ title = nullptr;	// 제목
	String^ content = nullptr;	// 내용
	String^ detail = nullptr;	// 세부내용
	SymbolInfo^ path = nullptr;	// 이 symbol이 가리키는 symbol들

public:
	SymbolInfo();
	SymbolInfo(int symbolNo, int symbolType, int rowIndex, int columnIndex);
	void setSymbolNo(int symbolNo);
	void setSymbolType(int symbolType);
	void setGridIndex(int rowIndex, int columnIndex);
	
	int getSymbolNo();
	int getSymbolType();
	int getRowIndex();
	int getColumnIndex();
	

};
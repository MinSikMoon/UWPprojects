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
	int symbolNo = 0;	// symbol�� ������ȣ
	int rowIndex, columnIndex;	// Grid ������ index
	int symbolType;	// symbol�� ����
	String^ title = nullptr;	// ����
	String^ content = nullptr;	// ����
	String^ detail = nullptr;	// ���γ���
	SymbolInfo^ path = nullptr;	// �� symbol�� ����Ű�� symbol��

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
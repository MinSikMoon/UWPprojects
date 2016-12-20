#include "SymbolInfo.h"

SymbolInfo::SymbolInfo() {}


SymbolInfo::SymbolInfo(int symbolNo, int symbolType, int rowIndex, int columnIndex)
{
	this->symbolNo = symbolNo;
	this->symbolType = symbolType;
	this->rowIndex = rowIndex;
	this->columnIndex = columnIndex;
}

int SymbolInfo::getSymbolNo()
{
	return symbolNo;
}
int SymbolInfo::getSymbolType() 
{
	return symbolType;
}
int SymbolInfo::getRowIndex()
{
	return rowIndex;
}
int SymbolInfo::getColumnIndex()
{
	return columnIndex;
}


void SymbolInfo::setSymbolNo(int symbolNo)
{

}
void SymbolInfo::setSymbolType(int symbolType) 
{

}
void SymbolInfo::setGridIndex(int rowIndex, int columnIndex)
{

}
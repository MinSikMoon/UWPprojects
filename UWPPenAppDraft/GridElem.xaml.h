//
// GridElem.xaml.h
// Dsafeitemname$ 클래스의 선언
//

#pragma once
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

#include "GridElem.g.h"

namespace UWPPenAppDraft
{
	enum {
		ACTIVITY,
		COMPUTER,
		INPUT,
		OUTPUT,
		GATEWAY,
		TRIGGER_RESULT,
		ARCHIVE,
		PROCESS_CONNECTOR
	};
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GridElem sealed
	{
	private:
		int id;
		int shapeType;
		int rowIndex, columnIndex;
		Button^ memoButton;
		Button^ connectorButton;
		Image^ shapeImage;
		TextBox^ titleBox;

	public:
		GridElem();
		GridElem(int id, int shapeType, Grid^ parentGrid, int rowIdx, int columnIdx);
		void makeImage(Grid^ parentGrid, int rowIdx, int columnIdx);
		void makeMemoButton(Grid^ parentGrid, int rowIdx, int columnIdx);
		void makeConnectorButton(Grid^ parentGrid, int rowIdx, int columnIdx);
		void makeTitleBox(Grid^ parentGrid, int rowIdx, int columnIdx);
		/*void makeMemoButton(Grid^ parentGrid, int horizontal, int vertical, int width, int height, int rowIdx, int columnIdx);
		void makeConnectorButton(Grid^ parentGrid, int horizontal, int vertical, int width, int height, int rowIdx, int columnIdx);*/


	};
}

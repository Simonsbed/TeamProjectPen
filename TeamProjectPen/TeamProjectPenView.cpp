
// TeamProjectPenView.cpp: CTeamProjectPenView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TeamProjectPen.h"
#endif

#include "TeamProjectPenDoc.h"
#include "TeamProjectPenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProjectPenView

IMPLEMENT_DYNCREATE(CTeamProjectPenView, CFormView)

BEGIN_MESSAGE_MAP(CTeamProjectPenView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CTeamProjectPenView::OnRectangle)
	ON_COMMAND(ID_32772, &CTeamProjectPenView::OnCircle)
	ON_COMMAND(ID_32773, &CTeamProjectPenView::OnDefault)
	ON_COMMAND(ID_32780, &CTeamProjectPenView::OnColorSelect)
END_MESSAGE_MAP()

// CTeamProjectPenView 생성/소멸

CTeamProjectPenView::CTeamProjectPenView() noexcept
	: CFormView(IDD_TEAMPROJECTPEN_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTeamProjectPenView::~CTeamProjectPenView()
{
}

void CTeamProjectPenView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
}

BOOL CTeamProjectPenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CTeamProjectPenView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTeamProjectPenView 인쇄

BOOL CTeamProjectPenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTeamProjectPenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTeamProjectPenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTeamProjectPenView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CTeamProjectPenView 진단

#ifdef _DEBUG
void CTeamProjectPenView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeamProjectPenView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTeamProjectPenDoc* CTeamProjectPenView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeamProjectPenDoc)));
	return (CTeamProjectPenDoc*)m_pDocument;
}
#endif //_DEBUG


// CTeamProjectPenView 메시지 처리기

CPoint opnt;
COLORREF Col;
void CTeamProjectPenView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	int n = GetDlgItemInt(IDC_EDIT1);
	CPen pen(PS_SOLID, n, Col);
	dc.SelectObject(&pen);
	if (nFlags & MK_LBUTTON)
	{
		dc.MoveTo(opnt);
		dc.LineTo(point);
	}

	opnt = point;

	CFormView::OnMouseMove(nFlags, point);
}


void CTeamProjectPenView::OnDraw(CDC* pDC)
{
	CTeamProjectPenDoc* pDoc = GetDocument();;
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_drawCircle)
		pDC->Ellipse(100, 100, 300, 300);
	else if (m_drawRectangle)
		pDC->Rectangle(100, 100, 400, 200);
}

void CTeamProjectPenView::OnRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_drawCircle = false;
	m_drawRectangle = true;
	Invalidate();
	UpdateWindow();
}


void CTeamProjectPenView::OnCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_drawRectangle = false;
	m_drawCircle = true;
	Invalidate();
	UpdateWindow();
}



void CTeamProjectPenView::OnDefault()
{
	m_drawRectangle = false;
	m_drawCircle = false;
	Invalidate();
	UpdateWindow();
}


void CTeamProjectPenView::OnColorSelect()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		Col = dlg.GetColor();
	}
}


// TeamProjectPenView.h: CTeamProjectPenView 클래스의 인터페이스
//

#pragma once


class CTeamProjectPenView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CTeamProjectPenView() noexcept;
	DECLARE_DYNCREATE(CTeamProjectPenView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TEAMPROJECTPEN_FORM };
#endif

// 특성입니다.
public:
	CTeamProjectPenDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTeamProjectPenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_Edit;
	CSpinButtonCtrl m_Spin;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	virtual void OnDraw(CDC* /*pDC*/);
private:
	bool m_drawCircle{false}; // 원이 아니라면 사각형
	bool m_drawRectangle{ false};
public:
	afx_msg void OnCircle();
	afx_msg void OnDefault();
	afx_msg void OnColorSelect();
};

#ifndef _DEBUG  // TeamProjectPenView.cpp의 디버그 버전
inline CTeamProjectPenDoc* CTeamProjectPenView::GetDocument() const
   { return reinterpret_cast<CTeamProjectPenDoc*>(m_pDocument); }
#endif


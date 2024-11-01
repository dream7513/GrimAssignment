
// YoutubeAssignmentDlg.h: 헤더 파일
//

#pragma once


// CYoutubeAssignmentDlg 대화 상자
class CYoutubeAssignmentDlg : public CDialogEx
{
// 생성입니다.
public:
	CYoutubeAssignmentDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YOUTUBEASSIGNMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int x1, y1, x2, y2;
	int dx, dy;
	int radius = 0;
	CImage image;

	afx_msg void OnBnClickedDraw();
	afx_msg void OnBnClickedAction();
	afx_msg void OnBnClickedOpen();
	void SaveJPG(CDC& dc, CString filePath);
};

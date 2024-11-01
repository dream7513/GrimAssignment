
// YoutubeAssignmentDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "YoutubeAssignment.h"
#include "YoutubeAssignmentDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CYoutubeAssignmentDlg 대화 상자



CYoutubeAssignmentDlg::CYoutubeAssignmentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YOUTUBEASSIGNMENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYoutubeAssignmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CYoutubeAssignmentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Draw, &CYoutubeAssignmentDlg::OnBnClickedDraw)
	ON_BN_CLICKED(IDC_Action, &CYoutubeAssignmentDlg::OnBnClickedAction)
	ON_BN_CLICKED(IDC_Open, &CYoutubeAssignmentDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// CYoutubeAssignmentDlg 메시지 처리기

BOOL CYoutubeAssignmentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CYoutubeAssignmentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CYoutubeAssignmentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CYoutubeAssignmentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYoutubeAssignmentDlg::OnBnClickedDraw()
{
	UpdateData(TRUE);

	x1 = GetDlgItemInt(IDC_x1);
	y1 = GetDlgItemInt(IDC_y1);

	radius = rand() % 100 + 10;

	CClientDC dc(this);
	dc.Ellipse(x1 - radius, y1 - radius, x1 + radius, y1 + radius);
}


void CYoutubeAssignmentDlg::OnBnClickedAction()
{
	
	UpdateData(TRUE);

	x1 = GetDlgItemInt(IDC_x1);
	y1 = GetDlgItemInt(IDC_y1);
	x2 = GetDlgItemInt(IDC_x2);
	y2 = GetDlgItemInt(IDC_y2);

	dx = (x2 - x1) / 10;
	dy = (y2 - y1) / 10;

	CClientDC dc(this);
	int curX = x1, curY = y1;

	for (int i = 0; i <= 10; ++i) {
		dc.Ellipse(curX - radius, curY - radius, curX + radius, curY + radius);

		// 이미지 저장
		CString filePath;
		filePath.Format(_T("../x64/Debug/image/%d.jpg"), i);
		SaveJPG(dc, filePath);

		curX += dx;
		curY += dy;

		Sleep(300);
		RedrawWindow();
	}
}


void CYoutubeAssignmentDlg::OnBnClickedOpen()
{
	CFileDialog fileDlg(TRUE, _T("jpg"), NULL, OFN_FILEMUSTEXIST, _T("Image Files (*.jpg; *.bmp)|*.jpg;*.bmp||"));
	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();
		int fileName = _tstoi(fileDlg.GetFileTitle());

		CImage image;
		image.Load(filePath);

		CClientDC dc(this);
		CRect rect;
		GetDlgItem(IDC_PicCtrl)->GetWindowRect(&rect);
		ScreenToClient(&rect);

		image.Draw(dc, rect);

		int xCenter = x1 + dx * fileName;
		int yCenter = y1 + dy * fileName;


		dc.MoveTo(xCenter - 5, yCenter - 5);
		dc.LineTo(xCenter + 5, yCenter + 5);
		dc.MoveTo(xCenter - 5, yCenter + 5);
		dc.LineTo(xCenter + 5, yCenter - 5);

		CString coordText;
		coordText.Format(_T("(%d, %d)"), xCenter, yCenter);
		dc.TextOutW(xCenter + 10, yCenter, coordText);
	}
}

void CYoutubeAssignmentDlg::SaveJPG(CDC& dc, CString filePath)
{
	CImage image;
	CRect rect;
	GetClientRect(&rect);

	image.Create(rect.Width(), rect.Height(), 24);

	CDC* pDC = CDC::FromHandle(image.GetDC());
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
	image.ReleaseDC();

	image.Save(filePath);
}
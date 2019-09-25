
// saisie_pointsDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "saisie_points.h"
#include "saisie_pointsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
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


// bo�te de dialogue Csaisie_pointsDlg



Csaisie_pointsDlg::Csaisie_pointsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAISIE_POINTS_DIALOG, pParent)
	, points(0)
	, nbBouts(0)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Csaisie_pointsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, points);
	DDV_MinMaxInt(pDX, points, 0, 90);
	DDX_Text(pDX, IDC_EDIT2, nbBouts);
	DDV_MinMaxInt(pDX, nbBouts, 0, 3);
	DDX_Control(pDX, IDC_COMBO1, mComboPetit);
	DDX_Control(pDX, IDC_COMBO2, mComboPoignee);
}

BEGIN_MESSAGE_MAP(Csaisie_pointsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Csaisie_pointsDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Csaisie_pointsDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK, &Csaisie_pointsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// gestionnaires de messages pour Csaisie_pointsDlg

BOOL Csaisie_pointsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// TODO: ajoutez ici une initialisation suppl�mentaire

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void Csaisie_pointsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void Csaisie_pointsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR Csaisie_pointsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Csaisie_pointsDlg::OnCbnSelchangeCombo1()
{
	testPetit = mComboPetit.GetCurSel();
}


void Csaisie_pointsDlg::OnCbnSelchangeCombo2()
{
	testPoignee = mComboPoignee.GetCurSel();
}

void Csaisie_pointsDlg::envoyerValeur()
{
	Poignee typePoignee;
	Camp campPetitAuBout;
	switch (testPetit)
	{
	case 0:
		campPetitAuBout = personne;
		break;
	case 1 :
		campPetitAuBout = preneur;
		break;
	case 2:
		campPetitAuBout = defenseur;
		break;
	}
	laPartie->setCampPetit(campPetitAuBout);
	switch (testPoignee)
	{
	case 0:
		typePoignee = Sans;
		break;
	case 1:
		typePoignee = Simple;
		break;
	case 2:
		typePoignee = Double;
		break;
	case 3:
		typePoignee = Triple;
		break;
	}
	laPartie->setPoingnee(typePoignee);
	laPartie->setPoint(points, nbBouts);
	laPartie->calculerDonne();

}


void Csaisie_pointsDlg::OnBnClickedOk()
{
	UpdateData(true);
	creer_partie();
	lesJoueurs[0] = new CJoueur("jack", 0);
	lesJoueurs[1] = new CJoueur("jacki", 0);
	lesJoueurs[2] = new CJoueur("jacko", 0);
	lesJoueurs[3] = new CJoueur("jacku", 0);
	laPartie->creerDonnes(lesJoueurs[1]);
	envoyerValeur();
	CDialogEx::OnOK();
}

void Csaisie_pointsDlg::OnCbnSelchangeCombo4()
{
		
}
void Csaisie_pointsDlg::creer_partie()
{
	laPartie = new CPartie(lesJoueurs);
}

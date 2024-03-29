
// saisie_pointsDlg.h : fichier d'en-t�te
//

#pragma once
#include "afxwin.h"
#include "CJoueur.h"
#include "CPartie.h"
#include "string"
using namespace std;



// bo�te de dialogue Csaisie_pointsDlg
class Csaisie_pointsDlg : public CDialogEx
{
// Construction
public:
	Csaisie_pointsDlg(CWnd* pParent = NULL);	// constructeur standard

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAISIE_POINTS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Impl�mentation
protected:
	HICON m_hIcon;

	// Fonctions g�n�r�es de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int points;
	int nbBouts;
	int testPetit;
	int testPoignee;
public:
	CComboBox mComboPetit;
	CComboBox mComboPoignee;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	void envoyerValeur();
	afx_msg void OnBnClickedOk();
	CComboBox mTest;
	afx_msg void OnCbnSelchangeCombo4();
};



#pragma once
#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		


class Csaisie_pointsApp : public CWinApp
{

public:
	Csaisie_pointsApp();
	virtual BOOL InitInstance();


	DECLARE_MESSAGE_MAP()
};

extern Csaisie_pointsApp theApp;

// saisie_points.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// Csaisie_pointsApp :
// Consultez saisie_points.cpp pour l'implémentation de cette classe
//

class Csaisie_pointsApp : public CWinApp
{
public:
	Csaisie_pointsApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern Csaisie_pointsApp theApp;
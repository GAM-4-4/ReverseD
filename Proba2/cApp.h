#pragma once
#include "wx/wx.h"
#include "cMain.h"
#include "cDnevnik.h"

//Definiranje klase cApp i davanje joj atribuda wxAppa što je kao klasa za prozore
class cApp : public wxApp
{
public:
	cApp();
	~cApp();
private:
	cMain* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};


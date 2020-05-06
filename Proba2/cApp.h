#pragma once
#include "wx/wx.h"
#include "FormLogin.h"
#include "cDnevnik.h"

//Definiranje klase cApp i davanje joj atribuda wxAppa što je kao klasa za prozore
class cApp : public wxApp
{
public:
	cApp();
	~cApp();
private:
	FormLogin* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};


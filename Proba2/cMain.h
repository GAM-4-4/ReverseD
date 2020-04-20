#pragma once
#include "wx/wx.h"
#include <stdio.h>
#include "cDnevnik.h"

//Definiranje cMain klase i davanje joj atributa

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
private:
	cDnevnik* m_frame2 = nullptr;
public:
	wxTextCtrl* m_txt1 = nullptr;
	wxTextCtrl* m_txt2 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxButton* m_btn1 = nullptr;


	void LogIn(wxCommandEvent& evt);

	//Kaže compileru da u cMain prozoru ima eventova koje treba slušat

	wxDECLARE_EVENT_TABLE();
};


#pragma once
#include "wx/wx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "cUcitelj.h"

//Definira klasu cDnevnik i daje joj atribude klase wxFrame (klasa koja omoguæava raðenje prozora)

class cDnevnik : public wxMDIParentFrame
{
public:
	cDnevnik();
	~cDnevnik();
public:
	//Daje cDnevniku ove atribude
	wxToolBar* m_ToolBar = nullptr;
	wxMenuBar* m_MenuBar = nullptr;
	wxTextCtrl* m_txt3 = nullptr;
	wxTextCtrl* m_txt4 = nullptr;
	wxListBox* m_list2 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxComboBox* m_box1 = nullptr;
	wxComboBox* m_box2 = nullptr;


	void OnSelect(wxCommandEvent& evt);
	void OnSelect2(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};



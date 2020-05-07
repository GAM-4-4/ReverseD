#pragma once
#include "wx/richtext/richtextctrl.h"
#include "wx/wx.h"
#include "wx/grid.h"
class cUcitelj :public wxMDIChildFrame
{
public:
	cUcitelj(wxMDIParentFrame* parent, wxString sName);
	~cUcitelj();
public:
	wxListBox* m_listtest = nullptr;
	wxRichTextCtrl* m_test = nullptr;
	wxGrid* m_grid = nullptr;
	wxPNGHandler* handler2 = new wxPNGHandler;
	wxStaticText* m_textime = nullptr;
	wxGrid* m_gridbilje�ke = nullptr;
	wxTextCtrl* m_bilje�ka = nullptr;
	wxListBox* m_bilje�kaOdluka = nullptr;
	wxButton* m_bilje�kabtn = nullptr;
	wxTextCtrl* m_ocjena = nullptr;
	wxButton* m_ocjenabtn = nullptr;
	wxButton* m_nextbtn = nullptr;

	wxButton* m_bilje�kaOdobri = nullptr;
	wxButton* m_bilje�kaObri�i = nullptr;

	void UB(wxCommandEvent& evt);
	void UO(wxCommandEvent& evt);


	void Spremi(wxCommandEvent& evt);
	void Obri�i(wxCommandEvent& evt);
	void Next(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

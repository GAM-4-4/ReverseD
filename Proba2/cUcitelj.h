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
	wxGrid* m_gridbilješke = nullptr;
	wxTextCtrl* m_bilješka = nullptr;
	wxButton* m_bilješkabtn = nullptr;
	wxTextCtrl* m_ocjena = nullptr;
	wxButton* m_ocjenabtn = nullptr;

	void UB(wxCommandEvent& evt);
	void UO(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};


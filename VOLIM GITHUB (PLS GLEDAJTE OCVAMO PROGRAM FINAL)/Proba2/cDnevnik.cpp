#include "cDnevnik.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;


wxBEGIN_EVENT_TABLE(cDnevnik, wxMDIParentFrame)
EVT_COMBOBOX(10003, OnSelect)
EVT_COMBOBOX(10004, OnSelect2)
wxEND_EVENT_TABLE()



extern int wEkran;
extern int hEkran;

//Definira prozor cDnevnik koji se poziva i poziva tu funkciju
int wDnevnik = 1000;
int hDnevnik = 800;

int brskola;

int brojskola() {
	brskola = 0;
	string Red;
	ifstream Skole("Škole.txt");
	while (getline(Skole, Red)) {
		brskola++;
	}
	return brskola;
}

wxArrayString ListaSkola() {
	wxArrayString skole;
	string Red;
	ifstream Skole("Škole.txt");
	while (getline(Skole, Red)) {
		skole.Add(Red);
	}
	return skole;
}

wxArrayString ListaUc(wxString skola) {
	string StdSkola = skola.ToStdString();
	bool tocnaskola = false;
	wxArrayString ucitelji;
	string Red;
	ifstream Ucitelji("Uèitelji.txt");
	while (getline(Ucitelji, Red)) {
		if (tocnaskola && Red != "End") {
			ucitelji.Add(Red.substr(0, Red.find(',')));
		}
		else if (Red == "End" && tocnaskola == true) {
			break;
		}
		if (Red == StdSkola) {
			tocnaskola = true;
		}
	}
	return ucitelji;
}


wxArrayString SplitString2(string Red) {
	wxArrayString rastavljen;
	while (Red.find(",") != std::string::npos) {
		rastavljen.Add(Red.substr(0, Red.find(",")));
		Red = Red.substr(Red.find(",") + 2);
	}
	return rastavljen;

}

wxArrayString PodatciUc(wxString ucitelj) {
	string StdUcitelj = ucitelj.ToStdString();
	wxArrayString uciteljArray;
	string Red;
	ifstream Ucitelji("Uèitelji.txt");
	while (getline(Ucitelji, Red)) {
		if (Red.substr(0, Red.find(",")) == StdUcitelj) {
			uciteljArray = SplitString2(Red);
			break;
		}
	}
	return uciteljArray;
}


cDnevnik::cDnevnik() : wxMDIParentFrame(nullptr, wxID_ANY, "ReverseD", wxPoint((wEkran - wDnevnik) / 2, 50), wxSize(wDnevnik, hDnevnik), wxDEFAULT_FRAME_STYLE | wxMAXIMIZE) {

	SetIcon(wxICON(sample));

	//m_txt3 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(wDnevnik / 2 - 300 / 2, 60), wxSize(300, 30));
	//m_txt4 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(wDnevnik / 2 - 300 / 2, 90), wxSize(300, 30));
	//m_list2 = new wxListBox(this, wxID_ANY, wxPoint(wDnevnik / 2 - 300 / 2, 350), wxSize(300, 100));
	//m_btn2 = new wxButton(this, 10001, "RAK", wxPoint(wDnevnik/2 - 150/2, 500), wxSize(150, 50));

	//Napravi menubar 
	m_MenuBar = new wxMenuBar();
	this->SetMenuBar(m_MenuBar);


	//Napravi toolbar u koji idu ComboBoxevi
	m_ToolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);

	m_box1 = new wxComboBox(m_ToolBar, 10003, wxEmptyString, wxDefaultPosition, wxSize(300, 50), ListaSkola());

}
bool treba = false;
wxString skola;
void cDnevnik::OnSelect(wxCommandEvent& evt) {
	skola = m_box1->GetValue();
	if (treba) {
		m_box2->~wxComboBox();
	}
	m_box2 = new wxComboBox(m_ToolBar, 10004, wxEmptyString, wxPoint(340, 1), wxSize(300, 50), ListaUc(skola));
	treba = true;
}

wxArrayString podatciUcitelja;
wxString ucitelj;
void cDnevnik::OnSelect2(wxCommandEvent& evt) {
	ucitelj = m_box2->GetValue();
	podatciUcitelja = PodatciUc(ucitelj);
	cUcitelj* f = new cUcitelj(this, "Test");
	f->Maximize();
	f->Show();
}


cDnevnik::~cDnevnik() {

}


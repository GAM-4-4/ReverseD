#include "cDnevnik.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//Slušaj za ove eventove

wxBEGIN_EVENT_TABLE(cDnevnik, wxMDIParentFrame)
EVT_COMBOBOX(10003, OnSelect)
EVT_COMBOBOX(10004, OnSelect2)
wxEND_EVENT_TABLE()

//Zovi sirinu i druzinu ekrana s poèetne inicirane klase (cApp)

extern int wEkran;
extern int hEkran;

//Definira prozor cDnevnik koji se poziva i poziva tu funkciju
int wDnevnik = 1000;
int hDnevnik = 800;

int brskola;

//Pobroji kolko je skola u skola fajlu

int brojskola() {
	brskola = 0;
	string Red;
	ifstream Skole("Škole.txt");
	while (getline(Skole, Red)) {
		brskola++;
	}
	return brskola;
}

//Stavi listu skola u array

wxArrayString ListaSkola() {
	wxArrayString skole;
	string Red;
	ifstream Skole("Škole.txt");
	while (getline(Skole, Red)) {
		skole.Add(Red);
	}
	return skole;
}

//Odi kroz popis podataka i stavi samo imena ucitelja u array

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
		else if (Red == "End") {
			break;
		}
		if (Red == StdSkola) {
			tocnaskola = true;
		}
	}
	return ucitelji;
}

//Rastavi line teksta po zarezima u array

wxArrayString SplitString2(string Red) {
	wxArrayString rastavljen;
	while (Red.find(",") != std::string::npos) {
		rastavljen.Add(Red.substr(0, Red.find(",")));
		Red = Red.substr(Red.find(",") + 2);
	}
	return rastavljen;

}

//Spremi line teksta o uèitelju u array (line razdvojen po zarezima)

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


cDnevnik::cDnevnik() : wxMDIParentFrame(nullptr, wxID_ANY, "FejkDnevnik", wxPoint((wEkran - wDnevnik) / 2, 50), wxSize(wDnevnik, hDnevnik), wxDEFAULT_FRAME_STYLE | wxMAXIMIZE) {


	//Napravi menubar 
	m_MenuBar = new wxMenuBar();
	this->SetMenuBar(m_MenuBar);

	wxMenu* menuFile = new wxMenu();
	menuFile->Append(1000, "Drek");


	m_MenuBar->Append(menuFile, "File");
	//Napravi toolbar u koji idu ComboBoxevi
	m_ToolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);

	//Daj drop down listu sa listom moguæih škola
	m_box1 = new wxComboBox(m_ToolBar, 10003, wxEmptyString, wxPoint(10, 1), wxSize(300, 50), ListaSkola());

}

//Na selekt škole uzmi tu školu i izbaci listu uèitelja u drugi combobox 

void cDnevnik::OnSelect(wxCommandEvent& evt) {
	wxString skola = m_box1->GetValue();
	m_box2 = new wxComboBox(m_ToolBar, 10004, wxEmptyString, wxPoint(340, 1), wxSize(300, 50), ListaUc(skola));
}

//Varijable za daljnje korištenje

wxArrayString podatciUcitelja;
wxString ucitelj;

//Kad odabere uèitelja opri dijete prozor i spremi gornje varijable za dalje koristit
void cDnevnik::OnSelect2(wxCommandEvent& evt) {
	ucitelj = m_box2->GetValue();
	podatciUcitelja = PodatciUc(ucitelj);
	cUcitelj* f = new cUcitelj(this, "Test");
	f->Maximize();
	f->Show();
}

//Deconstructor class
cDnevnik::~cDnevnik() {

}


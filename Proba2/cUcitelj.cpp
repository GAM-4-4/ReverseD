#include "cUcitelj.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//Slušaj za ove eventove
wxBEGIN_EVENT_TABLE(cUcitelj, wxMDIChildFrame)
EVT_BUTTON(10001, UB)
EVT_BUTTON(10002, UO)
wxEND_EVENT_TABLE()



//Vidi je uneseno broj od 1 do 5 (u stringu)
bool JelSmije(string ocjena) {
	if (ocjena == "1") {
		return true;
	}
	else if (ocjena == "2") {
		return true;
	}
	else if (ocjena == "3") {
		return true;
	}
	else if (ocjena == "4") {
		return true;
	}
	else if (ocjena == "5") {
		return true;
	}
	else {
		return false;
	}
}

//Gledajuæ red koji sadrži podatke tog profesora, izvadi ocjene po kriterijima, izmeðu ocjena svakog kriterija stavi "end"
//Napravi to kasnije fo funkciju s unosivim markerima

wxArrayString Podatci1R(wxArrayString podatci) {
	wxArrayString R1;
	wxString marker1 = "1R";
	wxString marker2 = "2R";
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R1.Add(podatci[i]);
	}
	R1.Add("end");
	podatci.Remove("1R");
	podatci.Remove("2R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R1.Add(podatci[i]);
	}
	R1.Add("end");
	podatci.Remove("1R");
	podatci.Remove("2R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R1.Add(podatci[i]);
	}
	R1.Add("end");
	return R1;
}

wxArrayString Podatci2R(wxArrayString podatci) {
	wxArrayString R2;
	wxString marker1 = "2R";
	wxString marker2 = "3R";
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R2.Add(podatci[i]);
	}
	R2.Add("end");
	podatci.Remove("2R");
	podatci.Remove("3R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R2.Add(podatci[i]);
	}
	R2.Add("end");
	podatci.Remove("2R");
	podatci.Remove("3R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R2.Add(podatci[i]);
	}
	R2.Add("end");
	return R2;
}
wxArrayString Podatci3R(wxArrayString podatci) {
	wxArrayString R3;
	wxString marker1 = "3R";
	wxString marker2 = "4R";
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R3.Add(podatci[i]);
	}
	R3.Add("end");
	podatci.Remove("3R");
	podatci.Remove("4R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R3.Add(podatci[i]);
	}
	R3.Add("end");
	podatci.Remove("3R");
	podatci.Remove("4R");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R3.Add(podatci[i]);
	}
	R3.Add("end");
	return R3;
}
wxArrayString Podatci4R(wxArrayString podatci) {
	wxArrayString R4;
	wxString marker1 = "4R";
	wxString marker2 = "Helpfulness";
	wxString marker3 = "Težina ispita u odnosu na predavano";
	wxString marker4 = "Kraj";
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker2); i++) {
		R4.Add(podatci[i]);
	}
	R4.Add("end");
	podatci.Remove("4R");
	podatci.Remove("Helpfulness");
	for (int i = (podatci.Index(marker1) + 1); i < podatci.Index(marker3); i++) {
		R4.Add(podatci[i]);
	}
	R4.Add("end");
	podatci.Remove("4R");
	podatci.Remove(marker3);
	for (int i = (podatci.Index(marker1) + 1); i < podatci.size(); i++) {
		R4.Add(podatci[i]);
	}
	R4.Add("end");
	return R4;
}


//Daj srednje vrijednosti svake rubrike u array
wxArrayString SrednjeVrijednosti(wxArrayString podatci1, wxArrayString podatci2, wxArrayString podatci3, wxArrayString podatci4) {
	wxArrayString ukupniPodatci;
	//Daj srednu vrijednost brojeva koje si vidio do end, kad end resetaj na start i ponovo
	for (int i = 0; i < 3; i++) {
		double zbroj = 0;
		int brojbr = 0;
		for (int i = 0; i < podatci1.Index("end"); i++) {
			double broj;
			podatci1[i].ToDouble(&broj);
			zbroj += broj;
			brojbr++;
		}
		wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
		ukupniPodatci.Add(broj1.substr(0, 3));
		podatci1.Remove("end");
	}
	for (int i = 0; i < 3; i++) {
		double zbroj = 0;
		int brojbr = 0;
		for (int i = 0; i < podatci2.Index("end"); i++) {
			double broj;
			podatci2[i].ToDouble(&broj);
			zbroj += broj;
			brojbr++;
		}
		wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
		ukupniPodatci.Add(broj1.substr(0, 3));
		podatci2.Remove("end");
	}
	for (int i = 0; i < 3; i++) {
		double zbroj = 0;
		int brojbr = 0;
		for (int i = 0; i < podatci3.Index("end"); i++) {
			double broj;
			podatci3[i].ToDouble(&broj);
			zbroj += broj;
			brojbr++;
		}
		wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
		ukupniPodatci.Add(broj1.substr(0, 3));
		podatci3.Remove("end");
	}
	for (int i = 0; i < 3; i++) {
		double zbroj = 0;
		int brojbr = 0;
		for (int i = 0; i < podatci4.Index("end"); i++) {
			double broj;
			podatci4[i].ToDouble(&broj);
			zbroj += broj;
			brojbr++;
		}
		wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
		ukupniPodatci.Add(broj1.substr(0, 3));
		podatci4.Remove("end");
	}
	return ukupniPodatci;
}


//Daje trenutno vrijeme dan.mjesec.godina.
//wxDateTime Sad = wxDateTime::Now();
//wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();

//Piši u Bilješke.txt
void StringWriteTo1(string unos) {
	FILE* korisnici = fopen("Bilješke.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Funkcija za unest bilješku u listu, ne unosi automatski u tabelu

void cUcitelj::UB(wxCommandEvent& evt) {
	//Daje trenutno vrijeme dan.mjesec.godina.
	wxDateTime Sad = wxDateTime::Now();
	wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();
	//Formatiraj status;datum.bilješka
	string s1 = "NeOdobren;" + vrijemeSad.ToStdString() + "," + m_bilješka->GetValue().ToStdString() + ",";


	vector <string> redovi;
	string RedT;
	ifstream Bilješke("Bilješke.txt");


	//Stavi sve redove u vektor
	while (getline(Bilješke, RedT)) {
		redovi.push_back(RedT);
	}
	//Obriši sve u fajlu
	FILE* Bilješke1 = fopen("Bilješke.txt", "w");
	fputs("", Bilješke1);

	extern wxString ucitelj;

	bool uciteljJe = false;

	//Stavi red po red natrag u fajl t.k.d. najnoviji odma poslije imena uèitelja kojem je namijenjen
	for (int i = 0; i < redovi.size(); i++) {
		if (redovi[i] == ucitelj.ToStdString()) {
			uciteljJe = true;
		}
		if (uciteljJe) {
			StringWriteTo1(redovi[i]);
			StringWriteTo1(s1);
			uciteljJe = false;
		}
		else {
			StringWriteTo1(redovi[i]);
		}
	}

	//Testovi

	//m_gridbilješke->InsertRows((m_gridbilješke->GetNumberRows() + 1), 1);

	//m_gridbilješke->SetCellValue((m_gridbilješke->GetNumberRows()-1), 0, vrijemeSad);
	//m_gridbilješke->SetCellValue((m_gridbilješke->GetNumberRows()-1), 1, m_bilješka->GetValue());


}

//Splitaj string po zarezu
vector<string> SplitString1(string Red) {
	vector <string> rastavljen;
	while (Red.find(",") != std::string::npos) {
		rastavljen.push_back(Red.substr(0, Red.find(",")));
		Red = Red.substr(Red.find(",") + 2);
	}
	return rastavljen;

}

//Piši u Uèitelj.txt
void StringWriteTo2(string unos) {
	FILE* korisnici = fopen("Uèitelji.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}

//Funkcija za unest ocjenu, unese ju odma poslije razreda korisnika u Uèitelj.txt

void cUcitelj::UO(wxCommandEvent& evt) {

	string ocjena = m_ocjena->GetValue().ToStdString();
	//Mora bit od 1 do 5
	if (JelSmije(ocjena)) {
		vector <string> redovi;
		string RedT;
		ifstream Uèitelji("Uèitelji.txt");

		extern wxString ucitelj;
		string ucitelj1 = ucitelj.ToStdString();

		bool umetni = false;

		//MAKNI OVO KASNIJE OVO JE SAMO ZA PROBU !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		string razred = "4R";

		//Stavi sve redove u vektor

		while (getline(Uèitelji, RedT)) {
			string ime = RedT.substr(0, RedT.find(","));

			//Ako je dobar red (uèitelj ime je toèno)
			if (ime == ucitelj1) {
				//Splitaj u array
				vector <string> rastavljen = SplitString1(RedT);

				//Odi po cijelom arrayu
				for (int i = 0; i < rastavljen.size(); i++) {
					//Ako je taman iteration prije bio razred, umetni unešenu ocjenu poslije razreda i ubi
					if (umetni) {
						rastavljen.insert(rastavljen.begin() + i, ocjena);
						break;
					}
					//Ako je taman na razredu koji se traži
					if (rastavljen[i] == razred) {
						umetni = true;
					}
				}
				//Spoji taj updejtan array natrag u string i stvi u vector koji drži cijeli fajl 
				string updated;
				for (int j = 0; j < rastavljen.size(); j++) {
					updated = updated + rastavljen[j] + ", ";
				}
				updated = updated + "Kraj";
				redovi.push_back(updated);
			}
			//Stavi dani red u vekto sa svim redovima
			else {
				redovi.push_back(RedT);
			}
		}


		FILE* Uèitelji1 = fopen("Uèitelji.txt", "w");
		fputs("", Uèitelji1);
		//U prazan fajl unesi vektor item po item da dobiš isto formatirano
		for (int i = 0; i < redovi.size(); i++) {
			StringWriteTo2(redovi[i]);
		}
	}

}


//Vrati string tako da je doputeštena duljina bilješke u svakom redu dobra

string RazbiNaRedove(string red) {
	string Gotovo;
	string red1 = red;
	while (red1.length() > 155) {
		string znak155 = red1.substr(0, 154);
		Gotovo = Gotovo + znak155.substr(0, znak155.rfind(" ")) + "\n";
		int poz = znak155.rfind(" ");
		red1 = red1.substr(poz + 1, red1.length() - 1);
	}
	Gotovo = Gotovo + red1;
	return Gotovo;
}



//Poèetak definiranja prozora

cUcitelj::cUcitelj(wxMDIParentFrame* parent, wxString sName) : wxMDIChildFrame(parent, wxID_ANY, sName) {
	//m_listtest = new wxListBox(this, wxID_ANY, wxPoint(850, 0), wxSize(300, 150));
	m_grid = new wxGrid(this, -1, wxPoint(50, 250), wxSize(585, 300));

	//Unos ocjene
	m_ocjena = new wxTextCtrl(this, wxID_ANY, "Unesi ocjenu od 1 do 5", wxPoint(50, 630), wxSize(375, 50));
	m_ocjenabtn = new wxButton(this, 10002, "Submit", wxPoint(485, 630), wxSize(150, 50));

	//Unos bilješke
	m_bilješka = new wxTextCtrl(this, wxID_ANY, "Unesi bilješku", wxPoint(50, 700), wxSize(375, 50));
	m_bilješkabtn = new wxButton(this, 10001, "Submit", wxPoint(485, 700), wxSize(150, 50));

	wxFont font = wxFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	//Definiranje grida za prosjeène ocjene
	m_grid->DisableDragGridSize();

	m_grid->CreateGrid(4, 3);

	m_grid->SetDefaultRowSize(60);
	m_grid->SetDefaultColSize(125);
	m_grid->SetColSize(2, 250);
	m_grid->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	m_grid->SetColLabelValue(0, "Odnos prema radu");
	m_grid->SetRowLabelValue(0, "1. razredi");
	m_grid->SetColLabelValue(1, "Helpfulness");
	m_grid->SetRowLabelValue(1, "2. razredi");
	m_grid->SetColLabelValue(2, "Težina ispita u odnosu na ispredavano");
	m_grid->SetRowLabelValue(2, "3. razredi");
	m_grid->SetRowLabelValue(3, "4. razredi");



	extern wxString ucitelj;

	//m_textime = new wxStaticText(this, wxID_ANY, ucitelj, wxPoint(200, 180), wxSize(150,50));


	//Postavi sliku
	wxImage::AddHandler(handler2);
	wxStaticBitmap* image;

	image = new wxStaticBitmap(this, wxID_ANY, wxBitmap((ucitelj + ".png"), wxBITMAP_TYPE_PNG), wxPoint(50, 50), wxSize(129, 150));



	//Bilješke strpa u grid

	m_gridbilješke = new wxGrid(this, -1, wxPoint(700, 250), wxSize(1200, 700));

	m_gridbilješke->DisableDragGridSize();

	m_gridbilješke->HideRowLabels();
	m_gridbilješke->CreateGrid(0, 2);
	m_gridbilješke->SetColSize(0, 125);
	m_gridbilješke->SetColSize(1, 1025);
	m_gridbilješke->SetDefaultRowSize(30);

	m_gridbilješke->SetRowLabelSize(1);

	m_gridbilješke->SetColLabelValue(0, "Datum");
	m_gridbilješke->SetColLabelValue(1, "Bilješka");

	//Podatci za bilješke
	string RedTeksta;
	ifstream Bilješke("Bilješke.txt");
	int red = 0;

	//Ovvaj bool ode na true kad doðe do imena profesora
	bool prvi = false;

	wxFont font1 = wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	//Odi po svim bilješkama
	while (getline(Bilješke, RedTeksta)) {
		//Ako je tažen prof skipaj umetanje 
		if (RedTeksta == ucitelj) {
			prvi = true;
			continue;
		}
		string RedTeksta2;

		//Nakon što je prof naðen odi red po red bilješke dok ne naðeš "End", uzmi bilješku samo ako je "Odobren"
		if (prvi && RedTeksta.substr(0, RedTeksta.find(";")) == "Odobren") {
			
			//Makni odobren s poèetka da imaš "datum,komentar"
			RedTeksta2 = RedTeksta.substr(RedTeksta.find(";") + 1, RedTeksta.length() - 1);

			//Ako je "End" ubi
			if (RedTeksta == "End") {
				break;
			}
			//Za svaku odobrenu dodaj red, umetni u 0 i 1 cell podatke, formatiraj
			m_gridbilješke->InsertRows(red, 1);
			string Datum = RedTeksta2.substr(0, RedTeksta2.find(","));
			string Bilješka = RedTeksta2.substr(RedTeksta2.find(",") + 1, RedTeksta2.length() - 1);
			m_gridbilješke->SetCellValue(red, 0, Datum);
			m_gridbilješke->SetCellValue(red, 1, RazbiNaRedove(Bilješka));

			m_gridbilješke->SetReadOnly(red, 0);
			m_gridbilješke->SetReadOnly(red, 1);

			m_gridbilješke->SetCellAlignment(red, 0, wxALIGN_CENTER, wxALIGN_CENTER);
			m_gridbilješke->SetCellAlignment(red, 1, wxALIGN_LEFT, wxALIGN_CENTER);
			
			//Ovisno o duljini bilješke posatvi visinu reda
			m_gridbilješke->SetRowSize(red, (Bilješka.length() / 155) * 16 + 30);

			m_gridbilješke->SetCellFont(red, 0, font1);
			m_gridbilješke->SetCellFont(red, 1, font1);

			red++;
		}
	}

	//Daj texbox da displaya ime uèitelja
	m_test = new wxRichTextCtrl(this, wxID_ANY, ucitelj, wxPoint(220, 130), wxSize(700, 80), wxTE_READONLY | wxBORDER_NONE | wxWANTS_CHARS);
	m_test->SetFont(wxFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


	//tEST JE RADI FUNKCIJA, IZBACI U LISTBOX
	extern wxArrayString podatciUcitelja;
	/*
	wxArrayString test = Podatci4R(podatciUcitelja);
	int broj = test.GetCount();
	int i = 0;
	while (i<broj) {
		m_listtest->AppendString(test[i]);
		i++;
	}
	*/


	//Iz jednog arraya unese u tabelu srednje vrijednosti
	wxArrayString ukupniPodatci = SrednjeVrijednosti(Podatci1R(podatciUcitelja), Podatci2R(podatciUcitelja), Podatci3R(podatciUcitelja), Podatci4R(podatciUcitelja));
	int f = 0;
	//Proði po cellovima grida i u svaki stavi one srednje vrijednosti i formatiraj ih
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			m_grid->SetCellValue(i, j, ukupniPodatci[f]);
			m_grid->SetCellFont(i, j, font);
			m_grid->SetReadOnly(i, j);
			f++;
		}
	}
}

//Deconstructor
cUcitelj::~cUcitelj() {

}
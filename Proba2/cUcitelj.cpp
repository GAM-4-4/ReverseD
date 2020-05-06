#include "cUcitelj.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


wxBEGIN_EVENT_TABLE(cUcitelj, wxMDIChildFrame)

EVT_BUTTON(10001, UB)
EVT_BUTTON(10002, UO)
EVT_BUTTON(10004, Spremi)
EVT_BUTTON(10005, Obri�i)
EVT_BUTTON(10006, Next)
wxEND_EVENT_TABLE()



//Vidi je uneseno broj od 1 do 5 (u stringu)
bool JelSmije(string ocjenaUnesena) {
	string ocjena = ocjenaUnesena.substr(0, 1);
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

//Gledaju� red koji sadr�i podatke tog profesora, izvadi ocjene po kriterijima, izme�u ocjena svakog kriterija stavi "end"

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
	wxString marker3 = "Te�ina ispita u odnosu na predavano";
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

//Iz arraya sa ocjenama spejsanim po kriteriju i odvojenim po razredima daj array sa vrijednostima prosjeka po razredima po kriterijima 

wxArrayString SrednjeVrijednosti(wxArrayString podatci1, wxArrayString podatci2, wxArrayString podatci3, wxArrayString podatci4) {
	wxArrayString ukupniPodatci;
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
wxDateTime Sad = wxDateTime::Now();
wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();

//Wrajtaj mi u bilje�ke

void StringWriteTo1(string unos) {
	FILE* korisnici = fopen("Bilje�ke.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Funkcija za unest bilje�ku u listu, ne unosi automatski u tabelu

void cUcitelj::UB(wxCommandEvent& evt) {
	if ((m_bilje�ka->GetValue().ToStdString() != "Unesi bilje�ku") && !(m_bilje�ka->IsEmpty()) && (m_bilje�ka->GetValue().ToStdString() != "Neuspjeh. Unesi bilje�ku") && (m_bilje�ka->GetValue().ToStdString() != "Bilje�ka uspje�no unesena")) {
			//Daje trenutno vrijeme dan.mjesec.godina.
			wxDateTime Sad = wxDateTime::Now();
			wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();
			string s1 = "NeOdobren;" + vrijemeSad.ToStdString() + "," + m_bilje�ka->GetValue().ToStdString();


			vector <string> redovi;
			string RedT;
			ifstream Bilje�ke("Bilje�ke.txt");


			//Stavi sve redove u vektor
			while (getline(Bilje�ke, RedT)) {
				redovi.push_back(RedT);
			}
		//Obri�i sve u fajlu
		FILE* Bilje�ke1 = fopen("Bilje�ke.txt", "w");
		fputs("", Bilje�ke1);

		extern wxString ucitelj;

		bool uciteljJe = false;

		//Stavi red po red natrag u fajl t.k.d. najnoviji do�e prije "End," pod u�itelj kojem je namjenjen
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
		//Reci korisniku da je uspjelo
		m_bilje�ka->~wxTextCtrl();
		m_bilje�ka = new wxTextCtrl(this, wxID_ANY, "Bilje�ka uspje�no unesena", wxPoint(50, 700), wxSize(375, 50));
	}
	else {
		//Reci korisniku da nije uspjelos
		m_bilje�ka->~wxTextCtrl();
		m_bilje�ka = new wxTextCtrl(this, wxID_ANY, "Neuspjeh. Unesi bilje�ku", wxPoint(50, 700), wxSize(375, 50));
	}

}
//Unesi ocjenu odnosno o razredu odma poslje oznake razreda u ocjenama 

vector<string> SplitString1(string Red) {
	vector <string> rastavljen;
	while (Red.find(",") != std::string::npos) {
		rastavljen.push_back(Red.substr(0, Red.find(",")));
		Red = Red.substr(Red.find(",") + 2);
	}
	return rastavljen;

}

//Za zapisat u U�itelji.txt
void StringWriteTo2(string unos) {
	FILE* korisnici = fopen("U�itelji.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Funkcija za unest ocjenu, unese ju odma poslije razreda korisnika u U�itelj.txt

void cUcitelj::UO(wxCommandEvent& evt) {

	vector <string> kriteriji;

	kriteriji.push_back("Odnos prema radu");
	kriteriji.push_back("Helpfulness");
	kriteriji.push_back("Te�ina ispita u odnosu na predavano");

	string ocjena = m_ocjena->GetValue().ToStdString();

	if (JelSmije(ocjena)) {
		vector <string> redovi;
		string RedT;
		ifstream U�itelji("U�itelji.txt");

		extern wxString ucitelj;
		string ucitelj1 = ucitelj.ToStdString();

		bool umetni = false;

		extern string razred;

		//Stavi sve redove u vektor

		while (getline(U�itelji, RedT)) {
			string ime = RedT.substr(0, RedT.find(","));
			//Kad do�e� do korektnog u�itelja
			if (ime == ucitelj1) {

				vector <string> rastavljen = SplitString1(RedT);
				bool dobarKriterij = false;
				//Pro�i sve elemente tog reda koji opisuje u�itelja
				for (int i = 0; i < rastavljen.size(); i++) {
					if (umetni) {
						//Kad si na�ao to�nog u�itelja i pro�ao uneseni kriterij
						rastavljen.insert(rastavljen.begin() + i, ocjena.substr(0, 1));
						break;
					}
					//Gleda jel pro�o dobar kriterij i �eka da do�e oznaka dobrog razred
					if (rastavljen[i] == razred && dobarKriterij) {
						umetni = true;
					}
					//Jel kriterij koji je unesen unesen
					if (rastavljen[i] == kriteriji[stoi(ocjena.substr(2, 1)) - 1]) {
						dobarKriterij = true;
					}
				}
				//Unesi taj updejtan string natrag u vektor
				string updated;
				for (int j = 0; j < rastavljen.size(); j++) {
					updated = updated + rastavljen[j] + ", ";
				}
				updated = updated + "Kraj";
				redovi.push_back(updated);
				//Potvrda u unosu
				m_ocjena->~wxTextCtrl();
				m_ocjena = new wxTextCtrl(this, wxID_ANY, "Ocjena uspje�no unesena", wxPoint(50, 630), wxSize(375, 50));
			}

			else {
				redovi.push_back(RedT);
			}
		}

		//Zapi�i sve natrag u tekst fajl
		FILE* U�itelji1 = fopen("U�itelji.txt", "w");
		fputs("", U�itelji1);

		for (int i = 0; i < redovi.size(); i++) {
			StringWriteTo2(redovi[i]);
		}
	}

	else {
		//Poruka za fail
		m_ocjena->~wxTextCtrl();
		m_ocjena = new wxTextCtrl(this, wxID_ANY, "Ocjena nije od 1 do 5", wxPoint(50, 630), wxSize(375, 50));
	}

}


//Vrati string tako da je dopute�tena duljina bilje�ke u svakom redu dobra

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

int brojBilje�ke = 0;
vector <string> Bilje�keVec;

//Funkcija za odobrit bilje�ku
void cUcitelj::Spremi(wxCommandEvent& evt) {
	string red = Bilje�keVec[brojBilje�ke];
	string unesi = "Odobren;" + red.substr(red.find(";") + 1, red.length() - 1);
	Bilje�keVec.insert(Bilje�keVec.begin() + brojBilje�ke, unesi);
	Bilje�keVec.erase(Bilje�keVec.begin() + brojBilje�ke + 1);

	extern wxString ucitelj;

	vector <string> redovi;
	string RedT;
	ifstream ABilje�ke("Bilje�ke.txt");


	//Stavi sve redove u vektor
	while (getline(ABilje�ke, RedT)) {
		redovi.push_back(RedT);
	}
	//Obri�i sve u fajlu
	FILE* ABilje�ke1 = fopen("Bilje�ke.txt", "w");
	fputs("", ABilje�ke1);

	vector <string> popravljen;
	bool nijeUcitelj = true;
	bool traziEnd = false;
	bool naslaEnd = false;
 
	for (int i = 0; i < redovi.size(); i++) {
		
		if (nijeUcitelj) {
			popravljen.push_back(redovi[i]);
			//Kad na�e� dobru bilje�ku koja se poklapa sa onom u textboxu spremi ju kao odobrenu
			if (redovi[i] == ucitelj) {
				nijeUcitelj = false;
				traziEnd = true;

				for (int j = 0; j < Bilje�keVec.size(); j++) {
					popravljen.push_back(Bilje�keVec[j]);
				}
			}
		}
		//Kad na�e kraj biljepki reci da jesi
		if (traziEnd && redovi[i] == "End") {
			naslaEnd = true;
		}
		//Ako na�en end dodaj tu odobrenu bilje�ku
		if (naslaEnd) {
			popravljen.push_back(redovi[i]);
		}

	}
	//Zapi�i sve opet u biljepke
	for (int k = 0; k < popravljen.size(); k++) {
		StringWriteTo1(popravljen[k]);
	}

	brojBilje�ke = (brojBilje�ke + 1) % Bilje�keVec.size();


	m_bilje�kaOdluka->SetString(0, (Bilje�keVec[brojBilje�ke].substr(Bilje�keVec[brojBilje�ke].find(",") + 1, Bilje�keVec[brojBilje�ke].length() - 1)));
}

void cUcitelj::Obri�i(wxCommandEvent& evt) {

	string red = Bilje�keVec[brojBilje�ke];

	Bilje�keVec.erase(Bilje�keVec.begin() + brojBilje�ke);

	extern wxString ucitelj;

	vector <string> redovi;
	string RedT;
	ifstream Bilje�ke("Bilje�ke.txt");


	//Stavi sve redove u vektor
	while (getline(Bilje�ke, RedT)) {
		redovi.push_back(RedT);
	}
	//Obri�i sve u fajlu
	FILE* BBilje�ke1 = fopen("Bilje�ke.txt", "w");
	fputs("", BBilje�ke1);

	for (int k = 0; k < redovi.size(); k++) {
		if (redovi[k] == red) {
			continue;
		}
		StringWriteTo1(redovi[k]);
	}



	m_bilje�kaOdluka->SetString(0, (Bilje�keVec[brojBilje�ke].substr(Bilje�keVec[brojBilje�ke].find(",") + 1, Bilje�keVec[brojBilje�ke].length() - 1)));
}


void cUcitelj::Next(wxCommandEvent& evt) {
	brojBilje�ke = (brojBilje�ke + 1) % Bilje�keVec.size();
	m_bilje�kaOdluka->SetString(0, (Bilje�keVec[brojBilje�ke].substr(Bilje�keVec[brojBilje�ke].find(",") + 1, Bilje�keVec[brojBilje�ke].length() - 1)));
}

//Po�etak definiranja prozora

cUcitelj::cUcitelj(wxMDIParentFrame* parent, wxString sName) : wxMDIChildFrame(parent, wxID_ANY, sName) {

	SetIcon(wxICON(sample));

	//m_listtest = new wxListBox(this, wxID_ANY, wxPoint(850, 0), wxSize(300, 150));
	m_grid = new wxGrid(this, -1, wxPoint(50, 250), wxSize(583, 273));

	m_ocjena = new wxTextCtrl(this, wxID_ANY, "Unesi ocjenu od 1 do 5", wxPoint(50, 630), wxSize(375, 50));
	m_ocjenabtn = new wxButton(this, 10002, "Submit", wxPoint(485, 630), wxSize(150, 50));


	m_bilje�ka = new wxTextCtrl(this, wxID_ANY, "Unesi bilje�ku", wxPoint(50, 700), wxSize(375, 50));
	m_bilje�kabtn = new wxButton(this, 10001, "Submit", wxPoint(485, 700), wxSize(150, 50));

	wxFont font = wxFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

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
	m_grid->SetColLabelValue(2, "Te�ina ispita u odnosu na ispredavano");
	m_grid->SetRowLabelValue(2, "3. razredi");
	m_grid->SetRowLabelValue(3, "4. razredi");



	extern wxString ucitelj;

	//m_textime = new wxStaticText(this, wxID_ANY, ucitelj, wxPoint(200, 180), wxSize(150,50));



	wxImage::AddHandler(handler2);
	wxStaticBitmap* image;

	image = new wxStaticBitmap(this, wxID_ANY, wxBitmap((ucitelj + ".png"), wxBITMAP_TYPE_PNG), wxPoint(50, 50), wxSize(129, 150));



	//Bilje�ke strpa u grid

	m_gridbilje�ke = new wxGrid(this, 10003, wxPoint(700, 250), wxSize(1153, 650));

	m_gridbilje�ke->DisableDragGridSize();

	m_gridbilje�ke->HideRowLabels();
	m_gridbilje�ke->CreateGrid(0, 2);
	m_gridbilje�ke->SetColSize(0, 125);
	m_gridbilje�ke->SetColSize(1, 1025);
	m_gridbilje�ke->SetDefaultRowSize(30);

	m_gridbilje�ke->SetRowLabelSize(1);

	m_gridbilje�ke->SetColLabelValue(0, "Datum");
	m_gridbilje�ke->SetColLabelValue(1, "Bilje�ka");


	string RedTeksta;
	ifstream Bilje�ke("Bilje�ke.txt");



	int red = 0;



	extern bool jeAdmin;

	//Ovvaj bool ode na true kad do�e do imena profesora
	bool prvi = false;

	wxFont font1 = wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	while (getline(Bilje�ke, RedTeksta)) {
		//Ako je prof skipaj umetanje
		if (RedTeksta == ucitelj) {
			prvi = true;
			continue;
		}
		string RedTeksta2;

		//Ako odobren i nije prof 
		if (prvi && ((RedTeksta.substr(0, RedTeksta.find(";")) == "Odobren") || jeAdmin == true)) {
			//Ako je "End," ubi
			RedTeksta2 = RedTeksta.substr(RedTeksta.find(";") + 1, RedTeksta.length() - 1);
			if (RedTeksta == "End") {
				break;
			}
			m_gridbilje�ke->InsertRows(red, 1);
			string Datum = RedTeksta2.substr(0, RedTeksta2.find(","));
			string Bilje�ka = RedTeksta2.substr(RedTeksta2.find(",") + 1, RedTeksta2.length() - 1);


			Bilje�keVec.push_back(RedTeksta);

			m_gridbilje�ke->SetCellValue(red, 0, Datum);
			m_gridbilje�ke->SetCellValue(red, 1, RazbiNaRedove(Bilje�ka));

			m_gridbilje�ke->SetReadOnly(red, 0);
			m_gridbilje�ke->SetReadOnly(red, 1);

			m_gridbilje�ke->SetCellAlignment(red, 0, wxALIGN_CENTER, wxALIGN_CENTER);
			m_gridbilje�ke->SetCellAlignment(red, 1, wxALIGN_LEFT, wxALIGN_CENTER);

			m_gridbilje�ke->SetRowSize(red, (Bilje�ka.length() / 155) * 16 + 30);

			m_gridbilje�ke->SetCellFont(red, 0, font1);
			m_gridbilje�ke->SetCellFont(red, 1, font1);

			red++;
		}
	}

	if (jeAdmin) {
		//Elementi za brisat bilje�ke
		m_bilje�kaOdobri = new wxButton(this, 10004, "Odobri Bilje�ku", wxPoint(1300, 125), wxSize(150, 50));
		m_bilje�kaObri�i = new wxButton(this, 10005, "Obri�i Bilje�ku", wxPoint(1500, 125), wxSize(150, 50));

		m_bilje�kaOdluka = new wxListBox(this, wxID_ANY, wxPoint(825, 50), wxSize(1025, 50));
		m_bilje�kaOdluka->AppendString(Bilje�keVec[brojBilje�ke].substr(Bilje�keVec[brojBilje�ke].find(",") + 1, Bilje�keVec[brojBilje�ke].length() - 1));

		m_nextbtn = new wxButton(this, 10006, "Sljede�a bilje�ka", wxPoint(1700, 125), wxSize(150, 50));
	}


	m_test = new wxRichTextCtrl(this, wxID_ANY, ucitelj, wxPoint(220, 130), wxSize(700, 80), wxTE_READONLY | wxBORDER_NONE | wxWANTS_CHARS);


	m_test->SetFont(wxFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	extern wxArrayString podatciUcitelja;


	//Iz jednog arraya unese u tabelu srednje vrijednosti
	wxArrayString ukupniPodatci = SrednjeVrijednosti(Podatci1R(podatciUcitelja), Podatci2R(podatciUcitelja), Podatci3R(podatciUcitelja), Podatci4R(podatciUcitelja));
	int f = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			m_grid->SetCellValue(i, j, ukupniPodatci[f]);
			m_grid->SetCellFont(i, j, font);
			m_grid->SetReadOnly(i, j);
			f++;
		}
	}
}
cUcitelj::~cUcitelj() {

}
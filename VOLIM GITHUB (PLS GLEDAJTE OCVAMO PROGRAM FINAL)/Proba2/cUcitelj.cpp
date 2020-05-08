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
EVT_BUTTON(10005, Obriši)
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

//Gledajuæ red koji sadrži podatke tog profesora, izvadi ocjene po kriterijima, izmeðu ocjena svakog kriterija stavi "end"

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

//Iz arraya sa ocjenama spejsanim po kriteriju i odvojenim po razredima daj array sa vrijednostima prosjeka po razredima po kriterijima 
double zbroj = 0;
int brojbr = 0;
double broj = 0;
int brojEnd;
wxArrayString SrednjeVrijednosti(wxArrayString podatci1, wxArrayString podatci2, wxArrayString podatci3, wxArrayString podatci4) {
	wxArrayString ukupniPodatci;
	for (int i = 0; i < 3; i++) {
		zbroj = 0;
		brojbr = 0;
		brojEnd = podatci1.Index("end");
		if (podatci1[0] + podatci1[1] + podatci1[2] != "endendend") {
			for (int j = 0; j < brojEnd; j++) {
				broj = 0;
				podatci1[0].ToDouble(&broj);
				zbroj += broj;
				brojbr++;
				podatci1.RemoveAt(0, 1);
			}
			wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
			ukupniPodatci.Add(broj1.substr(0, 3));
			podatci1.RemoveAt(0, 1);
		}
		else {
			ukupniPodatci.Add("0,0");
		}
	}
	for (int i = 0; i < 3; i++) {
		zbroj = 0;
		brojbr = 0;
		brojEnd = podatci2.Index("end");
		if (podatci2[0] + podatci2[1] + podatci2[2] != "endendend") {
			for (int j = 0; j < brojEnd; j++) {
				broj = 0;
				podatci2[0].ToDouble(&broj);
				zbroj += broj;
				brojbr++;
				podatci2.RemoveAt(0, 1);
			}
			wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
			ukupniPodatci.Add(broj1.substr(0, 3));
			podatci2.RemoveAt(0, 1);
		}
		else {
			ukupniPodatci.Add("0,0");
		}
	}
	for (int i = 0; i < 3; i++) {
		zbroj = 0;
		brojbr = 0;
		brojEnd = podatci3.Index("end");
		if (podatci3[0] + podatci3[1] + podatci3[2] != "endendend") {
			for (int j = 0; j < brojEnd; j++) {
				broj = 0;
				podatci3[0].ToDouble(&broj);
				zbroj += broj;
				brojbr++;
				podatci3.RemoveAt(0, 1);
			}
			wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
			ukupniPodatci.Add(broj1.substr(0, 3));
			podatci3.RemoveAt(0, 1);
		}
		else {
			ukupniPodatci.Add("0,0");
		}
	}
	for (int i = 0; i < 3; i++) {
		zbroj = 0;
		brojbr = 0;
		brojEnd = podatci4.Index("end");
		if (podatci4[0] + podatci4[1] + podatci4[2] != "endendend") {
			for (int j = 0; j < brojEnd; j++) {
				broj = 0;
				podatci4[0].ToDouble(&broj);
				zbroj += broj;
				brojbr++;
				podatci4.RemoveAt(0, 1);
			}
			wxString broj1 = wxString::Format(wxT("%f"), zbroj / brojbr);
			ukupniPodatci.Add(broj1.substr(0, 3));
			podatci4.RemoveAt(0, 1);
		}
		else {
			ukupniPodatci.Add("0,0");
		}
	}
	return ukupniPodatci;
}


//Daje trenutno vrijeme dan.mjesec.godina.
wxDateTime Sad = wxDateTime::Now();
wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();

//Wrajtaj mi u bilješke

void StringWriteTo1(string unos) {
	FILE* korisnici = fopen("Bilješke.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Funkcija za unest bilješku u listu, ne unosi automatski u tabelu

void cUcitelj::UB(wxCommandEvent& evt) {
	if ((m_bilješka->GetValue().ToStdString() != "Unesi bilješku") && !(m_bilješka->IsEmpty()) && (m_bilješka->GetValue().ToStdString() != "Neuspjeh. Unesi bilješku") && (m_bilješka->GetValue().ToStdString() != "Bilješka uspješno unesena")) {
			//Daje trenutno vrijeme dan.mjesec.godina.
			wxDateTime Sad = wxDateTime::Now();
			wxString vrijemeSad = Sad.Format("%d.%m.%Y.", wxDateTime::CET).c_str();
			string s1 = "NeOdobren;" + vrijemeSad.ToStdString() + "," + m_bilješka->GetValue().ToStdString();


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

		//Stavi red po red natrag u fajl t.k.d. najnoviji doðe prije "End," pod uèitelj kojem je namjenjen
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
		m_bilješka->~wxTextCtrl();
		m_bilješka = new wxTextCtrl(this, wxID_ANY, "Bilješka uspješno unesena", wxPoint(50, 700), wxSize(375, 50));
	}
	else {
		//Reci korisniku da nije uspjelos
		m_bilješka->~wxTextCtrl();
		m_bilješka = new wxTextCtrl(this, wxID_ANY, "Neuspjeh. Unesi bilješku", wxPoint(50, 700), wxSize(375, 50));
	}

}
string datum;

//Unesi ocjenu odnosno o razredu odma poslje oznake razreda u ocjenama 

vector<string> SplitString1(string Red) {
	vector <string> rastavljen;
	while (Red.find(",") != std::string::npos) {
		rastavljen.push_back(Red.substr(0, Red.find(",")));
		Red = Red.substr(Red.find(",") + 2);
	}
	return rastavljen;

}

//Za zapisat u Uèitelji.txt
void StringWriteTo2(string unos) {
	FILE* korisnici = fopen("Uèitelji.txt", "a");
	const char* uneseno = unos.c_str();
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Funkcija za unest ocjenu, unese ju odma poslije razreda korisnika u Uèitelj.txt
extern string razred;
void cUcitelj::UO(wxCommandEvent& evt) {

	vector <string> kriteriji;

	kriteriji.push_back("Odnos prema radu");
	kriteriji.push_back("Helpfulness");
	kriteriji.push_back("Težina ispita u odnosu na predavano");

	string ocjena = m_ocjena->GetValue().ToStdString();

	if (JelSmije(ocjena)) {
		vector <string> redovi;
		string RedT;
		ifstream Uèitelji("Uèitelji.txt");

		extern wxString ucitelj;
		string ucitelj1 = ucitelj.ToStdString();

		bool umetni = false;
		bool nijeJoš = true;

		//Stavi sve redove u vektor

		while (getline(Uèitelji, RedT)) {
			string ime = RedT.substr(0, RedT.find(","));
			//Kad doðeš do korektnog uèitelja
			if ((ime == ucitelj1) && nijeJoš) {

				vector <string> rastavljen = SplitString1(RedT);
				bool dobarKriterij = false;
				//Proði sve elemente tog reda koji opisuje uèitelja
				for (int i = 0; i < rastavljen.size(); i++) {
					if (umetni) {
						//Kad si našao toènog uèitelja i prošao uneseni kriterij
						rastavljen.insert(rastavljen.begin() + i, ocjena.substr(0, 1));
						nijeJoš = false;
						break;
					}
					//Gleda jel prošo dobar kriterij i èeka da doðe oznaka dobrog razred
					if ((rastavljen[i] == razred) && dobarKriterij) {
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
				m_ocjena = new wxTextCtrl(this, wxID_ANY, "Ocjena uspješno unesena", wxPoint(50, 630), wxSize(375, 50), wxTE_MULTILINE);
			}

			else {
				redovi.push_back(RedT);
			}
		}

		//Zapiši sve natrag u tekst fajl
		FILE* Uèitelji1 = fopen("Uèitelji.txt", "w");
		fputs("", Uèitelji1);

		for (int i = 0; i < redovi.size(); i++) {
			StringWriteTo2(redovi[i]);
		}
	}

	else {
		//Poruka za fail
		m_ocjena->~wxTextCtrl();
		m_ocjena = new wxTextCtrl(this, wxID_ANY, "Ocjena nije od 1 do 5 ili format nije toèan", wxPoint(50, 630), wxSize(375, 50), wxTE_MULTILINE);
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

int brojBilješke = 0;
vector <string> BilješkeVec;

//Funkcija za odobrit bilješku
void cUcitelj::Spremi(wxCommandEvent& evt) {
	string red = BilješkeVec[brojBilješke];
	string unesi = "Odobren;" + red.substr(red.find(";") + 1, red.length() - 1);
	BilješkeVec.insert(BilješkeVec.begin() + brojBilješke, unesi);
	BilješkeVec.erase(BilješkeVec.begin() + brojBilješke + 1);

	extern wxString ucitelj;

	vector <string> redovi;
	string RedT;
	ifstream ABilješke("Bilješke.txt");


	//Stavi sve redove u vektor
	while (getline(ABilješke, RedT)) {
		redovi.push_back(RedT);
	}
	//Obriši sve u fajlu
	FILE* ABilješke1 = fopen("Bilješke.txt", "w");
	fputs("", ABilješke1);

	vector <string> popravljen;
	bool nijeUcitelj = true;
	bool traziEnd = false;
	bool naslaEnd = false;
 
	for (int i = 0; i < redovi.size(); i++) {
		
		if (nijeUcitelj) {
			popravljen.push_back(redovi[i]);
			//Kad naðeš dobru bilješku koja se poklapa sa onom u textboxu spremi ju kao odobrenu
			if (redovi[i] == ucitelj) {
				nijeUcitelj = false;
				traziEnd = true;

				for (int j = 0; j < BilješkeVec.size(); j++) {
					popravljen.push_back(BilješkeVec[j]);
				}
			}
		}
		//Kad naðe kraj biljepki reci da jesi
		if (traziEnd && redovi[i] == "End") {
			naslaEnd = true;
		}
		//Ako naðen end dodaj tu odobrenu bilješku
		if (naslaEnd) {
			popravljen.push_back(redovi[i]);
		}

	}
	//Zapiši sve opet u biljepke
	for (int k = 0; k < popravljen.size(); k++) {
		StringWriteTo1(popravljen[k]);
	}

	brojBilješke = (brojBilješke + 1) % BilješkeVec.size();


	if (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";")) == "NeOdobren") {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";") + 1) + BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}
	else {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}

}

void cUcitelj::Obriši(wxCommandEvent& evt) {

	string red = BilješkeVec[brojBilješke];

	BilješkeVec.erase(BilješkeVec.begin() + brojBilješke);

	extern wxString ucitelj;

	vector <string> redovi;
	string RedT;
	ifstream Bilješke("Bilješke.txt");


	//Stavi sve redove u vektor
	while (getline(Bilješke, RedT)) {
		redovi.push_back(RedT);
	}
	//Obriši sve u fajlu
	FILE* BBilješke1 = fopen("Bilješke.txt", "w");
	fputs("", BBilješke1);

	for (int k = 0; k < redovi.size(); k++) {
		if (redovi[k] == red) {
			continue;
		}
		StringWriteTo1(redovi[k]);
	}

	if (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";")) == "NeOdobren") {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";") + 1) + BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}
	else {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}


}

//Odi na sljedeæi bilješku
void cUcitelj::Next(wxCommandEvent& evt) {
	brojBilješke = (brojBilješke + 1) % BilješkeVec.size();
	if (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";")) == "NeOdobren") {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";") + 1) + BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}
	else {
		m_bilješkaOdluka->SetString(0, (BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1)));

	}
}




//Poèetak definiranja prozora
extern bool nijeProf;
cUcitelj::cUcitelj(wxMDIParentFrame* parent, wxString sName) : wxMDIChildFrame(parent, wxID_ANY, sName) {

	SetIcon(wxICON(sample));

	brojBilješke = 0;
	BilješkeVec.clear();
	//m_listtest = new wxListBox(this, wxID_ANY, wxPoint(850, 0), wxSize(300, 150));
	m_grid = new wxGrid(this, -1, wxPoint(50, 250), wxSize(583, 273));

	if (nijeProf) {
		m_ocjena = new wxTextCtrl(this, wxID_ANY, "Unesi ocjenu od 1 do 5 u formatu 'ocjena,redniBrojKriterija' \n(npr. 3 iz Odnosa prema radu je '3,1') ", wxPoint(50, 630), wxSize(375, 50), wxTE_MULTILINE);
		m_ocjenabtn = new wxButton(this, 10002, "Submit", wxPoint(485, 630), wxSize(150, 50));


		m_bilješka = new wxTextCtrl(this, wxID_ANY, "Unesi bilješku", wxPoint(50, 700), wxSize(375, 50));
		m_bilješkabtn = new wxButton(this, 10001, "Submit", wxPoint(485, 700), wxSize(150, 50));

	}

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
	m_grid->SetColLabelValue(2, "Težina ispita u odnosu na ispredavano");
	m_grid->SetRowLabelValue(2, "3. razredi");
	m_grid->SetRowLabelValue(3, "4. razredi");



	extern wxString ucitelj;

	//m_textime = new wxStaticText(this, wxID_ANY, ucitelj, wxPoint(200, 180), wxSize(150,50));



	wxImage::AddHandler(handler2);
	wxStaticBitmap* image;

	image = new wxStaticBitmap(this, wxID_ANY, wxBitmap((ucitelj + ".png"), wxBITMAP_TYPE_PNG), wxPoint(50, 50), wxSize(129, 150));



	//Bilješke strpa u grid

	m_gridbilješke = new wxGrid(this, 10003, wxPoint(700, 250), wxSize(1153, 650));

	m_gridbilješke->DisableDragGridSize();

	m_gridbilješke->HideRowLabels();
	m_gridbilješke->CreateGrid(0, 2);
	m_gridbilješke->SetColSize(0, 125);
	m_gridbilješke->SetColSize(1, 1025);
	m_gridbilješke->SetDefaultRowSize(30);

	m_gridbilješke->SetRowLabelSize(1);

	m_gridbilješke->SetColLabelValue(0, "Datum");
	m_gridbilješke->SetColLabelValue(1, "Bilješka");


	string RedTeksta;
	ifstream Bilješke("Bilješke.txt");



	int red = 0;



	extern bool jeAdmin;

	//Ovvaj bool ode na true kad doðe do imena profesora
	bool prvi = false;
	//Unos svih bilješki za traženog profesora
	wxFont font1 = wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	while (getline(Bilješke, RedTeksta)) {
		//Ako je prof skipaj umetanje
		if (RedTeksta == ucitelj) {
			prvi = true;
			continue;
		}
		string RedTeksta2;
		if (RedTeksta == "End" && prvi) {
			break;
		}

		//Ako odobren i nije prof 
		if (prvi && ((RedTeksta.substr(0, RedTeksta.find(";")) == "Odobren") || jeAdmin == true)) {
			//Ako je "End," ubi
			RedTeksta2 = RedTeksta.substr(RedTeksta.find(";") + 1, RedTeksta.length() - 1);
			m_gridbilješke->InsertRows(red, 1);
			string Datum = RedTeksta2.substr(0, RedTeksta2.find(","));
			string Bilješka = RedTeksta2.substr(RedTeksta2.find(",") + 1, RedTeksta2.length() - 1);

			BilješkeVec.push_back(RedTeksta);

			m_gridbilješke->SetCellValue(red, 0, Datum);
			m_gridbilješke->SetCellValue(red, 1, RazbiNaRedove(Bilješka));

			m_gridbilješke->SetReadOnly(red, 0);
			m_gridbilješke->SetReadOnly(red, 1);

			m_gridbilješke->SetCellAlignment(red, 0, wxALIGN_CENTER, wxALIGN_CENTER);
			m_gridbilješke->SetCellAlignment(red, 1, wxALIGN_LEFT, wxALIGN_CENTER);

			m_gridbilješke->SetRowSize(red, (Bilješka.length() / 155) * 16 + 30);

			m_gridbilješke->SetCellFont(red, 0, font1);
			m_gridbilješke->SetCellFont(red, 1, font1);

			red++;
		}

	}

	if (jeAdmin) {
		//Elementi za brisat bilješke
		m_bilješkaOdobri = new wxButton(this, 10004, "Odobri Bilješku", wxPoint(1300, 125), wxSize(150, 50));
		m_bilješkaObriši = new wxButton(this, 10005, "Obriši Bilješku", wxPoint(1500, 125), wxSize(150, 50));

		m_bilješkaOdluka = new wxListBox(this, wxID_ANY, wxPoint(825, 50), wxSize(1025, 50));

		if (BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";")) == "NeOdobren") {
			m_bilješkaOdluka->AppendString(BilješkeVec[brojBilješke].substr(0, BilješkeVec[brojBilješke].find(";")+1) + BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1));

		}
		else {
			m_bilješkaOdluka->AppendString(BilješkeVec[brojBilješke].substr(BilješkeVec[brojBilješke].find(",") + 1, BilješkeVec[brojBilješke].length() - 1));

		}

		m_nextbtn = new wxButton(this, 10006, "Sljedeæa bilješka", wxPoint(1700, 125), wxSize(150, 50));
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

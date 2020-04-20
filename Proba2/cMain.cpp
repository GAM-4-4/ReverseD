#include "cMain.h"
#include "cDnevnik.h"
using namespace std;

//Deklarira za koje eventove program sluša i aktivira nešto

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, LogIn)
wxEND_EVENT_TABLE()

//Funkcija za zapisivanje char arraya

void WriteTo(const char uneseno[10]) {
	FILE* korisnici = fopen("Text.txt", "a");
	fputs(uneseno, korisnici);
	fputs("\n", korisnici);
	fclose(korisnici);
}


//Definiranje cMain prozora i njegovih komponenti

int wMain = 600;
int hMain = 600;


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Isusarija", wxPoint(710, 150), wxSize(wMain, hMain)) {
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(wMain / 2 - 300 / 2, 20), wxSize(300, 30));
	m_txt2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(wMain / 2 - 300 / 2, 60), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(wMain / 2 - 300 / 2, 350), wxSize(300, 100));
	m_btn1 = new wxButton(this, 10001, "Log in", wxPoint(225, 500), wxSize(150, 50));


}
cMain::~cMain() {

}

//Funkcija koju se može pozvati (ovdje ju gore gornja naredba za slušanje pritisaka gumba)

void cMain::LogIn(wxCommandEvent& evt) {
	m_list1->AppendString(m_txt1->GetValue());
	m_list1->AppendString(m_txt2->GetValue());
	string s = m_txt1->GetValue().ToStdString();
	const char* uneseno = s.c_str();
	WriteTo(uneseno);
	m_frame2 = new cDnevnik();
	m_frame2->Show();
	evt.Skip();
}
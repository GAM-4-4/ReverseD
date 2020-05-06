#include <wx/wx.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>

#include "ReverseD.xpm"

using namespace std;
//Funkcija za zapisivanje char arraya

void WriteTo(const char uneseno[10]) {
    FILE* korisnici = fopen("Text.txt", "a");
    fputs(uneseno, korisnici);
    fputs("\n", korisnici);
    fclose(korisnici);
}

wxArrayString SplitString3(string Red) {
    wxArrayString rastavljen;
    while (Red.find(",") != std::string::npos) {
        rastavljen.Add(Red.substr(0, Red.find(",")));
        Red = Red.substr(Red.find(",") + 2);
    }
    return rastavljen;

}


#include "FormLogin.h"
FormLogin::FormLogin(const wxString& title)
    : wxFrame((wxFrame*)NULL, wxID_ANY, title, wxPoint(wxID_ANY, wxID_ANY), wxSize(340, 150),
        wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{

    SetIcon(wxICON(sample));


    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    m_usernameLabel = new wxStaticText(panel, wxID_ANY, wxT("Korisnicko ime: "), wxDefaultPosition, wxSize(70, -1));
    hbox1->Add(m_usernameLabel, 0);

    m_usernameEntry = new wxTextCtrl(panel, wxID_ANY);
    hbox1->Add(m_usernameEntry, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    m_passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Lozinka: "), wxDefaultPosition, wxSize(70, -1));
    hbox2->Add(m_passwordLabel, 0);

    m_passwordEntry = new wxTextCtrl(panel, wxID_ANY, wxString(""),
        wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    hbox2->Add(m_passwordEntry, 1);
    vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    m_buttonLogin = new wxButton(panel, BUTTON_Login, wxT("Login"));
    hbox3->Add(m_buttonLogin);

    m_buttonQuit = new wxButton(panel, wxID_EXIT, ("Zatvori"));
    hbox3->Add(m_buttonQuit);
    vbox->Add(hbox3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);
    Centre();
}
bool jeAdmin = false;
string razred;
void FormLogin::OnLogin(wxCommandEvent& event)
{
    wxString username = m_usernameEntry->GetValue();
    wxString password = m_passwordEntry->GetValue();



    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Korisnicko ime ili Lozinka ne smije ostati neispunjeno"), wxT("Upozorenje!"), wxICON_WARNING);
    }
    else {
        vector <string> redovi;
        string podatci1;
        ifstream Korisnici("Korisnici.txt");



        //Stavi sve redove u vektor
        while (getline(Korisnici, podatci1)) {
            if (SplitString3(podatci1)[0] == username && SplitString3(podatci1)[1] == password) {
                m_frame3 = new cDnevnik();
                m_frame3->Show();
                razred = SplitString3(podatci1)[2];
                if (SplitString3(podatci1)[3] == "Admin") {
                    jeAdmin = true;
                }
            }
        }

    }
    Close();
}

void FormLogin::OnQuit(wxCommandEvent& event) {
    Close();
}

FormLogin::~FormLogin() {}

BEGIN_EVENT_TABLE(FormLogin, wxFrame)
EVT_BUTTON(BUTTON_Login, FormLogin::OnLogin)
EVT_BUTTON(wxID_EXIT, FormLogin::OnQuit)
END_EVENT_TABLE()
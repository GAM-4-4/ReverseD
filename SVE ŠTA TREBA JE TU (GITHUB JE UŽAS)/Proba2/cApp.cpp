#include "cAPP.h"
#include <stdio.h>

//Radi i "klasu" koja sadr�i cijei program

wxIMPLEMENT_APP(cApp);



void Veli�inaEkrana(int& wEkran, int& hEkran)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	wEkran = desktop.right;
	hEkran = desktop.bottom;
}

int wEkran;
int hEkran;




cApp::cApp() {

}

cApp::~cApp() {

}

//Funkcija koja stvara prvi prozor pri paljenju programa (OnInit = On initalisation)

bool cApp::OnInit() {
	m_frame1 = new FormLogin(wxT("Log In"));
	m_frame1->Show();
	return true;
}

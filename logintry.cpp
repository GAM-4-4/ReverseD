#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;
    cout<< "Enter username:"; cin >> username;
    cout <<"Enter password:"; cin >> password;

    ifstream read("data\\" + username + ".txt"); //cita file , ako ne radi onda (username + ".txt")
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


//sti+o ce izbaciti prvo kad se otvori program
int main()
{
    int choice;

    cout <<"1: Register \n 2: Login \n choice (1 or 2):"; cin >> choice;
    if (choice == 1) // zelimo se registrirat
    {
        string username, password, razred;

        cout << "choose username:"; cin >> username;
        cout << "choose password:"; cin >> password;
        cout << "choose class:"; cin >> razred;

        ofstream file;//radi file
        file.open("data\\" + username + ".txt");
        file << username << endl << password << endl << razred;
        file.close();

        main (); // nakon sto smo se registrirali vraca na na main
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();
        if (!status) // ako nismo ulogirani
        {
            cout << "false login" << endl;
            system ("PAUSE");
            return 0;
        }
        else
        {
            cout << "succesfully logged in" << endl;
            system("PAUSE");
            return 1;
        }
        

    }

}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, oassword, un, pw;
    cout<< "Enter username:"; cin >> username;
    cout <<"Enter password:"; cin >> password;

    ifstream read("data\\" + username + ".txt"); //cita file
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return True;
    }
    else
    {
        return False;
    }
    
}


//sti+o ce izbaciti prvo kad se otvori program
int main()
{
    int choice;

    cout <<"1: Register \n 2: Login \n choice (1 or 2):"; cin >> chioce;
    if (choice == 1) // zelimo se registrirat
    {
        string username, password;

        cout << "choose username:"; cin >> username;
        cout << "choose password:"; cin >> password;

        ofstream file;//radi file
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main (); // nakon sto smo se registrirali vraca na na main
    }
    else if (choice == 2)
    {
        bool status == IsLoggedIn();
        is (!status) // ako nismo ulogirani
        {
            cout << "false login" << endl;
            system ("pause");
            return 0;
        }
        else
        {
            cout << "succesfully logged in" << endl;
            system("paise");
            return 1;
        }
        

    }

}
#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>

using namespace std;

struct Account {
    string name, password;
};

string MyHash(string password)
{   
    int totalAscii = 0;
    for (int i = 0; i < password.length(); i++)
    {
        char temp = password[i];
        int ascii = static_cast<int>(temp);
        totalAscii += ascii;
    }
   
    string binary = bitset<16>(totalAscii).to_string();
    return binary;
}

int main()
{   
    unordered_map<string, Account> accounts(256);
    string username, password;
   
    for (int i = 1; i < 3; i++)
    {
        cout << "Enter Username: "; cin >> username; cout << "Enter Password: "; cin >> password;
        string hashed = MyHash(password);
        Account acc;
        acc.name = username;
        acc.password = password;
        accounts[hashed] = acc;
        cout << "Account added" << endl << "------------------------------------" << endl;
    }

    for (const auto& pair : accounts)
    {
        cout << "All Account details" << endl;
        cout << "Key: " << pair.first << endl << "Username: " << pair.second.name << endl 
        << "Password: " << pair.second.password << endl << "------------------------------------" << endl;
    }

    while(true)
    {
        string access;
        cout << "Enter Access Key: "; cin >> access;
        if (accounts.find(access) != accounts.end())
        {   
            cout << "------------------------------------" << endl << "Account Details: " << endl;
            cout << "Username: " << accounts[access].name << endl;
            cout << "Password: " << accounts[access].password << endl;
            break;
        }
        else
        {
            cout << "You have the wrong key, Coba lagi tahun depan";
        }
    }   
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string hypeline(20, '-');

struct Character {
    string name;
    int health_point;
    int mana;
    int attack_damage;
};

void initchars(vector<Character>& c)
{
    Character newCharacter;
    newCharacter.name = "Luna";
    newCharacter.health_point = 100;
    newCharacter.attack_damage = 27;
    newCharacter.mana = 40;
    c.push_back(newCharacter);

    Character newCharacter2;
    newCharacter2.name = "Spectre";
    newCharacter2.health_point = 130;
    newCharacter2.attack_damage = 23;
    newCharacter2.mana = 35;
    c.push_back(newCharacter2);

    Character newCharacter3;
    newCharacter3.name = "Snapfire";
    newCharacter3.health_point = 120;
    newCharacter3.attack_damage = 25;
    newCharacter3.mana = 45;
    c.push_back(newCharacter3);
}

void add(vector<Character> &c)
{
        Character newCharacter;
        cout << "Enter " << c.size()+1 << " Character" << endl;
        cout << "Enter Name : "; cin >> newCharacter.name;
        cout << "Health : "; cin >> newCharacter.health_point;
        cout << "Mana : "; cin >> newCharacter.mana;
        cout << "AttackDamage : "; cin >> newCharacter.attack_damage;
        c.push_back(newCharacter);
        cout << endl;
}

void modify(vector<Character> &c, string name)
{   
    for (int i = 0; i < 10; i++)
    {
        if(c[i].name == name)
        {
            cout << "Change name to : "; cin >> c[i].name; 
            cout << "Change HP to : "; cin >> c[i].health_point;
            cout << "Change Mana to : "; cin >> c[i].mana;
            cout << "Change Attack to : "; cin >> c[i].attack_damage;
            cout << "Data has been successfully changed!" << endl;
        }
    }
    cout << hypeline << endl;
}

void search(vector<Character> &c, string name)
{
    cout << "Searching " << name << "..." << endl;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].name == name)
            {
                cout << name << " is at data number " << i + 1 << " of the array" << endl;
                cout << "The attributes are\nName : " << c[i].name << endl << "HP : " << c[i].health_point << endl << "Mana : " << c[i].mana << endl
                << "Attack : " << c[i].attack_damage << endl;
                return;
            }
    }

    cout << name << " not found!" << endl<< hypeline << endl;   
}

void printAll(vector<Character> &c)
{
    cout << "Printing all of the Characters..." << endl;
    for (const Character &c : c)
    {
        cout << "Character Name : " << c.name << endl;
        cout << "Health : " << c.health_point << endl;
        cout << "Mana : " << c.mana << endl;
        cout << "Attack :" << c.attack_damage << endl;
        cout << hypeline<< endl;
    }
}

void deleteElement(vector<Character> &c, string name)
{
    int index = -1;
    cout << "Deleting character..." << endl;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].name == name)
        {
            index = i;
            break;
        }
         
    }

    if (index != -1)
    {
        vector<Character>::iterator it = c.begin() + index;
        c.erase(it);
        cout << name << " has been successfully removed" << endl;
    }
    else
    {
        cout << "Element not found!" << (20, '-') << endl; 
        return;
    }
    
    cout << hypeline << endl;
}

int main()
{   
    vector<Character> character;

    initchars(character);
    

    int prompt; cout << "How much command do you want to do? "; cin >> prompt;

    for (int i = 0; i < prompt; i++)
    {
        //Select Function
        string select; cout << endl << "Select Function (" << i+1 << "/" << prompt << ")(add/remove/modify/search/print) : "; cin >> select;
        
        if (select == "modify")
        {
            //modify
            string name;  cout << "Modify data (by name) : "; cin >> name;
            modify(character, name);
        }

        else if (select == "search")
        {
            string name; cout << "Which data you want to search (by name) : "; cin >> name;
            search(character,name);
        }

        else if (select == "add")
        {   
            add(character);
        }

        else if(select == "print")
        {
            printAll(character);
        }

        else if(select == "remove")
        {   
            string name; cout << "Which data you want to remove (by name) : "; cin >> name;
            deleteElement(character, name);
        }
    }
    return 0;
}
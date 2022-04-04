// first_test_c++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

void Damage(int health) {
    health -= 2;
}

void DamageReference(int& health) {
    health -= 2;
}

void DamagePointedObject(int* health) {
    *health -= 3;
}

void ShowMultiDimensionalMap()
{
    int tileMap[5][8]{ {4, 0, 0, 1, 1, 0, 3, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 2, 1, 0, 1, 1, 1, 1},
                        {3, 1, 1, 1, 1, 2, 1, 0},
                        {0, 3, 0, 1, 1, 1, 2, 0} };

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 8; y++) {
            int tile = tileMap[x][y];
            switch (tile)
            {
            case 0:
                cout << " X ";
                break;
            case 1:
                cout << " ~ ";
                break;
            case 2:
                cout << " O ";
                break;
            case 3:
                cout << " V ";
                break;
            default:
                cout << " ^ ";
                break;
            }
        }
        cout << endl;
    }

}

void ShowVector()
{
    vector<float> grades(20, 10);
    grades[5] = 12;
    grades[18] = 7;
    for (int i = 0; i < grades.size(); i++)
    {
        cout << grades[i] << " ; ";
    }
    cout << endl;
    grades.push_back(15);
    grades.push_back(12);
    grades.push_back(17);
    grades.pop_back();
    for (int i = 0; i < grades.size(); i++)
    {
        cout << grades[i] << " ; ";
    }
}

string GetLifeText(int life)
{
    return life > 5 ? "alive" : "dying";
}


int main()
{
    cout << "Hello World!\n";
    int life = 10;
    cout << "The value " << life << " is stored at memory adress : " << &life << endl;
    Damage(life);
    cout << life << endl;
    DamageReference(life);
    cout << life << endl;
    DamagePointedObject(&life);
    cout << life << endl;
    //if life > 5 show "Alive" else show "Dying"
    cout << "Player is " << GetLifeText(life) << endl;

    ShowMultiDimensionalMap();
    //ShowVector();
    cout << "============PIKACHU=============\n";
    Pokemon pikachu = Pokemon("Pikachu", "a yellow electric mouse", 20);
    pikachu.DisplaySumUp();
    cout << "=========================\n";
    pikachu.mPetName = "Pika Pika";
    pikachu.Hurt(6);
    pikachu.Heal(12);
    pikachu.DisplaySumUp();
}

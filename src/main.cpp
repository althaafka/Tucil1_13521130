#include "input_output.cpp"
#include "makeIt24.cpp"
#include <iostream>
using namespace std;

void displayHomePage(){
    cout << "                                                    .------.        \n" <<
            " ___  ___      _          _____ _     _____   ___   |A_  _ |        \n" <<
            " |  \\/  |     | |        |_   _| |   / __  \\ /   |  |( \\/ ).-----.  \n" <<
            " | .  . | __ _| | _____    | | | |_  `' / /'/ /| |  | \\  /|K /\\  |  \n" <<
            " | |\\/| |/ _` | |/ / _ \\   | | | __|   / / / /_| |  |  \\/ | /  \\ |  \n" <<
            " | |  | | (_| |   <  __/  _| |_| |_  ./ /__\\___  |  `-----| \\  / |  \n" <<
            " \\_|  |_/\\__,_|_|\\_\\___|  \\___/ \\__| \\_____/   |_/        |  \\/ K|  \n" <<
            "                                                          `------'  \n" <<
            "\nSelamat datang di Make It 24!\n\n";
}

void inputMenu(int *start, vector<string> *const &result){
    vector<int> card;
    cout << "\nPilih metode input:\n" <<
            "   1. Input manual\n" <<
            "   2. Input random\n" <<
            "   3. Keluar\n";
    int opt=0;
    cout << ">> ";
    cin >> opt;
    while (opt<1 || opt>3){
        cout << "\nInput salah, masukkan 1/2/3\n";
        cin >> opt;
    }
    string str;
    switch (opt){
    case 1:
        cout << "\nMasukkan 4 kartu (2-10, A, J, Q, K)\n" <<
                ">> ";
        getline(cin,str);
        *result = makeIt24(userInput());
        displayResult(*result);
        break;
    case 2:
        *result = makeIt24(randomInput());
        displayResult(*result);
        break;
    case 3:
        start=0;
    default:
        break;
    }
}

int main(){
    int start =1;
    vector<string> result;
    displayHomePage();
    while (start){
        inputMenu(&start, &result);
    }
    return 0;
}
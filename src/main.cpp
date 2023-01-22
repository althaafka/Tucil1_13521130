#include "input_output.cpp"
#include "makeIt24.cpp"
#include <iostream>
using namespace std;

void displayHomePage(){
    // menampilkan home page
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

void outputMenu(bool *const &start, vector<string> *const &result){
    // menampilkan menu save hasil
    cout << "\nIngin menyimpan hasil?\n" <<
            "   1. Ya\n" <<
            "   2. Tidak\n" <<
            ">> ";
    string str ;
    getline(cin,str);
    while (!isInputValid(2,str)){
        cout << "\nInput salah, masukkan angka 1/2\n";
            cout << "\nIngin menyimpan hasil?\n" <<
            "   1. Ya\n" <<
            "   2. Tidak\n" <<
            ">> ";
        getline(cin,str,'\n');
    }
    int opt = stoi(str);
    switch (opt){
        case 1:
            outputFile(*result);
            break;
        case 2:
            break;
        default:
            break;
    }
}

void inputMenu(bool *const &start, vector<string> *const &result){
    // menampilkan menu input
    cout << "\nPilih metode input:\n" <<
            "   1. Input manual\n" <<
            "   2. Input random\n" <<
            "   3. Keluar\n" <<
            ">> ";
    string str;
    getline(cin,str);
    while (!isInputValid(3,str)){
        cout << "\nInput salah, masukkan angksa 1/2/3\n";
        cout << "\nPilih metode input:\n" <<
            "   1. Input manual\n" <<
            "   2. Input random\n" <<
            "   3. Keluar\n" <<
            ">> ";
        getline(cin,str);
    }
    int opt = stoi(str);
    switch (opt){
    case 1: //input user
        cout << "\nMasukkan 4 kartu (2-10, A, J, Q, K)\n" <<
                ">> ";
        *result = makeIt24(userInput());
        displayResult(*result);
        outputMenu(start,result);
        break;
    case 2: //input random
        *result = makeIt24(randomInput());
        displayResult(*result);
        outputMenu(start,result);
        break;
    case 3: //keluar dari program
        cout << "\nProgram selesai\n";
        *start = false;
        break;
    default:
        break;
    }
}

int main(){
    bool start = true;
    srand(time(0));
    vector<string> result;
    displayHomePage();
    while (start){
        inputMenu(&start, &result);
    }
    return 0;
}
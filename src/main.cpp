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

void outputMenu(vector<string> *const &result){
    cout << "\nIngin menyimpan hasil?\n" <<
            "   1. Ya\n" <<
            "   2. Tidak\n" <<
            ">> ";
    string str;
    getline(cin,str);
    while (!isInputValid(2,str)){
        cout << "\nInput salah, masukkan angka 1/2\n";
        outputMenu(result);
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
    cout << "\nPilih metode input:\n" <<
            "   1. Input manual\n" <<
            "   2. Input random\n" <<
            "   3. Keluar\n" <<
            ">> ";
    string str;
    getline(cin,str);
    while (!isInputValid(3,str)){
        cout << "\nInput salah, masukkan angksa 1/2/3\n";
        inputMenu(start,result);
    }
    int opt = stoi(str);
    switch (opt){
    case 1:
        cout << "\nMasukkan 4 kartu (2-10, A, J, Q, K)\n" <<
                ">> ";
        *result = makeIt24(userInput());
        displayResult(*result);
        outputMenu(result);
        break;
    case 2:
        *result = makeIt24(randomInput());
        displayResult(*result);
        outputMenu(result);
        break;
    case 3:
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
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int isCardValid(vector<string> card){
    if (card.size()!=4){
        return 0;
    } else {
        string validInput[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        int isValid;
        for (int i=0; i<card.size();i++){
            isValid = 0;
            for (int j=0; j<13; j++){
                if (card[i]==validInput[j]){
                    isValid = 1;
                }
            }
            if (!isValid){
                return 0;
            }
        }
        return 1;
    }
}

vector<int> strCardToNum(vector<string> strCard){
    vector<int> card;
    string x;
    for (int i=0; i<4; i++){
        if (strCard[i]=="J") card.push_back(11);
        else if (strCard[i]=="Q") card.push_back(12);
        else if (strCard[i]=="K") card.push_back(13);
        else if (strCard[i]=="A") card.push_back(1);
        else card.push_back(stoi(strCard[i]));
    }
    return card;
}

bool isInputValid(int nOption, string input){
    for (int i=1; i<=nOption; i++){
        if (to_string(i) == input){
            return true;
        }
    }
    return false;
}

vector<int> userInput(){
    string str;
    vector<string> strCard;
    string x;
    getline(cin,str);
    istringstream iss(str);
    while(iss >> x){
        strCard.push_back(x);
    }
    while(!isCardValid(strCard)){
        strCard.clear();
        cout << "\nMaaf Kartu tidak valid\n>> ";
        getline(cin,str);
        istringstream iss(str);
        while(iss >> x){
            strCard.push_back(x);
        }
    }
    vector<int> card = strCardToNum(strCard);
    return card;
}

vector<int> randomInput(){
    int i,num;
    vector<int> card;
    for(int i=0; i<4; i++){
        card.push_back((rand())%13+1);
    }
    cout << "\nKartu Anda adalah ";
    string strCard[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0; i<4; i++){
        cout << strCard[card[i]-1] << " ";
    }
    cout << endl << endl;
    return card;
}

// void saveResult(vector<string> result){
//     fstream file;
//     file.open("")
// }
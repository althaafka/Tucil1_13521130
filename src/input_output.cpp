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

vector<float> strCardToNum(vector<string> strCard){
    vector<float> card;
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

vector<float> userInput(){
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
    vector<float> card = strCardToNum(strCard);
    return card;
}

vector<float> randomInput(){
    int i,num;
    vector<float> card;
    for(int i=0; i<4; i++){
        card.push_back((rand())%13+1);
    }
    cout << "\nKartu Anda adalah ";
    string strCard[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0; i<4; i++){
        cout << strCard[(int)card[i]-1] << " ";
    }
    cout << endl << endl;
    return card;
}

void saveResult(string fileName, vector<string> result){
    fstream file;
    file.open("../test/"+fileName,ios_base::out);
    for(int i=0;i<result.size();i++){
        file<<result[i]<<endl;
    }
    file.close();
}

void outputFile(vector<string> result){
    string fileName;
    cout << "Masukkan nama file\n" <<
            ">> ";
    getline(cin,fileName);
    saveResult(fileName, result);
    cout << "\nHasil berhasil disimpan\n";
}
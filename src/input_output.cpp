#include <iostream>
#include <vector>
#include <sstream> // untuk memisah spasi pada string
#include <ctime>    
#include <cstdlib> // untuk randomize
#include <fstream> // untuk save file

using namespace std;

bool isCardValid(vector<string> card){
    // Mengembailkan true apabila kartu valid
    // kartu dinyatakan valid apabila terdapat 4 kartu dan 
    // hanya terdiri dari angka 2-10, A, J, Q, atau K
    if (card.size()!=4){
        return false;
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
                return false;
            }
        }
        return true;
    }
}

vector<float> strCardToNum(vector<string> strCard){
    // mengubah kartu berbentuk vektor string menjadi vector float
    // A menjadi 1, J menjadi 11, Q menjadi 12, K menjadi 13
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
    // mengemballikan true apabila input merupakan angka dengan range 1-nOption
    for (int i=1; i<=nOption; i++){
        if (to_string(i) == input){
            return true;
        }
    }
    return false;
}

vector<float> userInput(){
    // mengembalikan 4 kartu inputan user yang berupa vector of float 
    // kartu telah valid
    string str;
    vector<string> strCard;
    string x;
    getline(cin,str);

    istringstream iss(str);
    while(iss >> x){
        strCard.push_back(x);
    }
    //pengecekan ke-valid-an kartu
    while(!isCardValid(strCard)){
        strCard.clear();
        cout << "\nMaaf Kartu tidak valid\n>> " ;
        getline(cin,str);
        istringstream iss(str);
        while(iss >> x){
            strCard.push_back(x);
        }
    }
    // mengubah kartu yang berupa string menjadi float
    vector<float> card = strCardToNum(strCard);
    return card;
}

vector<float> randomInput(){
    // mengenerate kartu secara random
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
    cout << endl;
    return card;
}

void saveResult(string fileName, vector<string> result){
    // menyimpan hasil pada file
    fstream file;
    file.open("../test/"+fileName,ios_base::out);
    for(int i=0;i<result.size()-1;i++){
        file<<result[i]<<endl;
    }
    file.close();
}

void outputFile(vector<string> result){
    // menyimpan hasil dengan nama file inputan user
    string fileName;
    cout << "\nMasukkan nama file\n" <<
            ">> ";
    getline(cin,fileName);
    saveResult(fileName, result);
    cout << "\nHasil berhasil disimpan\n";
}
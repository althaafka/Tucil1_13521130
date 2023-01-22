#include <iostream>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

void displayResult(vector<string> result){
    // menampilkan hasil dari perhitungan serta execution time
    int n = result.size()-1;
    if (n==0){
        cout << "\nTidak ditemukan solusi\n";
    } else{
        cout << "\nDitemukan " << n << " solusi\n";
        for(int i=0; i< n; i++){
            cout << "   "<< result[i] << endl;
        }
    }
    cout << "Execution time: " << result[n] << " microseconds\n";
}

float mathOp(float num1, char op, float num2){
    // mengembalikan hasil perhitungan antara operasi antara 2 bilangan
    float res;
    switch (op){
        case '+':
            res = num1+num2;
            break;
        case '-':
            res = num1-num2;
            break;
        case '*':
            res = num1*num2;
            break;
        case '/':
            if (num2==0){
                res =0;
            } else {
                res = num1/num2;
            }
            break;
        default:
            break;
    }
    return res;
}

string makeString(int variant, float num1, float num2, float num3, float num4, char op1, char op2, char op3){
    // membentuk string untuk operasi matematika
    string str,a,b,c,d;
    a=to_string((int)num1);
    b=to_string((int)num2);
    c=to_string((int)num3);
    d=to_string((int)num4);
    switch (variant){
        case 1: // ((a+b)+c)+d
            str = "(("+a+op1+b+")"+op2+c+")"+op3+d;
            break;
        case 2: // (a+b)+(c+d)
            str = "("+a+op1+b+")"+op2+"("+c+op3+d+")";
            break;
        case 3: // (a+(b+c))+d
            str = "("+a+op1+"("+b+op2+c+"))"+op3+d;
            break;
        case 4: // a+((b+c)+d)
            str = a+op1+"(("+b+op2+c+")"+op3+d+")";
            break;
        case 5: // a+(b+(c+d))
            str = a+op1+"("+b+op2+"("+c+op3+d+"))";
            break;
        default:
            break;
    }
    return str;
}

float calculate(int variant, float num1, float num2, float num3, float num4, char op1, char op2, char op3){
    // mengembalikan hasil operasi matematika berdasarkan variant tanda kurung,
    // 4 angka dan 3 operator
    float result;
    string strRes;
    switch (variant){
        case 1: // ((a+b)+c)+d
            result = mathOp(mathOp(mathOp(num1,op1,num2),op2,num3),op3,num4);
            break;
        case 2: // (a+b)+(c+d)
            result = mathOp(mathOp(num1,op1,num2),op2,mathOp(num3,op3,num4));
            break;
        case 3: // (a+(b+c))+d
            result = mathOp(mathOp(num1,op1,mathOp(num2,op2,num3)),op3,num4);
            break;
        case 4: // a+((b+c)+d)
            result = mathOp(num1,op1,mathOp(mathOp(num2,op2,num3),op3,num4));
            break;
        case 5: // a+(b+(c+d))
            result = mathOp(num1,op1,mathOp(num2,op2,mathOp(num3,op3,num4)));
            break;
        default:
            break;
    }
    return result;
}

bool isMember(vector<string> vec, string str){
    // mengecek apakah suatu string telah terdapat pada vector of string
    for (int i=0; i<vec.size();i++){
        if (str == vec[i]){
            return true;
        }
    }
    return false;
}

vector<string> makeIt24(vector<float> card){
    // Algoritma brute force, mengecek semua kemungkinan kejadian yang ada,
    // apabila suatu operasi matematika menghasilkan 24 akan dimasukkan dalam vector hasil
    char op[4] = {'+','-','*','/'};
    vector<string> result;
    string str;
    float is24;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    // variasi urutan angka
    for (int a=0;a<4;a++){
        for (int b=0;b<4;b++){
            if (a!=b){
                for (int c=0;c<4;c++){
                    if (c!=a && c!=b){
                        for (int d=0;d<4;d++){
                            if (d!=a && d!=b && d!=c){
                                // variasi operator
                                for(int op1=0;op1<4;op1++){
                                    for(int op2=0;op2<4;op2++){
                                        for(int op3=0;op3<4;op3++){
                                            // variasi tanda kurung
                                            for(int var=1;var<=5;var++){
                                                is24 = calculate(var,card[a],card[b],card[c],card[d],op[op1],op[op2],op[op3])-24;
                                                if (is24>-0.000000000001 && is24<0.000000000001){
                                                    str = makeString(var,card[a],card[b],card[c],card[d],op[op1],op[op2],op[op3]);
                                                    if (!isMember(result,str)){
                                                        result.push_back(str);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    result.push_back(to_string(chrono::duration_cast<chrono::microseconds>(end - begin).count()));
    return result;
}
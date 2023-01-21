#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void displayResult(vector<string> vec){
    for(int i=0; i< vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

float mathOp(float num1, char op, float num2){
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
    string str,a,b,c,d;
    a=to_string((int)num1);
    b=to_string((int)num2);
    c=to_string((int)num3);
    d=to_string((int)num4);
    switch (variant){
        case 1:
            str = "(("+a+op1+b+")"+op2+c+")"+op3+d;
            break;
        case 2:
            str = "("+a+op1+b+")"+op2+"("+c+op3+d+")";
            break;
        case 3:
            str = "("+a+op1+"("+b+op2+c+"))"+op3+d;
            break;
        case 4:
            str = a+op1+"(("+b+op2+c+")"+op3+d+")";
            break;
        case 5:
            str = a+op1+"("+b+op2+"("+c+op3+d+"))";
            break;
        default:
            break;
    }
    return str;
}

float calculate(int variant, float num1, float num2, float num3, float num4, char op1, char op2, char op3){
    float result;
    string strRes;
    switch (variant){
        case 1:
            result = mathOp(mathOp(mathOp(num1,op1,num2),op2,num3),op3,num4);
            break;
        case 2:
            result = mathOp(mathOp(num1,op1,num2),op2,mathOp(num3,op3,num4));
            break;
        case 3:
            result = mathOp(mathOp(num1,op1,mathOp(num2,op2,num3)),op3,num4);
            break;
        case 4:
            result = mathOp(num1,op1,mathOp(mathOp(num2,op2,num3),op3,num4));
            break;
        case 5:
            result = mathOp(num1,op1,mathOp(num2,op2,mathOp(num3,op3,num4)));
            break;
        default:
            break;
    }
    return result;
}

bool isMember(vector<string> vec, string str){
    for (int i=0; i<vec.size();i++){
        if (str == vec[i]){
            return true;
        }
    }
    return false;
}

vector<string> makeIt24(vector<float> card){
    char op[4] = {'+','-','*','/'};
    vector<string> result;
    string str;
    float is24;
    for (int a=0;a<4;a++){
        for (int b=0;b<4;b++){
            if (a!=b){
                for (int c=0;c<4;c++){
                    if (c!=a && c!=b){
                        for (int d=0;d<4;d++){
                            if (d!=a && d!=b && d!=c){
                                for(int op1=0;op1<4;op1++){
                                    for(int op2=0;op2<4;op2++){
                                        for(int op3=0;op3<4;op3++){
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
    return result;
}
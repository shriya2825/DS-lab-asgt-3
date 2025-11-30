#include<iostream>
#include<stack>
#include<cctype> // for isdigit
#include<cmath>
#include<string>
using namespace std;


int evaluatepostfix(string postfix){
    stack<int>s;

    for(char ch:postfix){
        //1.push operands onto stack
        if(isdigit(ch)) {
            s.push(ch-'0');//converts ch into int 
        } 
        else{
        //2.if operator->pop out top two elements
        int val2=s.top(); s.pop();
        int val1=s.top(); s.pop();

        switch(ch){
            case '+':s.push(val1+val2);break;
            case '-':s.push(val1-val2);break;
            case '*':s.push(val1*val2);break;
            case '/':s.push(val1/val2);break;
            case '^':s.push(pow(val1,val2));break;
            default:cout<<"no such operator is encountered\n";break;
        }
        }
    }
     return s.top();//result
}
int main(){
    string postfix;
    cout<<"enter postfix expression: ";
    getline(cin,postfix);

    cout<<"evaluation of postfix: "<<evaluatepostfix(postfix)<<endl;
    return 0;
}



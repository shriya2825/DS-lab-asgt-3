#include<iostream>
#include<string>
#include<stack>
#include<cctype>  // for isalnum and isdigit
using namespace std;


//function to return precedence of operator
int precedence(char op){
    if (op=='^') return 3;
    if(op=='*'|| op=='/') return 2;
    if(op=='+'||op=='-') return 1;
    return -1;
}

//function to convert infix to postfix 
string infixtopostfix(string infix){
    stack<char>s;
    string postfix="";

    for(char ch:infix){
        //1.operand->directly add to postfix
        if(isalnum(ch)){
            postfix+=ch;
        }

        //2.opening parentheses
        else if(ch=='('){
           s.push(ch);
        }

        //3.closing parentheses
        else if(ch==')'){
            while(!s.empty()&&s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();  //pop '('
        }
        //4.operator
        else{
            while(!s.empty() && precedence(s.top())>=precedence(ch)){
                if(ch=='^'&&s.top()=='^') break;
                postfix+=s.top();
                s.pop();
            }
            s.push(ch);
        }   
    }
    //5- removing remaining operator from the stack
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}


int main(){
    string infix;
    cout<<"enter infix expression: ";
    getline(cin,infix);
    //cin>>infix;

    cout<<"postfix expression: "<<infixtopostfix(infix)<<endl;
    return 0;
}
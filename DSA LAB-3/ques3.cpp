#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isbalanced(string expr){
    stack<char>s;//stack declaration

    for(char ch:expr){
        if(ch=='('||ch=='{'||ch=='['){
            s.push(ch);//pushing open brackets
        }

        else if(ch==')'||ch=='}'||ch==']'){
            if(s.empty()) return false; //stack is empty that is no opening bracket is not present

            char top=s.top();// storing the top element in another variable and then using it in matching condition
            s.pop();

            if((ch==')'&&top!='(')||(ch=='}'&& top!='{')||(ch==']'&&top!='[')){
                return false; //mismatched pair
            }
        }
    }
     return s.empty(); //if all the brackets matched and stack is empty now
}
int main(){

    string str;
    cout<<"enter the expression: ";
    getline(cin,str);

    if(isbalanced(str)){
        cout<<"expression is balanced\n";
    }
    else cout<<"not balanced";
    return 0;
}
#include<iostream>
#include<stack>
#include<string>
using  namespace std;

//using STL stack
int main(){
    string str;
    cout<<"enter  a string: ";
    cin>>str;

    stack<char>s;

    //push character to the stack using loop
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

    //pop all characters to reverse
    cout<<"reversed string: ";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    
    return 0;
}
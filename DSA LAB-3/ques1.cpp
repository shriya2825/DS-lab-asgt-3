#include<iostream>
using namespace std;

#define MAX 50
    int arr[MAX];
    int top=-1;

    void push(int x){
        if(top==MAX-1){
            cout<<"overflow\n";
        }
        else 
        {
            top++;
            arr[top]=x;
            cout<<x<<"is pushed into stack "<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"underflow\n";
        }
        else{
            cout<<arr[top]<<"is popped from stack"<<endl;
            top--;
        }
    }

    void isFull(){
        if(top==MAX-1)
        cout<<"stack is full"<<endl;
        else cout<<"stack is not full"<<endl;
       
    }

    void isEmpty(){
        if(top==-1)
        cout<<"stack is empty"<<endl;
        else cout<<"stack is not empty"<<endl;
        
    }

    void display(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else {
            cout<<"stack elements (top to bottom): ";
            for(int i =top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    void peek(){
         if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else {
            cout<<"top element is: "<<arr[top]<<endl;
        }
    }

int main(){
    int choice,value;
    do{
        cout<<"\n--stack menu program--\n";
        cout<<"1. Push\n2.Pop\n3.isEmpty\n4.isFull\n5.display\n6.peek\n7.exit\n";
        cout<<"enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"enter value: "; cin>>value; push(value); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout<<"exiting .."<<endl; break;
            default: cout<<"invalid choice\n";
        }
    }while(choice!=0);

    return 0;

}
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
bool isParenthesis(char ch){ return (ch == '(' || ch ==')'); }

int precedence(char ch){

    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(isParenthesis(ch))
        return 0;
}



char* infixToPostfix(char  exp[]){
    
    if(exp == NULL)
        return NULL;

    cout<<"ISHAN\n";

    char *arr = (char*)malloc(sizeof(char)*100);

    stack<char> st;
    int i =0;
    int j = 0;


    while(exp[i] != '\0'){



        if(exp[i] >= 'a' && exp[i] <='z'){
            arr[j] = exp[i];
            j++;
        }
        else if(isParenthesis(exp[i])){
            if(exp[i] == '(')
                st.push(exp[i]);
            else{
//    cout<<exp[i]<<'\n';
                while(!st.empty() && st.top() != '('){

                    arr[j] = st.top();
                    st.pop();
                    j++;
                }
                st.pop();
            }
        }
        else{

            if(st.empty() || precedence(exp[i]) >= precedence(st.top()))
                st.push(exp[i]);
            else{
                while(!st.empty() && precedence(st.top()) > precedence(exp[i])){
                    arr[j] = st.top();
                    st.pop();
                    j++;
                }
                st.push(exp[i]);
            }

        }
        i++;
    }

    while(!st.empty()){
        arr[j] = st.top();
        st.pop();
        j++;
    }
    exp[j] = '\0';


    return arr;

}
int main(){
char exp[] = "a+b*(c+d-e)/(f+g*h)-i";

cout<<exp[0]<<"\n";

char* exp1 = infixToPostfix(exp);

int i = 0;
while(exp1[i] != '\0'){
    cout<<exp1[i];
    i++;
}
cout<<"\n";
return 0;

}

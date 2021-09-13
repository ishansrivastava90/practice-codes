/*
 * The program tests the behaviour of const with pointers
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){

    int a = 2;
    int* const a_p = &a;

    cout<<a<<"\n";
    cout<<a_p<<"\n";
    cout<<*a_p<<"\n";

    int b = 3;
    *a_p = 3;
    //a_p = &b;
    
    cout<<a<<"\n";
    cout<<a_p<<"\n";
    cout<<*a_p<<"\n";





}


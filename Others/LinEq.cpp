#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

bool isOperator(char op){
	if (op == '+' || op =='*' || op =='-')
		return true;
	return false;
}

int prec(char op){
	if(op == '+')
		return 1;
	if(op == '-')
		return 2;
	if (op == '*')
		return 3;

	return -1;
}

int expValue(int a, int b , char op){

	if (op == '-')
		return a - b;
	if( op == '+')
		return a + b;
	if( op == '*')
		return a * b;
}

double solveForX(char exp[]){

	char prev_sym = 'z';
	int x_coeff = 0;
	int x_const = 0;

	stack<int> operands;
	stack<char> operators;

	for(int i = 0; exp[i] != '\0'; i++){
		if(exp[i] == 'x'){
			if(prev_sym == '-'){
				x_coeff--;				
			}
			else
				x_coeff++;

			if(!operators.empty())
				operators.pop();
		}
		else{

			if(isOperator(exp[i])){
				while(!operators.empty() && prec(operators.top()) > prec(exp[i]) ){
					char op;
					if(!operators.empty()){
						op = operators.top();
						operators.pop();
					}

					int a,b;
					if(!operands.empty()){
						a = operands.top();
						operands.pop();
					}

					if(!operands.empty()){
						b = operands.top()	;
						operands.pop();
					}
					
					x_const = expValue( b,a, op);
					operands.push(expValue( b,a, op));
				}
					
				operators.push(exp[i]);
			}
			else{
				int a = exp[i] -'0';				
				operands.push(a);
			}

		}
		prev_sym = exp[i];
	}

	while(!operands.empty()){
		if(operators.empty()){}
			//Error - Return

		char op = operators.top();
		operators.pop();

		int a = operands.top();
		operands.pop();

		if(operands.empty()){
			x_const = a;
			break;
		}
		int b = operands.top();
		operands.pop();
					
		x_const = expValue(b,a, op);
		operators.push(expValue( b,a, op));
	}

	//if( x_coeff == 0)
		//Not a linear equation in X

	cout<< x_coeff<<"\n";
	return -x_const/x_coeff;


}

int main(){

	char exp[] = {'x','+','2','-','3','*','4','-','x','+','4','+','x'};
	cout<<solveForX(exp)<<"\n";
	return 0;
}
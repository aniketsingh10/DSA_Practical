             

                           *************Assignment No. 02: Stack Implementation*****************

CODE:

#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;

struct node
{
	char data;
	struct node *next;
};

class stack
{
	node *top;
	public:
		stack()
		{
			top=NULL;
		}
	char Top()
	{
		return(top->data);
	}
	void push(char x)
	{
		node *temp;
		temp=new node;
		temp->data=x;
		temp->next=top;
		top=temp;
	}
	char pop()
	{
		char value;
		value=top->data;
		top=top->next;
		return(value);
	}
	int isempty()
	{
		if(top==NULL)
			return 1;
		else
			return 0;
	}
};

/*--------------------------------------------------------
Function Name: Priority 
Input: char op
Output: Returns the given operator's position value in 
the priorirty order of operators
--------------------------------------------------------*/

int priority(char op)
{
	if(op=='(' || op==')')	
		return 0;
	else if(op=='+' || op=='-')
		return 1;
	else if(op=='*' || op=='/')
		return 2;
	else if(op=='^')
		return 3;
	else
		return 4;
}

/*--------------------------------------------------------
Function Name: Operation 
Input: char op, int A, int B
Output: Returns the value obtained after performing 
respective operation on A and B 
--------------------------------------------------------*/

int operation(char op, int A, int B)
{
	if(op=='*')
		return A*B;
	else if(op=='/')
		return A/B;
	else if(op=='^')
		return pow(A,B);
	else if(op=='+')
		return A+B;
	else if(op=='-')
		return A-B;
	else
		return -1;
}

/*--------------------------------------------------------
Function Name: Infix to Postfix
Input: char infix[50]
Output: Postfix expression
--------------------------------------------------------*/

void infixtopostfix(char infix[50])
{
	char token,operand,post[50];
	int i,j=0;
	stack S;
	for(i=0;infix[i]!='\0';i++)
	{
		token=infix[i];
		if(isalnum(token))
			post[j++]=token;
		else if(token=='(')
			S.push(token);
		else if(token==')')
			while((operand=S.pop())!='(')
				post[j++]=operand;
		else
		{
			while(!S.isempty() && priority(S.Top())>=priority(token))
				post[j++]=S.pop();
			S.push(token);
		}
	}
	while(!S.isempty())
		post[j++]=S.pop();
	post[j]='\0';
	cout<<post;
}

/*--------------------------------------------------------
Function Name: Infix to Prefix
Input: char infix[50]
Output: Prefix expression
--------------------------------------------------------*/

void infixtoprefix(char infix[50])
{
 	char token, operand, pre[50];
	int i,j=0;
 	stack S;
	for(i=strlen(infix)-1;i>=0;i--)
	{
   		token=infix[i];
   		if(isalnum(token))
   			pre[j++]=token;
   		else if(token==')')
   			S.push(token);
   		else if(token=='(')
  	 		while((operand=S.pop())!=')')
   				pre[j++]=operand;
    	else
    		{
    		while(!S.isempty() && priority(S.Top())>priority(token))
    			pre[j++]=S.pop();
    		S.push(token);
		}	
	}
	while(!S.isempty())
		pre[j++]=S.pop();

	pre[j]='\0';  

	for(i=strlen(pre)-1;i>=0;i--) //displaying the expression in reverse order	
		cout<<pre[i];    	
}

/*--------------------------------------------------------
Function Name: Postfix Evaluation
Input: char exp[50]
Output: Returns the value obtained after the evaluation 
of the given expression
--------------------------------------------------------*/

float postfixevaluation(char exp[50])
{
	int i,val;
	char token;
	float operand1,operand2,result;
	stack  S;
	
	for(i=0;exp[i]!='\0';i++)
	{
		token=exp[i];
		if(isdigit(token))
		{
			S.push(token-48);
		}
		else
		{
			operand2=S.pop();
		 	operand1=S.pop();
		 	result=operation(token,operand1,operand2);
		 	S.push(result);
		}
	}	
	return S.pop();	
}

/*--------------------------------------------------------
Function Name: Prefix Evaluation
Input: char Str[50]
Output: Returns the value obtained after the evaluation
of the given expression
--------------------------------------------------------*/

float prefixevaluation(char Str[50])
{
	int i,val;
	float operand1,operand2,result;
	stack S;
	for(i=strlen(Str)-1;i>=0;i--)
	{
      	if(isdigit(Str[i]))  
      	{
        	S.push(Str[i]-48);
      	}
      	else
      	{
		operand1=S.pop();
		operand2=S.pop();
		result=operation(Str[i],operand1,operand2);
		S.push(result);
      	}
	}
	return S.pop();	
}

int main()
{
	int choice;
	char expression[50];
	cout<<"Operations: \n1. Infix to Postfix \n2. Infix to Prefix \n3. Postfix Evaluation \n4. Prefix Evaluation \n5. Exit\n";
	do
	{
		cout<<"\nEnter choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter Infix Expression\n";
				cin>>expression;
				cout<<"Postfix Expression: ";
				infixtopostfix(expression);
				break;
			case 2:
				cout<<"Enter Infix Expression\n";
				cin>>expression;
				cout<<"Prefix Expression: ";
				infixtoprefix(expression);
				break;
			case 3:
				cout<<"Enter Postfix Expression\n";
				cin>>expression;
				cout<<"Answer: "<<postfixevaluation(expression);
				break;
			case 4:
				cout<<"Enter Prefix Expression\n";
				cin>>expression;
				cout<<"Answer: "<<prefixevaluation(expression);
				break;
			case 5: 
				cout<<"End of program";
	      		break;
			default:
				cout<<"Wrong choice";
				break;
		}
		cout<<"\n";
	}
	while(choice!=5);
}

------------------------------------------------------------------------------------------
OUTPUT:
------------------------------------------------------------------------------------------


Operations:
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Exit

Enter choice:
1
Enter Infix Expression
abc+-
Postfix Expression: abc+-

Enter choice:
1
Enter Infix Expression
+-abc*d/
Postfix Expression: +abcd*/-

Enter choice:
2
Enter Infix Expression
+-abc*d/
Prefix Expression: -+/*abcd

Enter choice:
3
Enter Postfix Expression
+-abc*d/

--------------------------------
Process exited after 153.8 seconds with return value 3221225477
Press any key to continue . . .

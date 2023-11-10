// Infix_Postfix :
using namespace std;
#include<iostream>
#include<ctype.h>
#define SIZE 50
int Stack[SIZE];
int top = -1;

void Push(char item)
{
	top++;
	Stack[top] = item;
	return;
}

char Pop()
{
	char item;
	item = Stack[top];
	top--;
	return item;
}

char Peek()
{
	int item;
	item = Stack[top];
	return item;
}

int pr(char ch)
{
	switch (ch)
	{
	case '#': return 0;
	case '(': return 1;
	case '+': return 1;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}

int main()
{
	char Infx[50], Pofx[50], elem, ch;
	int i = 0, p = 0;
	cout << "Enter Infix Expression :  ";
	cin >> Infx;
	Push('#');
	while ((ch = Infx[i++]) != '\0')
	{
		if (ch == '(')
			Push(ch);
		else if (isalnum(ch))
			Pofx[p++] = ch;
		else if (ch == ')')
		{
			while (Peek() != '(')
				Pofx[p++] = Pop();
		}
		else
		{
			while (pr(Peek()) >= pr(ch))
				Pofx[p++] = Pop();
			Push(ch);
		}
	}
	while (Peek() != '#')
		Pofx[p++] = Pop();
	Pofx[p] = '\0';
	cout << "Given Expression : " << Infx << endl;
	cout << "Postfix Expression : " << Pofx << endl;
}

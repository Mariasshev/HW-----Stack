#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 5 };
	char st[FULL + 1];
	int top;

public:
	Stack();
	void Push(char c);
	char Pop();
	void Clear();
	char Top();
	bool IsEmpty();
	bool IsFull();

	int GetCount();
	bool Check(Stack ST, string userStr);
	void Show();
};


Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

char Stack::Top()
{
	if (IsEmpty()) {
		cout << "Стек пуст." << endl;
		return '\0';
	}
	return st[top];
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

bool Stack::Check(Stack ST, string userStr)
{
	char c;
	for (int i = 0; i < userStr.length(); i++) {
		c = userStr[i];
		switch (c) {				//for three types of brackets
		case '(':
			ST.Push(')');
			break;
		case '{':
			ST.Push('}');
			break;
		case '[':
			ST.Push(']');
			break;

		case ')':
			if (ST.IsEmpty() || ST.Top() != c)			//if the array is empty/the element is not on top of the stack
			{
				cout << "error";						//error message
				return false;
			}
			ST.Pop();									//in other case delete it
			break;

		case '}':
			if (ST.IsEmpty() || ST.Top() != c)
			{
				cout << "error";
				return false;
			}
			ST.Pop();
			break;
		case ']':
			if (ST.IsEmpty() || ST.Top() != c)
			{
				cout << "error";
				return false;
			}
			ST.Pop();
			break;
		}
	}
	cout << "All is correct!" << endl;
	return true;
}

void Stack::Show()
{
	for (int i = 0; i < GetCount(); i++) {
		cout << st[i] << ' ';
	}
}

void Stack::Push(char c)
{
	if (!IsFull()) {
		st[++top] = c;
	}
	else {
		cout << "Стек переполнен." << endl;
	}
}

char Stack::Pop()
{
	if (!IsEmpty()) {
		return st[top--];
	}
	else {
		cout << "Стек пуст." << endl;
		return '\0';
	}
}


int main()
{
	srand(time(0));
	Stack ST;
	string userStr;					//string to check
	cout << "Enter string: ";
	getline(cin, userStr);
	ST.Check(ST, userStr);

}


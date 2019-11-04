#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 5

class stack {
	int *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE); 	// constructor
	~stack();   				// destructor

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};

stack::stack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}

stack::~stack() {
	delete arr;
}

void stack::push(int x) {
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << x << endl;
	arr[++top] = x;
}

int stack::pop() {
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	return arr[top--];
}

int stack::peek() {
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

int stack::size() {
	return top + 1;
}

bool stack::isEmpty() {
	return top == -1;	
}

bool stack::isFull() {
	return top == capacity - 1;	
}

int main() {
	stack st(3);
	st.push(45);
	st.push(60);
	st.pop();
	cout<<st.peek()<<endl;

	if (st.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}
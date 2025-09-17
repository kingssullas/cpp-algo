#include <iostream>
#include <limits>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Node
{
public:
    string value;
    Node *next;

    Node(const string &val) : value(val), next(nullptr) {}
};

class Stack
{
private:
    int size = 0;
    Node *top = nullptr;

public:
    ~Stack()
    {
        while (top)
        {
            Node *node;
            node = top;
            top = top->next;
            delete node;
        }

        size = 0;
    }

    void push(string s)
    {
        Node *node = new Node(s);

        if (isEmpty())
        {
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }

        size++;
    }

    string pop()
    {
        if (isEmpty())
            return "";

        Node *node = top;
        top = top->next;
        string value = node->value;
        delete node;
        size--;
        return value;
    }

    string peek() const
    {
        if (!isEmpty())
            return top->value;

        return "";
    }

    bool isEmpty() const { return !size; }

    int getSize() { return size; }
};

Stack stack;

void init();

void printHeading()
{
    cout << "\t   ╔═══════════════════════════════════╗\n";
    cout << "\t   ║                                   ║\n";
    cout << "\t   ║        Stack Demo Program         ║\n";
    cout << "\t   ║                                   ║\n";
    cout << "\t   ║   Copyright © 2025 Ullas Shome.   ║\n";
    cout << "\t   ║        All Rights Reserved.       ║\n";
    cout << "\t   ╚═══════════════════════════════════╝\n\n";
}

bool isInteger(string &s);
void showMenu();

inline int checkCommand(int command);

int main()
{
    init();
    printHeading();

    while (true)
    {
        string input;
        int command;

        showMenu();

        getline(cin, input);
        cout << endl;

        if (isInteger(input))
        {
            command = stoi(input);
        }
        else
        {
            cout << "-> That's not a valid input.\n\n";
            continue;
        }

        checkCommand(command);
    }

    return 0;
}

bool isInteger(string &s)
{
    stringstream ss(s);
    int x;
    char c;
    return ss >> x && !(ss >> c);
}

void init()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    system("title Stack Demo Program");
#else
    system("clear");
#endif
}

void showMenu()
{
    cout << "What do you want? (n)\n";
    cout << "\t1. Add an Item to the Stack\n";
    cout << "\t2. Show Top Item\n";
    cout << "\t3. Take Out Top Item\n";
    cout << "\t4. Check Stack Size\n";
    cout << "\t5. Clear Stack\n";
    cout << "\t6. Show the Banner\n";
    cout << "\t7. End Program\n\n";
    cout << "Command (n): ";
}

void addItem();
void top();
void pop();
void stackSize();
void clearStack();

inline int checkCommand(int command)
{
    switch (command)
    {
    case 1:
        addItem();
        break;
    case 2:
        top();
        break;
    case 3:
        pop();
        break;
    case 4:
        stackSize();
        break;
    case 5:
        clearStack();
        break;
    case 6:
        printHeading();
        break;
    case 7:
        cout << "-> Program Ended.\n\n";
        cout << "Copyright © 2025 Ullas Shome. All rights reserved.\n";
        exit(0);
    default:
        cout << "-> Not a valid command\n\n";
    }

    return 0;
}

void addItem()
{
    string item;

    cout << "Give us an item: ";
    getline(cin, item);

    stack.push(item);
    cout << "-> Item added\n\n";
}

void top()
{
    if (stack.isEmpty())
    {
        cout << "-> No item to show.\n\n";
        return;
    }

    cout << "-> Top Item is: " << stack.peek() << "\n\n";
}

void pop()
{
    if (stack.isEmpty())
    {
        cout << "-> No item to take out! :(\n\n";
        return;
    }

    cout << "-> Item taken out is: " << stack.pop() << "\n\n";
}

void stackSize()
{
    cout << "-> Stack size: " << stack.getSize();
    if (stack.isEmpty())
        cout << ". No item found! :(";
    cout << "\n\n";
}

void clearStack()
{
    stack.~Stack();
    cout << "-> Stack memory erased!\n\n";
}
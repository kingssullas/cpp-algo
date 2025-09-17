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

class Queue
{
private:
    int size = 0;
    Node *front = nullptr;
    Node *end = nullptr;

public:
    ~Queue()
    {
        while (front)
        {
            Node *node;
            node = front;
            front = front->next;
            delete node;
        }

        end = nullptr;
        size = 0;
    }

    void put(const string &s)
    {
        Node *node = new Node(s);

        if (!front)
        {
            front = node;
            end = node;
        }
        else
        {
            end->next = node;
            end = node;
        }

        size++;
    }

    string get()
    {
        if (isEmpty())
            return "";

        Node *node = front;
        front = front->next;
        string value = node->value;
        delete node;
        size--;
        return value;
    }

    string peek() const
    {
        if (isEmpty())
            return "";

        return front->value;
    }

    bool isEmpty() const { return !size; }

    int getSize() const { return size; }
};

Queue queue;

void init();

void printHeading()
{
    cout << "\t   ╔═══════════════════════════════════╗\n";
    cout << "\t   ║                                   ║\n";
    cout << "\t   ║        Queue Demo Program         ║\n";
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
    system("title Queue Demo Program");
#else
    system("clear");
#endif
}

void showMenu()
{
    cout << "What do you want? (n)\n";
    cout << "\t1. Add an Item to the Queue\n";
    cout << "\t2. Show Nearest Item\n";
    cout << "\t3. Take Out Nearest Item\n";
    cout << "\t4. Check Queue Size\n";
    cout << "\t5. Clear Queue\n";
    cout << "\t6. Show the Banner\n";
    cout << "\t7. End Program\n\n";
    cout << "Command (n): ";
}

void addItem();
void front();
void pop();
void queueSize();
void clearQueue();

inline int checkCommand(int command)
{
    switch (command)
    {
    case 1:
        addItem();
        break;
    case 2:
        front();
        break;
    case 3:
        pop();
        break;
    case 4:
        queueSize();
        break;
    case 5:
        clearQueue();
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

    queue.put(item);
    cout << "-> Item added\n\n";
}

void front()
{
    if (queue.isEmpty())
    {
        cout << "-> No item to show.\n\n";
        return;
    }

    cout << "-> Nearest Item is: " << queue.peek() << "\n\n";
}

void pop()
{
    if (queue.isEmpty())
    {
        cout << "-> No item to take out! :(\n\n";
        return;
    }

    cout << "-> Item taken out is: " << queue.get() << "\n\n";
}

void queueSize()
{
    cout << "-> Queue size: " << queue.getSize();
    if (queue.isEmpty())
        cout << ". No item found! :(";
    cout << "\n\n";
}

void clearQueue()
{
    queue.~Queue();
    cout << "-> Queue memory erased!\n\n";
}
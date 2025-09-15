#include <iostream>
#include <limits>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class LinkedList
{
public:
    string value;
    LinkedList *nextItem;
};

LinkedList *root;
LinkedList *lastItem;

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
#endif

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    system("title Linked List Demo Program");
}

void printHeading()
{
    cout << "\t   ╔═════════════════════════════════╗\n";
    cout << "\t   ║                                 ║\n";
    cout << "\t   ║    Linked List Demo Program     ║\n";
    cout << "\t   ║                                 ║\n";
    cout << "\t   ║  Copyright © 2025 Ullas Shome.  ║\n";
    cout << "\t   ║      All Rights Reserved.       ║\n";
    cout << "\t   ╚═════════════════════════════════╝\n\n";
}

void addItem();
void showItems();
void showAnItem();
void clearItem(LinkedList *item);

int main()
{
    init();
    printHeading();

    while (true)
    {
        string input;
        int command;

        cout << "What do you want? (n)\n";
        cout << "\t1. Add Item\n";
        cout << "\t2. Show Items\n";
        cout << "\t3. Show an item\n";
        cout << "\t4. Clear Memory\n";
        cout << "\t5. Show the Banner\n";
        cout << "\t6. End Program\n\n";
        cout << "Command (n): ";

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

        switch (command)
        {
        case 1:
            addItem();
            break;
        case 2:
            showItems();
            break;
        case 3:
            showAnItem();
            break;
        case 4:
            clearItem(root);
            break;
        case 5:
            printHeading();
            break;
        case 6:
            cout << "-> Program Ended.\n";
            return 0;
        default:
            cout << "-> Not valid input\n\n";
        }
    }
}

void addItem()
{
    string item;

    cout << "Give us an item: ";
    getline(cin, item);

    LinkedList *newItem = new LinkedList;
    newItem->value = item;
    newItem->nextItem = nullptr;

    if (root == nullptr)
    {
        root = newItem;
        lastItem = root;
    }
    else
    {
        lastItem->nextItem = newItem;
        lastItem = newItem;
    }

    cout << "-> Item added\n\n";
}

void showItems()
{
    if (root == nullptr)
    {
        cout << "-> No items to show.\n\n";
        return;
    }

    LinkedList *item = root;
    cout << "Items are:\n";

    for (int i = 1;; i++)
    {
        cout << "\t" << i << ". " << item->value << "\n";
        item = item->nextItem;
        if (!item)
            break;
    }

    cout << endl;
}

void showAnItem()
{
    if (root == nullptr)
    {
        cout << "-> No item to show.\n\n";
        return;
    }
    cout << "Item number? ";

    string input;
    int itemNumber;

    getline(cin, input);
    cout << endl;

    if (isInteger(input))
    {
        itemNumber = stoi(input);
    }
    else
    {
        cout << "-> That's not a valid input.\n\n";
        return;
    }

    LinkedList *item = root;

    for (int i = 1; i < itemNumber; i++)
    {
        if (item && item->nextItem)
            item = item->nextItem;
        else
        {
            cout << "-> Item doesn\'t exist.\n\n";
            return;
        }
    }

    if (itemNumber > 0 && item)
        cout << "-> Item: " << item->value << endl;
    else
    {
        cout << "-> Item doesn\'t exist.\n\n";
        return;
    }

    cout << endl;
}

void clearItem(LinkedList *item)
{
    while (item != nullptr)
    {
        LinkedList *next = item->nextItem;
        delete item;
        item = next;
    }

    root = nullptr;
    lastItem = nullptr;
    cout << "-> Memory Cleared\n\n";
}

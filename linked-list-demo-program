#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *nextItem;
};

LinkedList *root;
LinkedList *lastItem;

inline bool validateInput()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "-> Invalid input. Please enter a number.\n\n";
        return false;
    }
    return true;
}

void printHeading()
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
    printHeading();
    while (true)
    {
        int input;

        cout << "What do you want? (n)\n\t1. Add Item\n\t2. Show Items\n\t3. Show an item\n\t4. Clear Memory\n\t5. End Program\n\nCommand (n): ";
        cin >> input;
        cout << endl;

        if (!validateInput())
            continue;

        switch (input)
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
            cout << "-> Program Ended.\n";
            return 0;
        default:
            cout << "-> Not valid input\n\n";
        }
    }
}

void addItem()
{
    int numberItem;

    cout << "Give us a number: ";
    cin >> numberItem;

    if (!validateInput())
        return;

    LinkedList *newItem = new LinkedList;
    newItem->value = numberItem;
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
        if (item->nextItem == nullptr)
            break;
        item = item->nextItem;
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

    int itemNumber;
    cin >> itemNumber;

    if (!validateInput())
        return;
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

    if (itemNumber != 0 && item)
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

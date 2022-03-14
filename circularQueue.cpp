#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int ar[5];
    int itemCount;

public:
    CircularQueue()
    {
        itemCount=0;
        front = rear = -1;
        for (int x = 0; x < 5; x++)
        {
            ar[x] = 0;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((rear+1)%5==front)       //////////
        {
            return true;
        }
        return false;
    }

    void Enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            ar[rear] = val;
            itemCount++;         /////
        }
        else
        {
            rear=(rear+1)%5;     ///////////
            ar[rear] = val;
            itemCount++;         ////
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            return ar[front];
        }
    }

    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (rear == front)
        {
            int x = ar[rear];
            ar[rear] = 0;
            front = rear = -1;
            itemCount--;           //////
            return x;
        }
        else
        {
            int x = ar[front];
            ar[front] = 0;
            front=(front+1)%5;  ///////
            itemCount--;
            return x;
        }
    }

    int count()
    {
        return (itemCount);      //////
    }

    void display()
    {
        for (int x = 0; x < 5; x++)
        {
            cout << ar[x] << "  ";
        }
    }
};

int main()
{
    CircularQueue q;

    int option, value;
    do
    {
        cout << endl
             << "Menu" << endl;
        cout << "1 - Enqueue()" << endl;
        cout << "2 - Dequeue()" << endl;
        cout << "3 - isEmpty()" << endl;
        cout << "4 - isFull()" << endl;
        cout << "5 - count()" << endl;
        cout << "6 - peek()" << endl;
        cout << "7 - display()" << endl;
        cout << "8 - Clear Screen" << endl
             << endl;
        cout << "Enter your choice. Enter 0 to exit." << endl
             << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Enter value" << endl;
            cin >> value;
            q.Enqueue(value);
            cout << "Done" << endl;
            break;

        case 2:
            cout << q.Dequeue() << endl;
            break;

        case 3:
            if (q.isEmpty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << "Not Empty" << endl;
            }

            break;

        case 4:
            if (q.isFull())
            {
                cout << "Full" << endl;
            }
            else
            {
                cout << "Not Full" << endl;
            }

            break;

        case 5:
            cout << "Number of values : " << q.count() << endl;
            break;

        case 6:
            cout << q.peek() << endl;
            break;

        case 7:
            q.display();
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Invalid Input" << endl;
        }

    } while (option != 0);

    return 0;
}
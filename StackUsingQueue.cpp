#include <iostream>
#include <queue>

using namespace std;

class Stack
{
public:
    queue<int> q1;
    queue<int> q2;

    void Push(int k)       //  O(n)
    {
        if (q1.empty())
        {
            q1.push(k);
        }
        else
        {
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(k);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    void Pop()             //   O(1)
    {
        if (q1.empty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << q1.front() << endl;
            q1.pop();
        }
    }
};

int main()
{
    Stack s;
    s.Push(1);
    s.Push(5);
    s.Push(3);
    s.Pop();  // 3
    s.Push(2);
    s.Pop();  // 2
    s.Pop();  // 5
    s.Pop();  // 1
    s.Pop();  // Stack Underflow

    return 0;
}
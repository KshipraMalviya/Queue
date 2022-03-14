#include<iostream>
#include<queue>

using namespace std;

class Stack
{
    public:
    queue<int>q1;
    queue<int>q2;
    void Push(int k)    // O(1)
    {
        q1.push(k);
    }
    void Pop()
    {
        int s=q1.size();
        if(s==0)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            for(int x=1; x<s; x++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            cout<<q1.front()<<endl;
            q1.pop();
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
};

int main()
{
    Stack s;
    s.Push(1);
    s.Push(5);
    s.Push(3);
    s.Pop();   // 3
    s.Push(2);
    s.Pop();   // 2
    s.Pop();   // 5
    s.Pop();   // 1
    s.Pop();   // Stack Underflow

    return 0;
}
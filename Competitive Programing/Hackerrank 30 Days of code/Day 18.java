#include <iostream>

using namespace std;

class Solution {
    public:
    //Write your code here
    char stack[100],queue[100];
    int top=-1,front=-1,last=-1;
    void pushCharacter(char c)
    {
        stack[++top]=c;
    }
    void enqueueCharacter(char c)
    {
        if(front==-1)
        {
            queue[++front] = c;
            ++last;
        }
        else{
            queue[++last] = c;
        }
    }
    char popCharacter()
    {
        return stack[top--];
    }
    char dequeueCharacter()
    {
        return queue[front++];
    }
};

int main() {
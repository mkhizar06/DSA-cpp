#include <iostream>
#include"c_queue.h"

int main()
{
    queue<int>q;
    q.push(2);
    q.push(3);
    q.push(7);
    q.push(4);
    q.push(6);
    q.push(5);
    q.push(1);
    std::cout <<"\nSize of queue = "<< q.size();
    q.pop();
    std::cout << "\nQueue's Front = " <<q.front();
    std::cout << "\nQueue's Back = " << q.back();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

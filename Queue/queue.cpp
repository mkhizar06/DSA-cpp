// queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"node.h"
#include"queue.h"

int main()
{
    queue<int>q1,q2,q3;
    //q1
    q1.push(1);
    q1.push(3);
    q1.push(5);
    //q2
    q2.push(1);
    q2.push(3);
    //q3
    q3.push(2);
    q3.push(4);
    q3.push(6);

    q2.pop();
    std::cout << "\nQ2 front = " << q2.front();
    std::cout << "\nQ2 back = " << q2.back();

    std::cout <<"\n< operator check for q1 and q2: " << (q1 < q2);
    std::cout <<"\n== operator check for q1 and q2: " << (q1 == q2);

    std::cout << "\nSize of q3 = " << q3.size();

        // copy constrcutor
        queue<int>q4(q1);

        //assignment op
        q2 = q3;
    std::cout << "\n== operator check for q2 and q3: " << (q2 == q3);
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

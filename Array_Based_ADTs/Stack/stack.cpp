
#include <iostream>
#include "stack.h"
#include<string>

//Client code indicates a string pushed into stack character by character and then displayed in reversed
    //order by popping from stack

int main()
{
    stack<char>s;
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        s.push(str[i]);
    }
    std::cout << "\nSize of stack = " << s.size()<<"\n";
    while (!s.empty())
    {
        std::cout<<s.top()<<" ";
        s.pop();
    }

    std::cout << "\nSize of stack = "<<s.size();
    std::cout << "\nEmpty: " << s.empty();

}


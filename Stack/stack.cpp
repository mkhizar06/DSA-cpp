#include "stack.h"
#include "node.h"
#include <iostream>

int main()
{
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(3);
    while (!st.empty())
    {
        std::cout << st.top() << "\n";
        st.pop();
    }

    stack<char> stk;
    std::string str;
    std::cout << "Enter String: ";
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        stk.push(str[i]);
    }
    std::cout<<"\n\nStack size: "<<stk.size();
    stk.pop();
    std::cout<<"\n\nTop value: "<<stk.top();
    std::cout<<"\n\nStack empty: "<<stk.empty();
    stack<int> s;
    std::cout << "\n\nStack empty: " << s.empty()<<"\n";

    stack<int>s1, s2;
    s1.push(1);
    s1.push(5);
    s1.push(4);
    s2.push(1);
    s2.push(2);

    //==
    if (s1 == s2)
        std::cout << "\n\ns1 and s2 are equal!\n";
    else
        std::cout << "s1 and s2 are not equal!\n";

    // !=
    if (s1 != s2)
        std::cout << "s1 and s2 are unequal!\n";

    // <
    if (s1 < s2)
        std::cout << "s1 is smaller than s2!\n";
    else
        std::cout << "s1 is not smaller than s2!\n";


}


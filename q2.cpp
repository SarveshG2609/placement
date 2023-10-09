/* Given a string A, containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Note:  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/

#include <bits/stdc++.h>
using namespace std;

int Solution::isValid(string A)
{
    stack<char> S;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ')')
        {
            if (!S.empty())
            {
                char top = S.top();
                if (top != '(' || S.empty())
                    return 0;
                S.pop();
            }
            else
                return 0;
        }
        else if (A[i] == '}')
        {
            if (!S.empty())
            {
                char top = S.top();
                if (top != '{' || S.empty())
                    return 0;
                S.pop();
            }
            else
                return 0;
        }
        else if (A[i] == ']')
        {
            if (!S.empty())
            {
                char top = S.top();
                if (top != '[' || S.empty())
                    return 0;
                S.pop();
            }
            else
                return 0;
        }

        else
        {
            S.push(A[i]);
        }
    }
    if (S.empty())
        return 1;
    else
        return 0;
}
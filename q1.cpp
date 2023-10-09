/* An arithmetic expression is given by a string array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each string may be an integer or an operator. */

#include <bits/stdc++.h>
using namespace std;

int Solution::evalRPN(vector<string> &A)
{
    stack<int> S;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == "+")
        {
            int num1 = S.top();
            S.pop();
            int num2 = S.top();
            S.pop();
            int num3 = num1 + num2;
            S.push(num3);
        }
        else if (A[i] == "-")
        {
            int num1 = S.top();
            S.pop();
            int num2 = S.top();
            S.pop();
            int num3 = num2 - num1;
            S.push(num3);
        }
        else if (A[i] == "*")
        {
            int num1 = S.top();
            S.pop();
            int num2 = S.top();
            S.pop();
            int num3 = num1 * num2;
            S.push(num3);
        }
        else if (A[i] == "/")
        {
            int num1 = S.top();
            S.pop();
            int num2 = S.top();
            S.pop();
            int num3 = num1 / num2;
            S.push(num3);
        }
        else
        {
            S.push(stoi(A[i]));
        }
    }
    return S.top();
}

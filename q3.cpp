/*
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.
*/

int Solution::braces(string A)
{
    int flag;
    vector<char> V;
    stack<char> S;
    for (int i = 0; i < A.size(); i++)
    {

        if (A[i] == '(')
        {
            S.push(A[i]);
        }
        else if (A[i] == ')')
        {
            while (S.top() != '(')
            {
                V.push_back(S.top());
                S.pop();
            }
            if (V.size() > 1)
            {
                V.clear();
                S.pop();
                S.push('X');
            }
            else
            {
                return 1;
            }
        }
        else
            S.push(A[i]);
        ;
    }
    return 0;
}

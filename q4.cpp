/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.
*/


vector<int> Solution::prevSmaller(vector<int> &A) 
{
    vector<int> ans;
    stack<int> S;
    
    for(int i=0; i<A.size(); i++)
    {
        if (S.empty())
        {
        ans.push_back(-1);
        S.push(A[i]);
        }
        else
        {
            while(!S.empty() && S.top()>=A[i]) 
            S.pop();
            
            if (S.empty()) ans.push_back(-1);
            else ans.push_back(S.top());
            
            S.push(A[i]);
        }
    }
    return ans;
}

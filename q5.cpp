/*
Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.
*/

int Solution::solve(string A)
{
{ 
    int count=0;
    if (A[0]==')')
    {
    return 0;
    }
    
    for (int i=0; i < A.length(); i++)
    {
        if (A[i]=='(') count++;
        else count--;
        
        if(count<0) 
        {
        return 0;
        }
     }
     if(count==0)
        return 1;
         else return 0;
}
}

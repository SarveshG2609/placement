/*
Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{  
deque<int> q;
vector<int> ans;
queue<int> i;
int j;

if(B>A.size())
{
    B= A.size();
}

for(j=0;j<B;j++)
{
    while(!q.empty() && q.back()<A[j])
    q.pop_back();
        
    q.push_back(A[j]);
    i.push(A[j]);
}

ans.push_back(q.front());

while(j<A.size())
{
    if(i.front()== q.front())
    {
        q.pop_front();
    }
    
    while(!q.empty() && q.back()<A[j])
    q.pop_back();
        
    q.push_back(A[j]);
    i.push(A[j]);
    i.pop();
    ans.push_back(q.front());
    j++;
}

return ans;
}

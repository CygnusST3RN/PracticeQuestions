//Question Link :- https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
//Code :-
bool isSafe(vector<vector<int> > mat , int i , int j)
{
    int n = mat.size();
    
    //left
    for(int col = j;col >= 0 ; col--)
    {
        if(mat[i][col] == 1)
        {
            return false;
        }
    }
    
    //Lower diag
    for(int row = i , col = j ; row < n  && col >= 0 ; row++ , col--)
    {
        if(mat[row][col] == 1)
        {
            return false;
        }
    }
    
    //Upper Diag
    for(int row = i , col = j ; row >= 0 && col >= 0 ; row-- , col--)
    {
        if(mat[row][col] == 1)
        {
            return false;
        }
    }
    
    return true;
}
void solve(int n , int i , int j , vector<vector<int> > &res , vector<vector<int> > &mat , vector<int> &arr)
{
    //base case
    if(j >= n)
    {
        res.push_back(arr);
        return;
    }
    
    while(i < n)
    {
        if(isSafe(mat, i , j))
        {
            mat[i][j] = 1;
            arr.push_back(i+1);
            solve(n , 0 , j + 1 , res , mat , arr);
            arr.pop_back();
            mat[i][j] = 0;
        }
        i++;
    }
    return;
}
    
vector<vector<int>> nQueen(int n) {
// code here
vector<vector<int> > res;
vector<vector<int> > mat(n , vector<int>(n , 0));
vector<int> arr;
for(int i = 0 ; i < n ; i++)
{
    mat[i][0] = 1;
    arr.push_back(i+1);
    solve(n , 0 , 1 , res , mat , arr);
    arr.pop_back();
    mat[i][0] = 0;
}

return res;
}

//The board can be printed using matrix 'mat' 
//Code by Rahul

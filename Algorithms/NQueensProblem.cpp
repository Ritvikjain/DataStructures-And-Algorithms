#include<bits/stdc++.h>
#include<map>
int board[11][11];
map<int,bool> column;
map<int,bool> upperLeft;
map<int,bool> upperRight;
bool Possible(int n,int row,int col)
{
    if(column[col] == true)
        return false;
    if(upperLeft[col-row] == true)
        return false;
    if(upperRight[col+row] == true)
        return false;
    return true;
}
/*bool isPossible(int n,int row,int column)
{
    //check in same column
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][column] == 1)
            return false;
    }
    
    //check in upper left diagonal
    for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j] == 1)
            return false;
    }
    
    //check in upper right diagonal
    for(int i=row-1,j=column+1;i>=0&&j<n;i--,j++)
    {
        if(board[i][j] == 1)
            return false;
    }
    
    return true;
}*/
void nQueenHelper(int n,int row){
    if(n==row){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
        cout<<endl;
        return;
    }
    for(int j=0;j<n;j++){
        if(Possible(n,row,j)){
            board[row][j] = 1;
            column[j] = true;
            upperLeft[j-row] = true;
            upperRight[row+j] = true;
            nQueenHelper(n,row+1);
            board[row][j] = 0;
            column[j] = false;
            upperLeft[j-row] = false;
            upperRight[row+j] = false;
        }
    }
    return;
}
void placeNQueens(int n){
  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    memset(board,0,11*11*sizeof(int));
    nQueenHelper(n,0);
}


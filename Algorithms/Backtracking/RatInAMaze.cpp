#include<bits/stdc++.h>
int solution[20][20];
void findPath(int maze[][20],int n,int row,int col)
{
    if(row<0||row>=n||col<0||col>=n)
        return;
    if(maze[row][col] == 0 || solution[row][col] == 1)
        return;
    if(row == n-1 && col == n-1)
    {
        solution[row][col] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<solution[i][j]<<" ";
        }
        cout<<endl;
        solution[row][col] = 0;
        return;
    }
    solution[row][col] = 1;
    findPath(maze,n,row+1,col);
    findPath(maze,n,row,col+1);
    findPath(maze,n,row-1,col);
    findPath(maze,n,row,col-1);
    solution[row][col] = 0;
    return;
}
void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    memset(solution,0,n*n*sizeof(int));
    findPath(maze,n,0,0);
}


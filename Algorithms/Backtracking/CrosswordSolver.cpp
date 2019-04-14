#include<bits/stdc++.h>
using namespace std;

bool isValidVertical(string grid[],int row,int col,vector<string> vec,int index){
	if(vec[index].length()>(9-row+1))
	return false;
	for(int i=row;i<row+vec[index].length();i++){
		if(grid[i][col]=='+')
		return false;
	}
	for(int i=0;i<vec[index].length();i++){
		if(grid[row+i][col]=='-'||grid[row+i][col]==vec[index][i]){
			
		}
		else
		return false;
	}
	return true;
}

bool isValidHorizontal(string grid[],int row,int col,vector<string> vec,int index){
	if(vec[index].length()>(9-col+1))
	{
		return false;
	}
	for(int i=col;i<col+vec[index].length();i++){
		if(grid[row][i]=='+')
		{
		return false;
	    }
	}
	for(int i=0;i<vec[index].length();i++){
		if(grid[row][col+i]=='-'||grid[row][col+i]==vec[index][i])
		{
			
	    }
	    else{
	    	return false;
		}
	}
	return true;
}

void setVertical(string grid[],int row,int col,vector<string> vec,int index,bool helper[]){
	for(int i=0;i<vec[index].length();i++){
		if(grid[i+row][col]=='-')
		helper[i]=true;
		else
		helper[i]=false;
		grid[i+row][col]=vec[index][i];
	}
	
}

void setHorizontal(string grid[],int row,int col,vector<string> vec,int index,bool helper[]){
	for(int i=0;i<vec[index].length();i++){
		if(grid[row][col+i]=='-')
		helper[i]=true;
		else
		helper[i]=false;
		grid[row][col+i]=vec[index][i];
	}
}

void resetVertical(string grid[],int row,int col,vector<string> vec,int index,bool helper[]){
	for(int i=0;i<vec[index].length();i++){
		if(helper[i]==true)
		grid[i+row][col]='-';
	}
}

void resetHorizontal(string grid[],int row,int col,vector<string> vec,int index,bool helper[]){
	for(int i=0;i<vec[index].length();i++){
		if(helper[i]==true)
		grid[row][col+i]='-';
	}
}

void crosswordSolver(string grid[],vector<string> vec,int index){
	if(index==vec.size())
    {
        for(int i=0;i<10;i++){
          for(int j=0;j<10;j++){
               cout<<grid[i][j];
                }
            cout<<endl;
            } 
        return;
    }
  int i,j;
  for(i=0;i<10;i++){
  	for(j=0;j<10;j++){
  		if(grid[i][j]=='-'||grid[i][j]==vec[index][0]){
  			if(isValidVertical(grid,i,j,vec,index)){
  				bool helper[vec[index].length()];
  				setVertical(grid,i,j,vec,index,helper);
  				crosswordSolver(grid,vec,index+1);
				resetVertical(grid,i,j,vec,index,helper);
			  }
			if(isValidHorizontal(grid,i,j,vec,index)){
  				bool helper[vec[index].length()];
  				setHorizontal(grid,i,j,vec,index,helper);
				crosswordSolver(grid,vec,index+1);
				resetHorizontal(grid,i,j,vec,index,helper);
			  }
		  }
	  }
  }
}

int main() {
  string grid[10];
  string s;
  vector<string> vec;
  vector<string>::iterator it;
  for(int i=0;i<10;i++)
      cin>>grid[i];
  cin>>s;
  int j=0,k=0;
  for(int i=0;i<s.length();i++){
  k++;
  if(s[i]==';'){
  vec.push_back(s.substr(j,k-1));
  k=0;
  j=i+1;
  }
  }
  vec.push_back(s.substr(j,k));
  crosswordSolver(grid,vec,0);
  return 0;
}

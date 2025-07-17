#include<iostream>
#include<vector>
using namespace std;

// Brute Force
void setRowToZero(int start,int j,vector<vector<int>>&matrix,int end){
    for(int i=start;i<end;i++){
        matrix[i][j]=0;
    }
}
void setColToZero(int start,int r,vector<vector<int>>&matrix,int end){
    for(int i=start;i<end;i++){
        matrix[r][i]=0;
    }
}
void setZeroes(vector<vector<int>>&matrix){
    int nRow=matrix.size();
    int nCol=matrix[0].size();
    for (size_t i = 0; i < nRow; i++)
    {
       for (size_t j = 0; j< nCol; j++)
       {
        if(matrix[i][j]==0){
            setRowToZero(i,j,matrix,nCol);
            // setcolToZero(j,i,matrix,nRow);
        }
       }
       
    }
    

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
           cin>>matrix[i][j];
        }
        
    }
    
    return 0;
}
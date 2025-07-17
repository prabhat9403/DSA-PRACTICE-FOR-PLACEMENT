/*Problem Statement: This problem has 3 variations. They are stated below:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:*/



#include<iostream>
using namespace std;

long long NcR(int n,int r){
    long long result=1;

    for (size_t i = 0; i <r; i++){
        result=result*(n-i);
        result=result/(i+1);
        
    }
    return result;
    
    
}
void printNthRow(int r){
    for(int i=1;i<=r;i++){
        cout<<NcR(r-1,i-1)<<" ";
    }
}
void PrintNRow(int r){
    for (size_t i = 0; i < r; i++)
    {
       printNthRow(i+1);
       cout<<endl;
    }
    
}

int elementAt_R_C(int r,int c){
    return NcR(r-1,c-1);
}

int main(){
    int r,c;
    // cin>>r;
    // cin>>c;
    PrintNRow(5); 
    return 0;
}
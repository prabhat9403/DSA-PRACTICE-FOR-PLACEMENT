#include<iostream>
#include<vector>
using namespace std;
void printArr(int *arr,int n){
    cout<<endl;
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
void AlternatePosNeg(int arr[],int n){
    int pos=0;
    int neg=1;
    int *temp=new int [n];
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i]>=0){
            temp[pos]=arr[i];
            pos+=2;
        }
        else{
           temp[neg]=arr[i];
            neg+=2;
        }

    }
    printArr (arr,n);
    printArr(temp,n);
    
}


int main(){
    int n = 4;
    int A[] ={1,2,-4,-5};
AlternatePosNeg(A,n);

}

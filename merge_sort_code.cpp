#include<bits/stdc++.h>
using namespace std;


void conquer( int arr[], int s, int mid , int e) {  //
     int mergedSize = e - s + 1;
    int *merged= new int[ mergedSize]; // it new memory allocation taken.


    int idx1=s;  // track 1 st array
    int idx2= mid+1;  // track 2nd array.
    int x=0;

    while ( idx1<=mid && idx2<=e)
    {
        if(arr[idx1]<=arr[idx2])
        {
            merged[x]= arr[idx1];
            x++; idx1;
        }
        else
        {
            merged[x]=arr[idx2];
            x++; idx2++;

            // merger[x++] = arr[idx2++];
        }

    }


    //  copy the other value
    while ( idx1<= mid)
    {
        merged[x++]=arr[idx1++];
    }

    while( idx2<=e)
    {
        merged [x++]= arr[ idx2++];
    }


    // merged value copy into main array

    for( int i=0, j=s; i<mergedSize;i++, j++)
    {
        arr[j]= merged[i];
    }






}

void divide( int arr[], int s, int e)
{
    if( s>=e){ return ;}// array is already sorted.
   int  mid = s + (e-s)/2;

    divide (arr, s, mid);

    divide (arr, mid+1, e);

    conquer( arr, s, mid, e);

}



int main()
{
    int arr[]={ 6,4,9,5,2,8};

    int n=sizeof(arr)/ sizeof(arr[0]);


    divide ( arr, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    } cout<<endl;



}

#include<bits/stdc++.h>
using namespace std;

void merge_them(int *arr, int s,int e, int count){

    int mid = s + (e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int index = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[index++];
    }
    index = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[index++];
    }
    int index1 =0;
    int index2 =0;
    while(index1 < len1 && index2 <len2){
        if(first[index1] > second[index2]){
            count+=len1-index1;
            index2++;
        }
        else if(first[index1] < second[index2]){
            index1++;
        }
    }
    index1 = 0;
    index2 = 0;
    int main_index =s;

    while(index1 < len1 && index2 <len2)
    {
        if(first[index1] < second[index2]){
            arr[main_index++] = first[index1++];
        }
        else if(first[index1] > second[index2]){
            arr[main_index++] = second[index2++];
        }
        else{
             arr[main_index++] = first[index1++];
        }
    }

    while(index1 < len1){
        arr[main_index++] = first[index1++];
    }
    while(index2 < len2){
        arr[main_index++] = second[index2++];
    }
}
void mergeSort(int *arr, int s, int e, int count){

    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;

    mergeSort(arr,s,mid,count);
    mergeSort(arr,mid+1,e,count);

    merge_them(arr,s,e,count);

}

void print(int *arr, int n){
   
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    
    int arr[] = {5,4,12,7,9,11,3,2,1};
    int n =9;
    int count =0;
    mergeSort(arr,0,n-1,count);
    print(arr,n);

    return 0;
}
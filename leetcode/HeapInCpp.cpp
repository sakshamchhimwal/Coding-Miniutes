#include<bits/stdc++.h>
using namespace std;

class heap_min{
private:
    vector<int> heapArray={};
    void swap(int index1,int index2){
        int temp=heapArray[index1];
        heapArray[index1]=heapArray[index2];
        heapArray[index2]=temp;
    }
    void heapify(int index){
        int size=heapArray.size();
        int largestIndex=index;
        int leftIndex=2*index+1;
        int rightIndex=2*index+2;
        if(leftIndex<size && heapArray[leftIndex]<heapArray[largestIndex])
            largestIndex=leftIndex;
        if(rightIndex<size && heapArray[rightIndex]<heapArray[largestIndex])
            largestIndex=rightIndex;
        if(largestIndex!=index){
            swap(largestIndex,index);
            heapify(largestIndex);
        }
    }
public:
    void insert(int i){
        if(heapArray.size()==0) 
            heapArray.push_back(i);
        else{
            heapArray.push_back(i);
            int size=heapArray.size();
            for (int i = size / 2 - 1; i >= 0; i--){
                heapify(i);   
            }
        }
    }
    void deleteNode(int nodeToBeDeleted){
        int size=heapArray.size();
        int i=0;
        for(;i<size;i++){
            if(nodeToBeDeleted==heapArray[i])
                break;
        }
        swap(i,size-1);
        heapArray.pop_back();
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(i);   
        }
    }
    int removeMin(){
        int size=heapArray.size();
        if(size!=0){
            int min=heapArray[0];
            swap(0,size-1);
            deleteNode(min);
            return min;
        }else
            return -1;
    }
    void printHeap(){
        for(int i:heapArray)
            cout<<i<<",";
        cout<<'\n';
    }
};

#include<bits/stdc++.h>
using namespace std;

struct node{
    int index;
    int enqueueTime;
    int processingTime;
    node(int index,int a,int b){
        this->index=index;
        enqueueTime=a;
        processingTime=b;
    }
};
typedef struct node node;
class heap_min{
private:
    vector<node> heapArray;
    void swap(int index1,int index2){
        node temp = heapArray[index1];
        heapArray[index1]=heapArray[index2];
        heapArray[index2]=temp;
    }
    void heapify(int i){
        int minimum = i;
        int leftIndex = 2*i+1;
        int rightInde = 2*i+2;
        int size = heapArray.size();
        if(leftIndex<size && heapArray[leftIndex].enqueueTime<heapArray[minimum].enqueueTime)
            minimum=leftIndex;
        if(rightInde<size && heapArray[rightInde].enqueueTime<heapArray[minimum].enqueueTime)
            minimum=rightInde;
        if(minimum!=i){
            swap(i,minimum);
            heapify(minimum);
        }
    }
public:
    void insert(node newNode){
        if(heapArray.size()==0){
            heapArray.push_back(newNode);
        }else{
            heapArray.push_back(newNode);
            int size=heapArray.size();
            for(int i=size/2 -1;i>=0;i--){
                heapify(i);
            }
        }
    }
    node minNode(){
        if(heapArray.size()==0)
            return node(-1,-1,-1);
        else{
            node minNode = heapArray[0];
            swap(0,heapArray.size()-1);
            heapArray.pop_back();
            int size=heapArray.size();
            for (int i = size/2 -1;i>=0; i--){
                heapify(i);
            }
            return minNode;
        }
    }
};
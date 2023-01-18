#include<bits/stdc++.h>
using namespace std;

struct node{
    int enqueueTime;
    int processingTime;
    int index;
    node(int i,int e,int p){
        index=i;
        enqueueTime=e;
        processingTime=p;
    }
};
typedef struct node node;

class heap_min_ProcessingTime{
private:
    vector<node> heapArray;
    void swap(int index1,int index2){
        node temp=heapArray[index1];
        heapArray[index1]=heapArray[index2];
        heapArray[index2]=temp;
    }
    void heapify(int index){
        int size=heapArray.size();
        int minimum=index;
        int leftIndex=2*index+1;
        int rightIndex=2*index+2;
        if(leftIndex<size && heapArray[leftIndex].processingTime<=heapArray[minimum].processingTime){
            if(heapArray[leftIndex].processingTime==heapArray[minimum].processingTime){
                if(heapArray[leftIndex].index<heapArray[minimum].index)
                    minimum=leftIndex;
            }else{
                minimum=leftIndex;
            }
        }
        if(rightIndex<size && heapArray[rightIndex].processingTime<=heapArray[minimum].processingTime){
            if(heapArray[rightIndex].processingTime==heapArray[minimum].processingTime){
                if(heapArray[rightIndex].index<heapArray[minimum].index)
                    minimum=rightIndex;
            }else{
                minimum=rightIndex;
            }
        }
        if(minimum!=index){
            swap(minimum,index);
            heapify(minimum);
        }
    }
public:    
    void insert(node newNode){
        if(heapArray.size()==0)
            heapArray.push_back(newNode);
        else{
            heapArray.push_back(newNode);
            int size=heapArray.size();
            for(int i=(size/2)-1;i>=0;i--){
                heapify(i);
            }
        }
    }
    node extractMin(){
        if(heapArray.size()!=0){
            node root=heapArray[0];
            swap(0,heapArray.size()-1);
            heapArray.pop_back();
            int size=heapArray.size();
            for(int i=(size/2)-1;i>=0;i--)
                heapify(i);
            return root;
        }
        return node(-1,-1,-1);
    }
    bool isEmpty(){
        if(heapArray.size()!=0) return false;
        return true;
    }
};

class heap_min_EnqueueTime{
private:
    vector<node> heapArray;
    void swap(int index1,int index2){
        node temp=heapArray[index1];
        heapArray[index1]=heapArray[index2];
        heapArray[index2]=temp;
    }
    void heapify(int index){
        int size=heapArray.size();
        int minimum=index;
        int leftIndex=2*index+1;
        int rightIndex=2*index+2;
        if(leftIndex<size && heapArray[leftIndex].enqueueTime<=heapArray[minimum].enqueueTime){
            if(heapArray[leftIndex].enqueueTime==heapArray[minimum].enqueueTime){
                if(heapArray[leftIndex].index<heapArray[minimum].index)
                    minimum=leftIndex;
            }else{
                minimum=leftIndex;
            }
        }
        if(rightIndex<size && heapArray[rightIndex].enqueueTime<=heapArray[minimum].enqueueTime){
            if(heapArray[rightIndex].enqueueTime==heapArray[leftIndex].enqueueTime){
                if(heapArray[rightIndex].index<heapArray[minimum].index)
                    minimum=rightIndex;
            }else{
                minimum=rightIndex;
            }
        }
        if(minimum!=index){
            swap(minimum,index);
            heapify(minimum);
        }
    }
public:    
    void insert(node newNode){
        if(heapArray.size()==0)
            heapArray.push_back(newNode);
        else{
            heapArray.push_back(newNode);
            int size=heapArray.size();
            for(int i=(size/2)-1;i>=0;i--){
                heapify(i);
            }
        }
    }
    node extractMin(){
        if(heapArray.size()!=0){
            node root= heapArray[0];
            swap(0,heapArray.size()-1);
            heapArray.pop_back();
            int size=heapArray.size();
            for(int i=(size/2)-1;i>=0;i--)
                heapify(i);
            return root;
        }
        return node(-1,-1,-1);
    }
    int getCurrentEnqueueTime(){
        if(heapArray.size()>0)
            return heapArray[0].enqueueTime;
        return -1;
    }
    bool isEmpty(){
        if(heapArray.size()!=0) return false;
        return true;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        heap_min_EnqueueTime sortedTaskHeap;
        heap_min_ProcessingTime sortedAvailableHeap;
        for(int i=0;i<tasks.size();i++)
            sortedTaskHeap.insert(node(i,tasks[i][0],tasks[i][1]));
        int currentTime=0;
        vector<int> processed;
        node processing=node(-1,-1,-1);
        while(processed.size()!=tasks.size()){
            while(!sortedTaskHeap.isEmpty() && sortedTaskHeap.getCurrentEnqueueTime()<=currentTime){
                sortedAvailableHeap.insert(sortedTaskHeap.extractMin());
            }
            if(processing.index!=-1){
                currentTime+=processing.processingTime;
                processed.push_back(processing.index);
                processing=node(-1,-1,-1);
            }else{
                if(!sortedAvailableHeap.isEmpty()){
                    processing=sortedAvailableHeap.extractMin();
                }else{
                    currentTime++;
                }
            }
        }
        return processed;
    }
};

int main(){
    Solution soln;
    vector<vector<int>> vec={};
    double time=clock();
    soln.getOrder(vec);
    time-=clock();
    cout<<time;
}
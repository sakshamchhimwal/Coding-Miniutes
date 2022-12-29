#include<bits/stdc++.h>
using namespace std;
FILE *fpw;
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
    void printHeap(){
        for(node x:heapArray)
            fprintf(fpw,"(I:%d,E:%d,P:%d)",x.index,x.enqueueTime,x.processingTime);
        fprintf(fpw,"\n");
    }
    void swap(int index1,int index2){
        node temp = heapArray[index1];
        heapArray[index1]=heapArray[index2];
        heapArray[index2]=temp;
    }
    bool isProcessingTimeSame(int index1,int index2){
        if(index1<heapArray.size() && index2<heapArray.size() && heapArray[index1].processingTime==heapArray[index2].processingTime)
            return true;
        return false;
    }
    void heapify(int i){
        int minimum = i;
        int leftIndex = 2*i+1;
        int rightIndex = 2*i+2;
        int size = heapArray.size();
        if(leftIndex<size && heapArray[leftIndex].processingTime<heapArray[minimum].processingTime)
            minimum=leftIndex;
        if(rightIndex<size && heapArray[rightIndex].processingTime<heapArray[minimum].processingTime)
            minimum=rightIndex;
        if(isProcessingTimeSame(leftIndex,rightIndex)){
            if(heapArray[leftIndex].index<heapArray[rightIndex].index){
                if(rightIndex<size && heapArray[rightIndex].processingTime<=heapArray[minimum].processingTime)
                    minimum=leftIndex;
            }else{
                if(leftIndex<size && heapArray[leftIndex].processingTime<=heapArray[minimum].processingTime)
                    minimum=rightIndex;
            }
        }else{
            if(isProcessingTimeSame(minimum,leftIndex)){
                if(heapArray[leftIndex].index<heapArray[minimum].index){
                    minimum=leftIndex;
                }
            }
            if(isProcessingTimeSame(minimum,rightIndex)){
                if(heapArray[rightIndex].index<heapArray[minimum].index){
                    minimum=rightIndex;
                }
            }
        }
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
            fprintf(fpw,"inserted And Heapifying\n");
            for(int i=size/2 -1;i>=0;i--){
                heapify(i);
            }
            printHeap();
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
            fprintf(fpw,"Deleted And Heapifying\n");
            for (int i = size/2 -1;i>=0; i--){
                heapify(i);
            }
            printHeap();
            return minNode;
        }
    }
    bool isEmpty(){
        if(heapArray.size()) return false;
        return true;
    }
    
};
class heap_min2{
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
    node getRoot(){
        return heapArray.at(0);
    }
    bool isEmpty(){
        if(heapArray.size()!=0)
            return false;
        return true;
    }
};
class Solution{
public:
    vector<int> getOrder(vector<vector<int>>& tasks){
        heap_min availableHeap;
        heap_min2 tasksHeap;
        for(int i=0;i<tasks.size();i++){
            node newNode = node(i,tasks[i][0],tasks[i][1]);
            tasksHeap.insert(newNode);
        }
        int currentTime=0;
        vector<node> processing={};
        vector<int> processed={};
        while(processed.size()!=tasks.size()){
            //Inserting new processes in the availableHeap
            while (!tasksHeap.isEmpty() && tasksHeap.getRoot().enqueueTime<=currentTime)
                availableHeap.insert(tasksHeap.minNode());
            //TaskCompletionLogic
            if(processing.size()==1){
                currentTime+=processing[0].processingTime;
                processed.push_back(processing[0].index);
                processing.pop_back();
            }else{
                if(!availableHeap.isEmpty()){
                    processing.push_back(availableHeap.minNode());
                }else
                    currentTime++;
            }
        }
        return processed;
    }
};

int main(){
    fpw=fopen("singlethread.txt","w");
    Solution soln;
    vector<vector<int>> v={{544,164},{214,141},{870,310},{456,349},{804,572},{899,704},{305,337},{446,987},{411,6},{324,78},{618,430},{722,901},{49,205},{28,913},{944,875},{696,687},{30,672},{445,322},{883,505},{279,591},{354,254},{667,933},{541,417},{593,394},{137,250},{163,620},{4,665},{54,398},{412,86},{451,808},{281,575},{484,456},{872,157},{718,242},{776,311},{781,929},{829,965},{580,105},{648,253},{793,573},{991,744},{813,886},{392,455},{845,992},{921,72},{97,489},{769,232},{399,953},{3,147},{268,191},{858,374},{651,748},{566,639},{299,685},{518,333},{489,371},{268,893},{809,725},{49,163},{643,379},{424,839},{428,274},{983,57},{158,283},{986,317},{888,224},{518,415},{290,752},{513,871},{841,410},{743,61},{814,584},{602,472},{299,102},{802,122},{610,351},{716,631},{384,927},{640,612},{486,245},{743,270},{608,494},{974,186},{911,949},{917,256},{562,49},{91,795},{650,897},{977,619},{669,979},{487,695},{501,927},{445,406},{774,210},{972,874},{915,985},{542,756},{49,563},{850,466},{988,134},{852,933},{686,891},{56,694},{792,316},{407,751},{551,20},{500,32},{841,793},{374,887},{882,2},{564,893},{231,465},{116,77},{281,766},{278,826},{245,518},{572,258},{199,875},{349,587},{463,991},{912,408},{203,311},{962,478},{863,257},{276,932},{612,777},{862,236},{51,785},{364,322},{866,4},{575,124},{21,335},{891,781},{57,815},{592,425},{434,657},{325,144},{242,418},{535,881},{648,539},{992,74},{214,851},{825,710},{676,58},{246,21},{270,886},{176,745},{664,873},{919,342},{57,195},{452,251},{829,537},{94,33},{854,56},{218,585},{489,590},{402,411},{639,611},{593,305},{370,241},{983,739},{407,887},{391,429},{686,77},{275,340},{160,783},{300,479},{904,897},{259,62},{809,667},{835,740},{71,785},{286,100},{218,252},{255,943},{534,450},{477,562},{730,586},{931,499},{131,166},{330,572},{993,115},{741,781},{225,653},{507,453},{307,973},{618,829},{270,614},{42,205},{955,839},{544,208},{342,287},{661,55},{459,651},{187,787},{617,481},{320,392},{922,374},{167,991},{263,455},{218,406},{86,833},{696,562},{147,311},{579,978},{382,536},{521,719},{153,890},{814,307},{382,847},{5,132},{839,452},{332,382},{125,255},{612,431},{774,562},{281,597},{299,553},{628,109},{268,156},{831,386},{976,502},{835,711},{589,599},{559,151},{296,734},{705,124},{540,473},{78,17},{459,885},{213,604},{805,983},{709,442},{876,770},{483,542},{12,853},{448,957},{960,638},{100,548},{61,601},{717,460},{386,800},{824,142},{175,943},{764,561},{477,32},{615,731},{195,677},{278,311},{163,753},{400,160},{417,611},{675,268},{696,715},{11,350},{900,626},{219,717},{677,771},{502,356},{257,68},{637,976},{647,81},{276,736},{197,846},{860,39},{168,41},{619,5},{333,379},{680,716},{310,820},{456,663},{984,225},{790,266},{224,421},{187,182},{238,960},{632,456},{658,663},{921,488},{935,28},{503,224},{199,562},{19,743},{259,25},{795,11},{302,494},{935,260},{533,114},{261,233},{390,38},{640,975},{210,567},{849,695},{397,578},{100,715},{904,990},{569,769},{198,323},{511,887},{64,493},{570,78},{926,367},{444,804},{692,593},{451,25},{988,727},{213,707},{402,98},{480,53},{868,957},{325,997},{553,233},{624,361},{769,680},{790,743},{595,300},{975,150},{117,948},{2,805},{657,118},{473,646},{859,969},{167,820},{337,170},{907,313},{113,98},{524,225},{569,652},{195,232},{445,840},{402,69},{266,837},{599,688},{366,401},{102,252},{76,770},{44,42},{541,964},{988,289},{447,713},{525,311},{543,767},{265,125},{859,663},{426,156},{223,963},{955,737},{344,48},{600,643},{14,602},{774,4},{515,65},{16,236},{867,467},{722,487},{530,516},{404,504},{937,868},{166,731},{276,980},{359,519},{214,250},{256,198},{981,315},{416,514},{584,456},{407,536},{531,328},{499,914},{814,92},{70,926},{139,68},{992,854},{817,979},{842,753},{13,711},{494,553},{857,752},{198,860},{46,398}};
    for(int x:soln.getOrder(v))
        cout<<x<<',';
}
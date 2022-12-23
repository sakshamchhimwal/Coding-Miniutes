/**
 * @file Heap.cpp
 * @author Saksham Chhimwal(210010046@iitdh.ac.in)
 * @brief This program contins the code for heapifying an array
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * @brief This is the struct used for creating a min heap;
 * 
 */
struct node{
    int value;
    int elementIndex;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

class heap{
    private:
        node *head=NULL;
        node *tail=head;
        /**
         * @brief Get the Head object
         * 
         * @return node* 
         */
        node* getHead(){
            return this->head;
        }
        /**
         * @brief Heapify The Heap
         * 
         * @param head 
         */
        void heapify(node** head,node** tail){
            node* copy = *tail;
            int elementIndex=(*tail)->elementIndex;
            int parentValueInLinkedList;
            elementIndex%2==0?parentValueInLinkedList=elementIndex/2:parentValueInLinkedList=(elementIndex-1)/2;
            for(int i=0;i<elementIndex-parentValueInLinkedList;i++){
                copy=copy->prev;
            }
            if(copy->value>(*tail)->value){
                int tempval=copy->value;
                int tempindex=copy->elementIndex;
                copy->value=(*tail)->value;
                copy->elementIndex=(*tail)->elementIndex;
                (*tail)->value=tempval;
                (*tail)->elementIndex=tempindex;
            }
        }
        /**
         * @brief Set the Heap object
         * 
         * @param array 
         */
        void setHeap(vector<int> array){
            int elementIndex=1;
            for(int x:array){
                elementIndex++;
                if(head==NULL){
                    node *newNode;
                    newNode=(node *)malloc(sizeof(node));
                    newNode->value=x;
                    newNode->next=NULL;
                    newNode->prev=NULL;
                    newNode->elementIndex=elementIndex;
                    head=newNode;
                    tail=newNode;
                }else{
                    node *newNode;
                    newNode=(node *)malloc(sizeof(node));
                    newNode->value=x;
                    newNode->next=NULL;
                    newNode->prev=tail;
                    newNode->elementIndex=elementIndex;
                    tail->next=newNode;
                    tail=newNode;
                    heapify(head,tail);
                }
            }
        }
    public:
        /**
         * @brief Make Min Heap Object
         * 
         * @param array 
         * @return node* 
         */
        node* makeHeap(vector<int> array){
            this->setHeap(array); 
            return this->getHead();
        }
};
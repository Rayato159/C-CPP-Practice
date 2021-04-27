#include <iostream>
#include <cstdlib>
#ifndef QueueCPP_h
#define QueueCPP_h

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
    private:
        int size; 
        int front, rear;
        Node **Q;
    public:
        Queue(int size){
            this->size = size+1;
            front = rear = 0;
            Q = new Node*[this->size];
        }

        bool isFull(){
            return (rear+1)%size==front;
        }

        bool isEmpty(){
            return rear==front;
        }

        void enqueue(Node *x){
            if(isFull()){
                std::cout << "Queue is full." << std::endl;
            }
            else{
                rear = (rear+1)%size;
                Q[rear] = x;
            }
        }

        Node* dequeue(){
            Node *x = NULL;
            if(isEmpty()){
                std::cout << "Queue is empty" << std::endl;
            }
            else{
                front = (front+1)%size;
                x = Q[front];
            }
            return x;
        }

        void display(){
            int i=front+1;
            do{
                std::cout << Q[i] << " " << std::flush;
                i=(i+1)%size;
            }while(i!=(rear+1)%size);
            std::cout << std::endl;
        }
};

#endif
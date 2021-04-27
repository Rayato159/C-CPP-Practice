#include <iostream>
#include <cstdlib>
using namespace std;

class Queue{
    private:
        int size; 
        int front, rear;
        int *Q;
    public:
        Queue(int size){
            this->size = size+1;
            front = rear = 0;
            Q = new int[this->size];
        }

        bool isFull(){
            return (rear+1)%size==front ? true: false;
        }

        bool isEmpty(){
            return rear==front ? true: false;
        }

        void enqueue(int x){
            if(isFull()){
                cout << "Queue is full." << endl;
            }
            else{
                rear = (rear+1)%size;
                Q[rear] = x;
            }
        }

        int dequeue(){
            int x = -1;
            if(isEmpty()){
                cout << "Queue is empty" << endl;
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
                cout << Q[i] << " " << flush;
                i=(i+1)%size;
            }while(i!=(rear+1)%size);
            cout << endl;
        }
};

int main(){
    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();

    q.display();

    return 0;
}
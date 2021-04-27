#include <iostream>
#include <cstdlib>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new int[this->size];
        }

        void enqueue(int x){
            if(rear == size-1){
                cout << "Queue is full." << endl;
            }
            else{
                rear++;
                Q[rear] = x;
            }
        }

        int dequeue(){
            int x = -1;
            if(rear == front){
                cout << "Queue is empty." << endl;
            }
            else{
                front++;
                x = Q[front];
            }
            return x;
        }

        void display(){
            for(int i=front+1; i<=rear; i++){
                cout << Q[i] << " " << flush;
            }cout << endl;
        }
};

int main(){
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << q.dequeue() << endl;

    return 0;
}
/*
 * Solution 3: Circular Queue
 */
#include <bits/stdc++.h>
using namespace std;
class CircularQueue{int*data;int front,rear,size,cap;
public:
    CircularQueue(int k):cap(k),front(0),rear(-1),size(0){data=new int[k];}
    bool enqueue(int v){if(size==cap)return false;rear=(rear+1)%cap;data[rear]=v;size++;return true;}
    bool dequeue(){if(!size)return false;front=(front+1)%cap;size--;return true;}
    int getFront(){return size?data[front]:-1;}
    int getRear(){return size?data[rear]:-1;}
    bool isEmpty(){return size==0;}
    bool isFull(){return size==cap;}
};
int main(){
    CircularQueue cq(3);cq.enqueue(1);cq.enqueue(2);cq.enqueue(3);
    cout<<cq.isFull()<<"\n"; // 1
    cout<<cq.getRear()<<"\n"; // 3
    cq.dequeue();cq.enqueue(4);
    cout<<cq.getFront()<<"\n"; // 2
    return 0;
}

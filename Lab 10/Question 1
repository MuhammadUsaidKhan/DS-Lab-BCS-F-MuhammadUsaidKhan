#include <iostream>
#include <string>
using namespace std;
class Heap{
    private:
        int size = 0;
        int heap[100];
    public:
        
        void insert(int value){
            if (size==100){
                cout<<"Cannot Insert. Heap is full."<<endl;
                return;
            }
            else{
                heap[size] = value;
                heapifyup(size);
                size++;
            }
        }
        void swap(int *a, int *b){
            int temp=*a;
            *a = *b;
            *b = temp;
        }
        void update_key(int i, int new_val){
            heap[i] = new_val;
            if(heap[parent(i)]<new_val){
                heapifyup(i);
            }
            else{
                heapifydown(i);
            }
        }

        void heapifyup(int index){
            while(index!=0 && heap[index] > heap[parent(index)]){
                swap(&heap[index], &heap[parent(index)]);
                index = parent(index);
            }
        }
        void heapifydown(int index){
            int largest = index;
            int l = lchild(index);
            int r = rchild(index);
            if(l< size && heap[l]>heap[largest]){
                largest = l;
            }
            if(r< size && heap[r]>heap[largest]){
                largest = r;
            }
            if(largest!=index){
                swap(&heap[index], &heap[largest]);
            heapifydown(largest);
            }
            while(index!=0 && heap[index] > heap[parent(index)]){
                swap(&heap[index], &heap[parent(index)]);
                index = parent(index);
            }
            }
        int parent(int i){
            return (i-1)/2;
        }
        int lchild(int i){
            return (2*i)+1;
        }
        int rchild(int i){
            return (2*i)+2;
        }
        void deleteheap(){
            if(size==0){
                cout<<"Heap is empty";
                return;
            }
            else{
                heap[0]= heap[size-1];
                size--;
                heapifydown(0);
            }
        }
};
int main() {
    return 0;
}

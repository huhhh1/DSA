#include <bits/stdc++.h>
using namespace std;

//  For Extract MAX value in heap
/*
-- Save max value
-- Copy last to root
-- remove last
    decrease Heap size
-- Heapify Root

//
Extract_max(heap){          T = O(log(n)) s = O(log(n))
    if(heap.size()<1)   return
    max = heap[0];
    heap[0] = heap[size()-1];
    heap_size = size() - 1;
    Max_heapifiy (Heap,0);
    return max;
}
*/

// For Increase Value
/*
-- Update node value
-- Percolate Up Alogo
     -- parrent > child
     -- Child node becom root of tree
 //
     Heap_increase(heap,i,key){         T = o(log(n))  S = O(1)
         if(key < a[i]){
             heap[i] = key;
             while(i>0 &&heap[i/2]<heap[i]){
                 swap(heap[i],heap[i/2])
                 i=i-1/2;
             }
         }
     }
*/

// for decrease key
/*
-- Decrease node value
-- Max_heapify node value
    -- percolate down
    //
    heap_Decrease(heap,i,key){      T = O(log(n)) S = O(log(n))
        if(heap[i]>key) return;
        heap[i]=key;
        max_heapify(heap,i);
    }
*/
// For Insert Element in heap
/*
    // note : Applicable for Complete Binary tree
-- insert node at the end of the Heap (left to the right Ordere)
-- Perculate Up Algo:   // same as increase key
    -- parrent > Child
    -- curr_node is root of tree
    //
    insert_heap(heap,key){          T = O(log(n))  S = O(1)
        size()++;
        heap[size()-1]=key;
        int i = size()-1;
        while(i>0 && heap[i-1/2]<heap[i])
        {
            swap([heap[i],heap[i-1/2]]);
            i=i/2;
        }
    }
*/

void Heapify(vector<int> &heap, int i, int size)
{
    int current = i;
    int left = i * 2 + 1;
    int rigth = i * 2 + 2;
    if (left < size && heap[left] > heap[current])
        current = left;

    if (rigth < size && heap[rigth] > heap[current])
        current = rigth;

    if (i != current)
    {
        swap(heap[i], heap[current]);
        Heapify(heap, current, size);
    }
};

void MaxHeapify(vector<int> &heap)
{
    int s = heap.size();
    for (int i = floor(s / 2) - 1; i >= 0; --i)
        Heapify(heap, i, s);
}

int Extract_Max(vector<int> &heap)
{
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    MaxHeapify(heap);
    return max;
}
void increse(vector<int> &heap, int inde, int key)
{
    if (heap[inde] < key && inde < heap.size())
    {
        heap[inde] = key;
        while (inde > 0 && heap[floor((inde - 1) / 2)] < heap[inde])
        {
            swap(heap[inde], heap[floor((inde - 1) / 2)]);
            inde = floor((inde - 1) / 2);
        };
    }
    return;
}
void Decrease(vector<int> &heap, int index, int key){
    if (heap[index] > key && index >= 0)
    {
        heap[index] = key;
        int current = index;
        int left = index * 2 + 1;
        int rigth = index * 2 + 2;
        if (index < heap.size() && heap[left] > heap[current])
            current = left;
        if (index < heap.size() && heap[rigth] > heap[current])
            current = rigth;
        if (current != index)
        {
            swap(heap[index], heap[current]);
            Decrease(heap, current, key);
        }
    }
    return;
}
void percolateUp(vector<int> &heap, int i)
{
    int p = (i - 1) / 2;
    while (heap[i] > heap[p] && i > 0)
    {
        swap(heap[i], heap[p]); 
        i = p;
        p = (i - 1) / 2;
    }
    return;
}



void insert(vector<int> &heap, int key)
{
    heap.push_back(key);
    int i = heap.size() - 1;
    percolateUp(heap, i);
}

void push(vector<int> &heap, int key)
{
    heap.push_back(key);
    int i = heap.size() - 1;
    percolateUp(heap, i);
    return;
}

int pop(vector<int> &heap)
{
    if (heap.size() == 0)
        return -1;
    int item = heap[0];
    heap[0] = heap[heap.size() - 1];
    MaxHeapify(heap);
    return item;
}

int main(){
    
    return 0;
}

//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int popIdx = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return popIdx;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1) / 2;
        while (pos > 0 && weightArr[data[parent]] > weightArr[data[pos]]) {
            swap(data[pos], data[parent]);
            pos = parent;
            parent = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            if (left >= size) break; // no children

            int smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[left]]) {
                smallest = right;
            }

            if (weightArr[data[pos]] <= weightArr[data[smallest]]) break;

            swap(data[pos], data[smallest]);
            pos = smallest;
        }
    }
};



//Implemented heap push/pop.
#endif
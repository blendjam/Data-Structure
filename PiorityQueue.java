package com.example.java;

public class PQueue {
    private int size = 0;
    private int minIndex = 0;
    DynamicArray<Integer> blob = new DynamicArray<Integer>(10);

    public void add(int data) {
        blob.add(data);
        size++;
        if (data <= blob.get(minIndex)) minIndex = size - 1;
    }

    public int getMinIndex() {return minIndex;}

    public int peekMin(){
        return blob.get(minIndex);
    }

    public void removeMin() {
        blob.removeMin(minIndex);
        size--;
    }

    public void printQueue() {
        blob.printArray();
    }

    public int size(){ return size; }
}

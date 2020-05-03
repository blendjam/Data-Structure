package com.example.java;

//Functions we must have in an Array
/**
 1)int size()
 2)Object get(int index) -> to return the value
 3)void add(Object obj) -> add to the array
 4)void add(Object obj, int index) -> add to an index
 5)Object remove(int index) -> remove from an index
 */

public class DynamicArray<T>{
    private T[] values;
    private int size = 0;//Not the size of the array but the no of values in the array
    private int capacity = 0;

    public DynamicArray(int capacity){this.capacity = capacity;
        values = (T[]) new Object[capacity];
    }
    public int size(){
        return this.size;
    }

    public T get(int index){
        if(index >= size)
            throw new IllegalArgumentException();
        return values[index];
    }

    public void printArray(){
        for(int i = 0; i < size; i++){
            System.out.println(values[i]);
        }
    }

    public void add(T data){
        ifFull();
        values[size++] = data;
    }

    public void addAt(int index, T data){
        ifFull();
        values[index] = data;
        size++;
    }

    public void remove(int index){
        for(int i = index; i < size - 1; i++){
            values[i] = values[i + 1];
        }
        size--;
    }

    public void removeMin(int minIndex){
        values[minIndex] = values[size - 1];
    }

    private void ifFull(){
        T[] bigger = (T[]) new Object[size * 2];
        if(size <= values.length) return;
        for(int i = 0; i < size; i++)
            bigger[i] = values[i];
        values = bigger;
    }

}


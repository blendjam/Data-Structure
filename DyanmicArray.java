package com.example.java;

//Functions we must have in an Array
/**
 1)int size()
 2)Object get(int index) -> to return the value
 3)void add(Object obj) -> add to the array
 4)void add(Object obj, int index) -> add to an index
 5)Object remove(int index) -> remove from an index
 */

public class DyanmicArray {
    private int[] values;
    private int size;//Not the size of the array but the no of values in the array

    public DyanmicArray(int length){ values = new int[length];}

    public int size(){
        return this.size;
    }

    public int get(int index){
        if(index >= size)
            throw new IllegalArgumentException();
        return values[index];
    }

    public void printArray(){
        for(int i = 0; i < size; i++){
            System.out.println(values[i]);
        }
    }

    public void add(int data){
        ifFull();
        values[size++] = data;
    }

    public void remove(int index){
        for(int i = index; i < size - 1; i++){
            values[i] = values[i + 1];
        }
        size--;
    }

    private void ifFull(){
        int[] bigger = new int[size * 2];
        if(size <= values.length) return;
        for(int i = 0; i < size; i++)
            bigger[i] = values[i];
        values = bigger;
    }

}


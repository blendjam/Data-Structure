package com.example.java;

import java.util.List;
import java.util.Map;

public class Hash{
    public static final int MAX_SIZE = 12;

    private int size = 0;
    private int data;
    private String names;
    private int[] IDs = new int[MAX_SIZE];

    public int size(){return size;}

    public boolean isEmpty(){return size == 0;}

    public Hash(){
        for (int i = 0; i < MAX_SIZE; i++)
            IDs[i] = -1;
    }

    public int hash(String name){
        int hash = 0;
        for(int i = 0; i < name.length(); i++)
            hash = name.charAt(i) + hash * name.charAt(i);
        hash = hash & 0x7fffffff;
        return hash % MAX_SIZE;
    }

    public void put(String name, int key){
        int index = hash(name);
        if(IDs[index] ==  -1 )
            IDs[index] = key;
        size++;
    }

    public int get(String name){
        int index = hash(name);
        if(IDs[index] == -1) throw new IllegalArgumentException();
        return IDs[index];
    }

    public void remove(String name){
        int index = hash(name);
        if(IDs[index] == -1) throw new IllegalArgumentException();
        IDs[index] = -1;
        size--;

    }

    public void remove(int id){
        int i = 0;
        while(IDs[i] != id){i++;}
        IDs[i] = -1;
    }

    public void printTable(){
        System.out.println("Start : ");
        for(int i = 0; i < MAX_SIZE; i++) {
            if(IDs[i] == -1)
                System.out.println("\t" + i + "\t---");
            else
                System.out.println("\t" + i + "\t" + IDs[i]);

        }
        System.out.println("End");
    }
}

package com.example.java;

public class LinkedList {
    private int size = 0;
    private Node head;

    private class Node {
        String data;
        Node next;
    }

    public int size() {return size;}

    public void insert(String newData){
        Node newNode = new Node();
        newNode.data = newData;
        newNode.next = null;
        if(head == null)
            head = newNode;
        else{
            Node temp = head;
            while(temp.next != null)
                temp = temp.next;
            temp.next = newNode;
        }
        size++;
    }

    public void insertFirst(String newData){
        Node newNode = new Node();
        newNode.data = newData;
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void printList(){
        Node temp = head;
        while(temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public void get(int index){
        Node temp = head;
        for(int i = 0; i < index;i++)
            temp = temp.next;
        System.out.println(temp.data);
    }

    public void remove(int index){
        Node temp = head;
        for(int i = 0; i < index - 1; i++)
            temp = temp.next;
        temp.next = temp.next.next;
        size--;
    }

    public void clear(){
        head = null;
        size = 0;
    }
}


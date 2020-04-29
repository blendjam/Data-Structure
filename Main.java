package com.example.java;
/**
 1)int size()
 2)Object get(int index) -> to return the value
 3)void add(Object obj) -> add to the array
 4)void add(Object obj, int index) -> add to an index
 5)Object remove(int index) -> remove from an index
 */

public class Main {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insert("Sanket");
        list.insert("Well Done");
        list.insert("Sanyog");
        list.insert("Binta");
        list.insert("Milan");
        list.printList();
        System.out.println(list.size());
        list.get(0);
        list.remove(1);
        System.out.println("After removing the index 1: ");
        list.printList();
        System.out.println("After adding in first: ");
        list.insertFirst("Atmaja");
        list.printList();
    }

}

package com.example.java;

import java.util.*;

/**
 1)int size()
 2)Object get(int index) -> to return the value
 3)void add(Object obj) -> add to the array
 4)void add(Object obj, int index) -> add to an index
 5)Object remove(int index) -> remove from an index
 */

public class Main {
    public static void main(String[] args) {
        Stack<Character> stack = new Stack<>();
        String bra = "{()}[{}()]";
        int len = bra.length();

        for(int i = 0; i < len; i++){
            if(bra.charAt(i) == '(' || bra.charAt(i) == '{' || bra.charAt(i) == '[')
                stack.push(bra.charAt(i));
            else if(!stack.isEmpty() &&
                    (bra.charAt(i) == '}' && stack.seek() == '{' ) ||
                    (bra.charAt(i) == ']' && stack.seek() == '[') ||
                    (bra.charAt(i) == ')' && stack.seek() == '(' )){
                stack.pop();
            }
        }
        if(stack.size() == 0)
            System.out.println("Balanced");
        else
            System.out.println("Not balanced");


    }
}


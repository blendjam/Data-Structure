package   com.example.java;

public class Stack<T>{
    LinkedList<T> list = new LinkedList<>();
    private int size = 0;

    public void push(T data){
        list.insertFirst(data);
        size++;
    }

    public void printStack(){
        list.printList();
    }

    public void pop(){
        list.remove(0);
        size--;
    }

    public T seek(){
        return list.get(0);
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public int size(){
        return size;
    }
}

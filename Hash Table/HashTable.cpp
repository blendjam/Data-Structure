#include <cstdlib>
#include <iostream>
using namespace std;
#define cap 13

int HashFunction(string key)
{
    int hash = 0;
    int index;
    for(int i = 0; i < key.length(); i++)
        hash += key[i] + 27 * key[i];
    index = hash & 0x7fffffff;
    return index % cap;
}

class Node{
    string key;
    int value;
    Node *next;
public: 
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    int getValue(){return value;}
    
    string getKey(){return key;}

    void setValue(int value){this->value = value;}

    void setNext(Node * next){this->next = next;}

    Node * getNext(){return next;}
};

class HashTable{
    Node ** table;
public:
    HashTable(){
        table = new Node*[cap];
        for(int i = 0; i < cap; i++)
            table[i] = NULL;
    }

    void add(string key, int value){
        int index = HashFunction(key);
        if(table[index] == NULL)
            table[index] = new Node(key, value);
        else
        {
            Node * temp = table[index];
            while (temp->getNext() != NULL) 
                temp = temp->getNext();
            if(temp->getKey() == key)
                temp->setValue(value);
            else
                temp->setNext(new Node(key, value));
        }
        
    }

    int get(string key){
        int index = HashFunction(key);
        if(table[index] == NULL)
            return -1;
        else{
            Node * temp = table[index];
            while (temp != NULL && temp->getKey() != key)
                temp = temp->getNext();
            if(temp == NULL)
                return -1;
            else
                return temp->getValue();
        }
        
    }

    void printTable(){
        cout<<endl;
        for(int i = 0; i < cap; i++)
        {
            Node * temp = table[i];
            cout<<"|"<< i <<" |";
            while (temp != NULL)
            {
                cout << "->|" << temp->getKey() << ", "<< temp->getValue()<<"|";\
                temp = temp->getNext();
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    HashTable h1;
    h1.add("Sanket", 35);
    h1.add("Sanyog",55);
    h1.add("Milan",55);
    h1.add("Binta",64);
    h1.add("Nice",88);
    h1.add("boy",44);
    h1.add("girl",00);
    h1.add("bond",34);
    h1.printTable();
    cout << h1.get("Milan")<<endl;
    cout << h1.get("bond");
    return 0;
}

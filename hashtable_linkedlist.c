#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct row{
    int key;
    int val;
    struct row *next;
};
struct table{
    int size;
    struct row **list;
};
struct table* createTable(int size){
    struct table *table1 = (struct table*)malloc(sizeof(struct table));
    table1->size = size;
    table1->list = (struct row**)malloc(size * sizeof(struct row*));
    memset(table1->list, ' ', size);
    return table1;
}
int hashCode(struct table *table1,int key){
    return abs(key%table1->size);
}
void insert(struct table *table1,int key,int val){
    int pos = hashCode(table1,key);
    struct row *list = table1->list[pos]; //stores the key, val and *next for the first occurence of hashcode in the hashtable; defined as *list because its an array of values - key, val and *next
    struct row *newNode = (struct row*)malloc(sizeof(struct row));
    newNode->key = key;
    newNode->val = val;
    newNode->next = list; //Passed by reference to allow the value change directly when a new hashcode is being used to insert  
    table1->list[pos] = newNode;
}
int lookup(struct table *table1,int key){
    int pos = hashCode(table1,key);
    struct row *list = table1->list[pos]; //stores the key, val and next of the first set matching the hashcode
    struct row *temp = list; //allows *list to be passed by value and not reference for the while loop  
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next; //scans every node on table after the first occurence matching the hashcode and returns the 'vals' for any matching the hashcode after that
    }
    return -1;
}

int main(){
    struct table *table1 = createTable(5);
    insert(table1,9,13);
    printf("%d\n",lookup(table1,9));
    return 0;	
}

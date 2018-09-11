#include <iostream>
using namespace std;
//g++ -o ll -Wall -ansi -pedantic -O0 -g linkedlist.cpp

typedef struct _node { //NODE
    char data;
    struct _node *prox;
}node;

typedef struct _lista { //LIST
    node *begin = NULL;
    node *end = NULL;
}list; 

//INSERT BACK
void insert(list *List,char data){
    //INSERT FIRST ELEMENT
    if(List->begin == NULL){
        List->begin = new node;
        List->end = List->begin;
        List->begin->data = data;
        List->begin->prox = NULL;
        cout << "Inseriu o primeiro!"<<endl;
    }
    else{
        //INSERT REMAINING ELEMENTS
        List->end->prox = new node;
        List->end = List->end->prox;
        List->end->data = data;
        List->end->prox = NULL;
        cout << "Inseriu!"<<endl;
    }

}
//REMOVE FRONT
void remove(list *List){
    if(List->begin){
        node *tmp = List->begin->prox;
        delete List->begin;
        List->begin = tmp;
        cout << "Removeu!"<<endl;
        if(!List->begin){List->begin = NULL;}
    }
}
//SHOW ELEMENTS OF LIST
void showElements(list *List){ 
    list *temp = List;
    while(temp->begin != NULL){
        cout << temp->begin->data <<endl;
        temp->begin = temp->begin->prox;
    }
}

//MERGE TWO LISTS BY THE BEGIN(HEADS)
_node* mergeLists(_node *headA, _node* headB)
{
    _node *result = NULL;
    _node **ptr = &result;
    while( headA || headB  ) {
        _node *temp = new _node;
        temp->prox = NULL;
        *ptr = temp;
        ptr = &temp->prox;
        if( headB == NULL || ( headA && headA->data < headB->data ) ) {
            temp->data = headA->data;
            headA = headA->prox;
        } else {
            temp->data = headB->data;
            headB = headB->prox;
        }
    }
    return result;
}

int main (){
    list *minhaLista = new list; //CREATE A NEW LIST
    list *segundaLista = new list;
    list *listaFinal = new list; 
    insert(minhaLista,'A');
    insert(minhaLista,'B');
    //remove(minhaLista);
    //remove(minhaLista);
    insert(segundaLista,'C');
    insert(segundaLista,'D');
    //insert(minhaLista,'E');
    //remove(minhaLista);
    //insert(minhaLista,'F');
    listaFinal->begin = mergeLists(minhaLista->begin,segundaLista->begin);
    showElements(listaFinal);
    return 0;
}
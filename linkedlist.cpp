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
void inserir(list *List,char data){
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
void remover(list *List){
    if(List->begin){
        node *tmp = List->begin->prox;
        delete List->begin;
        List->begin = tmp;
        cout << "Removeu!"<<endl;
        if(!List->begin){List->begin = NULL;}
    }
}
//SHOW ELEMENTS OF LIST
void ver(list *List){ 
    list *temp = List;
    while(temp->begin != NULL){
        cout << temp->begin->data <<endl;
        temp->begin = temp->begin->prox;
    }
}

int main (){
    list *minhaLista = new list; //CREATE A NEW LIST
    inserir(minhaLista,'A');
    inserir(minhaLista,'B');
    remover(minhaLista);
    remover(minhaLista);
    inserir(minhaLista,'C');
    inserir(minhaLista,'D');
    inserir(minhaLista,'E');
    remover(minhaLista);
    inserir(minhaLista,'F');
    ver(minhaLista);
    return 0;
}
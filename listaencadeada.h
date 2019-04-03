//
// Created by eduar on 02/04/2019.
//

#ifndef UNTITLED8_LISTAENCADEADA_H
#define UNTITLED8_LISTAENCADEADA_H


#include <iostream>
#include <list>
#include <string>

class Node{
public:
    int _v;
    Node *prox;

    Node(int v);
    Node();

    int obterValor();
    Node* obterProx();
    void setProx(Node* p);

};

class ListaEncadeada{
private:
    Node* _inicio;
    Node* _fim;
public:
    ListaEncadeada();
    ListaEncadeada(int v);

    ~ListaEncadeada();

    void setNode(Node* n);

    bool vazia();
    void insere_primeiro(int v);
    void insere_elemento(int v);
    int get_iesimo(int num);
    void inserir_iesimo(int num, int pos);
    void remover_iesimo(int pos);

};


#endif //UNTITLED8_LISTAENCADEADA_H

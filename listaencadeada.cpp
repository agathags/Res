//
// Created by eduar on 02/04/2019.
//

#include "listaencadeada.h"



    Node::Node(int v){
        this->_v = v;
        this->prox = nullptr;
    }
    Node::Node(){

    };

    int Node::obterValor(){
        return _v;
    }

    Node* Node::obterProx(){
        return prox;
    }

    void Node::setProx(Node* p){
        this->prox = p;
    }


    ListaEncadeada::ListaEncadeada(){
        _inicio = nullptr;
        _fim = nullptr;
    }

    ListaEncadeada::ListaEncadeada(int v){
        _inicio = new Node(v);
        _fim = _inicio;
    }

    ListaEncadeada::~ListaEncadeada(){
        delete _inicio;
    }

    void ListaEncadeada::setNode(Node* n){
        if(_inicio == nullptr){
            _inicio = n;
            _fim = _inicio;
        } else {
            _fim->setProx(n);
            _fim = n;
        }
    }

    bool ListaEncadeada::vazia(){
        return (_inicio == nullptr);
    }

    void ListaEncadeada::insere_primeiro(int v){
        if(vazia()){
            Node* aux = new Node(v);

            this->_inicio = aux;
            this->_fim = aux;
        } else {
            Node* aux = new Node(v);

            aux->setProx(this->_inicio);
            this->_inicio = aux;
        }
    }

    void ListaEncadeada::insere_elemento(int v){
        if(vazia()){
            insere_primeiro(v);
        } else {
            Node* aux = new Node(v);

            _fim->setProx(aux);
            this->_fim = aux;
        }
    }


    int ListaEncadeada::get_iesimo(int num){
        Node* aux = this->_inicio;
        for(int i = 0; i< num-1; i++){
            aux = aux->obterProx();
        }
        return aux->obterValor();
    }

    void ListaEncadeada::inserir_iesimo(int num, int pos){
        Node* aux = this->_inicio;
        Node* aux2;
        Node* novoNode = new Node(num);
        for(int i = 0; i< pos-2; i++){
            aux = aux->obterProx();
        }
        aux2 = aux->obterProx();

        aux->prox = novoNode;
        novoNode->prox = aux2;
    }

    void ListaEncadeada::remover_iesimo(int pos){
        Node* aux = this->_inicio;
        for(int i = 0; i< pos-2; i++){
            aux = aux->obterProx();
        }
        aux->prox = aux->obterProx()->obterProx();
    }
// abb.hpp
// Estrutura de uma Árvore Binária de Busca (ABB) com balanceamento AVL.
//
// The MIT License (MIT)
//
// Copyright (c) 2022 João Vicente Ferreira Lima, UFSM
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>

template<typename T>
struct Abb {
    T dado;         // o dado a ser guardado
    Abb<T>* esq;    
    Abb<T>* dir;
    int altura;        // valor de altura
};

template<typename T>
int abb_altura(Abb<T>* no)
{
    if(no == nullptr)
        return 0;
    return no->altura;
}

template<typename T>
int abb_get_fb(Abb<T>* no)
{
    if(no == nullptr)
        return 0;
    return (abb_altura(no->esq) - abb_altura(no->dir));
}

// Faz uma rotação a esquerda do nó x.
// Retorna o novo nó raiz (y).
template<typename T>
Abb<T>* abb_esq_rotate(Abb<T>* x)
{
    // TODO
    return x;
}

// Faz uma rotação a direita do nó x.
// Retorna o novo nó raiz (y).
template<typename T>
Abb<T>* abb_dir_rotate(Abb<T>* x)
{
    // TODO
    return x;
}

// inicia o no da arvore com valores nulos
template<typename T>
Abb<T>* abb_inicia(T v)
{
    Abb<T>* no = new Abb<T>;
    no->dado = v;
    no->altura = 1;
    no->esq = nullptr;
    no->dir = nullptr;

    return no;
}

// Insere um no pre-alocado na arvore
// - primeiro, verifica se a árvore é vazia
// - procura o nó adequado para inserção
// - atualiza a altura do nó recursivamente
// - verifica o balanceamento do nó e executa rotações necessárias
//
// Retorna o nó raiz, ou outro nó caso precisar de rotações.
template<typename T>
Abb<T>* abb_insere( Abb<T>* no, T v )
{
    if( no == nullptr )
        return abb_inicia(v);

    // o novo valor e menor que o meu?
    if(  v < no->dado )
        no->esq = abb_insere( no->esq, v );
    else if( v > no->dado ) // o novo valor e maior ou igual
        no->dir = abb_insere( no->dir, v );
    else 
        return no;

    no->altura = 1 + std::max(
        abb_altura(no->esq),
        abb_altura(no->dir)
    );

    // TODO

    return no;
}

template<typename T>
Abb<T>* abb_no_minimo( Abb<T>* no )
{
    Abb<T>* curr = no;
    while( curr->esq != nullptr )
        curr = curr->esq;
    return curr;
}

// Remove o nó de valor "v"
// - procura o nó adequado com o valor
// - se o nó tem uma sub-árvore, troca por ela.
// - senão, troca o nó pelo nó mais a esquerda da sub-árvore a direita
// - atualiza as alturas recursivamente
// - verifica se o nó precisa de balanceamento.
template<typename T>
Abb<T>* abb_remove( Abb<T>* no, T v )
{
    if( no == nullptr )
        return no;

    // TODO

    return no;
}

// faz o percurso pre-ordem.
// A visita e imprimir o valor de cada no
template<typename T>
void abb_emOrdem(Abb<T>* a)
{
    // primeiro esquerda
    if( a != nullptr ){
        abb_emOrdem(a->esq);
        std::cout << a->dado << "(" << a->altura << ") ";
        abb_emOrdem(a->dir);
    }
}   

template<typename T>
void abb_preOrdem(Abb<T>* a)
{
    // primeiro esquerda
    if( a != nullptr ){
        std::cout << a->dado << "(" << a->altura << ") ";
        abb_preOrdem(a->esq);
        abb_preOrdem(a->dir);
    }
}   

template<typename T>
void abb_destroi(Abb<T>* a)
{
    if(a != nullptr){
        abb_destroi(a->esq);
        abb_destroi(a->dir);
        delete a;
    }
}


#pragma once

#include <iostream>

template <typename TipoDato>
class ABB
{
    private:
        class NodoBin
        {
            public:
                TipoDato dato;
                NodoBin *izq;
                NodoBin *der;

                NodoBin(): izq(nullptr), der(nullptr){};
                NodoBin(TipoDato elemento) : dato(elemento), izq(nullptr), der(nullptr){};
        };
        typedef NodoBin *PuntNodoBin;
        PuntNodoBin miRaiz;

        void insertarAux(const TipoDato &elemento, PuntNodoBin &subRaiz);
        void preordenAux(PuntNodoBin subRaiz);
        bool buscarAux(const TipoDato &elemento, PuntNodoBin &subRaiz);
        void buscarParaEliminar(const TipoDato &elemento, bool &encontrado, PuntNodoBin &puntPost, PuntNodoBin &padre);

    public:
        ABB(): miRaiz(nullptr){};
        void insertar(const TipoDato &elemento);
        void preorden();
        bool buscar(const TipoDato &elemento);
        void eliminar(const TipoDato &elemento);
};

template <typename TipoDato>
void ABB<TipoDato>::buscarParaEliminar(const TipoDato &elemento, bool &encontrado, PuntNodoBin &puntPost, PuntNodoBin &padre)
{
    puntPost = miRaiz;
    padre = nullptr;
    encontrado = false;

    while (!encontrado && puntPost != nullptr)
    {
        if (elemento < puntPost->dato)
        {
            padre = puntPost;
            puntPost = puntPost->izq;
        }
        else if (puntPost->dato < elemento)
        {
            padre = puntPost;
            puntPost = puntPost->der;
        }
        else
        {
            encontrado = true;
        }
    }
}

template <typename TipoDato>
void ABB<TipoDato>::eliminar(const TipoDato &elemento)
{
    bool encontrado;
    PuntNodoBin x, padre;
        
    buscarParaEliminar(elemento, encontrado, x, padre); //Se pasan los parametros para hacer la busqueda para eliminar

    if (!encontrado)    //Si no se encontro
    {
        std::cout<<"El elemento no esta en el arbol"<<std::endl;    //Imprime en pantalla
        return;
    }
    
    if (x->izq != nullptr && x->der != nullptr) //Si tiene dos hijos
    {
        PuntNodoBin sucx = x->der;  //sucx variable de tipo NodoBin
        padre=x;    //A padre se le asigna x
        while (sucx->izq != nullptr)    //Mientras sucx no sea null
        {
            padre=sucx; //A padre se le asigna sucx
            sucx = sucx->izq;   //Y sucx se le signa la izquierda de sucx
        }
        x->dato = sucx->dato;   //Al dato dex se le asigna el dato de sucx
        x=sucx; //Y se le asigna a x sucx
    }

    PuntNodoBin subArbol = x->izq;  //Apunta al hijo de x o null, subArbol variable de tipo NodoBin
    if (subArbol == nullptr)
    {
        subArbol = x->der;  //Si es null subArbol se le asigna x derecha
    }
    if (padre == nullptr)   //Si el padre es null
    {
        miRaiz = subArbol;     //La raiz es igual a subArbol
    }
    else if (padre->izq == x)   //Si la izquierda de padre es igual a x 
    {
        padre->izq = subArbol;  //A padre izquerda se le asigna subArbol
    }
    else
    {
        padre->der = subArbol;  //Sino se le aisgna derecha
    }

    delete x;   //Se hace delete a ese nodo
}

template <typename TipoDato>
bool ABB<TipoDato>::buscarAux(const TipoDato &elemento, PuntNodoBin &subRaiz)
{
    if (subRaiz == nullptr) //Si no se encontro regresa false
    {
        return false;
    }
    else if (elemento < subRaiz->dato)  //Si el elemento es menor que el dato de subRaiz
    {  
        return buscarAux(elemento, subRaiz->izq);   //Recursivamente se busca en la subRaiz izquierda
    }
    else if (subRaiz->dato < elemento)  //Si el dato de subRaiz es menor que el elemento
    {
        return buscarAux(elemento, subRaiz->der);   //Recursivamente se busca en la subRaiz derecha
    }
    else
    {
        return true;    //Regresa true en caso de encontrarlo
    }
}

template <typename TipoDato>
bool ABB<TipoDato>::buscar(const TipoDato &elemento)
{
    return buscarAux(elemento, miRaiz);
}

template <typename TipoDato>
void ABB<TipoDato>::preordenAux(PuntNodoBin subRaiz)
{
    if(subRaiz!=nullptr)    //Si hay elementos que mostrar
    {
        std::cout<<subRaiz->dato<<" ";  //Se imprime en pantalla el dato
        preordenAux(subRaiz->izq);  //Se recorre la subRaiz izquierda
        preordenAux(subRaiz->der);  //Se recorre el subRaiz derecha
    }
}

template <typename TipoDato>
void ABB<TipoDato>::preorden()
{
    preordenAux(miRaiz);
}

template <typename TipoDato>
void ABB<TipoDato>::insertarAux(const TipoDato &elemento, PuntNodoBin &subRaiz)
{
    if (subRaiz == nullptr) //Si subRaiz es igual a null es que no siguen elementos
    {
        subRaiz = new NodoBin(elemento);    //Se crea el nuevo nodo
    }
    else if (elemento < subRaiz->dato)  //Si el elemento a insertar es menor que el elemento de subRaiz
    {
        insertarAux(elemento, subRaiz->izq);    //Recursivamente se inserta en la subRaiz izquierda
    }
    else
    {
        insertarAux(elemento, subRaiz->der);    //Si no recursivamente se inserta en la subRaiz derecha
    }
}

template <typename TipoDato>
void ABB<TipoDato>::insertar(const TipoDato &elemento)
{
    insertarAux(elemento, miRaiz);
}

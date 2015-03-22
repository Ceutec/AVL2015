#include <iostream>

using namespace std;

class Nodo
{
public:
    int num;
    Nodo *izq,*der;
    Nodo(int num)
    {
        this->num = num;
        izq = NULL;
        der = NULL;
    }
};

class Arbol
{
public:
    Nodo* raiz;

    Arbol()
    {
        raiz=NULL;
    }

    void imprimir()
    {
        imprimir(raiz);
    }

    void imprimir(Nodo* actual)
    {
        if(actual==NULL)
            return;
        cout<<actual->num<<endl;
        imprimir(actual->izq);
        imprimir(actual->der);
    }

    void insertar(Nodo* nuevo)
    {
        if(raiz != NULL)
            insertar(raiz,nuevo);
        else
            raiz = nuevo;
    }

    void insertar(Nodo* actual, Nodo* nuevo)
    {
        if(nuevo->num < actual->num)
        {
            //Izq
            if(actual->izq == NULL)
            {
                //Insertar
                actual->izq = nuevo;
            }else
            {
                //LLamada recurisva
                insertar(actual->izq,nuevo);
            }
        }else
        {
            //Der
            if(actual->der == NULL)
            {
                //Insertar
                actual->der = nuevo;
            }else
            {
                //LLamada recursiva
                insertar(actual->der,nuevo);
            }
        }
    }

    void borrar(int num)
    {
        borrar(raiz,num);
    }

    void borrar(Nodo*actual,int num)
    {
        if(actual == NULL)
            return;

        if(actual->izq != NULL && actual->izq->num == num)//Lo encontre!
        {
            Nodo* nodo_a_borrar = actual->izq;
            cout<<"El padre tiene un hijo a borrar por la izq"<<endl;
            if(nodo_a_borrar->izq == NULL && nodo_a_borrar->der==NULL)//Soy hoja
            {
                cout<<"Soy una hoja"<<endl;
                actual->izq = NULL;
            }else if(nodo_a_borrar->izq != NULL && nodo_a_borrar->der == NULL)//Tengo solo 1 hijo
            {
                cout<<"Tengo un hijo izq"<<endl;
                actual->izq = nodo_a_borrar->izq;
            }else if(nodo_a_borrar->der != NULL && nodo_a_borrar->izq == NULL)//Tengo solo 1 hijo
            {
                cout<<"Tengo un hijo der"<<endl;
                actual->izq = nodo_a_borrar->der;
            }else//Tengo 2 hijos
            {
                Nodo* succesor=nodo_a_borrar->der;
                Nodo* padre_scuccesor = NULL;
                while(succesor->izq!=NULL)
                {
                    padre_scuccesor = succesor;
                    succesor=succesor->izq;
                }
                cout<<"Succesor: "<<succesor->num<<endl;
                actual->izq = succesor;
                succesor->izq = nodo_a_borrar->izq;
                succesor->der = nodo_a_borrar->der;

                if(padre_scuccesor!=NULL)
                {
                    padre_scuccesor->izq = NULL;
                }else
                {
                    succesor->der =NULL;
                }

            }
        }
        else if(actual->der != NULL && actual->der->num == num)//Lo encontre!
        {
            Nodo* nodo_a_borrar = actual->der;
            cout<<"El padre tiene un hijo a borrar por la der"<<endl;
            if(nodo_a_borrar->izq == NULL && nodo_a_borrar->der==NULL)//Soy hoja
            {
                cout<<"Soy una hoja"<<endl;
                actual->der = NULL;
            }else if(nodo_a_borrar->izq != NULL && nodo_a_borrar->der == NULL)//Tengo solo 1 hijo
            {
                cout<<"Tengo un hijo izq"<<endl;
                actual->der = nodo_a_borrar->izq;
            }else if(nodo_a_borrar->der != NULL && nodo_a_borrar->izq == NULL)//Tengo solo 1 hijo
            {
                cout<<"Tengo un hijo der"<<endl;
                actual->der = nodo_a_borrar->der;
            }else//Tengo 2 hijos
            {
                Nodo* succesor=nodo_a_borrar->der;
                Nodo* padre_scuccesor = NULL;
                while(succesor->izq!=NULL)
                {
                    padre_scuccesor = succesor;
                    succesor=succesor->izq;
                }
                cout<<"Succesor: "<<succesor->num<<endl;
                actual->der = succesor;
                succesor->izq = nodo_a_borrar->izq;
                succesor->der = nodo_a_borrar->der;

                if(padre_scuccesor!=NULL)
                {
                    padre_scuccesor->izq = NULL;
                }else
                {
                    succesor->der =NULL;
                }
            }
        }
        else
        {
            borrar(actual->izq,num);
            borrar(actual->der,num);
        }
    }
};

int main()
{
    Arbol a;
    a.insertar(new Nodo(10));
    a.insertar(new Nodo(5));
    a.insertar(new Nodo(20));
    a.insertar(new Nodo(3));
    a.insertar(new Nodo(7));
    a.insertar(new Nodo(15));
    a.insertar(new Nodo(6));
    a.insertar(new Nodo(30));
    a.borrar(20);
    a.imprimir();
    return 0;
}







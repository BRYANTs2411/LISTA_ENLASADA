#include <iostream>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void agregarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    void imprimirLista() {
        Nodo* actual = cabeza;
        while (actual) {
            cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    void liberarLista() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }

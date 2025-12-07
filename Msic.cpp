#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;    

struct Cancion{
    string nombre;
    string artista;
    int duracion;
    int anio;
    Cancion* next = nullptr;
};

struct ListaP{      //Lista con todas las canciones.
    Cancion* head = nullptr;

    void insertarCancion(ListaP*& head, Cancion nuevaCancion){
        Cancion* nuevo = new Cancion();
        nuevo->nombre = nuevaCancion.nombre;
        nuevo->artista = nuevaCancion.artista;
        nuevo->duracion = nuevaCancion.duracion;
        nuevo->anio = nuevaCancion.anio;

        if(head == nullptr){
            head = nuevo;
        }
        else{
            Cancion* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nuevo;
            nuevo->next = nullptr;
        }
    }

    void eliminarCancion(ListaP*& head, string nombreCancion){
        if(head == nullptr){
            cout << "No hay canciones en la biblioteca." << endl;
            return;
        }
        
        Cancion* temp = head;
        Cancion* prev = nullptr;
        while(temp != nullptr || temp->nombre != nombreCancion){
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr){
            cout << "Canción no encontrada." << endl;
            return;
        }

        temp = prev->next;
        prev->next = temp->next;
        delete temp;
        cout << "Canción " << temp->nombre << " eliminada." << endl;
    }

    void mostrarCanciones(ListaP* head){
        if(head == nullptr){
            cout << "No hay canciones en la biblioteca." << endl;
            return;
        }

        Cancion* temp = head;
        while(temp != nullptr){
            cout << "Nombre: " << temp->nombre << ", Artista: " << temp->artista << ", Duración: " << temp->duracion << " seg, Año: " << temp->anio <<endl;
            temp = temp->next;
        }
    }

};

struct Historial{       //Pila de canciones reproducidas.
    Cancion* top = nullptr;

    void push(Cancion* nuevaCancion){
        Cancion* nuevo = new Cancion();
        nuevo->nombre = nuevaCancion->nombre;
        nuevo->artista = nuevaCancion->artista;
        nuevo->duracion = nuevaCancion->duracion;
        nuevo->anio = nuevaCancion->anio;

        if(top == nullptr){
            top = nuevaCancion;
        }
        else{
            nuevaCancion->next = top;
            top = nuevaCancion;
        }
    }

    Cancion pop(ListaP* &pila){
        if(top == nullptr){
            cout << "El historial está vacío." << endl;
            return *top;
        }
        else{
            Cancion* temp = top;
            top = top->next;
            cout << "La última canción reproducida fue: " << temp->nombre << "de " << temp->artista << "." << endl;
            return *temp;
        }
    }
};

struct ColaRep{     //Cola de canciones por reproducir.
    Cancion* head = nullptr;
    Cancion* tail = nullptr;

    void encolar(Cancion* nuevaCancion){
        if(tail == nullptr){
            head = nuevaCancion;
            tail = nuevaCancion;
        }
        else{
            tail->next = nuevaCancion;
            tail = nuevaCancion;
        }
    }

    void reproducir(ColaRep* cola){
        if(head == nullptr){
            cout << "La cola de reproducción está vacía." << endl;
            return;
        }
        else{
            Cancion* temp = head;
            head = head->next;
            cout << "Reproduciendo: " << temp->nombre << " de " << temp->artista << "." << endl;
        }
    }

    void mostrarCola(ColaRep* cola){
        if(head == nullptr){
            cout << "La cola de reproducción está vacía." << endl;
            return;
        }
        else{
            Cancion* temp = head;
            cout << "A continuación:" << endl;
            while(temp != nullptr){
                cout << temp->nombre << " de " << temp->artista << endl;
            }
        }
    }

};


struct ListaDoble{      //Lista doblemente enlazada para álbumes, playlists, etc.
    Cancion* head = nullptr;
    Cancion* tail = nullptr;
    string nombreLista;
    int numCanciones;
    Cancion* next = nullptr;
    Cancion* prev = nullptr;

    void insertarCancion(ListaDoble*& head, Cancion nuevaCancion){
        Cancion* nuevo = new Cancion();
        nuevo->nombre = nuevaCancion.nombre;
        nuevo->artista = nuevaCancion.artista;
        nuevo->duracion = nuevaCancion.duracion;
        nuevo->anio = nuevaCancion. anio;

        if(head == nullptr){
            head = nuevo;
        }
        else{
            Cancion* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nuevo;
            nuevo->next = nullptr;
        }
    }

    void eliminarCancion(ListaDoble*& head, string NombreCancion){

    }

    void mostrarCanciones(ListaDoble* head){

    }

    void cambiarNombre(ListaDoble*& head, string nuevoNombre){
        cout << "El nombre actual es: " << head->nombreLista << "." << endl;
        cout << "Introduzca el nuevo nombre: ";
        cin >> nuevoNombre;
        head->nombreLista = nuevoNombre;
        cout << "El nombre ha sido cambiado exitosamente a: " << head->nombreLista << "." << endl;
    }

    void ordenarPorAnio(ListaDoble* head){

    }

    void ordenarPorArtista(ListaDoble* head){

    }

    void ordenarPorDuracion(ListaDoble* head){

    }

    void ordenarAlfabeticamente(ListaDoble* head){

    }
};

void mostrarMenu(){
    cout << "=== Servicio de Música MSIC ===" << endl;
    cout << "1. Agregar canción a la biblioteca" << endl;
    cout << "2. Eliminar canción de la biblioteca" << endl;
    cout << "3. Mostrar canciones en la biblioteca" << endl;
    cout << "4. Crear playlist/álbum" << endl;
    cout << "5. Modificar playlist/álbum" << endl;
    cout << "6. Agregar canción a la cola de reproducción / Reproducir canción" << endl;
    cout << "7. Mostrar cola de reproducción" << endl;
    cout << "8. Mostrar historial de canciones reproducidas" << endl;
    cout << "9. Salir" << endl;
}

void menuModificarLista(ListaDoble* lista){
    cout << "Seleccione una opción de modificación:" << endl;
    cout << "1. Cambiar nombre de la lista" << endl;
    cout << "2. Agregar canción" << endl;
    cout << "3. Eliminar canción" << endl;
    cout << "4. Ordenar canciones por año" << endl;
    cout << "5. Ordenar canciones por artista" << endl;
    cout << "6. Ordenar canciones alfabéticamente" << endl;
    cout << "7. Ordenar canciones por duración" << endl;
    cout << "8. Regresar al menú principal" << endl;
}

int main(){
    cout << "Msic data: " << obj.data << endl;
    
return 0;
}

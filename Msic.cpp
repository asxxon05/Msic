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

    void insertarCancion(Cancion*& head, Cancion nuevaCancion){
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

    void eliminarCancion(Cancion*& head, string nombreCancion){
        if(head == nullptr){
            cout << "No hay canciones en la biblioteca." << endl;
            return;
        }
        
        Cancion* temp = head;
        Cancion* prev = nullptr;
        while(temp != nullptr && temp->nombre != nombreCancion){
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

    void mostrarCanciones(Cancion* head){
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

    Cancion pop(Historial* &pila){
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

    void mostrarHistorial(Historial* pila){
        if(top == nullptr){
            cout << "El historial está vacío." << endl;
            return;
        }
        else{
            Cancion* temp = top;
            cout << "Historial de canciones reproducidas:" << endl;
            while(temp != nullptr){
                cout << temp->nombre << " de " << temp->artista << endl;
                temp = temp->next;
            }
        }
    }
};

struct ColaRep{     //Cola de canciones por reproducir.
    Cancion* head = nullptr;
    Cancion* tail = nullptr;

    void encolar(Cancion* nuevaCancion, ColaRep* cola){
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
    int tamanio;
    Cancion* next = nullptr;
    Cancion* prev = nullptr;

    void insertarCancion(Cancion*& head, Cancion nuevaCancion){
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
        tamanio++;
    }

    void eliminarCancion(Cancion*& head, string NombreCancion){
        if(head == nullptr){
            cout << "No hay canciones en la lista." << endl;
            return;
        }
        Cancion* temp = head;
        Cancion* prev = nullptr;
        while(temp != nullptr && temp->nombre != NombreCancion){
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
        cout << "Canción " << temp->nombre << " eliminada de la lista." << endl;
        tamanio--;
    }

    void mostrarCanciones(Cancion* head){
        if(head == nullptr){
            cout << "No hay canciones en la lista." << endl;
            return;
        }

        Cancion* temp = head;
        while(temp != nullptr){
            cout << "Nombre: " << temp->nombre << ", Artista: " << temp->artista << ", Duración: " << temp->duracion << "seg, Año: " << temp->anio << endl;
            temp = temp->next;
        }
    }

    void cambiarNombre(ListaDoble*& head, string nuevoNombre){
        cout << "El nombre actual es: " << head->nombreLista << "." << endl;
        cout << "Introduzca el nuevo nombre: ";
        cin >> nuevoNombre;
        head->nombreLista = nuevoNombre;
        cout << "El nombre ha sido cambiado exitosamente a: " << head->nombreLista << "." << endl;
    }

    void ordenarPorAnio(Cancion* head, int tamanio){
        int i,j,h,v;
        Cancion* temp = head;
        for(h = 1; h = tamanio/9; h= 3*h+1);
        for(; h > 0; h = h/3){
            for(i = h; i < tamanio; i++){
                while(temp != nullptr && j < i){
                    temp = temp->next;
                    j++;
                }
                v = temp->anio;
                Cancion* aux = temp;
                j = i;
                while(j > h && aux->anio > v){
                    aux = aux->next;
                    j = j-h;
                }
                aux->anio = v;
            }
        }
    }

    void ordenarPorArtista(Cancion* head, int tamanio){
        int i,j, min, temp;
        Cancion* actual = head;
        for(i = 0; i < tamanio - 1; i++){
            min = i;
            Cancion* siguiente = actual->next;
            for(j = i + 1; j < tamanio; j++){
                if(siguiente->artista < actual->artista){
                    min = j;
                }
            }
            if(min != i){
                swap(actual->artista, siguiente->artista);
                swap(actual->nombre, siguiente->nombre);
                swap(actual->duracion, siguiente->duracion);
                swap(actual->anio, siguiente->anio);
            }
        }
    }

    void ordenarPorDuracion(Cancion* head, int tamanio){
        int i,j, min, temp;
        Cancion* actual = head;
        for(i = 0; i < tamanio - 1; i++){
            min = i;
            Cancion* siguiente = actual->next;
            for(j = i + 1; j < tamanio; j++){
                if(siguiente->duracion < actual->duracion){
                    min = j;
                }
            }
            if(min != i){
                swap(actual->artista, siguiente->artista);
                swap(actual->nombre, siguiente->nombre);
                swap(actual->duracion, siguiente->duracion);
                swap(actual->anio, siguiente->anio);
            }
        }

    }

    void ordenarAlfabeticamente(Cancion* head){
        int i,j, min, temp;
        Cancion* actual = head;
        for(i = 0; i < tamanio - 1; i++){
            min = i;
            Cancion* siguiente = actual->next;
            for(j = i + 1; j < tamanio; j++){
                if(siguiente->nombre < actual->nombre){
                    min = j;
                }
            }
            if(min != i){
                swap(actual->artista, siguiente->artista);
                swap(actual->nombre, siguiente->nombre);
                swap(actual->duracion, siguiente->duracion);
                swap(actual->anio, siguiente->anio);
            }
        }
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

void menuModificarLista(){
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

Cancion registrarCancion(){
    Cancion nuevaCancion;
    cout << "Ingrese el nombre de la canción: ";
    cin.ignore();
    getline(cin, nuevaCancion.nombre);
    cout << "Ingrese el artista: ";
    getline(cin, nuevaCancion.artista);
    cout << "Ingrese la duración (en segundos): ";
    cin >> nuevaCancion.duracion;
    cout << "Ingrese el año de lanzamiento: ";
    cin >> nuevaCancion.anio;
    return nuevaCancion;   
}

int main(){

    int op, opModLista = 0;
    string ListaSelec;
    ListaP* biblioteca = new ListaP();
    ListaP* Playlists = new ListaP();
    Historial* historial = new Historial();
    ColaRep* colaReproduccion = new ColaRep();

    do{
        mostrarMenu();
        cin >> op;
        switch(op){
            case 1:     //Agregar canción a la biblioteca
                biblioteca->insertarCancion(biblioteca->head, registrarCancion());
                break;

            case 2:     //Eliminar canción de la biblioteca
                string nombreCancion;
                cout << "Ingrese el nombre de la canción a eliminar: ";
                cin.ignore();
                getline(cin, nombreCancion);
                biblioteca->eliminarCancion(biblioteca->head, nombreCancion);
                break;

            case 3:     //Mostrar canciones en la biblioteca
                biblioteca->mostrarCanciones(biblioteca->head);
                break;

            case 4:     //Crear playlist/álbum
                cout << "Ingrese el nombre de la nueva playlist/álbum: ";
                string ListaSelec;
                cin.ignore();
                getline(cin, ListaSelec);
                ListaDoble* nuevaLista = new ListaDoble();
                nuevaLista->nombreLista = ListaSelec;
                cout << "Playlist/álbum " << ListaSelec << " creada exitosamente." << endl;
                break;

            case 5:     //Modificar playlist/álbum
                cout << "Seleccione la lista a modificar: " << endl;
                getline(cin, ListaSelec);

                menuModificarLista();
                cin >> opModLista;
                switch(opModLista){
                    case 1:     //Cambiar nombre de la lista
                        cout << "Ingrese el nuevo nombre de la lista: ";
                        string ListaSelec;
                        cin.ignore();
                        getline(cin, ListaSelec);
                        nuevaLista->cambiarNombre(nuevaLista, ListaSelec);
                        cout << "Nombre cambiado exitosamente a " << ListaSelec << "."<< endl;
                        break;

                    case 2:     //Agregar canción
                        nuevaLista->insertarCancion(nuevaLista->head, registrarCancion());
                        cout << "Canción agregada exitosamente a la lista." << endl;
                        break;

                    case 3:     //Eliminar canción
                        string nombreCancionEliminar;
                        cout << "Ingrese el nombre de la canción a eliminar: ";
                        cin.ignore();
                        getline(cin, nombreCancionEliminar);
                        nuevaLista->eliminarCancion(nuevaLista->head, nombreCancionEliminar);
                        cout << "Canción eliminada exitosamente de la lista." << endl;
                        break;

                    case 4:     //Ordenar canciones por año
                        nuevaLista->ordenarPorAnio(nuevaLista->head, nuevaLista->tamanio);
                        cout << "Canciones ordenadas por año exitosamente." << endl;
                        break;
                    case 5:     //Ordenar canciones por artista
                        nuevaLista->ordenarPorArtista(nuevaLista->head, nuevaLista->tamanio);
                        cout << "Canciones ordenadas por artista exitosamente." << endl;
                        break;

                    case 6:     //Ordenar canciones alfabéticamente
                        nuevaLista->ordenarAlfabeticamente(nuevaLista->head);
                        cout << "Canciones ordenadas alfabéticamente exitosamente." << endl;
                        break;

                    case 7:     //Ordenar canciones por duración
                        nuevaLista->ordenarPorDuracion(nuevaLista->head, nuevaLista->tamanio);
                        cout << "Canciones ordenadas por duración exitosamente." << endl;
                        break;
                    case 8:     //Regresar al menú principal
                        break;
                    default:
                        cout << "Opción inválida. Regresando al menú principal." << endl;
                }
                break;
            case 6:     //Agregar canción a la cola de reproducción / Reproducir canción
                cout << "1. Agregar canción a la cola de reproducción" << endl;
                cout << "2. Reproducir canción" << endl;
                int subOp;
                cin >> subOp;
                if(subOp == 1){
                    string nombreCancionCola;
                    cout << "Ingrese el nombre de la canción a agregar a la cola: ";
                    cin.ignore();
                    getline(cin, nombreCancionCola);
                    Cancion* temp = biblioteca->head;
                    while(temp != nullptr){
                        if(temp->nombre == nombreCancionCola){
                            colaReproduccion->encolar(temp, colaReproduccion);
                            cout << "Canción agregada a la cola de reproducción." << endl;
                            break;
                        }
                        temp = temp->next;
                    }
                }
                else if(subOp == 2){
                    colaReproduccion->reproducir(colaReproduccion);
                }
                else{
                    cout << "Opción inválida." << endl;
                }
                break;

            case 7:     //Mostrar cola de reproducción
                colaReproduccion->mostrarCola(colaReproduccion);
                break;

            case 8:     //Mostrar historial de canciones reproducidas
                historial->mostrarHistorial(historial);
                break;

            case 9:     //Salir alaverga
                cout << "Saliendo del programa." << endl << "Gracias por usar nuestro servicio :)" << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while(op != 9);

    return 0;
}

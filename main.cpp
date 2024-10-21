#include <iostream>
#include <unistd.h>  // Para fork()
#include <vector>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include <sys/wait.h>  // Para wait()

using namespace std;

// Variable global
vector<string> nombres;

void agregarNombre() {
    string nombre;
    cout << "Introduce un nombre: ";
    cin >> nombre;
    nombres.push_back(nombre);  // Añadimos el nombre al vector
}

void mostrarNombreAleatorio() {
    
    int indice = rand() % nombres.size();  // Elegir un índice aleatorio
    cout << "Proceso " << getpid() << ": Nombre elegido aleatoriamente -> " 
                  << nombres[indice] << endl;
    
}

int main() {
    int N;
    cout << "Introduce el número de procesos a crear: ";
    cin >> N;

    srand(time(0));  // Inicializamos el generador de números aleatorios
    pid_t pid;
    for (int i = 0; i < N; i++) {
        pid = fork();

        if (pid == 0) {  // Proceso hijo
            agregarNombre();
            mostrarNombreAleatorio();

            return 0;  // El proceso hijo termina aquí
        } else {
            wait(nullptr); 

            
        }

    }


    return 0;
}
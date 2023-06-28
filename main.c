#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
///VARIABLES GLOBALES:
const int DIM = 50;
///ESTRUCTURA:
typedef struct {
int matricula;
char nombre[30];
char genero; ///m, f, o
}Alumno;

///PROTOTIPADO:
void mostrarMenu();
Alumno modularizarCargarStruct();
void mostrarStruct(Alumno alumnos[], int validos);
void modularizacionMostrarStruct(Alumno alumnos);
void mostrarDatosPorMatricula(Alumno alumnos[], int validos, int matricula);
void modularizacionDatosPorMatricula(Alumno alumnos[], int i);
void ordenacionSeleccion(Alumno alumnos[], int validos);
int posicionMenor(Alumno alumnos[], int pos, int validos);
void mostrarSegunElGenero(Alumno alumnos[], int validos, char genero);
void modularizarSegunGenero(Alumno alumnos[], int i);
int cargarUnSoloAlumnoMas(Alumno alumnos[], int validos);
void ordenamientoXinsercion(Alumno alumnos[], int validos);
void insertar(Alumno alumnos[], int posicionBusqueda, Alumno alumnos1);
int cantidadAlumnosSegunGenero(Alumno alumnos[], int validos, char genero);

int main()
{


///VARIABLES ANTES DEL SWICH:
int validos;
Alumno alumnos[DIM];
char datoGenero, contarSegunGenero;
int validosNuevo, resultado;
///Matricula para mostrar sus datos:
int matricula;
    int salirMenu = 0;
    int eleccion;
    char continuar = 's';

    while(continuar == 's'){
        mostrarMenu(); ///Mostrando los ejercicios
        printf("\n");
        printf("Introduzca el numero correspondiente a cada ejercicio: ");
        fflush(stdin);
        scanf("%i", &eleccion);
        printf("\n");


    switch(eleccion){
        case 0:
        break;
        case 1:
        validos = cargarStruct(alumnos);
        break;

        case 2:
        mostrarStruct(alumnos, validos);
        break;

        case 3:
        printf("\nIngrese su numero de matricula: ");
        fflush(stdin);
        scanf("%i", &matricula);
        printf("\n\n");
        mostrarDatosPorMatricula(alumnos, validos, matricula);
        break;

        case 4:
            ordenacionSeleccion(alumnos, validos);
            printf("\n\nMOSTRANDO LOS ALUMNOS YA ORDENADOS: ");
            printf("\n\n");
            mostrarStruct(alumnos, validos);
        break;

        case 5:
            printf("\nIngrese el genero: ");
            fflush(stdin);
            scanf("%c", &datoGenero);
            printf("\n");
            mostrarSegunElGenero(alumnos, validos, datoGenero);
        break;

        case 6:
            ordenacionSeleccion(alumnos, validos);
            mostrarStruct(alumnos, validos);
            printf("\n\n");
            validos = cargarUnSoloAlumnoMas(alumnos, validos);
            printf("\n\n");
            mostrarStruct(alumnos, validos);
            printf("\n\n");
        break;

        case 7:
        break;

        case 8:
            printf("\nIngrese el genero: ");
            fflush(stdin);
            scanf("%c", &contarSegunGenero);
            printf("\n");
            resultado = cantidadAlumnosSegunGenero(alumnos, validos, contarSegunGenero);
            printf("\n\nLa cantidad de alumnos del genero %c son: %i ", contarSegunGenero, resultado);
        break;

        default:
        printf("\nNumero ingresado invalido\n");
        break;
        }

        printf("\n\nPulsa 0 si desea salir del menu: ");
        fflush(stdin);
        scanf("%i", &salirMenu);

        printf("\n\nPulsa 's' si desea seguir en el menu: ");
        fflush(stdin);
        scanf("%c", &continuar);

    }
return 0;

}
///FUNCIONES:
///Mostrar los ejercicios:
void mostrarMenu(){
    printf("\n1) Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.\n");
    printf("\n2) Hacer una funcion que muestre un arreglo de alumnos por pantalla. Modularizar.\n");
    printf("\n3) Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula.\n");
    printf("\n4) Hacer una funcion que ordene el arreglo de alumnos por medio del método de seleccion. El criterio de ordenacion es el numero de matricula.\n");
    printf("\n5) Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro)\n");
    printf("\n6) Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato,conservando el orden.\n");
    printf("\n7) Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de insercion. El criterio de ordenacion es el nombre.\n");
    printf("\n8) Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado(se envia por parametro) que tiene un arreglo de alumnos.\n");
}
///PUNTO 1:
int cargarStruct(Alumno alumnos[]){
        int i = 0;
        char eleccion = 's';

        while(eleccion == 's' && i < DIM){

            alumnos[i] = modularizarCargarStruct(); ///Modularizando la funcion cargar
            i++;
            printf("\n Pulsa 's' si desea continuar: ");
            fflush(stdin);
            scanf("%c", &eleccion);
            printf("\n");
        }
        return i;
    }

Alumno modularizarCargarStruct(){

        Alumno nuevoAlumno;

        printf("Ingrese su matricula: ");
        fflush(stdin);
        scanf("%i", &nuevoAlumno.matricula);

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(nuevoAlumno.nombre);

        printf("Ingrese su genero: ");
        fflush(stdin);
        scanf("%c", &nuevoAlumno.genero);

        return nuevoAlumno;
    }

///PUNTO 2:
void mostrarStruct(Alumno alumnos[], int validos){
    int i;
    for(i = 0; i < validos; i++){
        modularizacionMostrarStruct(alumnos[i]);
    }
}
void modularizacionMostrarStruct(Alumno alumnos){
    printf("| Matricula: %i |", alumnos.matricula);
    printf("| Alumno: %s |", alumnos.nombre);
    printf("| Genero: %c |", alumnos.genero);
    printf("\n");
}
///PUNTO 3:
void mostrarDatosPorMatricula(Alumno alumnos[], int validos, int matricula){
    int i;
    for(i =  0; i < validos; i++){
        if(alumnos[i].matricula == matricula){
            modularizacionDatosPorMatricula(alumnos, i);
        }
    }
}
void modularizacionDatosPorMatricula(Alumno alumnos[], int i){
    printf("| Matricula: %i |", alumnos[i].matricula);
    printf("| Alumno: %s |", alumnos[i].nombre);
    printf("| Genero: %c |", alumnos[i].genero);
    printf("\n");
}

///HACIENDO LAS FUNCIONES DEL ALGORITMO POR SELECCION:
void ordenacionSeleccion(Alumno alumnos[], int validos){
    int posMenor;
    Alumno aux;
    int i = 0;
    while(i < validos){
        posMenor = posicionMenor(alumnos, i, validos);
        aux = alumnos[posMenor];
        alumnos[posMenor] = alumnos[i];
        alumnos[i] = aux;
        i++;
    }

}

int posicionMenor(Alumno alumnos[], int pos, int validos){
    Alumno menor = alumnos[pos];
    int posMenor = pos;
    int i = pos + 1;
    while(i < validos){
        if(menor.matricula > alumnos[i].matricula){
            menor = alumnos[i];
            posMenor =  i;
        }
        i++;
    }
    return posMenor;
}
///PUNTO 5:
void mostrarSegunElGenero(Alumno alumnos[], int validos, char genero){
int i;

for(i = 0; i < validos; i++){
    if(alumnos[i].genero == genero){
            modularizarSegunGenero(alumnos, i);
        }
    }
}

void modularizarSegunGenero(Alumno alumnos[], int i){
        printf("| Matricula: %i |", alumnos[i].matricula);
        printf("| Nombre: %s |", alumnos[i].nombre);
        printf("| Genero: %c |", alumnos[i].genero);
        printf("\n\n");
}
///PUNTO 6:
int cargarUnSoloAlumnoMas(Alumno alumnos[], int validos){

   alumnos[validos] = modularizarCargarStruct();

   validos = validos + 1;
   ordenacionSeleccion(alumnos, validos);
return validos;
}
///PUNTO 7:
///Función Ordenamiento x Inserción:

void ordenamientoXinsercion(Alumno alumnos[], int validos) {

    int i = 0; ///Indice actual

    while(i < validos - 1) {
        insertar(alumnos, i, alumnos[i + 1]);
            i++;
    }
}

///Función que inserta el dato
void insertar(Alumno alumnos[], int posicionBusqueda, Alumno alumnos1){ ///Dato = dato a insertar

    int i = posicionBusqueda;
        while(i >= 0 && strcmp(alumnos1.nombre, alumnos[i].nombre) == 1) {

            alumnos[i + 1] = alumnos[i];
                i--;
            }
                alumnos[i + 1] = alumnos1;
}

///PUNTO 8:
int cantidadAlumnosSegunGenero(Alumno alumnos[], int validos, char genero){
int i;
int contador = 0;
for(i = 0; i < validos; i++){
    if(alumnos[i].genero == genero){
           contador++;
        }
    }
return contador;
}

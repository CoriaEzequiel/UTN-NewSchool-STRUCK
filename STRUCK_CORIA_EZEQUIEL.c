#include <stdio.h>
#include <stdlib.h>

void main() {
    int opcion, dni, dniEncontrado, posicionEncontrado, tam = 10; 
    float nota;
    struct alumno {
        int DNI_ALUMNO;
        float NOTA_ALUMNO;
    };
    struct alumno alumnos[tam];

    do {
        printf("Ingrese una opcion del menu: \n");
        printf("1. Cargar alumnos \n");
        printf("2. Buscar un alumno \n");
        printf("3. Modificar nota de un alumno \n");
        printf("4. Mostrar listado de los %i alumnos \n", tam);
        printf("5. Salir \n");
        scanf("%i", &opcion);

        while (opcion < 1 || opcion > 5) {
            printf("Opcion incorrecta. Ingrese nuevamente: \n");
            scanf("%i", &opcion);
        }

        switch(opcion) {
            case 1:
                for (int i = 0; i < tam; i++) {
                    printf("Ingrese el DNI del alumno %i: \n", i+1);
                    scanf("%i", &alumnos[i].DNI_ALUMNO);

                    while (alumnos[i].DNI_ALUMNO < 1000000 || alumnos[i].DNI_ALUMNO > 99999999) {
                        printf("DNI incorrecto. Ingrese nuevamente: \n");
                        scanf("%i", &alumnos[i].DNI_ALUMNO);
                    }

                    printf("Ingrese la nota del alumno %i: \n", i+1);
                    scanf("%f", &alumnos[i].NOTA_ALUMNO);

                    while (alumnos[i].NOTA_ALUMNO < 1 || alumnos[i].NOTA_ALUMNO > 10) {
                        printf("Nota incorrecta. Ingrese nuevamente: \n");
                        scanf("%f", &alumnos[i].NOTA_ALUMNO);
                    }
                }
            break;
            case 2:
                dniEncontrado = 0;
                printf("Ingrese un DNI a buscar: \n");
                scanf("%i", &dni);
                for (int i = 0; i < tam; i++) {
                    if (dni == alumnos[i].DNI_ALUMNO) {
                        dniEncontrado = 1;
                        posicionEncontrado = i;
                    }
                }
                if (dniEncontrado == 1) {
                    printf("Alumno encontrado: \n");
                    printf("DNI: %i \n", alumnos[posicionEncontrado].DNI_ALUMNO);
                    printf("Nota: %.2f \n", alumnos[posicionEncontrado].NOTA_ALUMNO);
                    system("pause");
                } else {
                    printf("DNI inexistente \n");
                    system("pause");
                }
            break;
            case 3:
                dniEncontrado = 0;
                printf("Ingrese el DNI del alumno a modificar: \n");
                scanf("%i", &dni);
                printf("Ingrese la nueva nota: \n");
                scanf("%f", &nota);

                while (nota < 1 || nota > 10) {
                    printf("Nota incorrecta. Ingrese nuevamente: \n");
                    scanf("%f", &nota);
                }

                for (int i = 0; i < tam; i++) {
                    if (dni == alumnos[i].DNI_ALUMNO) {
                        dniEncontrado = 1;
                        posicionEncontrado = i;
                    }
                }
                if (dniEncontrado == 1) {
                    alumnos[posicionEncontrado].NOTA_ALUMNO = nota;
                } else {
                    printf("DNI inexistente \n");
                    system("pause");
                }
            break;
            case 4:
                printf("Listado de alumnos: \n");

                for (int i = 0; i < tam; i++) {
                    printf("Alumno %i \n", i + 1);
                    printf("DNI: %i - ", alumnos[i].DNI_ALUMNO);
                    printf("Nota: %.2f \n", alumnos[i].NOTA_ALUMNO);
                }
                system("pause");
            break;
            default:
                printf("Fin del programa \n");
        }
    } while (opcion != 5);

    system("pause");
}
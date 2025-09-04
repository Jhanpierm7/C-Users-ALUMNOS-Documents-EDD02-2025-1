# C-Users-ALUMNOS-Documents-EDD02-2025-1
#include <stdio.h>

//  Llenamos un array con 10 numeros positivo
void llenarArray(int a[], int n) {
    int valor;
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese el valor %d (entero positivo): ", i + 1);
            scanf("%d", &valor);

            if (valor <= 0) {
                printf(" El número debe ser positivo. Intente de nuevo.\n");
            }

        } while (valor <= 0);
        a[i] = valor;
    }
}

// Mostrar el array de los numeros
void mostrarArray(int a[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

// Selection ordenamientos de  Sort Ascendente 
void ordenarSelectionAscendente(int a[], int n) {
    int i, j, minIndex, temp, paso = 1;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;

            printf("Paso %d (Selection): ", paso);
            mostrarArray(a, n);
            paso++;
        }
    }
}

// Insertion Sort Descendente 
void ordenarInsertionDescendente(int a[], int n) {
    int i, j, key, paso = 1;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;

        printf("Paso %d (Insertion): ", paso);
        mostrarArray(a, n);
        paso++;
    }
}

//  creamos un Main con menú 
int main() {
    const int N = 10;
    int arreglo[N];
    int opcion;
    int lleno = 0; // para verificar si ya se llenó el array

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Registrar elementos\n");
        printf("2. Mostrar elementos\n");
        printf("3. Ordenar ascendente (Selection Sort)\n");
        printf("4. Ordenar descendente (Insertion Sort)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarArray(arreglo, N);
                lleno = 1;
                break;

            case 2:
                if (lleno)
                    mostrarArray(arreglo, N);
                else
                    printf(" Primero debe registrar los elementos.\n");
                break;

            case 3:
                if (lleno) {
                    printf("\n=== Orden Ascendente con Selection Sort ===\n");
                    ordenarSelectionAscendente(arreglo, N);
                    printf("\nArreglo final ascendente: ");
                    mostrarArray(arreglo, N);
                } else {
                    printf(" Primero debe registrar los elementos.\n");
                }
                break;

            case 4:
                if (lleno) {
                    printf("\n=== Orden Descendente con Insertion Sort ===\n");
                    ordenarInsertionDescendente(arreglo, N);
                    printf("\nArreglo final descendente: ");
                    mostrarArray(arreglo, N);
                } else {
                    printf(" Primero debe registrar los elementos.\n");
                }
                break;

            case 5:
                printf(" Saliendo del programa...\n");
                break;

            default:
                printf(" Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 5);

    return 0;
}

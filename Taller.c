#include <stdio.h>

// definición de tipos
typedef struct {
    int codigo;
    double nota;
} estudiante;

// prototipos
double maxNotaRec(const estudiante arr[], int n, int index);
double sumaNotaRec(const estudiante arr[], int n, int index);
void imprimirEstudiantes(const estudiante arr[], int n);
void selectionSortRec(estudiante arr[], int n, int index);
int encontrarMinIndex(const estudiante arr[], int n, int index, int minIndex);

int main() {
    estudiante arr[] = {
        {2024101, 4.5},
        {2024105, 3.7},
        {2024103, 4.8},
        {2024104, 2.9},
        {2024102, 3.2}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    int opcion;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Mostrar estudiantes\n");
        printf("2. Nota maxima del curso\n");
        printf("3. Promedio del curso\n");
        printf("4. Ordenar estudiantes por codigo (Selection Sort Recursivo)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n=== Lista de Estudiantes ===\n");
                imprimirEstudiantes(arr, n);
                break;

            case 2: {
                double maxNota = maxNotaRec(arr, n, 0);
                printf("\nLa nota maxima del curso es: %.2f\n", maxNota);
                break;
            }

            case 3: {
                double suma = sumaNotaRec(arr, n, 0);
                double promedio = suma / n;
                printf("\nEl promedio del curso es: %.2f\n", promedio);
                break;
            }

            case 4:
                selectionSortRec(arr, n, 0);
                printf("\nLista ordenada por codigo (recursivo):\n");
                imprimirEstudiantes(arr, n);
                break;

            case 5:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 5);

    return 0;
}

// funciones recursivas
double maxNotaRec(const estudiante arr[], int n, int index) {
    if (index == n - 1) {
        return arr[index].nota; // caso base
    }
    double maxResto = maxNotaRec(arr, n, index + 1);
    return (arr[index].nota > maxResto) ? arr[index].nota : maxResto;
}

double sumaNotaRec(const estudiante arr[], int n, int index) {
    if (index == n) {
        return 0.0; // caso base
    }
    return arr[index].nota + sumaNotaRec(arr, n, index + 1);
}

// función auxiliar para mostrar lista
void imprimirEstudiantes(const estudiante arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d  |  Nota: %.2f\n", arr[i].codigo, arr[i].nota);
    }
}

// encontrar índice mínimo (recursivo)
int encontrarMinIndex(const estudiante arr[], int n, int index, int minIndex) {
    if (index == n) return minIndex;
    if (arr[index].codigo < arr[minIndex].codigo) {
        minIndex = index;
    }
    return encontrarMinIndex(arr, n, index + 1, minIndex);
}

// selection sort recursivo
void selectionSortRec(estudiante arr[], int n, int index) {
    if (index == n - 1) return; // caso base

    int minIndex = encontrarMinIndex(arr, n, index, index);

    if (minIndex != index) {
        estudiante temp = arr[index];
        arr[index] = arr[minIndex];
        arr[minIndex] = temp;
    }

    selectionSortRec(arr, n, index + 1);
}

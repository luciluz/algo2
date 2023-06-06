# Práctica 5 Ordenamiento

## Ejercicio 6
<div style="text-align: justify">
La idea es armar un arreglo con todas las escaleras, donde cada escalera se represente con tupla(cantEscalones, primerValor). Luego se ordena ese arreglo
con mergeSort o quickSort (no se puede usar un algoritmo lineal, ya que si bien la cantEscalones es menor al tamaño del arreglo, los valores de cada
posición pueden ser cualquier número). Una vez ordenado ese arreglo se van poniendo las escaleras en el arreglo original en O(n).
</div>
<br>


```cpp
void ordenarEscaleras(int arr[]){
    // no puse el caso en que el arreglo sea vacío. Asumo como precondición que el arreglo debe tener al menos 1 elemento
    int size = sizeof(arr) / sizeof(arr[0]);
    int cantEscaleras=1; // se inicializa en 1 porque en el ciclo no se está contando la última escalera
    for(int i=0;i<size-1;i++){ // veo cuántas escaleras hay en total. O(n)
        if(arr[i]!=arr[i+1]){
            cantEscaleras++;
        }
    }

    tuple<int, int> escaleras[cantEscaleras]; // creo un arreglo de escaleras del tamaño total de escaleras
    int j=0;
    int h=0;
    for(int i=0;i<size;i++){ // O(n)
        if(arr[i]!=arr[i+1]){
            escaleras[h]=make_pair(i-j,arr[j]); // <cantEscalones,primerValor>
            i++; h++;
            j=i;
        }
    }
    //ordeno el vector escaleras
    mergeSort(escaleras); // O(m*log m) donde m es la cantidad de escaleras

    // ahora con el vector de escaleras hago las asignaciones correspondientes al arreglo original
    int j=0; // se usará como índice del vector escaleras
    for(int i=0;i<size-1;i++){ // O(n) 
        tuple<int,int> esc=escaleras[j];
        ponerEscalera(arr,i,esc);
        i+=esc.first; // esto modifica i de acuerdo a la cantidad de veces que corrió el ciclo de ponerEscalera
                      // por eso la complejidad no es mayor a O(n)
        }
    }
}

void ponerEscalera(int arr[], int i, tuple<int, int> esc){
    int cont=esc.first;
    int valor=esc.second;
    for(int j=0;j<=cont;j++){
        arr[i]=valor;
        i++; valor++;
    }
}
```

Complejidad: O(n+m*log m) donde n es el tamño del arreglo y m es la cantidad de escaleras. Como m<=n se puede expresar como O(n*log n).

## Ejercicio 9
<div style="text-align: justify">
1- el algoritmo de ordenarPlanilla se puede resolver de forma lineal ya que los puntajes son menores o iguales a 10. La idea del algoritmo
    es armar dos arreglos, uno con todas las mujeres y otro con todos los hombres. Luego cada uno de esos ordenarlos con counting sort.
    Finalmente asignar primero a todas las mujeres y luego a todos los hombres al arreglo original.
</div>
<br>


```cpp
void ordenarPlanilla(tuple<string, enum{masc, fem}, int>  arr[]){
    // como el puntaje es un nat no mayor a 10 puedo hacer counting sort
    // inicializo contador de hombres y mujeres
    int hombres=0;
    int mujeres=0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<size;i++){ // O(n)
        if(arr[i].genero == masc){
            hombres++;
        }
        else{
            mujeres++
        }
    }

    int arrMujeres[mujeres];
    int arrHombres[hombres];

    int h=0;
    int m=0; //indices para arrMujeres y arrHombres
    for(int i=0;i<size;i++){ //O(n)
        if(arr[i].genero == masc){
            arrHombres[h]=arr[i];
            h++;
        }
        else{
            arrMujeres[m]=arr[i];
            m++;
        }
    }
    // En este punto tengo un arreglo con todos los hombres y otro con todas las mujeres
    // Uso countingSort en cada uno tomando como criterio el mayor puntaje
    // para desempatar se podría usar el string pero la consigna no te pide nada al respecto
    countingSort(arrMujeres); 
    countngSort(arrHombres); // O(n) cada uno
    
    //recorro el ciclo original una última vez para hacer las asignaciones
    int m=0;
    int h=0;
    for(int i=0;i<size;i++){ // O(n)
        while(m!=mujeres){
            arr[i]=arrMujeres[m];
            m++; i++;
        }
        while(h<size){
            arr[i]=arrHombres[h];
            h++; i++;
        }
    }    
}
```

Complejidad: O(n).

2- La idea del ítem dos es la misma, solo que en vez de separar en dos arreglos hay que separar en tantos arreglos
como géneros haya. <br>
3- No contradice "lower bound" ya que eso se aplica para arreglos de los que no se tiene información.
En este caso sabemos que los puntajes y los géneros están acotados

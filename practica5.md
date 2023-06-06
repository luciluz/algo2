Ej 6
<div style="text-align: justify">
La idea es armar un arreglo con todas las escaleras, donde cada escalera se represente con tupla(cantEscalones, primerValor). Luego se ordena ese arreglo
con mergeSort o quickSort (no se puede usar un algoritmo lineal, ya que si bien la cantEscalones es menor al tamaño del arreglo, los valores de cada
posición pueden ser cualquier número). Una vez ordenado ese arreglo se van poniendo las escaleras en el arreglo original en O(n).
</div>
<br>


```cpp
void ordenarEscaleras(int arr[]){
    // armo tuplas <longitud, inicio>

    int size = sizeof(arr) / sizeof(arr[0]);
    int cantEscaleras;
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

# Práctica 6 - Dividir y Conquistar

## Ejercicio 1

<div style="text-align: justify">
La idea es usar un algoritmo similar al mergeSort. Es decir, buscamos la mitad, llamamos recursivamente a cada mitad del arreglo y luego
  vemos si la suma del lado izquiero es mayor a la del lado derecho.
</div>
<br>


```cpp
bool esMasALaIzqSuma(int arr[],int izq, int mid, int der){
    int sumaIzq=0;
    int sumaDer=0;

    for(int i=izq;i<=der;i++){
        if(i<=mid){
            sumaIzq+=arr[i];
        }
        else{
            sumaDer+=arr[i];
        }
    }
    return sumaIzq>sumaDer;
}

bool esMasALaIzq(int arr[],int izq, int der){
    if (izq==der) {
        return true;
    }

    if(izq<der){
        int mid=(izq+der)/2;
        bool mitadIzq=esMasALaIzq(arr,izq,mid);
        bool mitadDer=esMasALaIzq(arr,mid+1,der);
        bool sumaIzqMayor=esMasALaIzqSuma(arr, izq, mid, der);

        return mitadIzq && mitadDer && sumaIzqMayor;
    }
    return false;
}
```

Complejidad: O(n*log n)

## Ejercicio 2
<div style="text-align: justify">
La idea es fijarse en el elemento del medio si es igual o no a su índice. Si te da true ya está. En caso contrario, si es menor al indice quiere decir debo hacer la recursión en la mitad derecha. Si es mayor, hago la recursión sobre la mitad izquierda. La complejidad en peor caso es O(log n) porque no necesito recorrer todo el arreglo ya que voy haciendo recursión sobre la mitad.
</div>
<br>

```cpp
bool existePosIgualIndice(int arr[],int inicio, int final){
    if (inicio==final) {
        return arr[inicio]==inicio;
    }

    int mid=(inicio+final)/2;
    if(arr[mid]==mid){
        return true;
    }
    if(arr[mid]>mid){
        return existePosIgualIndice(arr,inicio,mid-1);
    }
    else{
        return existePosIgualIndice(arr,mid+1, final);
    }
}
```

Complejidad: O(log n)

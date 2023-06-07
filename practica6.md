# Práctica 6 - Dividir y Conquistar

## Ejercicio 1

<div style="text-align: justify">
La idea es usar un algoritmo similar al mergeSort. Es decir, buscamos la mitad, llamamos recursivamente a cada mitad del arreglo y luego vemos si la suma del lado izquierdo es mayor a la del lado derecho.
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
La idea es fijarse en el elemento del medio si es igual o no a su índice. Si te da true ya está. En caso contrario, si es menor al indice quiere decir que debo hacer la recursión en la mitad derecha. Si es mayor, hago la recursión sobre la mitad izquierda. La complejidad en peor caso es O(log n) porque no necesito recorrer todo el arreglo ya que voy haciendo recursión sobre la mitad.
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

## Ejercicio 3
<div style="text-align: justify">
  Tenemos a^b, la idea es resolverlo en tiempo log(b).<br>
    - Si b es par ➔ a^b = a^2k = (a^k)^2 ➔ puedo hacer la recursión con k como exponente y al resultado lo multiplico por sí mismo.<br>
    - Si b es impar ➔ a^b = a^(2k+1) = a*a^2k = a*(a^k)^2 ➔ puedo hacer la recursión con k como exponente y al resultado lo multiplico por sí mismo y por a.<br>
  La complejidad es logarítmica porque la recursión se va haciendo con la mitad del arreglo. Además depende de b porque es el exponente el que se va reduciendo.
</div>
<br>


```cpp
int potenciaLog(int base, int exp){
    int res=0;

    if(exp==0){
        res=1;
        return res;
    }
    if(exp%2==0){
        res=potenciaLog(base, exp/2);
        res*=res;
    }
    else{
        res=potenciaLog(base, exp/2);
        res*=res;
        res*=base;
    }
    return res;
}
```
Complejidad: O(log b)

## Ejercicio 6
<div style="text-align: justify">
Dado un arbol, quiero encontrar la distancia máxima que hay entre dos nodos. Para ello calculo la altura del hijo izquierdo, la altura del hijo derecho y después le sumo 2. 
</div>
<br>


```cpp
struct nodo {
    int valor;
    nodo* izq;
    nodo* der;

    nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}

    int altura(nodo* arbol);
    int maxDistancia(nodo* arbol);
};

int max(int a, int b) {
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int nodo::altura(nodo* arbol) {
    if(arbol == nullptr){
        return 0;
    }
    if(arbol->izq != nullptr && arbol->der != nullptr){ // caso dos hijos
        return 1+ max(altura(arbol->izq),altura(arbol->der));
    }
    if(arbol->izq != nullptr){ // tiene 1 hijo y es el izq
        return 1 + altura(arbol->izq);
    }
    if(arbol->der != nullptr){ // tiene 1 hijo y es el der
        return 1 + altura(arbol->der);
    }

    //no tiene hijos
    return 0;
}

int nodo::maxDistancia(nodo* arbol) {
    return altura(arbol->izquierdo) + altura(arbol->derecho) + 2
}


```

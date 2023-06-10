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

## Ejercicio 5
<div style="text-align: justify">
    El truco está en que podemos dividir el arreglo a la mitad ( A[1..n/2] ) y de esta forma para no perder la suma que va desde el (n/2)+1 hasta n, podemos notar que A^((n/2)+i) = A^(n/2) * A^i. Entonces se calcula sólo la mitad del arreglo y para la otra mitad se tiene que es igual a la anterior pero multiplicada por A^(n/2). 
    
</div>
<br>

```cpp
// algoritmo para sumar matrices (se asume que A y B son cuadradas del mismo tamaño)
vector<vector<int>> sumaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=A[i][j]+B[i][j];
        }
    }
    return res;
}


// algoritmo para multiplicar dos matrices (se asume que A y B son cuadradas del mismo tamaño)
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

// algoritmo para calcular A^n utilizando el método potencia
vector<vector<int>> metodoPotencia(const vector<vector<int>>& A, int n) {
    if (n == 0) {
        int dim = A.size();
        vector<vector<int>> matrizId(dim, vector<int>(dim, 0));
        for (int i = 0; i < dim; i++) {
            matrizId[i][i] = 1;
        }
        return matrizId;
    } else if (n == 1) {
        return A;
    } else {
        vector<vector<int>> mid = metodoPotencia(A, n / 2);
        vector<vector<int>> res = multiplicarMatrices(mid, mid);
        if (n % 2 == 1) {
            res = multiplicarMatrices(res, A);
        }
        return res;
    }
}

// algoritmo para calcular A^1 + A^2 + ... + A^n con dividir y conquistar
vector<vector<int>> sumaPotencias(const vector<vector<int>>& A, int n) {
    if (n == 1) {
        return A;
    } else {
        //dividimos el arreglo a la mitad haciendo una recursión con la primera parte
        vector<vector<int>> recursionMitad = sumaPotencias(A, n / 2);

        //calculamos el valor de A^(n/2)
        vector<vector<int>> potenciaMitad = metodoPotencia(A, n / 2);

        //multiplicamos las dos matrices anteriores
        vector<vector<int>> casiRes = multiplicarMatrices(recursionMitad,potenciaMitad);

        //devolvemos la suma entre la última multiplicación y la recursión
        return sumaMatrices(casiRes, recursionMitad);
    }
}
```
Complejidad: O(log n)

## Ejercicio 6
<div style="text-align: justify">
Dado un arbol, quiero encontrar la distancia máxima que hay entre dos nodos. Para ello, se hace recursión con cada hijo del árbol. Luego, devuelvo el máximo entre la recursión de los dos hijos y la suma de las alturas de esos mismos.
</div>
<br>


```cpp
struct Nodo { // estructura del árbol
    int valor;
    Nodo* izq;
    Nodo* der;

    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};

void insertarNodo(Nodo*& raiz, int valor) { // este algoritmo sirve si se quiere testear el maxDistanciaABB
    if (raiz == nullptr) {
        raiz = new Nodo(valor);
    } else if (valor < raiz->valor) {
        insertarNodo(raiz->izq, valor);
    } else {
        insertarNodo(raiz->der, valor);
    }
}

int max(int a, int b) { // algoritmo que devuelve el máximo entre dos enteros
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int alturaABB(Nodo* arbol) { // esto calcula la altura de un ABB
    if (arbol == nullptr) {
        return 0;
    }
    return 1 + max(alturaABB(arbol->izq), alturaABB(arbol->der));
}

int maxDistanciaABB(Nodo* nodo) { // esta es la función que pide la consigna
    if (nodo == nullptr) {
        return 0;
    }
    int izqDistancia = maxDistanciaABB(nodo->izq);
    int derDistancia = maxDistanciaABB(nodo->der);

    return max(max(izqDistancia, derDistancia), alturaABB(nodo->izq) + alturaABB(nodo->der));
}
```
Complejidad: te la debo

## Ejercicio 7

```cpp
int parejasEnDesorden(int arr[], int l, int r) {
    if(l==r){
        return 0;
    }

    int mid=(l+r)/2;
    int mitadIzq=parejasEnDesorden(arr, l, mid);
    int mitadDer=parejasEnDesorden(arr, mid+1, r);

    merge(arr, l, mid, r); // hasta aquí ordené el arreglo con merge sort

    // luego contamos las parejas
    int cont=0;
    int i=0; // índice primera mitad
    int j=mid+1; // índice segunda mitad

    while(i<=mid && j<=r) { // O(n)
        if(arr[i] > arr[j]) {
            cont+=(mid-i+1);  // si ya uno es mayor, el resto de esa mitad también
            j++;
        } else {
            i++;
        }
    }
    return mitadIzq+mitadDer+cont;
}
```
Complejidad: O(n * log n)

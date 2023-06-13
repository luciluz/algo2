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

    return max(max(izqDistancia, derDistancia), alturaABB(nodo->izq) + alturaABB(nodo->der) + 2);
}
```
Complejidad: te la debo

## Ejercicio 7
<div style="text-align: justify">
La idea es hacer algo similar al merge sort. Se hacen dos recursiones, una con cada mitad del arreglo y se hace el merge para que queden ordenadas. Luego para contar las parejas se va viendo desde el primer elemento de cada mitad y si en algún punto A[i] > A[j] entonces se que el resto de elementos de la primera mitad también son mayores que A[j] (esto porque están ordenadas).
</div>
<br>

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

## Ejercicio 8
### 1.
<div style="text-align: justify">
Aquí hice algo parecido a búsqueda binaria pero con matrices. La idea es dividir la matriz en dos y fijarse con la función conjuncionSubmatriz si da true o falso. Si ese resultado es true quiere decir que no hay ningún false en esa mitad entonces se hace recursión sobre la otra. Se sigue así hasta encontrar la corrdenada que se necesita.
</div>
<br>

```cpp
tuple<int, int> buscarFalse(vector<vector<bool>> A, int i0, int i1, int j0, int j1){

    // guardo la mitad de filas y columnas
    int mitadFila = (i0+i1)/2;
    int mitadColum = (j0+j1)/2;
    
    // guardo la conjuncion de la mitad de filas y columnas izquierdas
    bool conjMitadFilaIzq = conjuncionSubmatriz(A,i0, mitadFila, j0, j1);
    bool conjMitadColumIzq = conjuncionSubmatriz(A,i0, i1, j0, mitadColum);

    //caso base: significa que estoy en la posición que tiene un false
    if(i0==i1 && j0==j1){
        return make_pair(i0,j0);
    }
    // caso en que sea solo una columna
    if(!conjMitadFilaIzq && j0==j1){
        return buscarFalse(A,i0, mitadFila, j0, j1); // voy dividiendo la fila con búsqueda binaria hasta encontrar el false
    }
    else if(j0==j1) { // lo mismo en caso de que el false esté al otro lado
        return buscarFalse(A, mitadFila+1, i1, j0, j1);
    }

    // este es el caso general, es parecido al de arriba pero voy reduciendo las columnas (j)
    if(!conjMitadColumIzq){ // si da falso es porque algún falso hay en esta mitad
        return buscarFalse(A,i0, i1, j0, mitadColum);
    }
    else{ // si lo anterior da true entonces el falso está en la otra mitad
        return buscarFalse(A,i0,i1, mitadColum+1, j1);
    }
}
```
Complejidad: O(log n^2) donde n es la cantidad de filas o columnas. 

### 2.
<div style="text-align: justify">
En este caso el algoritmo es similar, sólo hay que hacer algunos cambios. La recursion siempre se hará si es que hay un false en esa mitad y parará cuando llegue a una posición false o simplemente no haya ningún falso en esa mitad.
</div>
<br>

```cpp
int cuantosFalses(vector<vector<bool>> A, int i0, int i1, int j0, int j1){

    // busco la mitad de filas y columnas
    int mitadFila = (i0+i1)/2;
    int mitadColum = (j0+j1)/2;

    // guardo el bool correspondiente a cada mitad de matriz
    bool conjMitadFilaIzq = conjuncionSubmatriz(A,i0, mitadFila, j0, j1);
    bool conjMitadFilaDer = conjuncionSubmatriz(A,mitadFila+1, i1, j0, j1);
    bool conjMitadColumIzq = conjuncionSubmatriz(A,i0, i1, j0, mitadColum);
    bool conjMitadColumDer = conjuncionSubmatriz(A,i0, i1, mitadColum, j1);

    //caso base: significa que estoy en la posición que tiene un false
    if(i0==i1 && j0==j1){
        return 1;
    }

    // caso cuando tengo una columna
    if(!conjMitadFilaIzq && !conjMitadFilaDer && j0==j1){ // ambas mitades tienen algún false
        return cuantosFalses(A,i0, mitadFila, j0, j1) + cuantosFalses(A, mitadFila+1, i1, j0, j1); // devuelvo la suma de ambas
    }
    else if(!conjMitadFilaIzq && j0==j1) { // aquí hago recursión solo en la mitad que tiene un false
        return cuantosFalses(A, i0, mitadFila, j0, j1);
    } else if(!conjMitadFilaDer && j0==j1) {
        return cuantosFalses(A, mitadFila+1, i1, j0, j1);
    }

    // este es el caso general, es parecido al de arriba pero voy reduciendo las columnas (j)
    if(!conjMitadColumIzq && !conjMitadColumDer){ // ambas mitades tienen algún false
        return cuantosFalses(A,i0, i1, j0, mitadColum) + cuantosFalses(A, i0, i1, mitadColum+1, j1); // devuelvo la suma
    }else if(!conjMitadColumIzq){ // aquí hago recursión solo en la mitad que tiene un false
        return cuantosFalses(A,i0, i1, j0, mitadColum);
    } else{
        return cuantosFalses(A,i0,i1, mitadColum+1, j1);
    }
}
```
Complejidad: O(log n^2)
Explicación: Si para encontrar un falso haciendo búsqueda binaria se logra en log n^2. Si tengo que encontrar a lo sumo 5 falsos será a lo sumo en 5*log n^2. El problema es que para n < 4 la complejidad llega a ser mayor que n^2

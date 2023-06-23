
tupla(int altura, Nodo arr[]) caminoHastaUltHoja(Nodo ab){
  if(ab == nullptr){
    return {};
  }
  
  vector<Nodo> caminoHastaUltHoja(ab.izq);
  
}

caminoUltHoja(in ab: arbolbinario) -> res: arr[nodo] {
  if(ab == nullptr){
    return {}
  }
  // calculo altura del árbol
  altura = 1;
  tamaño = ab.size;
  while(tamaño > 0){
    tamaño -= 2^(altura-1);
    altura++,
  }

  res = caminoUltHojaAux(ab, altura);
  return res.first;
}

caminoUltHojaAux(in ab: arbolbinario, in altura: nat) -> res: <arr[nodo][altura], nat> {
  
  if(altura == 1){
  nodos = arr[Nodos][altura] // creo un arreglo de nodos con tantas posiciones como altura tenga el árbol
  nodos[altura-1] = ab;
  return <nodos, altura>
  }

  // veo si la ult hoja está en la primera o segunda mitad del último nivel
  k = ab.size;
  ulthoja = k-(2^(altura-1)-1)

  if( ulthoja < 2^(altura-1)/2){
    res = caminoUltHojaAux(ab.izq, altura-1);
  } else{
    res = caminoUltHojaAux(ab.der, altura-1);
  }

  // agrego el nodo actual al arreglo
  res[altura-1] = ab;
    
  return res
  
}

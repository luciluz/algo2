Estructura

tad MULT.AR se representa con m,
donde m es:
 tupla <
        localidadxVehi
        vehiculosXLocalidad        : diccDigital(localidad, <conj(vehiculo), <conj(camara)>),
        camarasXLocalidad   : diccDigital(localidad, diccDigital(camara, multiconj(multa))),
        multasXCamras
        multasXvehiculos         : diccDigital(vehiculo, diccDigital(camara, multiconj(multa))),
        
        
        
        

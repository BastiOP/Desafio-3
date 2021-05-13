# README Desafio 3
~~~
CAMILO ACEVEDO ÁLVAREZ
RODRIGO MORALES PEÑA
BASTIÁN ROLDÁN PULGAR
~~~

Link al video: 

## Instrucciones. 

1. Tener instalado compilador para correr c++. (https://code.visualstudio.com/docs/cpp/config-mingw)
2. Abrir archivo main.cpp desde Visual Studio Code.
3. Presionar "Terminal->Run Task" en la barra superior y seleccionar "g++"
4. Abrir Terminal, ir a ubicación donde se encuentra el archivo "main.exe" (misma ubicación donde se encuentra main.cpp).
5. Ejecutar esta linea de codigo, ".\main"

## Explicación del problema.

El problema a desarrollar consiste en la solicitud de Manuel, para la creación de un programa, el cual a partir de datos recopilados de las aplicaciones más descargadas de una tienda en específico se obtenga información sobre aplicaciones similares a las que se encuentra desarrollando Manuel. Para esto, toda la información recopilada  de la tienda se encuentra guardada dentro de un dataset en formato csv donde cada aplicación posee un id para identificarlo, un nombre, su tamaño, su precio junto con el tipo de moneda del precio, la cantidad total de calificaciones del juego, la calificación de la versión en que se encuentra, un promedio de puntaje de las reseñas, un promedio de puntaje de las reseñas para la versión actual, la última versión en que se encuentra el juego,  la clasificación de edad para el contenido de este, el género principal, la cantidad de dispositivos que soporta, la cantidad de capturas de pantalla por dispositivo, la cantidad de lenguajes que soporta y la licencia Vpp.

Para poder realizar este programa se deberá escoger una estructura espacial que sea adecuada y que sea conocida por nosotros, ya que se deberá almacenar la información en esta estructura y al escoger una estructura espacial conocida se nos hará más sencillo el manejo de los datos y la creación de las funcionalidades. Además el programa deberá contener al menos tres funcionalidades que son necesarias para encontrar información de las aplicaciones similares. La primera funcionalidad que se debe de implementar es que se debe mostrar toda la información de una aplicación específica al ingresar el id o nombre de esta. En segundo lugar, la funcionalidad que se debe de implementar es que se debe de mostrar la información de las 10 aplicaciones más parecidas a una aplicación que fue entregada por id. Por último, se debe de mostrar las 10 aplicaciones más parecidas a un vector de atributos, entregado su precio, tamaño, etc.

Además de esas funcionalidades, se deben identificar los atributos de cada aplicación que se podrán comparar entre sí, y se deberá definir una funcionalidad la cual calcule la distancia entre los datos que se estén comparando. Todo esto se verá a más detalle a continuación, donde se explicará la solución propuesta a este problema.

## Solución propuesta
Para resolver el problema, se usó el algoritmo  KNN aplicado en un K-D Tree. El K-D Tree es una estructura de datos similar al árbol de búsqueda binario, con la diferencia de que cada nodo tiene K dimensiones y ordenados por estas.	
Cada nivel del K-D Tree corresponde a una dimensión de los puntos y en el plano cartesiano (si corresponde a 2 dimensiones) se puede representar como la división de este según la dimensión en que se compara. El K-D Tree se compone de un conjunto de nodos, los cuales tienen asociado punteros hacia sus hijos (lado derecho e izquierdo). El algoritmo comienza con un nodo raíz (root), el cual da comienzo al árbol y lo “divide” en dos partes, luego los puntos se van ordenando según las dimensiones que tengan, midiendo la distancia con la función implementada. Con la misma función comentada anteriormente, se pueden descartar nodos, es decir, con la distancia calculada entre el punto de referencia y el centro del árbol, se puede escoger solo un lado y descartar totalmente el otro.

Para calcular la distancia entre puntos, se implementó una función en donde los datos pertenecientes a las dimensiones que fueran númericos (bytes, precio, etc), se obtuviera la diferencia de estos, entre dos puntos, lo que sumaría distancia si no fueran iguales en esa dimensión. En cambio, los datos que se pueden definir como una representación vectorial(one hot encoding), se les asignó un "peso" o valor a esa distancia si fueran distintos. Al final, esta distancia calculada en cada dimensión, es sumada y da como resultado la distancia total entre dos puntos.


## Coevaluación

### **Autor: Camilo Acevedo Álvarez**
\
-*Rodrigo Morales Peña*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0  
* Aspecto positivo:  Disposición a trabajar en los momentos necesarios.
* Aspecto negativo:  Falta de comunicación.
\
-*Bastían Roldán Pulgar*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0
* Aspecto positivo:  Motivación por el trabajo.
* Aspecto negativo:  Poco control de la motivación.

***
### **Autor: Rodrigo Morales Peña**
\
-*Camilo Acevedo Álvarez*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0

* Aspecto positivo: Tiene buena disposición en ayudar a sus compañeros, tiene paciencia
* Aspecto negativo: Es muy disperso.
\
-*Bastían Roldán Pulgar*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0
* Aspecto positivo: Tiene buena disposición, es centrado.
* Aspecto negativo: Tiene poca paciencia.

***
### **Autor: Bastían Roldán Pulgar**
\
-*Camilo Acevedo Álvarez*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0
* Aspecto positivo: Veloz aprendizaje.
* Aspecto negativo: Es desordenado.
\
-*Rodrigo Morales Peña*-

Criterio | Evaluación
-- | --
Asistencia y puntualidad | 0
Integración | 0
Responsabilidad | 0
Contribución | 0
Resolución de conflictos | 0
* Aspecto positivo:  Se esfuerza para obtener buenos resultados.
* Aspecto negativo:  Dificultad en organizar el tiempo.

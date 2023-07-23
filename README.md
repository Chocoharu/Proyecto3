# Proyecto3: Carrera de Algoritmos de Ordenamiento y Búsqueda

En este proyecto se planteó un caso hipotético en el que se requería ordenar grandes cantidades de datos almacenados de manera ascendente o descendente,
utilizando algoritmos cuadráticos y logarítmicos de ordenamiento. Se crearon versiones ascendentes y descendentes de los siguientes algoritmos:

1. Selection Sort.
2. Bubble Sort.
3. Insertion Sort.
4. Shell Sort.
5. Merge Sort.
5. Quick Sort.
7. Heap Sort.
Para realizar la comparación de rendimiento, se generaron tres carreras con diferentes valores de "amount" y cuatro tipos de arreglos:

1. Ascendente.
2. Descendente.
3. Aleatorio.
4. Aleatorio sin números duplicados.

## Estructura del proyecto

### SortGeneration
SortGeneration es una función encargada de generar los arreglos con diferentes tipos de datos para ser utilizados en la carrera de algoritmos de ordenamiento y búsqueda. Esta función toma como entrada los siguientes parámetros:

* amount: La cantidad de elementos que tendrá el arreglo.
* arr: Los 4 tipos de arreglo a generar (ascendente, descendente, aleatorio o aleatorio sin números duplicados).
La función trabaja de la siguiente manera:

1. Crea un arreglo de tamaño amount y lo inicializa con valores predeterminados, dependiendo del tipo de arreglo que se haya especificado.
2. Si el tipo de arreglo es ascendente, el arreglo se inicializa con valores desde 1 hasta amount.
3. Si el tipo de arreglo es descendente, el arreglo se inicializa con valores desde amount hasta 1.
4. Si el tipo de arreglo es aleatorio, se genera un valor aleatorio para cada elemento del arreglo dentro de un rango determinado.
5. Si el tipo de arreglo es aleatorio sin números duplicados, se utiliza un algoritmo de Fisher-Yates para permutar aleatoriamente los elementos del arreglo sin duplicados.
Al finalizar, la función retorna los arreglos generado.

### getResultFromAlg
getResultFromAlg es una función que ejecuta un algoritmo de ordenamiento específico y mide el tiempo que tarda en ordenar un arreglo dado. Esta función toma como entrada los siguientes parámetros:

* arr: El arreglo que se va a ordenar.
* option: El puntero a la función del algoritmo de ordenamiento que se va a ejecutar (puede ser cualquiera de los algoritmos mencionados, como Selection Sort, Bubble Sort, etc.).
La función trabaja de la siguiente manera:

1. Utiliza la biblioteca "Chrono" para obtener el tiempo de inicio antes de llamar a la función de ordenamiento.
2. Ejecuta la función de ordenamiento pasándole el arreglo y su tamaño.
3. Obtiene el tiempo de finalización utilizando "Chrono".
4. Calcula la diferencia entre el tiempo de inicio y el tiempo de finalización para obtener el tiempo de ejecución del algoritmo.
Retorna el tiempo de ejecución en segundos.

### SortExecution
SortExecution es una función que se encarga de realizar la comparación de rendimiento de los algoritmos de ordenamiento para un tipo de arreglo específico (ascendente). Esta función toma como entrada los siguientes parámetros:

* amount: La cantidad de elementos que tendrá el arreglo.
La función trabaja de la siguiente manera:

1. Utiliza SortGeneration para generar el arreglo específico del tipo de dato seleccionado.
2. Clona el arreglo generado para asegurar una ejecución justa y comparativa para cada algoritmo. Crea un "unordered_map" que almacenará los tiempos de ejecución de cada algoritmo.
3. Crea un "unordered_map" que almacenará los tiempos de ejecución de cada algoritmo.
4. Ejecuta cada algoritmo de ordenamiento usando getResultFromAlg y almacena los tiempos en el "unordered_map".
5. Recorre el "unordered_map" para encontrar el algoritmo con el menor tiempo de ejecución.
6. Imprime el algoritmo ganador junto con su tiempo de ejecución.

## Ejecución
Para ejecutar el programa, selecciona el tipo de orden (ascendente o descendente) en el menú y el programa realizará 12 comparaciones utilizando diferentes arreglos generados. Los tamaños de los arreglos para cada caso específico son:

* Tablero: De 30,000 a 100,000 datos.
* Caminos: De 20,000 a 70,000 datos.
* Objetos: De 7,500 a 15,000 datos.

Por fines prácticos de la ejecución y presentación de video, se redujo la cantidad de datos a 30.000 para Tablero y 20.000 para Caminos.

## Video explicativo
A continuación, puedes encontrar un [video explicativo]() que muestra la ejecución y los resultados de la carrera de algoritmos de ordenamiento y búsqueda desarrollada en este proyecto.
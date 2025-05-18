# Task #3: Libreria Estandar  
**course:** Programación III  
**unit:** 2  
**cmake project:** prog3_unit2_standar_library_v2022_1

## Instructions
Subir a gradescope los siguientes archivos:
- `p1.h`
- `p2.h`
- `p3.h`
- `p4.h`
- `p5.h`
- `p6.h`
- `p7.h`
- `p8.h`
- `p9.h`

## Question #1 - split_range (2 points)

Generar una función template `split_range`, que reciba como parámetros un contenedor y un número `n` y permita dividir el contenedor en `n` contenedores, si el valor `n` no es múltiplo del tamaño del contenedor, los ítems restantes de la división deberán ser almacenados en el último contenedor. El resultado o valor de retorno deberá ser un contenedor que contenga los contenedores devueltos, siendo vector el contenedor por defecto, el template tendrá la posibilidad de personalizar en contenedor de resultado.

**Use Case #1:**
```cpp
deque<int> d1 = {1, 2, 3, 4, 5, 6, 7};
auto resultado = split_range(d1, 3};
    // resultado[0] = {1, 2};
    // resultado[1] = {3, 4};
    // resultado[2] = {5, 6, 7};
 ```

**Use Case #2:**
```cpp
std::list<int> cnt{10, 20, 30, 40, 50, 60};
auto res2 = split_range(cnt, 2);
for (const auto& row : res2) {
    std::cout << "|";
    for (const auto& item : row)
        std::cout << item << " ";
}   // |10 20 30 |40 50 60
```

**Use Case #3:**
```cpp
std::vector<int> vec{};
std::forward_list<int> cnt{std::begin(vec), std::end(vec)};
auto res3 = split_range(cnt, 3);
for (const auto& row : res3) {
    std::cout << "|";
    for (const auto& item : row)
        std::cout << item << " ";
}   // |10 20 |30 40 |50 60 70
```

**Use Case #4:**
```cpp
std::string all = "El mundo es ancho y ajeno";
auto chunks = split_range(all, 5);
for (const auto& part : chunks) {
    std::cout << '|' << part;
}   // |El mu|ndo e|s anc|ho y |ajeno
```


## Question #2 - sum_range (2 points)

Escribir una función template `sum_range` que permita la suma de los valores de 2 contenedores. Si uno de los contenedores es de menor tamaño, el contenedor de menor tamaño se sumará repetidamente con otro contenedor hasta completar el tamaño del mayor.

**Use Case #1:**
```cpp
std::stringstream os;
std::list<int> l1 = { 10, 20, 30, 40, 50, 60, 70 };
std::list<int> l2 = { 4, 8 };
auto res1 = sum_range(l1, l2);
for (const auto& item : res1)
    std::cout << item << " ";
// 14 28 34 48 54 68 74
```
**Use Case #2:**
```cpp
std::forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
std::forward_list<int> fl2 = { 4, 8, 7};
auto res2 = sum_range(fl1, fl2);
for (const auto& item : res2)
    std::cout << item << " ";
// 14 28 37 44 58 67 74 88
```
**Use Case #3:**
```cpp
std::stringstream os;
std::vector<int> l1 = { 10, 20, 30, 40, 50, 60, 70, 80, 100};
std::vector<int> l2 = { 4, 8 };
auto res1 = sum_range(l1, l2);
for (const auto& item : res1)
    std::cout << item << " ";
// 14 28 34 48 54 68 74 88 104
```
**Use Case #4:**
```cpp
const std::deque<int> d1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
const std::deque<int> d2 = { 4, 8, 7};
for (const auto res2 = sum_range(d1, d2); const auto& item : res2)
    std::cout << item << " ";
// 14 28 37 44 58 67 74 88
```
## Question #3 - delete_range (2 points)

Escribir una función template `delete_items` que permita eliminar un valor específico o una lista de valores de un contenedor secuencial:

**Use Case #1:**
```cpp
std::vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v3 = delete_range(v1, 1); // {3, 4, 3, 2, 3, 4, 6, 5}
```
**Use Case #2:**
```cpp
std::list<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v3 = delete_range(v1, {1, 4});	 // {3, 3, 2, 3, 6, 5}
```

## Question #4 - delete_duplicated (2 points)

Escribir una función template `delete_duplicated` que permita eliminar todos los valores duplicados:

**Use Case #1:**
```cpp
std::vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v2 = delete_duplicated(v1);        // {1, 3, 4, 2, 6, 5}
```
**Use Case #2:**
```cpp
std::list<int> v3 = {1, 1, 1, 1, 3, 2, 2, 2, 2, 5}; 
auto v4 = delete_duplicated(v3);	    // {1, 3, 2, 5}
```


## Question #5 - unpack (2 points)

La librería estándar de C++ brinda un contenedor simple conocido como `std::tuple`, que permite almacenar valores de diferente tipo, ejemplo:
```cpp
std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
```
El acceso a sus valores es por medio de la función template `std::get` cuyo parámetro de template se utiliza para identificar la posición de alguno de sus valores.
```cpp
std::cout << std::get<0>(tup1) << endl; // 1321
std::cout << std::get<1>(tup1) << endl; // Jose
std::cout << std::get<2>(tup1) << endl; // Perez
std::cout << std::get<3>(tup1) << endl; // 1.68
```
Lenguajes como python brindan un mecanismo conocido como unpack que permita asignar valores de un contenedor a variable con nombres significativos. Por ejemplo en python:
```python
tup1 = (1321, 'Jose', 'Perez', 1.68)
id, first_name, last_name, height = tup1
print(id, name, last_name, height)
```

Diseñar y desarrollar la función template `unpack` que permita desempaqueta los valores de una tupla en variables individuales.

**Use Case #1:**
```cpp
std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
int key; 
string first_name; 
string last_name; 
double height;
unpack(key, first_name, last_name, height) = t1;
std::cout << key <<  " "<< first_name << last_name << height << endl;
```

**Use Case #2:**
```cpp
std::tuple<std::list<int>, std::string, char> t1 = { {1, 2, 3, 4}, "Texto2", 'A' };
std::list<int> vec;
std::string text2;
char flag;
unpack(vec, text2, flag) = t1;
std::ranges::copy(vec, std::ostream_iterator<int>(std::cout, " "));
// 1 2 3 4
std::cout << std::endl;
std::cout << text2 << " " << flag;
// Texto2 A
```

## Question #6 - zip (2 points)
En python existe una función denominada `zip` que permite recibir un número variado de contenedores del mismo tipo y agrupar los valores de una misma fila generando tuplas por cada fila con los valores de cada contenedor.
Generar un function template similar, pero en vez de tuplas generé un `std::vector` con los valores correspondientes de cada fila.

**Use Case #1:**
```cpp
std::list<int> v1 = { 11, 12, 13 };
std::list<int> v2 = { 21, 22, 23 };
std::list<int> v3 = { 31, 32, 33 };
auto result = zip(v1, v2, v3);
// result sería del tipo: list<vector<int>>
for (const auto& row : result) {
    for (const auto& value : row)
        std::cout << value << " ";
    std::cout << std::endl;
}
// lo impreso sería:
//	11 21 31
//	12 22 32
//	13 23 33
```

## Question #7 - rotate_range (2 points)
Escribir una función template `rotate_range` que permite rotar los valores de un contenedor una cantidad determinada, esta función recibe 2 parámetros un contenedor, y un valor entero, en caso sea positivo los valores rotará hacia la derecha, en caso negativo los valores rotaran a la izquierda:

**Use Case #1:**
```cpp
std::vector<int> v1 = {1, 2, 3, 4, 5, 6}; 
auto v3 =rotate_range(v1, 2);   		// {5, 6, 1, 2, 3, 4}
```
**Use Case #2:**
```cpp
std::list<int> v1 = {10, 20, 30, 40, 50}; 
auto v3 = rotate_range(v1, -2);	 	// {30, 40, 50, 10, 20}
```

## Question #8 -  (2 points)

Escribir una función `filter_codes` que lea de un archivo una lista de códigos y que retorne de forma ordenada todos aquellos códigos que empiecen un carácter, el contenedor de retorno por default es un `std::vector` pero podrá seleccionarse cualquier otro repositorio secuencial (`std::deque`, `std::list` o `std::forward_list`).

**NOTA:** Los códigos están conformados por 4 letras en minúsculas iniciales y 3 digito de 0 a 9.

**Use Case #1:**
```cpp
std::vector<std::string> codes = filter_codes('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #2:**
```cpp
auto codes = filter_codes<std::list>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #3:**
```cpp
auto codes = filter_codes<std::deque>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #4:**
```cpp
auto codes = filter_codes<std::forward_list>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

## Question #9 - Fixed Stack  (4 points)

Desarrollar el template de clase `fixed_stack` que permita implementar pilas de tamaño fijo que cuente con 2 parámetros:

- Tipo de dato de los valores que almacenara la pila (`T`) (Parámetro tipo)
- Cantidad fija de valores que aceptara la pila (`sz`) (Parámetro No tipo)

y que cuenten con los siguientes métodos:

- `fixed_stack(std::initializer_list lst)` constructor que permita copiar valores en la pila considerando como restricción la cantidad fija de valores aceptada por la pila, en caso `lst` tuviera más valores que los soportados por la pila esos valores serian descartados. 
- `T top()` retorna el valor al tope de la pila
- `pop()` remueve el valor del tope de la pila y actualiza el valor del tope.
- `bool push(T Value)` agrega un nuevo valor a la pila, actualiza la posición del tope y retornar `true` si fue exitoso, se considera que NO es exitoso si se intenta ingresar un valor y se rebasa el tope máximo definido por el tamaño fijo de la pila.  
- `boo empty()` retorna `true` si la pila esta vacía.
- `int size()` retorne la cantidad de datos grabados en la pila.

Adicionalmente elaborar el template de clase `fixed_stack_pusher` amiga de la clase `fixed_stack` que se comportara como un iterador `forward` para lo cual la clase `fixed_stack_pusher` debe implementar los siguientes métodos:

- `fixed_stack_pusher(fixed_stack<T, sz> stack)` constructor utilizado para que la clase `fixed_stack_pusher` acceda a los valores almacenados y al tope de la pila.

- `fixed_stack_inserter& operator++()` y `fixed_stack_inserter<T, sz> operator++(int)` que permiten avanzar desde el primer elemento hacia adelante.

- `fixed_stack_inserter& operator=(T value)` que permite realizar el `push` de un nuevo valor en la pila.

- `fixed_stack_inserter& operator*()` que retorne la referencia a la misma clase (usar `*this`).

**Use Case #1:**
```cpp
    fixed_stack<int, 5> fs1 = {1, 2, 3, 4, 5};
    while (!fs1.empty()){
        std::cout << fs1.top() << " ";
        fs1.pop();
    }
    // 5 4 3 2 1
```

**Use Case #2:**
```cpp
    fixed_stack<int, 100> fs1;
    std::vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::copy(std::begin(vc1), std::end(vc1), fixed_stack_pusher(fs1));
    while (!fs1.empty()){
        std::cout << fs1.top() << " ";
        fs1.pop();
    }
    // 8 7 6 5 4 3 2 1
```

**Use Case #3:**
```cpp
    fixed_stack<float, 100> fs1;
    std::vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    for(const auto& item: vc1)
        fs1.push(item);
    while (!fs1.empty()){
        std::cout << fs1.top() << " ";
        fs1.pop();
    }
    // 8 7 6 5 4 3 2 1
```

**Use Case #4:**
```cpp
    fixed_stack<float, 5> fs1;
    std::vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    for(const auto& item: vc1)
        if (!fs1.push(item))
            break;
    while (!fs1.empty()) {
        std::cout << fs1.top() << " ";
        fs1.pop();
    }
    // 5 4 3 2 1
```

**Use Case #5:**
```cpp
    fixed_stack<std::unique_ptr<std::pair<int, int>>, 7> fs1;
    int n = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> vc1(n);
    for (auto& item: vc1)
        std::cin >> item.first >> item.second;
    
    for (auto& item: vc1)
        if (!fs1.push(std::make_unique<std::pair<int, int>>(item)))
            break;
    
    while (!fs1.empty()){
        std::cout << fs1.top()->first << " " << fs1.top()->second << std::endl;
        fs1.pop();
    }
    // 5 4 3 2 1
```

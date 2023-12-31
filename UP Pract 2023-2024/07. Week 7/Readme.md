# УП - Практикум 22.11.2023 Седмица 7

## 1. Уводни задачи - Подготовка за контролно

**Задача 1:** Да се напише функция, която приема масив от символи, големината му и число K. Масивът от символи е число в K-ична бройна система. Функцията трябва да увеличава числото с 1 (приемаме, че в масива има достатъчно място).

**Пример:**
```c++
[0, 1, 1] 3 2 // Входни данни за функцията - array, size, K
```
```c++
[1, 0, 0]
```

**Задача 2:** Да се напише функция, която приема масив от символи, големината му и число K. Масивът от символи е число в K-ична бройна система. Функцията трябва да намалява числото с 1.
**Пример:**
```c++
[1, 0, 0] 3 2
```
```c++
[0, 1, 1]
```

**Задача 3:** Напишете функция, която приема два масива от символи, големината им (която е еднаква), число K и празен масив res заедно с големината му. Масивите от символи са числа в K-ична бройна система. Функцията трябва да прибавя второто към първото и да попълни резултата в res.

**Пример:**
```c++
[1, 7, 5] 
[5, 3, 7]
3 8
[]
```
```c++
[7, 3, 4]
```

## 2. Задачи за бройни системи

**Задача 1:** Да се направи функция, която извежда на екрана двоичната репрезентация на 32 битово число записано в десетична бройна система.

**Пример:**
```c++
10
```
```c++
00000000000000000000000000001010
```

**Задача 2:** Да се напише функция, която приема число в десетична бройна система и число k <= 16 и k > 0. Функцията извежда на стандартния изход числото в k-ична бройна система

**Пример:**
```c++
167 12
```
```c++
11B // 167 in base 10 is equal to 11B in base 12
```

**Задача 3:** Да се напише функция, която приема число в трoична бройна система и го връща в осмична **без да използва масив.**

**Пример:**
```c++
11120
```
```c++
173
```

**Задача 4:** Да се напише функция, която приема число в дванайсетична бройна система и го връща в тринайсетична **с масив.**

**Пример:**
```c++
23
```
```c++
21
```

**Задача 5:**
Да се напише функция, която приема осем битово число в двоична бройна система, представено като int и връща числото, умножено по -1.

**Пример 1:**
```c++
00001010 // 10
```
```c++
11110110 // -10
```

**Пример 2:**
```c++
11111111 // -1
```
```c++
00000001 // 1
```

**Задача 6:** Да се напише функция, която приема число от тип unsigned int (32 бита) и K - бройна система (<= 16-ична). Функцията да връща дали числото е палиндром в дадената бройна система.

**Пример:**
```c++
7 2
```
```c++
true // 7 = 111 in binary
```

**Задача 7:** Да се напише функция, която приема два масива от символи, големината им и числа К и N. Масивите са съответно две числа - първото в К-ична, второто в N-ична бройна система. Функцията да връща дали числата са равни.

**Пример:**
```c++
[3, 4, 5] 3 8
[E, 5] 2 16
```
```c++
true //345(8) = 229(10) = E5(16)
```

**Задача 8:** Конвертори на бройни системи:
1. Да се напише функция, която приема число в N-ична бройна система и го връща в K-ична бройна система **без да използва масив.** (N и K са най-много 10).
   
2. Да се напише функция, която приема число в N-ична бройна система и го връща в K-ична бройна система **с масив.** (N и K са най-много 36 - с други думи са бройни системи само с цифри от 0 до 9 и букви от A до Z).

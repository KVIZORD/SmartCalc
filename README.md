# SmartCalc

Данный проект представляет собой калькулятор, который позволяет выполнять арифметические операции и вычислять различные математические функции. Кроме того, в приложении можно строить графики функций и использовать кредитный калькулятор.

## Интерфейс

![smartcalc](docs/images/smartcalc_ui.png)
![graph](docs/images/graph_ui.png)
![credit](docs/images/creditcalc_ui.png)

## Установка

Для установки приложения необходимо выполнить следующие действия:

1. Склонировать репозиторий на свой компьютер.
2. Перейти в директорию с проектом.
3. Выполнить команду `make install`.

## Тестирование

Для запуска тестов необходимо выполнить команду `make test`. Тесты проверяют работу арифметических операций и математических функций, а также работу кредитного калькулятора. 

## Возможности

Калькулятор поддерживает следующие арифметические операции:

- Сложение: `a + b`
- Вычитание: `a - b`
- Умножение: `a * b`
- Деление: `a / b`
- Возведение в степень: `a ^ b`
- Остаток от деления: `a mod b`
- Унарный плюс: `+a`
- Унарный минус: `-a`

Калькулятор также поддерживает скобки для задания порядка выполнения операций. Например, можно вычислять следующее выражение: `(a + b) * c`. И выражени в научной нотации: `10E5 + 10E-5`

Кроме арифметических операций, калькулятор позволяет вычислять различные математические функции, такие как:

- Косинус: `cos(x)`
- Синус: `sin(x)`
- Тангенс: `tan(x)`
- Арккосинус: `acos(x)`
- Арксинус: `asin(x)`
- Арктангенс: `atan(x)`
- Квадратный корень: `sqrt(x)`
- Натуральный логарифм: `ln(x)`
- Десятичный логарифм: `log(x)`

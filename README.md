# Проект Explorer Баранов Артём ИУ8-33
## Задание I этапа:
[![Build Status](https://travis-ci.org/Murderdoll/Homework_Explorer_01.svg?branch=master)](https://travis-ci.org/Murderdoll/Homework_Explorer_01)

- [X] 1. Вычислить свою комбинацию

Порядковый номер можно узнать на листе Домашние Задания в Цифровом Журнале.
```ShellSession
Порядковый номер: N // 6
Двоичное представление N: A[4]A[3]A[2]A[1]A[0] // 110
Комбинация: A[0],A[1],A[2],A[3..4] // 0110
```
- [X] 2. Написать программу принимающую в качестве входного параметра {
 - [X] A[0] == 0: через стандартный поток ввода
 - [] A[0] == 1: через параметры командной строки 
} путь к ресурсу файловой системы {
 - [] A[1] == 0: файл
 - [X] A[1] == 1: директория
} и выводящую в {
 - [] A[2] == 0: файл, путь к файлу задается с помощью переменной окружения EXPLORER_LOG_PATH
 - [X] A[2] == 1: стандартный поток вывода
} информацию следующего вида
 - [X] A[3..4] == 0: полный путь, размер, дата создания
 - [] A[3..4] == 1: имя, размер, дата модификации
 - [] A[3..4] == 2: имя, место расположения, тип
 - [] A[3..4] == 3: имя, дата создания, дата изменения
} c использованием std::filesystem.

Пример для комбинации 1,0,1,0:
```
$ ./explorer file.dat
path:	 /home/user/file.dat
size:	 2258 Kb
date:	 10/17/2017 8:43
```

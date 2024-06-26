#include <stdio.h>
#include <string.h>

int command(char *str, int huart1, char *com, char *arg) {
    const short len = 3+strlen(com) + strlen(arg);
    strcpy(str, "AT+");
    strcat(str, com);
    strcat(str, arg);
    //HAL_UART_Transmit_IT(&huart1, str, 24);
    return 0;
}


// таблица комманд -> https://radioprog.ru/post/397 или https://esp8266.ru/esp8266-at-commands-v022/
/*
| Команда | Описание
|---------|---------------------
| AT      | Проверить запуск AT
| AT+RST  | Перезапустить модуль
| 
*/

/*
| ТИП        | Формат команды      | Описание
|------------|---------------------|--------------------------------------------------------------------------------
| Тест       |     AT+<x>=?        | Запрос внутренних параметров и диапазона их значений для заданной команды.
| Запрос     |     AT+<x>?         | Возвращает текущее значение параметра.
| Установка  |     AT+<x>=<...>    | Установка параметров, заданных в команде пользователем, и запуск этой команды.
| Выполнение |     AT+<x>          | Запуск команды без заданных пользователем параметров.
*/


// Добавляем строку из массива app в массив dst. 
// strcat (dst, app);

#pragma once
using namespace std;
#include <vector>
#include <string>

/*!	Поиск возможных вариантов перевода с азубки Морзе на русский
 *\param[in] srcString - исходная строка, зашифрованная в азбуке Морзе
 *\param[in] currentDecodedString - строка для временного хранения промежуточных данных расшифорвки
 *\param[out] variants - вектор расшифрованных вариантов
*/
void decodeMorze(const string srcString, string currentDecodedString, vector <string>& variants);

/*! Проверка строки морзе на корректность данных
 *\param[in] morzeString - строка, которая проверяется на наличие посторонних символов
 *\throw errorIndex - номер ошибки
*/
void checkInput(const string morzeString);
#pragma once
using namespace std;
#include <vector>
#include <string>

/*!	����� ��������� ��������� �������� � ������ ����� �� �������
 *\param[in] srcString - �������� ������, ������������� � ������ �����
 *\param[in] currentDecodedString - ������ ��� ���������� �������� ������������� ������ �����������
 *\param[out] variants - ������ �������������� ���������
*/
void decodeMorze(const string srcString, string currentDecodedString, vector <string>& variants);

/*! �������� ������ ����� �� ������������ ������
 *\param[in] morzeString - ������, ������� ����������� �� ������� ����������� ��������
 *\throw errorIndex - ����� ������
*/
void checkInput(const string morzeString);
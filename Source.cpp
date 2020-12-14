#include <iostream>
#include <fstream>
#include <Windows.h> // ������������ ����������� ��������
#include <string>
using namespace std;
enum Data_narodzhennia { DEN_NARODZHENIA, MISIATS_NARODZHENNIA, RIK_NARODZHENNIA };
string data_narodzhenniaStr[] = { "����", "�����", "��" };
struct Note
{
	string prizv;
	string nomer_telephonu;
	Data_narodzhennia data_narodzhennia;
};
void Print(char* fname);
void LineSearch(char* fname);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - ���� ����� �� �����" << endl;
		cout << " [2] - ���� ���������� ��� ������, ����� �������� ��� �������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Print(fname);
			break;
		case 2:
			LineSearch(fname);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Print(char* fname)
{
	ifstream fin(fname);
	string s;
	while (!fin.eof())
	{
		fin.getline(fname, sizeof(fname));
		cout << fname << endl;
	}
}
void LineSearch(char* fname)
{
	string fname1;
	cout << "Enter the route: "; cin >> fname1;
	char line[50];
	int index = 0;
	ifstream f(fname, ios::in);
	if (!f.is_open())
	{
		cout << "File not open!" << endl;
		return;
	}
	string lines;
	int n = 0;
	while (getline(f, lines))
	{
		n++;
	}
	f.close();
	f.open(fname, ios::in);
	for (int i = 0; i < n; i++)
	{
		f.getline(line, sizeof(line));
		if (line == fname1)
			cout << line;
	}


}
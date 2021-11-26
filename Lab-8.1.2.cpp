#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


char* ChangeSim(char* dest, const char* cs, char* t, int i)
{
	if (cs[i] != 0)
	{
		if (cs[i] == '+' || cs[i] == '-' || cs[i] == '=')
		{
			strcat(t, "**");
			return ChangeSim(dest, cs, t + 2, i + 1);
		}
		else
		{
			*t++ = cs[i++];
			*t = '\0';
			return ChangeSim(dest, cs, t, i);
		}
	}

	else
	{
		*t++ = cs[i++];
		*t++ = cs[i++];
		*t = '\0';
		return dest;
	}
}

int CountSim(char* s, const char* cs)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strpbrk(s + pos, cs))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char cs[101];
	cout << "Ввод: " << endl;
	cin.getline(cs, 100);

	char s[] = "+-=";
	cout << "Кол-во: " << CountSim(cs, s) << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = ChangeSim(dest1, cs, dest1, 0);
	cout << "Вывод: " << dest1 << endl;
	return 0;
}
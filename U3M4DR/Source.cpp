#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <vector>

using namespace std;
unsigned short int nz;

int Len(int ch);
bool Pal(int N);

void main()
{
	setlocale(LC_ALL, "Rus");

start:
	cout << "Введите номер задания \n";
	cin >> nz;

	switch (nz)
	{
	case 1:
	{
		//1.	Для заданного n в одном цикле вычислить n!и n2.
		int n, kv=0, fa=1;
		cout << "Введите число \n";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			fa *= i;
			kv += n;
		}
		cout << "Квадрат = " << kv << ", факториал = " << fa << endl;
		goto start;
	}
	break;
	case 2:
	{
		/*2.	Задано натуральные числа от 10 до N.Найти наибольшую цифру 
			целого десятичного числа.*/
		int N, maks;
		cout << "Введите число > 10 \n";
		cin >> N;
		vector<int>MN(N);
		MN[0] = 10;
		for (int i = 11; i <= N; i++)
		{
			MN[i - 10] = MN[i - 11] + 1;
		}
		/*for (int i = 0; i < N-9; i++)
		{
			cout << MN[i] << endl;
		}*/
		for (int i = 1; i < N - 9; i++)
		{
			if (MN[i] > MN[i - 1]) maks = MN[i];
			else maks = MN[i - 1];
		}
		cout << "Наибольшая цифра "<<maks << endl;
		goto start;
	}
	break;
	case 3:
	{
		/*3.	Задано натуральные числа от 10 до N.Для натурального числа 
			найти первую цифру и сумму его цифр.*/
		int N, per,sum,c1,c2;
		cout << "Введите число > 10 < 100 \n";
		cin >> N;
		vector<int>MN(N);
		MN[0] = 10;
		for (int i = 11; i <= N; i++)
		{
			MN[i - 10] = MN[i - 11] + 1;
		}
		for (int i = 1; i < N - 9; i++)
		{
			c1 = MN[i] / 10;
			c2= MN[i] % 10;
			cout << "Число " << MN[i] << ", первая цифра " << c1 << ", сумма цифр " << c1 + c2 << endl;
		}
		goto start;
	}
	break;
	case 4:
	{
		/*4.	Определить, является ли целое число симметричным, т.е.таким числом, которое 
			одинаково читается слева направо и справа налево(палиндром, перевертыш).
			Например, числа 123321, 202, 9889, 5555.*/
		int N, raz;
		bool Rez;
	NN:
		cout << "Введите пяти разрядное число \n";
		cin >> N;
		raz = Len(N);
		if (raz == 5)
		{
			Rez = Pal(N);
			if (Rez == true)
			{
				cout << "Число " << N << " является симметричным \n";
				goto start;
			}
			else
			{
				cout << "Число " << N << " не является симметричным \n";
				goto start;
			}
		}
		else
		{
			cout << "Число не является пяти разрядным \n";
			goto NN;
		}

	}
	break;
	case 5:
	{
		//5.	Вывести сумму квадратов чисел от 12 до 80 по 1 - числу в строке.
		int sum=0;
		for (int i = 12; i < 89; i++)
		{
			cout << pow(i, 2) << endl;
			sum += pow(i, 2);
		}
		cout << sum << endl;
		goto start;
	}
	break;
	case 6:
	{
		//6.	Вывести разность квадратов чисел от 22 до 88 по 1 - числу в строке.
		int razn = 0;
		for (int i = 22; i < 89; i++)
		{
			cout << pow(i, 2) << endl;
			razn -= pow(i, 2);
		}
		cout << razn << endl;
		goto start;
	}
	break;
	case 7:
	{
		/*7.	Дано вещественное число A и натуральные числа от 1 до N(> 0).Найти разности
			квадратов A и натуральных чисел N .*/
		float A;
		int N;
		cout << "Введите вещественное число \n";
		cin >> A;
		cout << "Введите число \n";
		cin >> N;
		vector<int>MN(N);
		MN[0] = 1;
		for (int i = 1; i < N; i++)
		{
			MN[i] = MN[i - 1] + 1;
		}	
		for (int i = 0; i < N; i++)
		{
			cout << pow(A, 2) - pow(MN[i], 2) << endl;
		}
		goto start;
	}
	break;
	case 8:
	{
		/*8.	Задано натуральные числа от 10 до N.Найти наименьшую цифру целого 
			десятичного числа.*/
		int N, min;
		cout << "Введите число > 10 \n";
		cin >> N;
		vector<int>MN(N);
		MN[0] = 10;
		for (int i = 1; i <= N-10; i++)
		{
			MN[i] = MN[i - 1] + 1;
			//cout << MN[i] << endl;
		}
		for (int i = N-10; i > 0; i--)
		{
			if (MN[i-1] > MN[i]) min = MN[i];
			else min = MN[i-1];
		}
		cout << "Наименьшая цифра " << min << endl;
		goto start;
	}
	break;
	case 9:
	{
		/*9.	Известно количество очков, набранных каждой из 20 - ти команд - участниц 
			первенства по футболу.Перечень очков дан в порядке убывания(ни одна пара 
			команд не набрала одинаковое количество очков).Определить, какое место 
			заняла команда, набравшая N очков(естественно, что значение N имеется  
			в перечне).Условный оператор не использовать.*/
		int kom[20];
		kom[0] = 20;
		for (int i = 1; i <= 19; i++) 
			kom[i] = kom[i - 1] - 1;
		int och,n=0;
		cout << "Введите очки "; 
		cin >> och;
		int m = 0;
		while (n != och)
		{
			n = kom[m];
			m++;
		}
		cout << "Команда заняла " << m<<" место"<<endl;
		goto start;
	}
	break;
	case 10:
	{
		/*10.	Дано натуральное число  n(n < 9999).Найти предпоследнюю цифру числа
		(в предположении, что n > 10).*/
		unsigned short int ch, ost, c1, c2, c3,len;
		CH:
		cout << "Введите число болше 10 но меньше 9999 ";
		cin >> ch;
		len = Len(ch);
		switch (len)
		{
		case 2:
		{
			c3 = ch / 10;
			cout << "Предпоследняя цифра " << c3 << endl;
		}
		break;
		case 3:
		{
			c2 = ch / 100;
			ost = ch - c2 * 100;
			c3 = ost / 10;
			cout << "Предпоследняя цифра " << c3 << endl;
		}
		break;
		case 4:
		{
			c1 = ch / 1000;
			ost = ch - c1 * 1000;
			c2 = ost / 100;
			ost = ost - c2 * 100;
			c3 = ost / 10;
			cout << "Предпоследняя цифра " << c3 << endl;
		}
		break;
		default:
		{
			cout << "Вы ввели неправильно число \n";
			goto CH;
		}
		break;
		}
		goto start;
	}
	break;
	case 11:
	{
		/*11.	Даны числа от 1 до 1000 и число m.Вывести все остатки от деления четных 
			сотен на число m.*/
		int mas[1000];
		int m;
		mas[0] = 1;
		for (int i = 1; i <= 999; i++)
		{
			mas[i] = mas[i - 1] + 1;
		}
		cout << "Введите число ";
		cin >> m;
		for (int i = 0; i <= 999; i++)
		{
			if (mas[i] == 200 || mas[i] == 400 || mas[i] == 600 || mas[i] == 800)
				cout << mas[i] / m << endl;
		}
		goto start;
	}
	break;
	default:
	{
		cout << "Такого задания не существует \n";
		goto start;
	}
	break;
	}

}
int Len(int ch)
{
	// Функция считающая количестов разрядов
	int raz = 0;
	while (ch > 0)
	{
		ch = ch / 10;
		++raz;
	}
	return raz;
}
bool Pal(int N)
{
	int c1, c2, c3, c4, c5, ost;
	c1 = N / 10000;
	ost = N - (c1 * 10000);
	c2 = ost / 1000;
	ost = ost - (c2 * 1000);
	c3 = ost / 100;
	ost = ost - (c3 * 100);
	c4 = ost / 10;
	ost = ost - (c4 * 10);
	c5 = ost;
	if ((c1 == c5) && (c2 == c4)) return true;
	else return false;
}


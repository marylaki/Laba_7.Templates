// Laba_7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "time.h"
#include "Pechenie.h"

using namespace std;



template <class ML>
class Matrix
{
	
	ML **matrix;
public:
	int n;//kol-vo strok
	int m;//kol-vo stolbtsov
	Matrix();
	Matrix(int, int);
	~Matrix();
	void init_vvod()
	{
		cout << "������� �������� ������� " << n << "x" << m << endl << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
				cin >> matrix[i][j];
			}
		}
	}

	void print()
	{
		cout << "������� " << n << "x" << m << endl << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl << endl;
		}
	}
	void init_rand(int, int);

	Matrix* operator+ (const Matrix &m2)
	{
		if (this->n == m2.n && m2.m == this->m)
		{
			Matrix*m = new Matrix(this->n, this->m);
			for (int i = 0; i < this->n; i++)
			{
				for (int j = 0; j < this->m; j++)
					m->matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];
			}
			return m;
		}
		else
		{
			cout << "\nC������� �� ��������!\n����������� ������ �� ���������\n\n";
			Matrix*m = new Matrix(1, 1);
			m->matrix[0][0] = 0;
			return m;
		}
	}
	ML* operator()(int i)
	{
		i--;
		if (i >= 0 && i < this->n)
		{
			cout << i + 1 << "-�� ������ �������:\n";
			for (int v = 0; v < this->m; v++)
				cout << this->matrix[i][v] << " ";
			cout << endl;
			return this->matrix[i];
		}
		else
		{
			cout << "��� ����� ������\n���������� ������\n";
			for (int v = 0; v < this->m; v++)
				cout << this->matrix[0][v] << " ";
			cout << endl;
			return this->matrix[0];
		}
	}

	ML* operator[](int i)
	{
		return this->matrix[i];
	}


	double Det()
	{
		double det = 0, tj = 0;
		if (n != m)
		{
			cout << "������� �� �������� ����������!\n������������ �� ����������\n";
			return NULL;
		}
		if (n == 1 && m == 1)
			det = matrix[0][0]*1.0;
		else
		if (n == 2 && m == 2)
		{
			det = ((matrix[0][0] *1.0)*( matrix[1][1]*1.0)) - ((matrix[0][1]*1.0) * (matrix[1][0]*1.0));
		}
		else
		{
			for (int j = 0; j < m; j++)
			{
				Matrix* temp = new Matrix(n - 1, m - 1);
				for (int i = 1; i < n; i++)
				{
					for (int v = 0, tj = 0; v < m; v++)
					if (v != j)
					{
						temp->matrix[i - 1][tj] = matrix[i][v];
						tj++;
					}
				}
				//cout << 1 << " ������ " << j + 1 << " C������ ���������� �� ������� \n"<<matrix[0][j]<<endl;
				//this->print();
				//cout << "���������\n";
				//temp->print();
				det += matrix[0][j] * pow(-1, (j + 1 + 1))*temp->Det();
			}
		}
		//cout << "DET(M) = " << det << endl;
		return det;
	}

	bool operator<(Matrix &m2)
	{
		double dm1 = this->Det();
		double dm2 = m2.Det();
		this->print();
		cout << "Det(m1) = " << dm1 << endl;
		m2.print();
		cout << "Det(m2) = " << dm2 << endl;
		if (dm1 == dm2)
			cout << "Det(m1) = Det(m2)\n";
		if (dm1<dm2)
			cout << "Det(m1) < Det(m2)\n";
		if (dm1>dm2)
			cout << "Det(m1) > Det(m2)\n";
		return dm1 < dm2;
	}

	void operator== (const Matrix&m2)
	{
		this->~Matrix();
		matrix = new ML*[m2.n];
		for (int i = 0; i < m2.n; i++)
		{
			matrix[i] = new ML[m2.m];
		}
		n = m2.n;
		m = m2.m;
		for (int i = 0; i < m2.n; i++)
		for (int j = 0; j < m2.m; j++)
			matrix[i][j] = m2.matrix[i][j];
	}

};
/////////////////////
/////////////////////////////
///////////////////////////////////
/*7 laba ������ � ��������� �������� 2 �����,������� �������������� ������ �������� ����� ���������� */
///////////////////////////////////
////////////////////////////
/////////////////////

template<class ML> void Matrix<ML>::init_rand(int min, int max)
{
	if (min < -99) min = -99;
	if (max>999) max = 999;
	srand(unsigned(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = min + rand() % (max - min + 1);
			matrix[i][j] += (rand() % (100))*0.01;
		}
	}
	
	
}

template <class ML> Matrix<ML>::Matrix() : Matrix(3, 3)
{

}
template <class ML> Matrix<ML>::Matrix(int N, int M)
{
	n = N;
	m = M;
	matrix = new ML*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new ML[m];
	}
}
template <class ML> Matrix<ML>::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

template <class ML>int Kol(Matrix<ML>&m1, int i_el, int j_el)
{
	i_el--; j_el--;
	int kol = 0;
	if (i_el >= 0 && i_el < m1.n && j_el >= 0 && j_el < m1.m)
	{
		for (int i = 0; i < m1.n; i++)
		{
			for (int j = 0; j < m1.m; j++)
			{
				if (m1[i][j]>m1[i_el][j_el])
					kol++;
			}
		}
		cout << "� ������� ������� " << kol << " ��������� ������� " << m1[i_el][j_el] << endl;
	}
	else
		cout << "��� �������� [" << i_el+1 << "][" << j_el+1 << "]\n";
	return kol;
}

int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "Rus");
	int i,i_el,j_el;
	cout << "^^^^^^^^^^^^^^^^INT^^^^^^^^^^^^^\n\n";
	_getch();
	Matrix<int> m_int;
	//m_int.init_vvod();
	m_int.init_rand(-20,20);
	Matrix<int> m2_int;
	m2_int.init_rand(-10, 20);
	cout << "\n**************��������*************\n\n";
	m_int.print();
	cout << "+" << endl;
	m2_int.print();
	cout << "  =  " << endl;
	(m_int + m2_int)->print();
	cout << "****************************************\n";
	_getch();
	cout << "******************������ � ������ �� �********\n";
	m2_int.print();
	cout << "������� � ";
	cin>>i;
	m2_int(i);
	cout << "������� � ";
	cin >> i;
	m2_int(i);
	cout << "������� � ";
	cin >> i;
	m2_int(i);
	cout << "****************************************\n";
	_getch();
	cout << "**************������ �������************\n";
	m2_int.print();
	cout << "Det(M) = " << m2_int.Det() << endl;
	cout << "****************************************\n";
	_getch();
	cout << "**************C�������� ������� �������************\n";
	m_int < m2_int;
	cout << "****************************************\n";
	_getch();
	cout << "*************�����������**********\n";
	cout << "B M1:\n";
	m_int.print();
	cout << "�� M2:\n";
	m2_int.print();
	m_int == m2_int;
	cout << "��������� M1 :\n";
	m_int.print();
	cout << "*****************************************\n";
	_getch();
	cout << "***********���������� ��������� ������� ���������*****\n";
	m2_int.print();
	cout << "������� ����� ������ "; cin >> i_el;
	cout << "������� ����� ������� "; cin >> j_el;
	Kol(m2_int, i_el, j_el);
	cout << "****************************************************\n\n";
	_getch();
	cout << "^^^^^^^^^^^^^^^^DOUBLE^^^^^^^^^^^^^\n\n";
	_getch();
	Matrix<double> m_doub;
	Matrix<double> m2_doub(2,2);
	//m_doub.init_vvod();
	m_doub.init_rand(-30,30);
	m2_doub.init_rand(-15, 20);
	cout << "\n**************��������*************\n\n";
	m_doub.print();
	cout << "+" << endl;
	m2_doub.print();
	cout << "  =  " << endl;
	(m_doub + m2_doub)->print();
	cout << "****************************************\n";
	_getch();
	cout << "******************������ � ������ �� �********\n";
	m2_doub.print();
	cout << "������� � ";
	cin >> i;
	m2_doub(i);
	cout << "������� � ";
	cin >> i;
	m2_doub(i);
	cout << "������� � ";
	cin >> i;
	m2_doub(i);
	cout << "****************************************\n";
	_getch();
	cout << "**************������ �������************\n";
	m2_doub.print();
	cout << "Det(M) = " << m2_doub.Det() << endl;
	cout << "****************************************\n";
	_getch();
	cout << "**************C�������� ������� �������************\n";
	m_doub < m2_doub;
	cout << "****************************************\n";
	_getch();
	cout << "\n*************�����������**********\n\n";
	cout << "B M1:\n";
	m_doub.print();
	cout << "�� M2:\n";
	m2_doub.print();
	m_doub == m2_doub;
	cout << "��������� M1 :\n";
	m_doub.print();
	cout << "\n*****************************************\n";
	_getch();
	cout << "***********���������� ��������� ������� ���������*****\n";
	m2_doub.print();
	cout << "������� ����� ������ "; cin >> i_el;
	cout << "������� ����� ������� "; cin >> j_el;
	Kol(m2_doub, i_el, j_el);
	cout << "****************************************************\n\n";
	_getch();


	cout << "^^^^^^^^^^^^^^^^PECHENIE^^^^^^^^^^^^^\n\n";
	_getch();
	Matrix<Pechenie> m_pech;
	Matrix<Pechenie> m2_pech;
	//m_pech.init_vvod();
	m_pech.init_rand(-20,20);
	m2_pech.init_rand(0, 30);
	cout << "\n**************��������*************\n\n";
	m_pech.print();
	cout << "+" << endl;
	m2_pech.print();
	cout << "  =  " << endl;
	(m_pech + m2_pech)->print();
	cout << "****************************************\n";
	_getch();
	cout << "******************������ � ������ �� �********\n";
	m2_pech.print();
	cout << "������� � ";
	cin >> i;
	m2_pech(i);
	cout << "������� � ";
	cin >> i;
	m2_pech(i);
	cout << "������� � ";
	cin >> i;
	m2_pech(i);
	cout << "****************************************\n";
	_getch();
	cout << "**************������ �������************\n";
	m2_pech.print();
	cout << "Det(M) = " << m2_pech.Det() << endl;
	cout << "****************************************\n";
	_getch();
	cout << "**************C�������� ������� �������************\n";
	m_pech < m2_pech;
	cout << "****************************************\n";
	_getch();
	cout << "\n*************�����������**********\n\n";
	cout << "B M1:\n";
	m_pech.print();
	cout << "�� M2:\n";
	m2_pech.print();
	m_pech == m2_pech;
	cout << "��������� M1 :\n";
	m_pech.print();
	cout << "\n*****************************************\n";
	_getch();
	cout << "***********���������� ��������� ������� ���������*****\n";
	m2_pech.print();
	cout << "������� ����� ������ "; cin >> i_el;
	cout << "������� ����� ������� "; cin >> j_el;
	Kol(m2_pech, i_el, j_el);
	cout << "****************************************************\n\n";
	_getch();

	return 0;
}


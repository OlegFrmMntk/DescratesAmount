#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t;
	fin >> t;

	for (int q = 0; q < t; q++)
	{
		int G[111][111], H[111][111];
		map < pair <pair <int, int>, pair <int, int>>, int > GH;

		int n1;
		fin >> n1;

		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n1; j++)
			{
				fin >> G[i][j];
			}

		int n2;
		fin >> n2;

		for (int i = 1; i <= n2; i++)
			for (int j = 1; j <= n2; j++)
			{
				fin >> H[i][j];
			}

		vector < pair <int, int>> Answer;
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++) // Формирование множества всех вершин
			{
				Answer.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < Answer.size(); i++)
			for (int j = 0; j < Answer.size(); j++) // Обнуляем матрицу смежности
				GH[make_pair(Answer[i],Answer[j])] = 0;

		for (int i = 0; i < Answer.size(); i++)
			for (int j = i + 1; j < Answer.size(); j++)
				if (G[Answer[i].first][Answer[j].first] || H[Answer[i].second][Answer[j].second])// Проверяем вершины на смежность
				{
					GH[make_pair(Answer[i], Answer[j])] = 1;
					GH[make_pair(Answer[j], Answer[i])] = 1;// Помечаем в матрице смежности, что между вершинами есть ребро
				}

		fout << "      ";
		for (int i = 0; i < Answer.size(); i++)
		{
			fout << "(" << Answer[i].first << ", " << Answer[i].second << ") "; // выводим название всех вершин
		}

		for (int i = 0; i < Answer.size(); i++)
		{
			fout << "\n(" << Answer[i].first << ", " << Answer[i].second << ") " << "  " << GH[make_pair(Answer[i], Answer[0])];
			// Выводи матрицу смежности
			for (int j = 1; j < Answer.size(); j++)
				fout << "      " << GH[make_pair(Answer[i], Answer[j])];
		} 
	}

}
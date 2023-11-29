#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
    m_Mat = new int * [size];
    for (int i = 0; i < size; i++)
        m_Mat[i] = new int [size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            m_Mat[i][j] = 0;
    }
}

MatrixGraph::~MatrixGraph()
{
    for (int i = 0; i < m_Size; i++)
        delete[] m_Mat[i];
    delete[] m_Mat;
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{	
    for (int i = 0; i < m_Size; i++)
    {
        if (m_Mat[vertex - 1][i])
            m->insert(map<int, int>::value_type(i + 1, m_Mat[vertex][i]));
        if (m_Mat[i][vertex - 1])
            m->insert(map<int, int>::value_type(i + 1, m_Mat[vertex][i]));
    }
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)
{
	for (int i = 0; i < m_Size; i++)
    {
        if (m_Mat[vertex - 1][i])
            m->insert(map<int, int>::value_type(i + 1, m_Mat[vertex][i]));
    }
}

void MatrixGraph::insertEdge(int from, int to, int weight)	
{
	m_Mat[from][to] = weight; // need to fix
}

bool MatrixGraph::printGraph(ofstream *fout)	
{
    if (!(fout->is_open()))
        return false;
	*fout << "========PRINT========" << endl;
    *fout << "    ";
    for (int i = 0; i < m_Size; i++)
        *fout << '[' << i + 1 << "] ";
    *fout << endl;
    for (int i = 0; i < m_Size; i++)
    {
        *fout << '[' << i + 1 << "] ";
        for (int j = 0; j < m_Size; j++)
        {
            fout->width(3);
            fout->fill(' ');
            *fout << m_Mat[i][j];
            *fout << ' ';
        }
        *fout << endl;
    }
    *fout << "=====================" << endl << endl;
    return true;
}
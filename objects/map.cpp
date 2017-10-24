#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"

Map::Map(int N,int M)
{
    create_map(N,M);
}

void Map::create_map(int N,int M)
{
    m_wall = new int [N][M]
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            m_wall[i][j] = '*';
        
    for(int i = 0; i < N; i++)
    {
        m_wall[i][0] = 'X';
        m_wall[i][M-1] = 'X';
    }
    for(int j = 0; j < M; j++)
    {
        m_wall[0][j] = 'X';
        m_wall[N-1][j] = 'X';
    }
    


}

void Map::print_map()
{
    for(int i = 0; i < N; i++)
    {   
        for(int j = 0; j < M; j++)
        {
            if(m_wall[i][j] == 'X')
                cout<<"XX";
            else 
                cout<<"* ";
        }
        cout<<endl;
    }   
}






















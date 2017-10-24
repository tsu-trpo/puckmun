#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"



Map::Map(int k)
{
    switch(k){
        case 1: create_map1();
                break;
        /*case 2: create_map2();
                break;
        case 3: create_map3;
                break;
          */    }
}

void Map::create_map1()
{
    m_N = 10;
    m_M = 10;
    create_wall(m_N,m_M);
    for(int i = 1; i < 4; i++)
        m_wall[i][4] = Wall;
    m_wall[2][2] = Wall;
    m_wall[3][2] = Wall;
    m_wall[2][6] = Wall;
    m_wall[2][7] = Wall;
    m_wall[4][7] = Wall;
    m_wall[5][2] = Wall;
    m_wall[5][3] = Wall;
    m_wall[5][4] = Wall;
    m_wall[5][6] = Wall;
    m_wall[5][7] = Wall;
    m_wall[5][8] = Wall;
    m_wall[6][7] = Wall;
    m_wall[6][8] = Wall;
    for(int i = 2; i < 6; i++)
        m_wall[7][i] = Wall;
    m_wall[1][3] = BigPoint;
    m_wall[4][8] = BigPoint;
    m_wall[6][8] = BigPoint;
    m_wall[8][1] = BigPoint;
}
void Map::create_wall(const int N,const int M)
{
    m_N = N;
    m_M = M;
    m_wall = new block_t * [N];
    for(int i = 0; i < N; i++)
        m_wall[i] = new block_t [M];

    for(int i = 0; i < m_N; i++)
        for(int j = 0; j < m_M; j++)
            m_wall[i][j] = Point;
        
    for(int i = 0; i < m_N; i++)
    {
        m_wall[i][0] = Wall;
        m_wall[i][m_M-1] = Wall;
    }
    for(int j = 0; j < m_M; j++)
    {
        m_wall[0][j] = Wall;
        m_wall[m_N-1][j] = Wall;
    }
    


}

void Map::print_map()
{
    
    for(int i = 0; i < m_N; i++)
    {   
        for(int j = 0; j < m_M; j++)
        {
             cout<<char(m_wall[i][j]);
        }
        cout<<endl;
    }   
}






















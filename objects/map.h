#include <stdio.h>
#include <iostream>
#include <stdlib.h>

typedef int block_t;

const block_t Wall = 'X';
const block_t Point = '.';
const block_t BigPoint = '*';
    

using namespace std;

class Map
    {
        //int x;
        //int y;
        int m_N;
        int m_M;
        int ** m_wall;
        
    public:
        Map(int);
        Map(const Map&);
        void create_wall(int,int);
        void create_map1();
        void print_map();
    } ;

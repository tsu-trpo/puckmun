#include <stdio.h>
#include <iostream>
#include <stdlib.h>

typedef int block_t;

const block_t Wall = 'X';
const block_t Point = '*';
const block_t BigPoint = '#';
    

using namespace std;

class Map
    {
        //int x;
        //int y;
        int m_wall[][];
        //int m_;
        //int m_;
    public:
        Map(int,int);
        Map(const Map&);
        void create_map(int,int);
        void print_map();
    } ;

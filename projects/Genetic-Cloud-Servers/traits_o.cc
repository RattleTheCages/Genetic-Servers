/**  traits_o.cc  *************************************************************

 Copyright 12.31.1999  Performance Server Library v2.000  Daniel Huffman



    DNA Artifical Intellegence Chromosome Object.




when        who        what
9.24.96     Dan        Creation.
6.14.98     Dan        Changed:  Object name from chromosome_ to chromosome_o.
            Dan        Added:    Some constructors, genes method.
9.2.99      Dan        Changed:  Using global_o object now.
12.24.99    Dan        Changed:  Object serial definition to OLP.


*******************************************************************************/


#include "traits_o.h"


traits_o::traits_o()  {}

traits_o::traits_o(const traits_o& t)  {}

traits_o::~traits_o()  {}

traits_o& traits_o::operator = (const traits_o& t)  {
    return *this;
}

//int trait_o::operator [](int t)  const  {
int traits_o::trait(int t, const entity_o& e)  {
    if(t < 0 || t > 6)  return  0;

    switch(t)  {
        case 1:
            return  trait1(e);

        case 2:
            return  trait2(e);

        default:
            return  0;
}
}



int traits_o::trait1(const entity_o& e)  {
    int x, y;
    int r = 0;
    int* m = new int[e.Chromosomes[0]->numberOfGenes()];


    for(x = 0; x < e.numberOfChromosomes(); x++)  {
        for(y = 0; y < 22; y++)  {
            m[y] = m[y] % (*e.Chromosomes[x])[y];
        }
    }

    for(y = 0; y < 22; y++)  r += m[y];

    delete m;

    return  r;

}

int traits_o::trait2(const entity_o& e)  {
    return  2;
    int x, y;
    int r = 0;
    int* m = new int[e.Chromosomes[0]->numberOfGenes()];


    for(x = 0; x < e.numberOfChromosomes(); x++)  {
        for(y = 23; y < 44; y++)  {
            m[y] = m[y] % (*e.Chromosomes[x])[y];
        }
    }

    for(y = 0; y < 22; y++)  r += m[y];

    delete m;

    return  r;
}



/******************************************************************************/

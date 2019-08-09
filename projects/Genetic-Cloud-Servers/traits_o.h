/**  traits_o.h  **************************************************************

 Copyright 12.31.1999  Performance Server Library v2.000  Daniel Huffman



    DNA Artifical Intellegence Chromosome Object.



when        who        what
9.24.96     Dan        Creation.
6.14.98     Dan        Changed:  Object name from chromosome_ to chromosome_o.
                                 Moved genes object to private.
            Dan        Added:    Some constructors, genes method.
6.15.98     Dan        Added:    Constructor chromosome_o(rand_o&).
9.2.99      Dan        Removed:  Constructor chromosome_o(rand_o&), and rand_o
                                 object from data members.
12.24.99    Dan        Changed:  Object serial definition to OLP.

*******************************************************************************/


#ifndef TraitsOBJECT_API
#define TraitsOBJECT_API


#include "string_o"
#include "entity_o"


#define CHROMOSOME_OBJECT          "chromosome_o"
#define CHROMOSOME_NUMBER_OF_GENES "numofgenes"
#define CHROMOSOME_GENES           "genes"

#define CHROMOSOME_MAX_NUMBER_OF_GENES 16384


class traits_o  {
  private:

  public:
    traits_o();
    traits_o(const traits_o&);
    virtual        ~traits_o();
    traits_o&   operator = (const traits_o&);
    void            operator >> (string_o&) const;      // OLP representation.
    void            operator << (const char*);          // Reconstruct from OLP.

    int    operator [](int)        const;

    int    trait(int, const entity_o&);


    int  trait1(const entity_o&);
    int  trait2(const entity_o&);

};

/******************************************************************************/



#endif

/******************************************************************************/

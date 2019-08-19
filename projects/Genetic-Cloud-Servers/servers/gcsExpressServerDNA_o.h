/**  gcsExpressServerDNA_o.h  *************************************************
                                   Copyright 2019  Rattle  All rights reserved.


            Genetic Cloud Servers



            Express Genetic Cloud Server DNA.




            Express the DNA genotypes into their Genetic Cloud Server phenotypes.

*******************************************************************************/

#ifndef GCSExpressDNA_API
#define GCSExpressDNA_API

#include "list_o"
#include "gcsDNA_o.h"
#include "gcsVMInfo_o.h"

class gcsExpressServerDNA_o  {
  protected:
    int         State;

    list_o<gcsVMInfo_o>  VMInfoList;

  public:
    gcsExpressServerDNA_o();
    gcsExpressServerDNA_o(const gcsExpressServerDNA_o&);
    virtual ~gcsExpressServerDNA_o();
    gcsExpressServerDNA_o& operator = (const gcsExpressServerDNA_o&);

    int     state() const;

    void    expressGenes(gcsDNA_o&, gcsVMInfo_o&);

    void    dumpVMList(string_o&);
};


/******************************************************************************/

inline int gcsExpressServerDNA_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

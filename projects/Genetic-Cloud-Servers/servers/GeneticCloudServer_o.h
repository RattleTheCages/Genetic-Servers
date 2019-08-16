/**  GeneticCloudServer_o.h  ***************************************************

            Genetic-Cloud-Servers



            Server



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef GeneticCloudServer_API
#define GeneticCloudServer_API

#include "pserver_o"
#include "entity_o"      // Server DNA!
#include "gcsDNA_o.h"

class GeneticCloudServer_o : public gcsDNA_o, public pserver_o  {
  protected:
    int         State;
    //string_o    Name;

  public:
    GeneticCloudServer_o();
    GeneticCloudServer_o(const gcsDNA_o&);
    GeneticCloudServer_o(const GeneticCloudServer_o&);
    virtual ~GeneticCloudServer_o();
    GeneticCloudServer_o& operator = (const GeneticCloudServer_o&);

    int     state() const;

    int     start();

    const char* name() const;

int loadDNAColony();
};


/******************************************************************************/

inline int GeneticCloudServer_o::state() const  {
    return  State;
}

inline const char* GeneticCloudServer_o::name() const  {
    return  Name.string();
}



#endif

/******************************************************************************/

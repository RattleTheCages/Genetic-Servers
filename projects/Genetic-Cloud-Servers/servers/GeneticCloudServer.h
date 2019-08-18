/**  GeneticCloudServer_o.h  **************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Genetic Cloud Server Object



*******************************************************************************/

#ifndef GeneticCloudServer_API
#define GeneticCloudServer_API

#include "pserver_o"
#include "time_o"
#include "entity_o"      // Server DNA!
#include "gcsDNA_o.h"
#include "gcsVMInfo_o.h"

class GeneticCloudServer_o : public gcsDNA_o, public pserver_o  {
  protected:
    int         State;
    time_o      Time;
    gcsVMInfo_o vminfo;

    int         StartTime;
    int         Duration;

  public:
    GeneticCloudServer_o();
    GeneticCloudServer_o(const gcsDNA_o&);
    GeneticCloudServer_o(const GeneticCloudServer_o&);
    virtual ~GeneticCloudServer_o();
    GeneticCloudServer_o& operator = (const GeneticCloudServer_o&);

    int     state() const;

    int     start();

    int     loop();

    const char* name() const;

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

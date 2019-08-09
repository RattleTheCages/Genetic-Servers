/**  GeneticCloudServerDNA_o.h  ***********************************************

            Genetic-Cloud-Servers



            Server DNA



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef GeneticCloudServerDNA_API
#define GeneticCloudServerDNA_API

#include "pserver_o"
#include "entity_o"      // Server DNA!
#include "traits_o.h"

class GeneticCloudServerDNA_o : public entity_o, public traits_o  {
  protected:
    int         State;

  public:
    GeneticCloudServerDNA_o();
    GeneticCloudServerDNA_o(const GeneticCloudServerDNA_o&);
    virtual ~GeneticCloudServerDNA_o();
    GeneticCloudServerDNA_o& operator = (const GeneticCloudServerDNA_o&);

    int     state() const;

                                      // DNA genotypes:
    int     numberOfWorkerThreads();  // These virtual server parameters
    int     numberOfGateThreads();    // are traits revealed in the
    int     numberOfCPUs();           // Genetic Cloud Server DNA.
    int     diskSpaceSize();
    int     operatingSystemID();      // E.g.:
                                      // (1) Amazon Linux 2 AMI (HVM)
                                      // (2) Red Hat Enterprise Linux 8 (HVM)
                                      // (3) SUSE Linux Enterprise Server 15 SP1 (HVM)
                                      // (4) Ubuntu Server 18.04 LTS (HVM)
    int     operatingSystemConfig();  // Configuration script executed to setup
                                      // operating system on the virtual server.


};


/******************************************************************************/

inline int GeneticCloudServerDNA_o::state() const  {
    return  State;
}

inline int GeneticCloudServerDNA_o::numberOfWorkerThreads()  {
    return  traits_o::trait(1, *this);
}

inline int GeneticCloudServerDNA_o::numberOfGateThreads()  {
    return  traits_o::trait(2, *this);
}

inline int GeneticCloudServerDNA_o::numberOfCPUs()  {
    return  traits_o::trait(3, *this);
}

inline int GeneticCloudServerDNA_o::diskSpaceSize()  {
    return  traits_o::trait(4, *this);
}

inline int GeneticCloudServerDNA_o::operatingSystemID()  {
    return  traits_o::trait(5, *this);
}

inline int GeneticCloudServerDNA_o::operatingSystemConfig()  {
    return  traits_o::trait(6, *this);
}


#endif

/******************************************************************************/

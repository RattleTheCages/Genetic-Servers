/**  gcsDNA_o.h  **************************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Server DNA



            Server DNA genotypes expressed as server behavior phenotypes.

*******************************************************************************/

#ifndef GCS_DNA_API
#define GCS_DNA_API

#include "pserver_o"
#include "entity_o"      // Server DNA!
#include "traits_o.h"

class gcsDNA_o : public entity_o, public traits_o  {
  protected:
    int         State;

  public:
    gcsDNA_o();
    gcsDNA_o(const entity_o&);
    gcsDNA_o(const gcsDNA_o&);
    virtual ~gcsDNA_o();
    gcsDNA_o& operator = (const gcsDNA_o&);

    int     state() const;


                      // Phenotypes expressed from Server DNA:

    int     numberOfWorkerThreads();          // These virtual server parameters
    int     numberOfGateThreads();            // are traits revealed in the
    int     numberOfCPUs();                   // Genetic Cloud Server DNA.
    int     ramSize();
    int     diskSpaceSize();                
    int     bandwidthSize();                
    int     operatingSystemID();              // E.g.:
                                              // (1) Amazon Linux 2 AMI (HVM)
                                              // (2) Red Hat Enterprise Linux 8 (HVM)
                                              // (3) SUSE Linux Enterprise Server 15 SP1 (HVM)
                                              // (4) Ubuntu Server 18.04 LTS (HVM)
    int     operatingSystemConfig();          // Configuration script executed to setup
                                              // operating system on the virtual server.
    int     cloudService();                   // Cloud service on which to execute this
                                              // server.  E.g.:
                                              // (1) Amazon Cloud aws ec2
                                              // (2) Google Cloud
                                              // (3) Azure Cloud
    int     duration();
                                      


};


/******************************************************************************/

inline int gcsDNA_o::state() const  {
    return  State;
}


#endif

/******************************************************************************/

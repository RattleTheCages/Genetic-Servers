/**  gcsDNA_o.h  **************************************************************

            Genetic-Cloud-Servers



            Server DNA



                           Copyright 2019  Daniel Huffman  All rights reserved.

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

                                              // DNA genotypes:
    int     numberOfWorkerThreads();          // These virtual server parameters
    int     numberOfGateThreads();            // are traits revealed in the
    int     numberOfCPUs();                   // Genetic Cloud Server DNA.
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
                                      


};


/******************************************************************************/

inline int gcsDNA_o::state() const  {
    return  State;
}

inline int gcsDNA_o::numberOfWorkerThreads()  {
    return  traits_o::trait(1, *(entity_o*)this);
}

inline int gcsDNA_o::numberOfGateThreads()  {
    return  traits_o::trait(2, *this);
}

inline int gcsDNA_o::numberOfCPUs()  {
    return  traits_o::trait(3, *this);
}

inline int gcsDNA_o::diskSpaceSize()  {
    return  traits_o::trait(4, *this);
}

inline int gcsDNA_o::operatingSystemID()  {
    return  traits_o::trait(5, *this);
}

inline int gcsDNA_o::operatingSystemConfig()  {
    return  traits_o::trait(6, *this);
}

inline int gcsDNA_o::bandwidthSize()  {
    return  traits_o::trait(7, *this);
}

inline int gcsDNA_o::cloudService()  {
    return  traits_o::trait(8, *this);
}



#endif

/******************************************************************************/

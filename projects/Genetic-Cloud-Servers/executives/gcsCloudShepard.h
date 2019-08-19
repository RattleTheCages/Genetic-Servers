/**  gcsCloudShepard.h  *******************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Cloud Shepard Object



            The executive controlling the fates of the Genetic Cloud Servers.

*******************************************************************************/

#ifndef gcsCloudShepard_API
#define gcsCloudShepard_API

#include "pserver_o"
#include "carapace_o"
#include "input_o"
#include "output_o"
#include "queue_o"
#include "thread_o"
#include "sortList_o"
#include "colony_o"
#include "gcsStatusPacket_o.h"

class gcsCloudShepard_o : public pserver_o  {
  protected:
    int         State;
    colony_o    flock;
    thread_o    loadThread;
    queue_o<gcsStatusPacket_o>  queueOfGeneticCloudServers;
    sortList_o<gcsStatusPacket_o>  sortedListOfGeneticCloudServers;

  public:
    gcsCloudShepard_o();
    gcsCloudShepard_o(const gcsCloudShepard_o&);
    virtual ~gcsCloudShepard_o();
    gcsCloudShepard_o& operator = (const gcsCloudShepard_o&);

    int     state() const;


    int     start();
    int     process(input_o&, output_o&);

    int     processedLoad();

    int     spawnGeneticCloudServer();
    int     loadDNAColony();

    void    loadThreadLoop();

    int     processStatusPacket(input_o&, output_o&);
    int     processLoadPacket(input_o&, output_o&);
};


/******************************************************************************/

inline int gcsCloudShepard_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

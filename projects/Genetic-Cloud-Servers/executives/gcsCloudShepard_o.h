/**  gcsCloudShepard_o.h  *********************************************************

            Cloud-Shepard



            Server



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef gcsCloudShepard_API
#define gcsCloudShepard_API

#include "pserver_o"
#include "carapace_o"
#include "input_o"
#include "output_o"
#include "queue_o"
#include "sortList_o"
#include "colony_o"
#include "gcsShepardPacket_o.h"

class gcsCloudShepard_o : public pserver_o /*, public carapace_o*/  {
//  friend class carapace_o;
  protected:
    int         State;
    colony_o    flock;
    queue_o<gcsShepardPacket_o>  queueOfGeneticCloudServers;
    sortList_o<gcsShepardPacket_o>  sortedListOfGeneticCloudServers;

  public:
    gcsCloudShepard_o();
    gcsCloudShepard_o(const gcsCloudShepard_o&);
    virtual ~gcsCloudShepard_o();
    gcsCloudShepard_o& operator = (const gcsCloudShepard_o&);

    int     state() const;


    int     start();
    int     process(input_o&, output_o&);

    int     spawnGeneticCloudServer();
    int     loadDNAColony();
};


/******************************************************************************/

inline int gcsCloudShepard_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

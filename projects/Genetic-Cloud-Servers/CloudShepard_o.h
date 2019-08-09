/**  CloudShepard_o.h  *********************************************************

            Cloud-Shepard



            Server



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef CloudShepard_API
#define CloudShepard_API

#include "pserver_o"
#include "carapace_o"
#include "input_o"
#include "output_o"
#include "queue_o"
#include "../Code-from-the-90s/projects/library/lib/memory/sortList_o.h"
#include "CloudShepardPacket_o.h"

class CloudShepard_o : public pserver_o /*, public carapace_o*/  {
//  friend class carapace_o;
  protected:
    int         State;
    queue_o<CloudShepardPacket_o>  queueOfGeneticCloudServers;
    sortList_o<CloudShepardPacket_o>  sortedListOfGeneticCloudServers;

  public:
    CloudShepard_o();
    CloudShepard_o(const CloudShepard_o&);
    virtual ~CloudShepard_o();
    CloudShepard_o& operator = (const CloudShepard_o&);

    int     state() const;


    int     start();
    int     process(input_o&, output_o&);
};


/******************************************************************************/

inline int CloudShepard_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

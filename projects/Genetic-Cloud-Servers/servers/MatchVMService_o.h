/**  MatchVMService_o.h  ******************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Match VM Service   



            Match server DNA to a virtual machine profile.

*******************************************************************************/

#ifndef MatchVMService_API
#define MatchVMService_API

#include "list_o"
#include "gcsDNA_o.h"
#include "gcsVMInfo_o.h"

class MatchVMService_o  {
  protected:
    int         State;

    list_o<gcsVMInfo_o>  VMInfoList;

  public:
    MatchVMService_o();
    MatchVMService_o(const MatchVMService_o&);
    virtual ~MatchVMService_o();
    MatchVMService_o& operator = (const MatchVMService_o&);

    int     state() const;

    void    dumpVMList(string_o&);

    void    match(gcsDNA_o&, gcsVMInfo_o&);

};


/******************************************************************************/

inline int MatchVMService_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

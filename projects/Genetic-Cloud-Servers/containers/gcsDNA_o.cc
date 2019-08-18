/**  gcsDNA_o.cc  *************************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Server DNA



            Server DNA genotypes expressed as server behavior phenotypes.

*******************************************************************************/

#include "gcsDNA_o.h"


gcsDNA_o::gcsDNA_o() : State(2) , entity_o(2002, 8, 200, 2002, "bob", 2002)  {}

gcsDNA_o::gcsDNA_o(const entity_o& entity) : State(2) , entity_o(entity)  {}

gcsDNA_o::gcsDNA_o(const gcsDNA_o& dna) : entity_o(dna)  {
    State = dna.State;
}

gcsDNA_o::~gcsDNA_o()  {}


int gcsDNA_o::numberOfWorkerThreads()  {
    int nowt = traits_o::trait(1, *(entity_o*)this);

    nowt = nowt % 100000;
    nowt = nowt / 2000;
    nowt = nowt + 2;

    return  nowt;
}

int gcsDNA_o::numberOfGateThreads()  {
    int nogt = traits_o::trait(2, *this);

    nogt = nogt % 100000;
    nogt = nogt / 8000;
    nogt = nogt + 2;

    return  nogt;
}

int gcsDNA_o::numberOfCPUs()  {
    int nocpus = traits_o::trait(3, *this);

    nocpus = nocpus % 24;
    if(nocpus < 8)  return 1;
    if(nocpus == 8)  return   2;
    if(nocpus == 9)  return   2;
    if(nocpus == 10)  return  2;
    if(nocpus == 11)  return  4;
    if(nocpus == 12)  return  4;
    if(nocpus == 13)  return  4;
    if(nocpus == 14)  return  8;
    if(nocpus == 15)  return  8;
    if(nocpus == 16)  return  8;
    if(nocpus == 17)  return  16;
    if(nocpus == 18)  return  16;
    if(nocpus == 19)  return  32;
    if(nocpus == 20)  return  32;
    if(nocpus == 21)  return  48;
    if(nocpus == 22)  return  72;
    if(nocpus == 23)  return  96;

    return  1;
}

int gcsDNA_o::ramSize()  {
    int rams = traits_o::trait(4, *this);

    rams = rams % 1048544;

    rams = rams / 1000;

    return  rams;
}

int gcsDNA_o::diskSpaceSize()  {
    int dss = traits_o::trait(5, *this);

    dss = dss % 4000;

    return  dss;
}

int gcsDNA_o::operatingSystemID()  {
    int osid = traits_o::trait(6, *this);

    osid = osid % 16;

    return  osid;
}

int gcsDNA_o::operatingSystemConfig()  {
    int ossc = traits_o::trait(7, *this);

    ossc = ossc % 8;

    return  ossc;
}

int gcsDNA_o::bandwidthSize()  {
    int bw = traits_o::trait(8, *this);
    bw = bw % 4;
    bw = bw * 10;
}

int gcsDNA_o::cloudService()  {
    int serv = traits_o::trait(9, *this);
    serv = serv % 3;
    return  serv;
}

int gcsDNA_o::duration()  {
    int dur;

    dur = traits_o::trait(10, *this);
    dur = dur % 100;
    dur = dur / 10 + 1;
    dur = dur * 10;

    return  dur;
}



/******************************************************************************/

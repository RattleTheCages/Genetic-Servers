/**  gcsCloudShepard.cc  ******************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Cloud Shepard Implementation




            The executive controlling the fates of the Genetic Cloud Servers.



*******************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "rand_o"
#include "entity_o"
#include "colony_o"
#include "gcsCloudShepard.h"

log_o       log;
rand_o      rndm;
sysinfo_o   sysinfo;
carapace_o  carapace;
gcsCloudShepard_o cloudShepard;


void* gcsCloudShepard_oThreadLoop(void*);

gcsCloudShepard_o::gcsCloudShepard_o() : State(2) {}

gcsCloudShepard_o::~gcsCloudShepard_o()  {}


int gcsCloudShepard_o::loadDNAColony()  {
    flock.load("dna.olp");
}


int gcsCloudShepard_o::start()  {
    int     r = 0;
    string_o ls;
    gcsStatusPacket_o* cspp;
    gcsStatusPacket_o* geneticServer;


    loadDNAColony();

    loadThread.start(gcsCloudShepard_oThreadLoop, this);


    r = serveport(8228);
    if(r)  return  r;



        spawnGeneticCloudServer();





    while(2)  {
        cspp = queueOfGeneticCloudServers.get();

        geneticServer = new gcsStatusPacket_o(*cspp);
        sortedListOfGeneticCloudServers.put(geneticServer->load(), geneticServer);

        geneticServer = sortedListOfGeneticCloudServers.first();
        while(geneticServer)  {
            (ls = "") << "In sorted list: ";
            geneticServer->Serialize(ls);
            log << ls;
            geneticServer = sortedListOfGeneticCloudServers.next();
        }




    }  


    persist();

    return  2;
}

void gcsCloudShepard_o::loadThreadLoop()  {
    int      n = 0;
    string_o ls;
    gcsStatusPacket_o* gcs;

    while(2)  {

        (ls="\n") << "Checking load.";
        log << ls;

        n = 1;
        gcs = sortedListOfGeneticCloudServers.first();
        (ls = "") << "In sorted list: ";
        log << ls;
        while(gcs)  {
            (ls="") << n++;
            gcs->Serialize(ls);
            log << ls;

            gcs = sortedListOfGeneticCloudServers.next();
        }


        loadThread.usleep(2000000);

    }
}

int gcsCloudShepard_o::process(input_o& input, output_o& output)  {


    string_o      out;
    string_o      ls;
    gcsStatusPacket_o* cspp;


    cspp = new gcsStatusPacket_o();
    (ls = "") << input.message();
    log << ls;
    cspp->Deserialize(input.message());


    queueOfGeneticCloudServers.put(cspp);

    cspp->setName("gcsCloudShepard_o");
    cspp->Serialize(out);

    output.setMessage(out.string());

    (ls = "") << "gcsCloudShepard_o::carapace_o::process( socket(" << input.socket() << "), sequence(";
    ls << cspp->sequence() << ") ) finished.";
    log << ls;

    return  0;
}

int carapace_o::process(input_o& input, output_o& output)  {
    return  cloudShepard.process(input, output);
}

int main(int argc, char* argv[])  {
    return  cloudShepard.start();
}

int gcsCloudShepard_o::spawnGeneticCloudServer()  {

    entity_o e(*flock.entities()[0]);

string_o ls;
string_o systemString;

    systemString << "./GeneticCloudServer " << e.uniqueid() << " >> gcs.log &";

log << systemString;

system(systemString.string());

    return  2;
}

void* gcsCloudShepard_oThreadLoop(void* gcsCloudShepard_oThread)  {
    (void)((gcsCloudShepard_o*)gcsCloudShepard_oThread)->loadThreadLoop();
    (void)((thread_o*)gcsCloudShepard_oThread)->exit();
    return  gcsCloudShepard_oThread;
}


/******************************************************************************/

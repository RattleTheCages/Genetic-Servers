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
#include "time_o"
#include "list_o"
#include "entity_o"
#include "colony_o"
#include "client_o"
#include "gcsLoad_o.h"
#include "gcsCloudShepard.h"

log_o       log;
rand_o      rndm;
time_o      tyme;
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

    r += serveport(8228);
  //r += serveport(8828);
    if(r)  return  r;

    loadDNAColony();

    loadThread.start(gcsCloudShepard_oThreadLoop, this);





        //spawnGeneticCloudServer();





    while(2)  {
        cspp = queueOfGeneticCloudServers.get();

        geneticServer = new gcsStatusPacket_o(*cspp);
        sortedListOfGeneticCloudServers.put(geneticServer->load(), geneticServer);

    }  


    persist();

    return  2;
}

void gcsCloudShepard_o::loadThreadLoop()  {
    int      n = 0;
    int      loadProcessed = 0;
    int      repLoad = 0;
    string_o ls;
    string_o ss;
    string_o rs;
    client_o  client;
    gcsLoad_o load;
    gcsStatusPacket_o* gcs;

    while(2)  {

        (ls="\n") << "Checking load.";
        log << ls;

        ss=""; 
        load >> ss;
        client.connect("localhost", 8828);
        client.send(ss);
        thread_o::yield();

        rs = "";
        while(!rs.contains("\n\n"))  client.recv(rs);
        client.disconnect();

        load << rs;

//      (ls="gcsCloudShepard_o::loadThreadLoop() ") << "Load reported as: ";
//      load >> ls;
//      log << ls;

        repLoad = load.load();
        loadProcessed = processedLoad();

(ls="")  << "load processed: " << loadProcessed << "   reported load: " << repLoad;
log << ls;

        if(loadProcessed < repLoad)  {
            (ls="")  << "gcsCloudShepard_o::loadThreadLoop():  Spawning new Genetic Cloud Server!";
            log << ls;
            spawnGeneticCloudServer();
        }



        loadThread.usleep(2000002);

    }
}

int gcsCloudShepard_o::processedLoad()  {
    string_o ls;
    gcsStatusPacket_o* gcs;
    list_o<gcsStatusPacket_o>  activeServers;
    int n;
    int l = 0;

    gcs = sortedListOfGeneticCloudServers.get();
//n = 1;
//(ls = "") << "In sorted list: ";
//log << ls;
    while(gcs)  {

//(ls="") << n++;
//gcs->Serialize(ls);
//log << ls;

//(ls="") << "start time: " <<  gcs->startTime() << "   duration: " << gcs->duration();
//ls << "current time: " << tyme.startSec() << "   start+duration: ";
//ls << gcs->startTime() + gcs->duration();

        tyme.reset();
        if(tyme.startSec() - gcs->startTime() > gcs->duration())  {
            delete gcs;
        }
        else  {
            activeServers.put(gcs);
        }

        gcs = sortedListOfGeneticCloudServers.get();
    }


    (ls="") << "gcsCloudShepard_o::processedLoad(), Active Genetic Cloud Servers:\n";
    ls << "     Name      Load\n";
    l = 0;
    gcs = activeServers.get();
    while(gcs)  {
        l += gcs->load();

        string_o format;
        format = gcs->name();
        format.justifyRight(12);
        ls << format;
        (format = "") << gcs->load();
        format.justifyRight(6);
        ls << format << '\n';

        sortedListOfGeneticCloudServers.put(gcs->load(), gcs);
        gcs = activeServers.get();
    }
    log << ls;

    return  l;
}

int gcsCloudShepard_o::processStatusPacket(input_o& input, output_o& output)  {
    gcsStatusPacket_o* cspp;
    string_o      out;
    string_o      ls;

    cspp = new gcsStatusPacket_o();
    (ls = "") << input.message();
    log << ls;
    cspp->Deserialize(input.message());

    queueOfGeneticCloudServers.put(cspp);

    cspp->setName("gcsCloudShepard_o");
    cspp->Serialize(out);

    output.setMessage(out.string());

    (ls = "") << "gcsCloudShepard_o::processStatusPacket(( socket(" << input.socket() << "), sequence(";
    ls << cspp->sequence() << ") ) finished.";
    log << ls;

    return  0;
}

int gcsCloudShepard_o::processLoadPacket(input_o& input, output_o& output)  {
    gcsLoad_o*  lpp;
    string_o    out;
    string_o    ls;

    lpp = new gcsLoad_o();
    (ls = "") << input.message();
    log << ls;
    lpp->Deserialize(input.message());

    lpp->setName("gcsCloudShepard_o");
    lpp->Serialize(out);

log << out;

    output.setMessage(out.string());

    (ls = "") << "gcsCloudShepard_o::processLoadPacket(( socket(" << input.socket() << "), load(";
    ls << lpp->load() << ") ) finished.";
    log << ls;

    return  0;
}

int gcsCloudShepard_o::process(input_o& input, output_o& output)  {
/*
    switch(input.port())  {
        case 8228:
            return  processStatusPacket(input, output);

        case 8828:
            return  processLoadPacket(input, output);
    }
*/

    if(input.message().contains(GCSLOAD_OBJECT))  {
        return  processLoadPacket(input, output);
    }
    if(input.message().contains(GCSStatusPacket_OBJECT))  {
        return  processStatusPacket(input, output);
    }

}

int carapace_o::process(input_o& input, output_o& output)  {
    return  cloudShepard.process(input, output);
}

int main(int argc, char* argv[])  {
    return  cloudShepard.start();
}

int gcsCloudShepard_o::spawnGeneticCloudServer()  {
    string_o ls;
    string_o systemString;

    entity_o baby(*flock.entities()[rndm.i(flock.population())]);

    systemString << "./gcsGeneticCloudServer " << baby.uniqueid() << " >> gcs.log &";

log << systemString;

    ::system(systemString.string());

    return  2;
}

void* gcsCloudShepard_oThreadLoop(void* gcsCloudShepard_oThread)  {
    (void)((gcsCloudShepard_o*)gcsCloudShepard_oThread)->loadThreadLoop();
    (void)((thread_o*)gcsCloudShepard_oThread)->exit();
    return  gcsCloudShepard_oThread;
}


/******************************************************************************/

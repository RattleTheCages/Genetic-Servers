/**  gcsCloudShepard_o.cc  ********************************************************

            Cloud-Shepard


            Server




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include <iostream>
#include <fstream>

#include "rand_o"
#include "entity_o"
#include "colony_o"
#include "gcsCloudShepard_o.h"

log_o       log;
rand_o      rndm;
sysinfo_o   sysinfo;
carapace_o  carapace;
    gcsCloudShepard_o cloudShepard;


gcsCloudShepard_o::gcsCloudShepard_o() : State(2) {}

gcsCloudShepard_o::~gcsCloudShepard_o()  {}


int gcsCloudShepard_o::loadDNAColony()  {
    int x;
    string_o colonyString;
    string_o message;
    char buffer[4096];

    std::ifstream in;

    in.open("dna.olp");
    if(!in)  {
        (message = "") << "File not found: " << "dna.olp";
        ::log.error(message);
        return -1;
    }

    while(!in.eof())  {
        for(x=0;x<4096;x++)  {
            in.get(buffer[x]);
            if(in.eof())  break;
        }
        colonyString.fill(x, buffer);
    }
    in.close();

    flock << colonyString.string();
}


int gcsCloudShepard_o::start()  {
    int     r = 0;
    string_o ls;
    gcsShepardPacket_o* cspp;
    gcsShepardPacket_o* geneticServer;


    r = serveport(8228);
    if(r)  return  r;


loadDNAColony();

        spawnGeneticCloudServer();





    while(2)  {
        cspp = queueOfGeneticCloudServers.get();

(ls = "") << "In loop: ";
        cspp->Serialize(ls);
log << ls;

        geneticServer = new gcsShepardPacket_o(*cspp);
        sortedListOfGeneticCloudServers.put(geneticServer->GeneticServerScore(), geneticServer);

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

int gcsCloudShepard_o::process(input_o& input, output_o& output)  {


    string_o      out;
    string_o      ls;
    gcsShepardPacket_o* cspp;


    cspp = new gcsShepardPacket_o();
    (ls = "") << input.message();
    log << ls;
    cspp->Deserialize(input.message());


    queueOfGeneticCloudServers.put(cspp);

    cspp->setName("gcsCloudShepard_o");
    cspp->Serialize(out);

    output.setMessage(out.string());

    (ls = "") << "gcsCloudShepard_o::carapace_o::process( socket(" << input.socket() << "), sequence(";
    ls << cspp->Sequence() << ") ) finished.";
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

    systemString << "./GeneticCloudServer_o " << e.uniqueid() << " >> gcs.log &";

log << systemString;

system(systemString.string());

    return  2;
}


/******************************************************************************/

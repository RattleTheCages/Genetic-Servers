/**  CloudShepard_o.cc  ********************************************************

            Cloud-Shepard


            Server




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "CloudShepard_o.h"

log_o       log;
sysinfo_o   sysinfo;
carapace_o  carapace;
    CloudShepard_o cloudShepard;


CloudShepard_o::CloudShepard_o() : State(2) {}

CloudShepard_o::~CloudShepard_o()  {}

int CloudShepard_o::start()  {
    int     r = 0;
    string_o ls;
    CloudShepardPacket_o* cspp;


    r = serveport(8228);
    if(r)  return  r;



    while(2)  {
        cspp = queueOfGeneticCloudServers.get();

(ls = "") << "In loop: ";
        cspp->Serialize(ls);
log << ls;

        sortedListOfGeneticCloudServers.put(cspp->GeneticServerScore(), cspp);

        cspp = sortedListOfGeneticCloudServers.first();
        while(cspp)  {
            (ls = "") << "In sorted list: ";
            cspp->Serialize(ls);
            log << ls;
            cspp = sortedListOfGeneticCloudServers.next();
        }


    }  


    persist();

    return  2;
}

int CloudShepard_o::process(input_o& input, output_o& output)  {


    string_o      out;
    string_o      ls;
    CloudShepardPacket_o* cspp;


    cspp = new CloudShepardPacket_o();
    (ls = "") << input.message();
    log << ls;
    cspp->Deserialize(input.message());


    queueOfGeneticCloudServers.put(cspp);

    cspp->setName("CloudShepard_o");
    cspp->Serialize(out);

    output.setMessage(out.string());

    (ls = "") << "CloudShepard_o::carapace_o::process( socket(" << input.socket() << "), sequence(";
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

/******************************************************************************/

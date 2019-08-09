/**  GeneticCloudServer_o.cc  ****************************************************

            Genetic-Cloud-Servers


            Genetic Cloud Server




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "client_o"
#include "rand_o"
#include "name_o"
#include "GeneticCloudServer_o.h"
#include "CloudShepardPacket_o.h"


log_o       log;
rand_o      rndm;
name_o      name;
sysinfo_o   sysinfo;
carapace_o  carapace;


GeneticCloudServer_o::GeneticCloudServer_o() : State(2)  {
    entity_o::setName(::name.name());
}

GeneticCloudServer_o::~GeneticCloudServer_o()  {}

int GeneticCloudServer_o::start()  {
    int     r = 0;
    client_o client;
    string_o name;
    string_o ss; 
    string_o rs; 
    CloudShepardPacket_o csp;


    client.connect("localhost", 8228);

    csp.setGeneticServerIP("localhost");
    csp.setGeneticServerScore(rndm.i(22));
    name << entity_o::name() << uniqueid();
log << name;
    csp.setName(name);

    csp.Serialize(ss);

    client.send(ss);
    client.recv(rs);

    csp.Deserialize(rs);




//    r = gcs.serveport(8228);
    if(r)  return  r;


 //   gcs.persist();
}

int carapace_o::process(input_o& input, output_o& output)  {
    string_o      out;
    string_o      ls;
   // packet_o ssipp;

/*

    ssipp.Deserialize(input.message());


    ssipp.setName("The mark of GeneticCloudServer_o.");
    ssipp.Serialize(out);
    output.setMessage(out.string());

    ls << "GeneticCloudServer_o::carapace_o::process( socket(" << input.socket() << "), sequence(";
    ls << ssipp.Sequence() << ") ) finished.";
    log << ls;

*/

    return  0;
}



int main(int argc, char* argv[])  {
    GeneticCloudServer_o gcs;

    return  gcs.start();
}

/******************************************************************************/

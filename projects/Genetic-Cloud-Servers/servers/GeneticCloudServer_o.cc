/**  GeneticCloudServer_o.cc  ****************************************************

            Genetic-Cloud-Servers


            Genetic Cloud Server




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "client_o"
#include "rand_o"
//#include "name_o"
#include "colony_o"
#include "GeneticCloudServer_o.h"
#include "gcsShepardPacket_o.h"


log_o       log;
rand_o      rndm;
//name_o      name;
sysinfo_o   sysinfo;
carapace_o  carapace;


GeneticCloudServer_o::GeneticCloudServer_o() : State(2)  {
//    entity_o::setName(::name.name());
}

GeneticCloudServer_o::GeneticCloudServer_o(const gcsDNA_o& dna) : State(2), gcsDNA_o(dna)  {}

GeneticCloudServer_o::~GeneticCloudServer_o()  {}

int GeneticCloudServer_o::start()  {
    int     r = 0;
    client_o client;
    string_o name;
    string_o ss; 
    string_o rs; 
    gcsShepardPacket_o csp;

    string_o ls;

    ls << "numberOfWorkerThreads " << numberOfWorkerThreads() << '\n';
    ls << "numberOfGateThreads " << numberOfGateThreads() << '\n';
    ls << "numberOfCPUs " << numberOfCPUs() << '\n';
    ls << "diskSpaceSize " << diskSpaceSize() << '\n';
    ls << "bandwidthSize " << bandwidthSize() << '\n';
    ls << "operatingSystemID " << operatingSystemID() << '\n';
    ls << "operatingSystemConfig " << operatingSystemConfig() << '\n';
    log << ls;

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

#include <fstream>
colony_o flock;
int GeneticCloudServer_o::loadDNAColony()  {
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




int main(int argc, char* argv[])  {
string_o ls;
      string_o s2n;
    GeneticCloudServer_o gcsdel;
    entity_o* entity;

    s2n = argv[1];
    int uniqueId = s2n.stoi();

    gcsdel.loadDNAColony();


(ls="") << "uniqueId: " << uniqueId;
log << ls;

entity = flock.get(uniqueId);

if(!entity)  {
(ls="") << "entity not found: ";
log << ls;
return  -2;
}


//(ls="") << "enitity: ";
//*entity >> ls;
//log << ls;

gcsDNA_o gcsDNA(*entity);
GeneticCloudServer_o gcs(gcsDNA);

(ls="") << "enitity: ";
(entity_o)gcsDNA >> ls;
log << ls;

ls << sysinfo.pid() << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
log << ls;

    return  gcs.start();
}

/******************************************************************************/

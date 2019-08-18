/**  GeneticCloudServer_o.cc  *************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Genetic Cloud Server Implementation



*******************************************************************************/

#include "client_o"
#include "rand_o"
#include "file_o"
#include "thread_o"
#include "colony_o"
#include "time_o"
#include "GeneticCloudServer.h"
#include "gcsStatusPacket_o.h"
#include "gcsVMInfo_o.h"
#include "MatchVMService_o.h"


log_o       log;
rand_o      rndm;
sysinfo_o   sysinfo;
carapace_o  carapace;


GeneticCloudServer_o::GeneticCloudServer_o() : State(2)  {
    StartTime = Time.startSec();
}

GeneticCloudServer_o::GeneticCloudServer_o(const gcsDNA_o& dna) : State(2), gcsDNA_o(dna)  { 
    StartTime = Time.startSec();
}

GeneticCloudServer_o::~GeneticCloudServer_o()  {}

int GeneticCloudServer_o::loop()  {
    string_o ss;
    string_o rs;
    string_o ls;
    client_o client;
    gcsStatusPacket_o csp;
    string_o nname;
    nname << gcsDNA_o::name() << uniqueid();

    while(2)  {

        client.connect("localhost", 8228);

        csp.setIP("localhost");
        csp.setLoad(rndm.i(100));
        csp.setStartTime(StartTime);
        csp.setName(nname);
        csp.setDuration(duration());

        ss="";
        csp.Serialize(ss);
log << ss;

        client.send(ss);
        rs="";
        client.recv(rs);

        csp.Deserialize(rs);

        (ls="") << "Command: " << csp.command();
        log << ls;


        thread_o::usleep(2000000);

        Time.adjust();
(ls="")<<StartTime<<" "<<duration()<<" "<<Time.seconds();
log<<ls;
        if(Time.seconds() > duration())  break;
    }


    return  2;
}

int GeneticCloudServer_o::start()  {
    int     r = 0;
    string_o ss; 
    string_o rs; 

    string_o ls;

    ls << "numberOfWorkerThreads " << numberOfWorkerThreads() << '\n';
    ls << "numberOfGateThreads " << numberOfGateThreads() << '\n';
    ls << "numberOfCPUs " << numberOfCPUs() << '\n';
    ls << "diskSpaceSize " << diskSpaceSize() << '\n';
    ls << "bandwidthSize " << bandwidthSize() << '\n';
    ls << "operatingSystemID " << operatingSystemID() << '\n';
    ls << "operatingSystemConfig " << operatingSystemConfig() << '\n';
    ls << "cloud service " << cloudService() << '\n';
    ls << "duration " << duration() << '\n';
    log << ls;

MatchVMService_o mvms;
ls="";
//mvms.dumpVMList(ls);
//log << ls;
mvms.match(*this, vminfo);


return 2;


//    r = gcs.serveport(8228);
    if(r)  return  r;

    loop();

 //   gcs.persist();

    return  2;
}

int carapace_o::process(input_o& input, output_o& output)  {

    return  0;
}




colony_o flock;

int main(int argc, char* argv[])  {
string_o ls;
      string_o s2n;
    GeneticCloudServer_o gcsdel;
    entity_o* entity;

    s2n = argv[1];
    int uniqueId = s2n.stoi();

    flock.load("dna.olp");


(ls="") << "uniqueId: " << uniqueId;
log << ls;


/*
string_o ffs;
file_o ff;
ff.read("vminfo.olp", ffs);

gcsVMInfo_o info;

info << ffs;
ls="";
info >> ls;
//log << ls;

info << ffs;
ls="";
info >> ls;
//log << ls;

info << ffs;
ls="";
info >> ls;
//log << ls;
*/



//return 2;




entity = flock.get(uniqueId);

if(!entity)  {
(ls="") << "entity not found: ";
log << ls;
return  -2;
}


(ls="") << "enitity: ";
ls << entity->name();
log << ls;


gcsDNA_o gcsDNA(*entity);
GeneticCloudServer_o gcs(gcsDNA);



ls << sysinfo.pid() << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
ls << rndm.i(22) << '\n';
log << ls;

//return 2;
    return  gcs.start();
}

/******************************************************************************/

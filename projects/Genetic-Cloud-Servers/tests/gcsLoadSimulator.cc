/**  gcsLoadSimulator_o.cc  ***************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Genetic Cloud Server Implementation



*******************************************************************************/

#include "log_o"
#include "rand_o"
#include "sysinfo_o"
#include "thread_o"
#include "client_o"
#include "pserver_o"
#include "gcsLoad_o.h"
#include "gcsLoadSimulator.h"


log_o       log;
time_o      tyme;
rand_o      rndm;
carapace_o  carapace;
sysinfo_o   sysinfo;
gcsLoadSimulator_o gcsLoadSim;


gcsLoadSimulator_o::gcsLoadSimulator_o() : State(2)  {
    StartTime = tyme.startSec();
}

gcsLoadSimulator_o::~gcsLoadSimulator_o()  {}

int gcsLoadSimulator_o::loop()  {
    string_o    ls;
    string_o    ss;
    string_o    rs;
    client_o    client;
    gcsLoad_o   gcsLoad;

    while(2)  {
        thread_o::usleep(1000002 + rndm.i(2222));

        (ls="") << "LoadSimulator_o::loop()";
        log << ls;


/*
        gcsLoad.setName("Simulated Load");
        gcsLoad.setType(1);
        gcsLoad.setLoad(222);

        client.connect("localhost", 8228);

        ss = "";
        gcsLoad >> ss;
        client.send(ss);
        thread_o::yield();
        rs = "";
        client.recv(rs);

        gcsLoad << rs;

        client.disconnect();

        ls = "";
        gcsLoad >> ls;

        log << ls;
*/

    }


    return  2;
}

int gcsLoadSimulator_o::start()  {
    int         r = 0;
    string_o    ls;

    r = serveport(8828);

    ls << "LoadSimulator_o::start()";
    log << ls;

    return  loop();
}

int gcsLoadSimulator_o::process(input_o& input, output_o& output)  {
    gcsLoad_o gcsLoad;
    string_o  ss;
    string_o  ls;
    string_o  rs;

log << "gcsLoadSimulator_o::process()";

    gcsLoad << input.message();

    gcsLoad.setName("Simulated Load");
    gcsLoad.setType(1);
    gcsLoad.setLoad(222);

    gcsLoad >> ss;
    ss << '\n';


    log << ss;

    output.setMessage(ss);

    return  0;
}

int carapace_o::process(input_o& input, output_o& output)  {
log << "gcsLoadSimulator_o::process()";
    return  gcsLoadSim.process(input, output);
}

int main(int argc, char* argv[])  {
    return  gcsLoadSim.start();
}

/******************************************************************************/

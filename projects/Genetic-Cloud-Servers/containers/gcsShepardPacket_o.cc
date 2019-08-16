/**  gcsShepardPacket_o.cc  ****************************************************

            Genetic-Cloud-Servers



            Cloud Shepard Packet Object




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#include "succession_o"
#include "parse_o"
#include "gcsShepardPacket_o.h"


gcsShepardPacket_o::gcsShepardPacket_o()  {
    name = "gcsShepardPacket_o";
    sequence = 0;
    dataLength = 0;
/*
    string_o            geneticServerIP;
    int                 geneticServerScore;
    int                 geneticServerState;
*/
    geneticServerScore = 0;
    geneticServerState = 0;

    succession_o::bzero(rawData, 2048);
}

gcsShepardPacket_o::gcsShepardPacket_o(const gcsShepardPacket_o& sp)  {
    name = sp.name;
    sequence = sp.sequence;
    geneticServerIP = sp.geneticServerIP;
    geneticServerScore = sp.geneticServerScore;
    geneticServerState = sp.geneticServerState;
    dataLength = sp.dataLength;
    succession_o::memcpy(rawData, sp.rawData, 2048);
}

gcsShepardPacket_o::~gcsShepardPacket_o()  {}

void gcsShepardPacket_o::setRawData(const char* raw, const int dl)  {
    dataLength = dl;
    succession_o::memcpy(rawData, raw, dataLength);
    succession_o::bzero(rawData+dataLength, 2048-dataLength);
}

void gcsShepardPacket_o::Serialize(string_o& sout)  {

    sout << "gcsShepardPacket_o:\n";
    sout << "name=" << name.string() << '\n';
    sout << "sequence=" << sequence << '\n';
    sout << "geneticServerIP=" << geneticServerIP << '\n';
    sout << "geneticServerScore=" << geneticServerScore << '\n';
    sout << "geneticServerState=" << geneticServerState << '\n';
    sout << "dataLength=" << dataLength << '\n';
    sout << "rawData=" << rawData << '\n';
    sout << "\n";

}

void gcsShepardPacket_o::Deserialize(string_o& sin)  {
    parse_o parse(sin.string());

    parse.it("name", name);
    parse.it("sequence", sequence);
    parse.it("geneticServerScore", geneticServerScore);
    parse.it("geneticServerState", geneticServerState);
    parse.it("geneticServerIP", geneticServerIP);
/*
    sin.upcut("gcsShepardPacket_o:");
    sin.upcut("name=");
    name = sin;
    name.cut('\n');
    sin.upcut("sequence=");
    sequence = sin.stoi();
    sin.upcut("geneticServerIP=");
    geneticServerIP = sin;
    geneticServerIP.cut('\n');
    sin.upcut("geneticServerScore=");
    geneticServerScore = sin.stoi();
    sin.upcut("geneticServerState=");
    geneticServerState = sin.stoi();
    sin.upcut("dataLength=");
    dataLength = sin.stoi();
    sin.upcut("rawData=");
    succession_o::memcpy(rawData, sin.string(), dataLength);
    succession_o::bzero(rawData+dataLength, 2048-dataLength);
*/
}



/******************************************************************************/

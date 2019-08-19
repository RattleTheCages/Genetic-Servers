/**  gcsStatusPacket_o.cc  ****************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Genetic Cloud Server Status Packet



*******************************************************************************/


#include "parse_o"
#include "gcsStatusPacket_o.h"


gcsStatusPacket_o::gcsStatusPacket_o()  {
    Name = GCSStatusPacket_OBJECT;
    Sequence = 0;
    Load = 0;
    State = 0;
    StartTime = 0;
    Duration = 0;
}

gcsStatusPacket_o::gcsStatusPacket_o(const gcsStatusPacket_o& sp)  {
    Name      = sp.Name;
    Sequence  = sp.Sequence;
    IP        = sp.IP;
    Load      = sp.Load;
    State     = sp.State;
    Command   = sp.Command;
    StartTime = sp.StartTime;
    Duration  = sp.Duration;
}

gcsStatusPacket_o::~gcsStatusPacket_o()  {}


void gcsStatusPacket_o::Serialize(string_o& sout) const  {

    sout << '\n' << GCSStatusPacket_OBJECT << ':';
    sout << '\n' << GCSStatusPacket_NAME << '=' << Name;
    sout << '\n' << GCSStatusPacket_SEQ << '=' << Sequence;
    sout << '\n' << GCSStatusPacket_GSIP << '=' << IP;
    sout << '\n' << GCSStatusPacket_LOAD << '=' << Load;
    sout << '\n' << GCSStatusPacket_STATE << '=' << State;
    sout << '\n' << GCSStatusPacket_COMMAND << '=' << Command;
    sout << '\n' << GCSStatusPacket_STARTTIME << '=' << StartTime;
    sout << '\n' << GCSStatusPacket_DURATION << '=' << Duration;
    sout << '\n';

}

void gcsStatusPacket_o::Deserialize(const string_o& sin)  {
    parse_o parse(sin.string());

    parse.it(GCSStatusPacket_NAME, Name);
    parse.it(GCSStatusPacket_SEQ, Sequence);
    parse.it(GCSStatusPacket_LOAD, Load);
    parse.it(GCSStatusPacket_STATE, State);
    parse.it(GCSStatusPacket_GSIP, IP);
    parse.it(GCSStatusPacket_COMMAND, Command);
    parse.it(GCSStatusPacket_STARTTIME, StartTime);
    parse.it(GCSStatusPacket_DURATION, Duration);

}

void gcsStatusPacket_o::operator >> (string_o& s) const  {
    Serialize(s);
}

gcsStatusPacket_o& gcsStatusPacket_o::operator << (string_o& s)  {
    Deserialize(s);
    s.upcut("\n\n");
    return  *this;
}




/******************************************************************************/

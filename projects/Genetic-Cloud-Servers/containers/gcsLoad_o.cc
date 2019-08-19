/**  gcsLoad_o.cc  ************************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Cloud Load Packet Object



*******************************************************************************/


#include "parse_o.h"
#include "gcsLoad_o.h"


gcsLoad_o::gcsLoad_o()  {
    Name = GCSLOAD_OBJECT;
    Type = 0;
    Load = 0;
}

gcsLoad_o::gcsLoad_o(const gcsLoad_o& lg)  {
    Name = lg.Name;
    Type = lg.Type;
    Load = lg.Load;
}

gcsLoad_o::~gcsLoad_o()  {}


void gcsLoad_o::Serialize(string_o& sout) const  {

    sout << '\n' << GCSLOAD_OBJECT << ':';
    sout << '\n' << GCSLOAD_NAME << '=' << Name;
    sout << '\n' << GCSLOAD_TYPE << '=' << Type;
    sout << '\n' << GCSLOAD_LOAD << '=' << Load;
    sout << '\n';

}

void gcsLoad_o::Deserialize(const string_o& sin)  {
    parse_o parse(sin.string());

    parse.it(GCSLOAD_NAME, Name);
    parse.it(GCSLOAD_TYPE, Type);
    parse.it(GCSLOAD_LOAD, Load);
}

void gcsLoad_o::operator >> (string_o& s) const  {
    Serialize(s);
}

gcsLoad_o& gcsLoad_o::operator << (string_o& s)  {
    Deserialize(s);
    s.upcut("\n\n");
    return  *this;
}



/******************************************************************************/

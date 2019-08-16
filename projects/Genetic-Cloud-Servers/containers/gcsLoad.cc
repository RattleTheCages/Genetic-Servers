/**  gcsLoad.cc  **************************************************************

            Genetic-Cloud-Servers



            Cloud Load Packet Object




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#include "parse_o.h"
#include "gcsLoad.h"


gcsLoad_o::gcsLoad_o()  {
    name = GCSLOAD_OBJECT;
    type = 0;
    load = 0;
}

gcsLoad_o::gcsLoad_o(const gcsLoad_o& lg)  {
    name = lg.name;
    type = lg.type;
    load = lg.load;
}

gcsLoad_o::~gcsLoad_o()  {}


void gcsLoad_o::Serialize(string_o& sout) const  {

    sout << '\n' << GCSLOAD_OBJECT << ':';
    sout << '\n' << GCSLOAD_NAME << '=' << name;
    sout << '\n' << GCSLOAD_TYPE << '=' << type;
    sout << '\n' << GCSLOAD_LOAD << '=' << load;

}

void gcsLoad_o::Deserialize(const string_o& sin)  {
    parse_o parse(sin.string());

    parse.it(GCSLOAD_NAME, name);
    parse.it(GCSLOAD_TYPE, type);
    parse.it(GCSLOAD_LOAD, load);
}

void gcsLoad_o::operator >> (string_o& s) const  {
    Serialize(s);
}

gcsLoad_o& gcsLoad_o::operator << (const string_o& s)  {
    Deserialize(s);
    return  *this;
}



/******************************************************************************/

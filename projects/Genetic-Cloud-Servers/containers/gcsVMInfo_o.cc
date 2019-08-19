/**  gcsVMInfo_o.cc  **********************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Virtual Machine Information




            Cloud provider's virtual machine profile options.

*******************************************************************************/


#include "parse_o.h"
#include "gcsVMInfo_o.h"


gcsVMInfo_o::gcsVMInfo_o()  {
    Index = 0;
    CPUGHz = 0;
    CPUCores = 0;
    RAMMemory = 0;
    SDDMemory = 0;
    Bandwidth = 0;
    Price = 0;
    Duration = 0;
}

gcsVMInfo_o::gcsVMInfo_o(const gcsVMInfo_o& yz)  {
    Index         = yz.Index;
    CloudProvider = yz.CloudProvider;
    Name          = yz.Name;
    Type          = yz.Type;
    CPUName       = yz.CPUName;
    CPUGHz        = yz.CPUGHz;
    CPUCores      = yz.CPUCores;
    RAMMemory     = yz.RAMMemory;
    SDDMemory     = yz.SDDMemory;
    Bandwidth     = yz.Bandwidth;
    Price         = yz.Price;
    Duration      = yz.Duration;
    OSShortName   = yz.OSShortName;
    OSLongName    = yz.OSLongName;
}

gcsVMInfo_o& gcsVMInfo_o::operator = (const gcsVMInfo_o& vi)  {

    Index         = vi.Index;
    CloudProvider = vi.CloudProvider;
    Name          = vi.Name;
    Type          = vi.Type;
    CPUName       = vi.CPUName;
    CPUGHz        = vi.CPUGHz;
    CPUCores      = vi.CPUCores;
    RAMMemory     = vi.RAMMemory;
    SDDMemory     = vi.SDDMemory;
    Bandwidth     = vi.Bandwidth;
    Price         = vi.Price;
    Duration      = vi.Duration;
    OSShortName   = vi.OSShortName;
    OSLongName    = vi.OSLongName;

    return  *this;
}

gcsVMInfo_o::~gcsVMInfo_o()  {}


void gcsVMInfo_o::Serialize(string_o& sout) const  {

    sout << '\n' << GCSVMInfo_o << ':';
    sout << '\n' << GCSVMInfo_Index << '=' << Index;
    sout << '\n' << GCSVMInfo_CloudProvider << '=' << CloudProvider;
    sout << '\n' << GCSVMInfo_Name << '=' << Name;
    sout << '\n' << GCSVMInfo_Type << '=' << Type;
    sout << '\n' << GCSVMInfo_CPUName << '=' << CPUName;
    sout << '\n' << GCSVMInfo_CPUGHz << '=' << CPUGHz;
    sout << '\n' << GCSVMInfo_CPUCores << '=' << CPUCores;
    sout << '\n' << GCSVMInfo_RAMMemory << '=' << RAMMemory;
    sout << '\n' << GCSVMInfo_SDDMemory << '=' << SDDMemory;
    sout << '\n' << GCSVMInfo_Bandwidth << '=' << Bandwidth;
    sout << '\n' << GCSVMInfo_Price << '=' << Price;
    sout << '\n' << GCSVMInfo_Duration << '=' << Duration;
    sout << '\n' << GCSVMInfo_OSShortName << '=' << OSShortName;
    sout << '\n' << GCSVMInfo_OSLongName << '=' << OSLongName;
    sout << '\n';

}

void gcsVMInfo_o::Deserialize(const string_o& sin)  {
    parse_o parse(sin.string());

    parse.it(GCSVMInfo_Index, Index);
    parse.it(GCSVMInfo_CloudProvider, CloudProvider);
    parse.it(GCSVMInfo_Name, Name);
    parse.it(GCSVMInfo_Type, Type);
    parse.it(GCSVMInfo_CPUName, CPUName);
    parse.it(GCSVMInfo_CPUGHz, CPUGHz);
    parse.it(GCSVMInfo_CPUCores, CPUCores);
    parse.it(GCSVMInfo_RAMMemory, RAMMemory);
    parse.it(GCSVMInfo_SDDMemory, SDDMemory);
    parse.it(GCSVMInfo_Bandwidth, Bandwidth);
    parse.it(GCSVMInfo_Price, Price);
    parse.it(GCSVMInfo_Duration, Duration);
    parse.it(GCSVMInfo_OSShortName, OSShortName);
    parse.it(GCSVMInfo_OSLongName, OSLongName);
}

void gcsVMInfo_o::operator >> (string_o& s) const  {
    Serialize(s);
}

gcsVMInfo_o& gcsVMInfo_o::operator << (string_o& s)  {
    Deserialize(s);
    s.upcut("\n\n");
    return  *this;
}



/******************************************************************************/

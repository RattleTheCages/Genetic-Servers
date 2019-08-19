/**  gcsExpressServerDNA_o.cc  ************************************************
                                   Copyright 2019  Rattle  All rights reserved.


            Genetic Cloud Servers



            Express Genetic Cloud Server DNA.




            Express the DNA genotypes into their Genetic Cloud Server phenotypes.

*******************************************************************************/


#include "file_o"
#include "gcsDNA_o.h"
#include "gcsVMInfo_o.h"
#include "gcsExpressServerDNA_o.h"

extern log_o log;

gcsExpressServerDNA_o::gcsExpressServerDNA_o() : State(2)  {
    file_o ff;
    string_o ffs;
    gcsVMInfo_o* vminfo;

    ff.read("vminfo.olp", ffs);

    while(ffs.length() > 2)  {
        vminfo = new gcsVMInfo_o();
        *vminfo << ffs;
        VMInfoList.put(vminfo);
    }
}

gcsExpressServerDNA_o::~gcsExpressServerDNA_o()  {}

void gcsExpressServerDNA_o::dumpVMList(string_o& s)  {
    gcsVMInfo_o* vminfo;
    vminfo = VMInfoList.first();
    while(vminfo)  {
        *vminfo >> s;
        s << '\n';
        vminfo = VMInfoList.next();
    }
}

void gcsExpressServerDNA_o::expressGenes(gcsDNA_o& dna, gcsVMInfo_o& info)  {
    string_o            ls;
    string_o            cloudNameTry;
    int                 cloudId;
    list_o<gcsVMInfo_o> cloudList;
    list_o<gcsVMInfo_o> coreList;
    list_o<gcsVMInfo_o> ramList;
    list_o<gcsVMInfo_o> bwList;
    list_o<gcsVMInfo_o> osList;
    list_o<gcsVMInfo_o> vmList;
    gcsVMInfo_o*        vminfo;


    cloudId = dna.cloudService() % 4;
cloudId = 0;

    switch(cloudId)  {
        case 0:
            cloudNameTry = "chicagovps.net";
            break;
        case 1:
            cloudNameTry = "aws";
            break;
        case 2:
            cloudNameTry = "gcloud";
            break;
        case 3:
            cloudNameTry = "azure";
            break;
        default:
            cloudNameTry = "fluffy";
            break;
    }

    vminfo = VMInfoList.first();
    while(vminfo)  {
        if(cloudNameTry == vminfo->cloudProvider())  cloudList.put(vminfo);
        vminfo = VMInfoList.next();
    }


    vminfo = cloudList.first();
    while(vminfo)  {
        if(dna.numberOfCPUs() == vminfo->cpuCores())  coreList.put(vminfo);
        vminfo = cloudList.next();
    }


    if(coreList.cardinality() > 1)  {
        int bestram = 0;
        int lastram = 0;
        int nowram = 0;
        vminfo = coreList.first();
        while(vminfo)  {
            nowram = dna.ramSize() - vminfo->ramMemory();
            if(nowram < 0)  nowram *= -1;
            if(bestram == 0)  bestram = nowram;

            if(nowram <= lastram)  bestram = nowram;
            lastram = nowram;
            vminfo = coreList.next();
        }
        vminfo = coreList.first();
        while(vminfo)  {
            nowram = dna.ramSize() - vminfo->ramMemory();
            if(nowram < 0)  nowram *= -1;
            if(nowram == bestram)  ramList.put(vminfo);
            vminfo = coreList.next();
        }
    }
    else  ramList.put(coreList.first());


    if(ramList.cardinality() > 1)  {
        int bestw = 0;
        int lastw = 0;
        int noww = 0;

        vminfo = ramList.first();
        while(vminfo)  {
            noww = dna.bandwidthSize() - vminfo->bandwidth();
            if(noww < 0)  noww *= -1;
            if(bestw == 0)  bestw = noww;

            if(noww < lastw)  bestw = noww;
            lastw = noww;
            vminfo = ramList.next();
        }

        vminfo = ramList.first();
        while(vminfo)  {
            noww = dna.bandwidthSize() - vminfo->bandwidth();
            if(noww < 0)  noww *= -1;
            if(noww == bestw)  bwList.put(vminfo);
            vminfo = ramList.next();
        }
    }
    else  bwList.put(ramList.first());


//  if(sddList.cardinality() > 1)  {
    if(bwList.cardinality() > 1)  {
        string_o  osNameTry;
        int osname = dna.operatingSystemID() % 3;

        switch(osname)  {
            case 0:
                osNameTry = "Fedora";
                break;
            case 1:
                osNameTry = "Centos";
                break;
            case 2:
                osNameTry = "RedHat";
                break;
            default:
                osNameTry = "UNIX";
                break;
        }

        vminfo = bwList.first();
        while(vminfo)  {
            if(osNameTry == vminfo->osShortName())  vmList.put(vminfo);
            vminfo = bwList.next();
        }
    }
    else  vmList.put(bwList.first());


    log << "\nVM matched list:";
    vminfo = vmList.first();
    while(vminfo)  {
        info = *vminfo;
        ls="";
        *vminfo >> ls;
        ls << '\n';
        log << ls;
        vminfo = vmList.next();
    }
    log << ":VM matched list\n";

    ls = "gcsExpressServerDNA_o::match() ";
    vminfo = vmList.first();
    if(vmList.cardinality() > 1)  {
        ls << "gcsExpressServerDNA_o::match() ";
        ls << "DNA matched multiple VMInfo records.  Taking first VMInfo record on VMInfo list: ";
        ls << vminfo->index();
    }
    else  if(vmList.cardinality() < 1)  {
        ls << "No records found of VMInfo matching the DNA.";
    }
    else  {
        ls << "DNA matched: " << vminfo->index();
    }
    log << ls;


    if(vminfo)  info = *vminfo;

}

/******************************************************************************/

/**  gcsShepardPacket_o.h  *****************************************************

            Genetic-Cloud-Servers


            Packet Object



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef GCSShepardPacket_API
#define GCSShepardPacket_API


#include "string_o"


class gcsShepardPacket_o  {
  protected:
    string_o            name;
    int                 sequence;
    string_o            geneticServerIP;
    int                 geneticServerScore;
    int                 geneticServerState;
    int                 dataLength;
    char                rawData[2048];

  public:
    gcsShepardPacket_o();
    gcsShepardPacket_o(const gcsShepardPacket_o&);
    virtual ~gcsShepardPacket_o();
    gcsShepardPacket_o&   operator = (const gcsShepardPacket_o&);

    const char*      RawData() const;
    const char*      Name() const;
    const char*      GeneticServerIP() const;
    int              GeneticServerScore() const;
    int              GeneticServerState() const;
    int              Sequence() const;
    int              DataLength() const;

    void             setSequence(const int);
    void             setGeneticServerScore(const int);
    void             setGeneticServerState(const int);
    void             setGeneticServerIP(const string_o);
    void             setDataLength(const int);
    void             setName(const string_o);
    void             setRawData(const char*, const int);

    void             Serialize(string_o&);
    void             Deserialize(string_o&);

    int              operator < (gcsShepardPacket_o&);

};


/******************************************************************************/

inline const char* gcsShepardPacket_o::RawData() const  {
    return  rawData;
}

inline const char* gcsShepardPacket_o::Name() const  {
    return  geneticServerIP.string();
}

inline const char* gcsShepardPacket_o::GeneticServerIP() const  {
    return  name.string();
}

inline int gcsShepardPacket_o::Sequence() const  {
    return  sequence;
}

inline int gcsShepardPacket_o::GeneticServerScore() const  {
    return  geneticServerScore;
}

inline int gcsShepardPacket_o::GeneticServerState() const  {
    return  geneticServerState;
}

inline int gcsShepardPacket_o::DataLength() const  {
    return  dataLength;
}

inline void gcsShepardPacket_o::setGeneticServerScore(const int gss)  {
    geneticServerScore = gss;
}

inline void gcsShepardPacket_o::setGeneticServerState(const int gss)  {
    geneticServerState = gss;
}

inline void gcsShepardPacket_o::setGeneticServerIP(const string_o gsip)  {
    geneticServerIP = gsip;
}

inline void gcsShepardPacket_o::setSequence(const int seq)  {
    sequence = seq;
}

inline void gcsShepardPacket_o::setDataLength(const int dl)  {
    dataLength = dl;
}

inline void gcsShepardPacket_o::setName(const string_o n)  {
    name = n;
}

inline int gcsShepardPacket_o::operator<(gcsShepardPacket_o& s)  {
    return  this->sequence < s.sequence;
}


#endif

/******************************************************************************/

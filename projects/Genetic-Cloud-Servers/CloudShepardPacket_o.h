/**  CloudShepardPacket_o.h  ****************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Packet Object



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef CloudShepardPacket_API
#define CloudShepardPacket_API


#include "string_o"


class CloudShepardPacket_o  {
  protected:
    string_o            name;
    int                 sequence;
    string_o            geneticServerIP;
    int                 geneticServerScore;
    int                 geneticServerState;
    int                 dataLength;
    char                rawData[2048];

  public:
    CloudShepardPacket_o();
    CloudShepardPacket_o(const CloudShepardPacket_o&);
    virtual         ~CloudShepardPacket_o();
    CloudShepardPacket_o&   operator = (const CloudShepardPacket_o&);

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

    int              operator < (CloudShepardPacket_o&);

};


/******************************************************************************/

inline const char* CloudShepardPacket_o::RawData() const  {
    return  rawData;
}

inline const char* CloudShepardPacket_o::Name() const  {
    return  geneticServerIP.string();
}

inline const char* CloudShepardPacket_o::GeneticServerIP() const  {
    return  name.string();
}

inline int CloudShepardPacket_o::Sequence() const  {
    return  sequence;
}

inline int CloudShepardPacket_o::GeneticServerScore() const  {
    return  geneticServerScore;
}

inline int CloudShepardPacket_o::GeneticServerState() const  {
    return  geneticServerState;
}

inline int CloudShepardPacket_o::DataLength() const  {
    return  dataLength;
}

inline void CloudShepardPacket_o::setGeneticServerScore(const int gss)  {
    geneticServerScore = gss;
}

inline void CloudShepardPacket_o::setGeneticServerState(const int gss)  {
    geneticServerState = gss;
}

inline void CloudShepardPacket_o::setGeneticServerIP(const string_o gsip)  {
    geneticServerIP = gsip;
}

inline void CloudShepardPacket_o::setSequence(const int seq)  {
    sequence = seq;
}

inline void CloudShepardPacket_o::setDataLength(const int dl)  {
    dataLength = dl;
}

inline void CloudShepardPacket_o::setName(const string_o n)  {
    name = n;
}

inline int CloudShepardPacket_o::operator<(CloudShepardPacket_o& s)  {
    return  this->sequence < s.sequence;
}


#endif

/******************************************************************************/

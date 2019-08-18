/**  gcsStatusPacket_o.h  *****************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Genetic Cloud Server Status Packet Object



*******************************************************************************/

#ifndef GCSStatusPacket_API
#define GCSStatusPacket_API


#include "string_o"

#define GCSStatusPacket_OBJECT    "gcsStatusPacket_o"
#define GCSStatusPacket_NAME      "name"
#define GCSStatusPacket_SEQ       "sequence"
#define GCSStatusPacket_GSIP      "gcsip"
#define GCSStatusPacket_LOAD      "gcsLoad"
#define GCSStatusPacket_STATE     "gcsState"
#define GCSStatusPacket_COMMAND   "gcsCommand"
#define GCSStatusPacket_STARTTIME "gcsStartTime"
#define GCSStatusPacket_DURATION  "gcsDuration"



class gcsStatusPacket_o  {
  protected:
    int                 State;
    string_o            Name;
    int                 Sequence;
    string_o            IP;
    int                 Load;
    string_o            Command;
    int                 StartTime;
    int                 Duration;

  public:
    gcsStatusPacket_o();
    gcsStatusPacket_o(const gcsStatusPacket_o&);
    virtual ~gcsStatusPacket_o();
    gcsStatusPacket_o& operator = (const gcsStatusPacket_o&);

    int             state() const;
    const char*     name() const;
    int             sequence() const;
    const char*     ip() const;
    int             load() const;
    const char*     command() const;
    int             startTime() const;
    int             duration() const;

    void            setSequence(const int);
    void            setLoad(const int);
    void            setState(const int);
    void            setIP(const string_o&);
    void            setName(const string_o&);
    void            setCommand(const string_o&);
    void            setStartTime(const int);
    void            setDuration(const int);


    void            operator >> (string_o&) const;      // OLP representation.
    void            Serialize(string_o&) const;
    gcsStatusPacket_o& operator << (const string_o&);   // Reconstruct.
    void            Deserialize(const string_o&);

    int              operator < (gcsStatusPacket_o&);

};


/******************************************************************************/

inline const char* gcsStatusPacket_o::name() const  {
    return  Name.string();
}

inline const char* gcsStatusPacket_o::command() const  {
    return  Command.string();
}

inline const char* gcsStatusPacket_o::ip() const  {
    return  IP.string();
}

inline int gcsStatusPacket_o::sequence() const  {
    return  Sequence;
}

inline int gcsStatusPacket_o::load() const  {
    return  Load;
}

inline int gcsStatusPacket_o::state() const  {
    return  State;
}

inline int gcsStatusPacket_o::startTime() const  {
    return  StartTime;
}

inline int gcsStatusPacket_o::duration() const  {
    return  Duration;
}

inline void gcsStatusPacket_o::setLoad(const int gsl)  {
    Load = gsl;
}

inline void gcsStatusPacket_o::setStartTime(const int st)  {
    StartTime = st;
}

inline void gcsStatusPacket_o::setDuration(const int d)  {
    Duration = d;
}

inline void gcsStatusPacket_o::setState(const int gss)  {
    State = gss;
}

inline void gcsStatusPacket_o::setIP(const string_o& gsip)  {
    IP = gsip;
}

inline void gcsStatusPacket_o::setSequence(const int seq)  {
    Sequence = seq;
}

inline void gcsStatusPacket_o::setName(const string_o& n)  {
    Name = n;
}

inline int gcsStatusPacket_o::operator<(gcsStatusPacket_o& s)  {
    return  this->Name < s.Name;
}


#endif

/******************************************************************************/

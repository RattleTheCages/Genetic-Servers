/**  gcsLoad_o.h  *************************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers



            Load Packet Object



*******************************************************************************/

#ifndef GCSLoadPacket_API
#define GCSLoadPacket_API


#include "string_o"

#define GCSLOAD_OBJECT  "gcsLoad_o"
#define GCSLOAD_NAME    "name"
#define GCSLOAD_TYPE    "type"
#define GCSLOAD_LOAD    "load"


class gcsLoad_o  {
  protected:
    string_o            Name;
    int                 Type;
    int                 Load;

  public:
    gcsLoad_o();
    gcsLoad_o(const gcsLoad_o&);
    virtual ~gcsLoad_o();
    gcsLoad_o&   operator = (const gcsLoad_o&);

    const char*     name() const;
    int             load() const;
    int             type() const;

    void            setName(const string_o&);
    void            setType(const int);
    void            setLoad(const int);


    void            operator >> (string_o&) const;      // OLP representation.
    void            Serialize(string_o&) const;
    gcsLoad_o&      operator << (string_o&);            // Reconstruct.
    void            Deserialize(const string_o&);


};


/******************************************************************************/


inline const char* gcsLoad_o::name() const  {
    return  Name.string();
}

inline int gcsLoad_o::type() const  {
    return  Type;
}

inline int gcsLoad_o::load() const  {
    return  Load;
}

inline void gcsLoad_o::setLoad(const int l)  {
    Load = l;
}

inline void gcsLoad_o::setType(const int t)  {
    Type = t;
}

inline void gcsLoad_o::setName(const string_o& n)  {
    Name = n;
}


#endif

/******************************************************************************/

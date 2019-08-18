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
    string_o            name;
    int                 type;
    int                 load;

  public:
    gcsLoad_o();
    gcsLoad_o(const gcsLoad_o&);
    virtual ~gcsLoad_o();
    gcsLoad_o&   operator = (const gcsLoad_o&);

    const char*     Name() const;
    int             Load() const;
    int             Type() const;

    void            setName(const string_o&);
    void            setType(const int);
    void            setLoad(const int);


    void            operator >> (string_o&) const;      // OLP representation.
    void            Serialize(string_o&) const;
    gcsLoad_o&      operator << (const string_o&);      // Reconstruct.
    void            Deserialize(const string_o&);


};


/******************************************************************************/


inline const char* gcsLoad_o::Name() const  {
    return  name.string();
}

inline int gcsLoad_o::Type() const  {
    return  type;
}

inline int gcsLoad_o::Load() const  {
    return  load;
}

inline void gcsLoad_o::setLoad(const int l)  {
    load = l;
}

inline void gcsLoad_o::setType(const int t)  {
    type = t;
}

inline void gcsLoad_o::setName(const string_o& n)  {
    name = n;
}


#endif

/******************************************************************************/

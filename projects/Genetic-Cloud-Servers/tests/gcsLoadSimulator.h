/**  gcsLoadSimulator.h  ******************************************************
                                   Copyright 2019  Rattle  All rights reserved.

            Genetic Cloud Servers




            Load Simulator Client


            Simulate changing loading conditions to force the AI to change
            server profiles.

*******************************************************************************/

#ifndef GCSLoadSimulator_API
#define GCSLoadSimulator_API

#include "time_o"
#include "pserver_o"

class gcsLoadSimulator_o : public pserver_o  {
  protected:
    int         State;
    int         StartTime;

  public:
    gcsLoadSimulator_o();
    gcsLoadSimulator_o(const gcsLoadSimulator_o&);
    virtual ~gcsLoadSimulator_o();
    gcsLoadSimulator_o& operator = (const gcsLoadSimulator_o&);

    int     state() const;

    int     loop();
    int     start();

    int     process(input_o&, output_o&);

};


/******************************************************************************/

inline int gcsLoadSimulator_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/

/**  gcsDNA_o.cc  *************************************************************

            Genetic-Cloud-Servers



            Server DNA



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "gcsDNA_o.h"


gcsDNA_o::gcsDNA_o() : State(2) , entity_o(2002, 8, 200, 2002, "bob", 2002)  {}

gcsDNA_o::gcsDNA_o(const entity_o& entity) : State(2) , entity_o(entity)  {}

gcsDNA_o::gcsDNA_o(const gcsDNA_o& dna) : State(2) , entity_o(dna)  {}


gcsDNA_o::~gcsDNA_o()  {}


/******************************************************************************/

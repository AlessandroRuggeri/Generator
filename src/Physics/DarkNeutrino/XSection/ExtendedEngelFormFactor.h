//____________________________________________________________________________
/*!

  \class    genie::ExtendedEngelFormFactor

  \brief    Form Factor for BertuzzoDNuCOHXSec...+ nucleon Form Factor for H1

  \ref      J. Engel
            Phys.Lett. B264, 114 (1991)

  \author   Iker de Icaza <i.de-icaza-astiz \at sussex.ac.uk>
            University of Sussex

            Costas Andreopoulos <c.andreopoulos \at cern.ch>
            University of Liverpool

            Alessandro Ruggeri <a.ruggeri \at bo.infn.it>
            University of Bologna

  \created  June 26, 2025

  \cpright  Copyright (c) 2003-2024, The GENIE Collaboration
            For the full text of the license visit http://copyright.genie-mc.org

*/
//____________________________________________________________________________

#ifndef _EXTENDED_ENGEL_FORM_FACTOR_H_
#define _EXTENDED_ENGEL_FORM_FACTOR_H_

#include "Physics/DarkNeutrino/EngelFormFactor.h"

namespace genie {

class ExtendedEngelFormFactor : public EngelFormFactor {

public:
  ExtendedEngelFormFactor();
  ExtendedEngelFormFactor(string config);
  virtual ~ExtendedEngelFormFactor();

  double FormFactor(const double Q, const Target & target) const ;
  // The Q has to be in GeV
  // The returned FF is in natural units

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);


private:
  // keep an instance of the base class to be used for A>1 targets
    const EngelFormFactor *fFragmFunc;
    
    void LoadConfig(void);
};

} // genie namespace
#endif  // _EXTENDED_ENGEL_FORM_FACTOR_H_
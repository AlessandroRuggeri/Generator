//____________________________________________________________________________
/*
  Copyright (c) 2003-2024, The GENIE Collaboration
  For the full text of the license visit http://copyright.genie-mc.org

  Author: Iker de Icaza <i.de-icaza-astiz \at sussex.ac.uk>
  University of Sussex

  Costas Andreopoulos <c.andreopoulos \at cern.ch>
  University of Liverpool
*/
//____________________________________________________________________________

#include <TMath.h>

#include "Physics/DarkNeutrino/XSection/ExtendedEngelFormFactor.h"
#include "Framework/Messenger/Messenger.h"

#include "Framework/Conventions/Constants.h"
#include "Framework/Conventions/Units.h"

#include "Framework/Utils/StringUtils.h"

using namespace genie;


//____________________________________________________________________________
ExtendedEngelFormFactor::ExtendedEngelFormFactor() :
EngelFormFactor("genie::ExtendedEngelFormFactor", "Default")
{

}
//____________________________________________________________________________
ExtendedEngelFormFactor::ExtendedEngelFormFactor(string config) :
EngelFormFactor("genie::ExtendedEngelFormFactor", config)
{

}
//____________________________________________________________________________
ExtendedEngelFormFactor::~ExtendedEngelFormFactor()
{

}
//____________________________________________________________________________
double ExtendedEngelFormFactor::FormFactor(const double Q2, const Target & target) const {

  if(!target.IsProton()) {
    return fFragmFunc->FormFactor(Q2, target);
  }
  
  LOG("ExtendedEngelFormFactor", pWARN)
    << "target: " << target.AsString() << " is a proton.";

  LOG("ExtendedEngelFormFactor", pDEBUG)
    << "Running Engel Form Factor with Q2: " << Q2
    << " and target: " << target.AsString();

  const double A = target.A();

//   // TODO: placeholder form factor for H1
  return 1.0;
  //   const double s = 1.*units::fm;
  //   const double s2 = s * s;
  //   const double R = 1.2*TMath::Power(A, 1./3.)*units::fm;
  //   const double r = TMath::Sqrt(R*R - 5.*s*s);
  //   const double qr = TMath::Sqrt(Q2) * r;

  //   const double f1 = 3. * TMath::Exp(-.5*Q2*s2) * TMath::Power(qr, -3.);
  //   const double f2 = TMath::Sin(qr) - qr*TMath::Cos(qr);
  //   return f1 * f2;
}
//____________________________________________________________________________
void ExtendedEngelFormFactor::Configure(const Registry & config)
{
  Algorithm::Configure(config);
  this->LoadConfig();
}
//____________________________________________________________________________
void ExtendedEngelFormFactor::Configure(string config)
{
  Algorithm::Configure(config);
  this->LoadConfig();
}
//____________________________________________________________________________
void ExtendedEngelFormFactor::LoadConfig(void)
{
  fFragmFunc = dynamic_cast<const EngelFormFactor *>(this->SubAlg("base-ff"));
}
//____________________________________________________________________________
// @(#)root/minuit2:$Id$
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MN_GaussFcn_H_
#define MN_GaussFcn_H_

#include "Minuit2/FCNBase.h"

#include <vector>

namespace ROOT {

namespace Minuit2 {

class GaussFcn : public FCNBase {

public:
   GaussFcn(std::span<const double> meas, std::span<const double> pos, std::span<const double> mvar)
      : fMeasurements(meas.begin(), meas.end()),
        fPositions(pos.begin(), pos.end()),
        fMVariances(mvar.begin(), mvar.end())
   {
   }

   double Up() const override { return fErrorDef; }
   double operator()(std::vector<double> const &) const override;

   std::vector<double> Measurements() const { return fMeasurements; }
   std::vector<double> Positions() const { return fPositions; }
   std::vector<double> Variances() const { return fMVariances; }

   void SetErrorDef(double def) override { fErrorDef = def; }

private:
   std::vector<double> fMeasurements;
   std::vector<double> fPositions;
   std::vector<double> fMVariances;
   double fErrorDef = 1.;
};

} // namespace Minuit2

} // namespace ROOT

#endif // MN_GaussFcn_H_

// @(#)root/minuit2:$Id$
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "Minuit2/FCNGradientBase.h"

#include <vector>

namespace ROOT {

namespace Minuit2 {

class Quad1F : public FCNGradientBase {

public:
   double operator()(std::vector<double> const &par) const override
   {

      double x = par[0];

      return x * x;
   }

   std::vector<double> Gradient(std::vector<double> const &par) const override
   {

      double x = par[0];

      return std::vector<double>(1, 2. * x);
   }

   void SetErrorDef(double up) override { fErrorDef = up; }

   double Up() const override { return fErrorDef; }

   const FCNBase *Base() const { return this; }

private:
   double fErrorDef = 1.;
};

} // namespace Minuit2

} // namespace ROOT

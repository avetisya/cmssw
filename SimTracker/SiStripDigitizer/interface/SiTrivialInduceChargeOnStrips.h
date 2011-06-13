#ifndef Tracker_SiTrivialInduceChargeOnStrips_H
#define Tracker_SiTrivialInduceChargeOnStrips_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "SimTracker/SiStripDigitizer/interface/SiInduceChargeOnStrips.h"

class SiTrivialInduceChargeOnStrips: public SiInduceChargeOnStrips {
 public:
  SiTrivialInduceChargeOnStrips(const edm::ParameterSet& conf,double g);
  virtual ~SiTrivialInduceChargeOnStrips() {}
  void  induce(SiChargeCollectionDrifter::collection_type* collection_points,
	       const StripGeomDetUnit& det,
	       std::vector<double>& localAmplitudes,
	       size_t& recordMinAffectedStrip,
	       size_t& recordMaxAffectedStrip);
  
 private:
  static unsigned int typeOf(const StripGeomDetUnit&);
  static unsigned int indexOf(const std::string&);
  static const std::string type[];
  static const int Ntypes;
  std::vector<std::vector<double> > signalCoupling; 
  
  const double Nsigma;
  const double geVperElectron;
};

#endif

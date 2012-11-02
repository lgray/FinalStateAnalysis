// A slight revision of the bare RochesterCorrection code...
// Modifications from L. Gray

#ifndef __ROCHESTER_CORRECTIONS_2012_H__
#define __ROCHESTER_CORRECTIONS_2012_H__


#include <iostream>
#include <TChain.h>
#include <TClonesArray.h>
#include <TString.h>
#include <map>

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/RandomNumberGenerator.h"

#include <TSystem.h>
#include <TROOT.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TRandom3.h>

namespace rochcor {

  class RochesterCorrections2012 {
  public:
    RochesterCorrections2012(bool central_value);
    ~RochesterCorrections2012();
    
    void momcor_mc(TLorentzVector&, float, float, int);
    void momcor_data(TLorentzVector&, float, float, int);
    
    void musclefit_data(TLorentzVector& , TLorentzVector&);
    
    float zptcor(float);
    int etabin(float);
    int phibin(float);
    
  private:
    
    edm::Service<edm::RandomNumberGenerator> rng;    
    
    //  static float netabin[9] = {-2.4,-2.1,-1.4,-0.7,0.0,0.7,1.4,2.1,2.4};
    static constexpr double pi = 3.14159265358979323846;
    static const float netabin[9];
    
    static constexpr float genm_smr = 9.09915e+01; //gen mass peak with eta dependent gaussian smearing => better match in Z mass profile vs. eta/phi
    static constexpr float genm = 91.06; //gen mass peak without smearing => Z mass profile vs. eta/phi in CMS note
    
    static constexpr float mrecm = 90.8177; //rec mass peak in MC (2011A)
    static constexpr float drecm = 90.5332; //rec mass peak in data (2011A)
    static constexpr float mgscl_stat = 0.0001; //stat. error of global factor for mass peak in MC (2011A)  
    static constexpr float mgscl_syst = 0.0006; //syst. error of global factor for mass peak in MC (2011A)  
    static constexpr float dgscl_stat = 0.0001; //stat. error of global factor for mass peak in data (2011A)
    static constexpr float dgscl_syst = 0.0008; //syst. error of global factor for mass peak in data (2011A)
    
    //iteration2 after FSR : after Z Pt correction
    static constexpr float delta = -5.48477e-06;
    static constexpr float delta_stat = 4.38582e-07;
    static constexpr float delta_syst = 6.992e-07;
    
    static constexpr float sf = 33.4956;
    static constexpr float sf_stat = 0.312614;
    static constexpr float sf_syst = 9.29;
    
    static constexpr float apar = 1.0; //+- 0.002
    static constexpr float bpar = -5.03313e-06; //+- 1.57968e-06
    static constexpr float cpar = -4.41463e-05; //+- 1.92775e-06
    static constexpr float d0par = -0.000148871; //+- 3.16301e-06
    static constexpr float e0par = 1.59501; //+- 0.0249021
    static constexpr float d1par = 7.95495e-05; //+- 1.12386e-05
    static constexpr float e1par = -0.364823; //+- 0.17896
    static constexpr float d2par = 0.000152032; //+- 5.68386e-06
    static constexpr float e2par = 0.410195; //+- 0.0431732
 
    //---------------------------------------------------------------------------------------------
    
    static const float dcor_bf[8][8];  
    static const float dcor_ma[8][8];
    static const float mcor_bf[8][8];
    static const float mcor_ma[8][8];
    static const float dcor_bfer[8][8];  
    static const float dcor_maer[8][8];
    static const float mcor_bfer[8][8];
    static const float mcor_maer[8][8];
    
    //=======================================================================================================
    
    static const float dmavg[8][8];  
    static const float dpavg[8][8];  
    static const float mmavg[8][8];  
    static const float mpavg[8][8];
    
    //===============================================================================================
    //parameters for Z pt correction
    static constexpr int nptbins=84;
    static const float ptlow[85];    
    
    static const float zptscl[84];
    static const float zptscler[84];
    
    float mptsys_mc_dm[8][8];
    float mptsys_mc_da[8][8];
    float mptsys_da_dm[8][8];
    float mptsys_da_da[8][8];
    
    float gscler_mc_dev;
    float gscler_da_dev;
  };

} // namespace rochcor

#endif
  

#ifndef ANALYSISDATAFORMATS_BOOSTEDOBJECTS_ELECTRON_HH
#define ANALYSISDATAFORMATS_BOOSTEDOBJECTS_ELECTRON_HH

#include "AnalysisDataFormats/BoostedObjects/interface/Candidate.h"

/*\ 
 * Simple Electron class to be used with B2G EDMNtuples
 * https://github.com/cmsb2g/B2GAnaFW
 */

namespace vlq{
  class Electron ;
  typedef std::vector<vlq::Electron> ElectronCollection ; 
  class Electron : public vlq::Candidate {
    public:
      Electron () : index_(-1) {} 
      Electron (const vlq::Electron& el) :
        vlq::Candidate(el),
        index_             (el.getIndex             () ),  
        Charge_            (el.getCharge            () ), 
        Dxy_               (el.getDxy               () ), 
        Dz_                (el.getDz                () ), 
        E_                 (el.getE                 () ), 
        Eta_               (el.getEta               () ), 
        HoE_               (el.getHoE               () ), 
        Iso03_             (el.getIso03             () ), 
        Key_               (el.getKey               () ), 
        Mass_              (el.getMass              () ), 
        Phi_               (el.getPhi               () ), 
        Pt_                (el.getPt                () ), 
        Y_                 (el.getY                 () ), 
        dEtaIn_            (el.getdEtaIn            () ), 
        dEtaInSeed_        (el.getdEtaInSeed        () ), 
        dPhiIn_            (el.getdPhiIn            () ), 
        full5x5siee_       (el.getfull5x5siee       () ), 
        hasMatchedConVeto_ (el.gethasMatchedConVeto () ), 
        isEB_              (el.getisEB              () ), 
        isLoose_           (el.getisLoose           () ), 
        isMedium_          (el.getisMedium          () ), 
        isTight_           (el.getisTight           () ), 
        isVeto_            (el.getisVeto            () ), 
        missHits_          (el.getmissHits          () ), 
        ooEmooP_           (el.getooEmooP           () ), 
        scEta_             (el.getscEta             () )  
    { } 
      ~Electron () {}

      int getIndex () const { return index_ ; }
      float getCharge () const { return Charge_ ; } 
      float getDxy () const { return Dxy_ ; } 
      float getDz () const { return Dz_ ; } 
      float getE () const { return E_ ; } 
      float getEta () const { return Eta_ ; } 
      float getHoE () const { return HoE_ ; } 
      float getIso03 () const { return Iso03_ ; } 
      float getKey () const { return Key_ ; } 
      float getMass () const { return Mass_ ; } 
      float getPhi () const { return Phi_ ; } 
      float getPt () const { return Pt_ ; } 
      float getY () const { return Y_ ; } 
      float getdEtaIn () const { return dEtaIn_ ; } 
      float getdEtaInSeed () const { return dEtaInSeed_ ; } 
      float getdPhiIn () const { return dPhiIn_ ; } 
      float getfull5x5siee () const { return full5x5siee_ ; } 
      float gethasMatchedConVeto () const { return hasMatchedConVeto_ ; } 
      float getisEB () const { return isEB_ ; } 
      float getisLoose () const { return isLoose_ ; } 
      float getisMedium () const { return isMedium_ ; } 
      float getisTight () const { return isTight_ ; } 
      float getisVeto () const { return isVeto_ ; } 
      float getmissHits () const { return missHits_ ; } 
      float getooEmooP () const { return ooEmooP_ ; } 
      float getscEta () const { return scEta_ ; } 

      void setIndex (const int& index) {index_ = index ; } 
      void setCharge (const float Charge) {Charge_ = Charge ;} 
      void setDxy(const float Dxy) {Dxy_ = Dxy ;} 
      void setDz (const float Dz) {Dz_ = Dz ;} 
      void setE (const float E) {E_ = E ;} 
      void setEta (const float Eta) {Eta_ = Eta ;} 
      void setHoE (const float HoE) {HoE_ = HoE ;} 
      void setIso03 (const float Iso03) {Iso03_ = Iso03 ;} 
      void setKey (const float Key) {Key_ = Key ;} 
      void setMass (const float Mass) {Mass_ = Mass ;} 
      void setPhi (const float Phi) {Phi_ = Phi ;} 
      void setPt (const float Pt) {Pt_ = Pt ;} 
      void setY (const float Y) {Y_ = Y ;} 
      void setdEtaIn (const float dEtaIn) {dEtaIn_ = dEtaIn ;} 
      void setdEtaInSeed (const float dEtaInSeed) {dEtaInSeed_ = dEtaInSeed ;} 
      void setdPhiIn (const float dPhiIn) {dPhiIn_ = dPhiIn ;} 
      void setfull5x5siee (const float full5x5siee) {full5x5siee_ = full5x5siee ;} 
      void sethasMatchedConVeto (const float hasMatchedConVeto) {hasMatchedConVeto_ = hasMatchedConVeto ;}
      void setisEB (const float isEB) {isEB_ = isEB ;} 
      void setisLoose (const float isLoose) {isLoose_ = isLoose ;} 
      void setisMedium (const float isMedium) {isMedium_ = isMedium ;} 
      void setisTight (const float isTight) {isTight_ = isTight ;} 
      void setisVeto (const float isVeto) {isVeto_ = isVeto ;} 
      void setmissHits (const float missHits) {missHits_ = missHits ;} 
      void setooEmooP (const float ooEmooP) {ooEmooP_ = ooEmooP ;} 
      void setscEta (const float scEta) {scEta_ = scEta ;} 

    private: 
      int index_ ; 
      float Charge_ ;
      float Dxy_ ;
      float Dz_ ;
      float E_ ;
      float Eta_ ;
      float HoE_ ;
      float Iso03_ ;
      float Key_ ;
      float Mass_ ;
      float Phi_ ;
      float Pt_ ;
      float Y_ ;
      float dEtaIn_ ;
      float dEtaInSeed_ ;
      float dPhiIn_ ;
      float full5x5siee_ ;
      float hasMatchedConVeto_;
      float isEB_ ;
      float isLoose_ ;
      float isMedium_ ;
      float isTight_ ;
      float isVeto_ ;
      float missHits_ ;
      float ooEmooP_ ;
      float scEta_ ;
  }; 
}

#endif 


#ifndef ANALYSISDATAFORMATS_BOOSTEDOBJECTS_MUON_HH
#define ANALYSISDATAFORMATS_BOOSTEDOBJECTS_MUON_HH

#include "AnalysisDataFormats/BoostedObjects/interface/Candidate.h"

/*\ 
 * Simple Muon class to be used with B2G EDMNtuples
 * https://github.com/cmsb2g/B2GAnaFW
 */

namespace vlq{
  class Muon ;
  typedef std::vector<vlq::Muon> MuonCollection ; 
  class Muon : public vlq::Candidate {
    public:
      Muon () : index_(-1) {} 
      Muon (const vlq::Muon& mu) :
        vlq::Candidate(mu),
        index_                   (mu.getIndex                   () ),   
        Charge_                  (mu.getCharge                  () ), 
        Dxy_                     (mu.getDxy                     () ), 
        Dxyerr_                  (mu.getDxyerr                  () ), 
        Dz_                      (mu.getDz                      () ), 
        Dzerr_                   (mu.getDzerr                   () ), 
        E_                       (mu.getE                       () ), 
        Eta_                     (mu.getEta                     () ), 
        GenMuonCharge_           (mu.getGenMuonCharge           () ), 
        GenMuonE_                (mu.getGenMuonE                () ), 
        GenMuonEta_              (mu.getGenMuonEta              () ), 
        GenMuonPhi_              (mu.getGenMuonPhi              () ), 
        GenMuonPt_               (mu.getGenMuonPt               () ), 
        GenMuonY_                (mu.getGenMuonY                () ), 
        GlbTrkNormChi2_          (mu.getGlbTrkNormChi2          () ), 
        InTrkNormChi2_           (mu.getInTrkNormChi2           () ), 
        IsGlobalMuon_            (mu.getIsGlobalMuon            () ), 
        IsLooseMuon_             (mu.getIsLooseMuon             () ), 
        IsPFMuon_                (mu.getIsPFMuon                () ), 
        IsSoftMuon_              (mu.getIsSoftMuon              () ), 
        IsTightMuon_             (mu.getIsTightMuon             () ), 
        IsTrackerMuon_           (mu.getIsTrackerMuon           () ), 
        Iso04_                   (mu.getIso04                   () ), 
        Key_                     (mu.getKey                     () ), 
        Mass_                    (mu.getMass                    () ), 
        NumberMatchedStations_   (mu.getNumberMatchedStations   () ), 
        NumberOfPixelLayers_     (mu.getNumberOfPixelLayers     () ), 
        NumberOfValidTrackerHits_(mu.getNumberOfValidTrackerHits() ), 
        NumberTrackerLayers_     (mu.getNumberTrackerLayers     () ), 
        NumberValidMuonHits_     (mu.getNumberValidMuonHits     () ), 
        NumberValidPixelHits_    (mu.getNumberValidPixelHits    () ), 
        Phi_                     (mu.getPhi                     () ), 
        Pt_                      (mu.getPt                      () ), 
        SumChargedHadronPt_      (mu.getSumChargedHadronPt      () ), 
        SumNeutralHadronPt_      (mu.getSumNeutralHadronPt      () ), 
        SumPUPt_                 (mu.getSumPUPt                 () ), 
        SumPhotonPt_             (mu.getSumPhotonPt             () )  
    { } 
      ~Muon () {}

      int   getIndex                   () const { return index_                   ; }
      float getCharge                  () const { return Charge_                  ; }
      float getDxy                     () const { return Dxy_                     ; }
      float getDxyerr                  () const { return Dxyerr_                  ; }
      float getDz                      () const { return Dz_                      ; }
      float getDzerr                   () const { return Dzerr_                   ; }
      float getE                       () const { return E_                       ; }
      float getEta                     () const { return Eta_                     ; }
      float getGenMuonCharge           () const { return GenMuonCharge_           ; }
      float getGenMuonE                () const { return GenMuonE_                ; }
      float getGenMuonEta              () const { return GenMuonEta_              ; }
      float getGenMuonPhi              () const { return GenMuonPhi_              ; }
      float getGenMuonPt               () const { return GenMuonPt_               ; }
      float getGenMuonY                () const { return GenMuonY_                ; }
      float getGlbTrkNormChi2          () const { return GlbTrkNormChi2_          ; }
      float getInTrkNormChi2           () const { return InTrkNormChi2_           ; }
      float getIsGlobalMuon            () const { return IsGlobalMuon_            ; }
      float getIsLooseMuon             () const { return IsLooseMuon_             ; }
      float getIsPFMuon                () const { return IsPFMuon_                ; }
      float getIsSoftMuon              () const { return IsSoftMuon_              ; }
      float getIsTightMuon             () const { return IsTightMuon_             ; }
      float getIsTrackerMuon           () const { return IsTrackerMuon_           ; }
      float getIso04                   () const { return Iso04_                   ; }
      float getKey                     () const { return Key_                     ; }
      float getMass                    () const { return Mass_                    ; }
      float getNumberMatchedStations   () const { return NumberMatchedStations_   ; }
      float getNumberOfPixelLayers     () const { return NumberOfPixelLayers_     ; }
      float getNumberOfValidTrackerHits() const { return NumberOfValidTrackerHits_; } 
      float getNumberTrackerLayers     () const { return NumberTrackerLayers_     ; }
      float getNumberValidMuonHits     () const { return NumberValidMuonHits_     ; }
      float getNumberValidPixelHits    () const { return NumberValidPixelHits_    ; }
      float getPhi                     () const { return Phi_                     ; }
      float getPt                      () const { return Pt_                      ; }
      float getSumChargedHadronPt      () const { return SumChargedHadronPt_      ; }
      float getSumNeutralHadronPt      () const { return SumNeutralHadronPt_      ; }
      float getSumPUPt                 () const { return SumPUPt_                 ; }
      float getSumPhotonPt             () const { return SumPhotonPt_             ; }

      void setIndex                   (const int& index)                      {index_ = index                                       ; } 
      void setCharge                  (const float& Charge)                   { Charge_ = Charge                                    ; }
      void setDxy                     (const float& Dxy)                      { Dxy_ = Dxy                                          ; }
      void setDxyerr                  (const float& Dxyerr)                   { Dxyerr_ = Dxyerr                                    ; }
      void setDz                      (const float& Dz)                       { Dz_ = Dz                                            ; }
      void setDzerr                   (const float& Dzerr)                    { Dzerr_ = Dzerr                                      ; }
      void setE                       (const float& E)                        { E_ = E                                              ; }
      void setEta                     (const float& Eta)                      { Eta_ = Eta                                          ; }
      void setGenMuonCharge           (const float& GenMuonCharge)            { GenMuonCharge_ = GenMuonCharge                      ; }
      void setGenMuonE                (const float& GenMuonE)                 { GenMuonE_ = GenMuonE                                ; }
      void setGenMuonEta              (const float& GenMuonEta)               { GenMuonEta_ = GenMuonEta                            ; }
      void setGenMuonPhi              (const float& GenMuonPhi)               { GenMuonPhi_ = GenMuonPhi                            ; }
      void setGenMuonPt               (const float& GenMuonPt)                { GenMuonPt_ = GenMuonPt                              ; }
      void setGenMuonY                (const float& GenMuonY)                 { GenMuonY_ = GenMuonY                                ; }
      void setGlbTrkNormChi2          (const float& GlbTrkNormChi2)           { GlbTrkNormChi2_ = GlbTrkNormChi2                    ; }
      void setInTrkNormChi2           (const float& InTrkNormChi2)            { InTrkNormChi2_ = InTrkNormChi2                      ; }
      void setIsGlobalMuon            (const float& IsGlobalMuon)             { IsGlobalMuon_ = IsGlobalMuon                        ; }
      void setIsLooseMuon             (const float& IsLooseMuon)              { IsLooseMuon_ = IsLooseMuon                          ; }
      void setIsPFMuon                (const float& IsPFMuon)                 { IsPFMuon_ = IsPFMuon                                ; }
      void setIsSoftMuon              (const float& IsSoftMuon)               { IsSoftMuon_ = IsSoftMuon                            ; }
      void setIsTightMuon             (const float& IsTightMuon)              { IsTightMuon_ = IsTightMuon                          ; }
      void setIsTrackerMuon           (const float& IsTrackerMuon)            { IsTrackerMuon_ = IsTrackerMuon                      ; }
      void setIso04                   (const float& Iso04)                    { Iso04_ = Iso04                                      ; }
      void setKey                     (const float& Key)                      { Key_ = Key                                          ; }
      void setMass                    (const float& Mass)                     { Mass_ = Mass                                        ; }
      void setNumberMatchedStations   (const float& NumberMatchedStations)    { NumberMatchedStations_ = NumberMatchedStations      ; }
      void setNumberOfPixelLayers     (const float& NumberOfPixelLayers)      { NumberOfPixelLayers_ = NumberOfPixelLayers          ; }
      void setNumberOfValidTrackerHits(const float& NumberOfValidTrackerHits) { NumberOfValidTrackerHits_ = NumberOfValidTrackerHits; } 
      void setNumberTrackerLayers     (const float& NumberTrackerLayers)      { NumberTrackerLayers_ = NumberTrackerLayers          ; }
      void setNumberValidMuonHits     (const float& NumberValidMuonHits )     { NumberValidMuonHits_ = NumberValidMuonHits          ; }
      void setNumberValidPixelHits    (const float& NumberValidPixelHits )    { NumberValidPixelHits_ = NumberValidPixelHits        ; }
      void setPhi                     (const float& Phi )                     { Phi_ = Phi                                          ; }
      void setPt                      (const float& Pt )                      { Pt_ = Pt                                            ; }
      void setSumChargedHadronPt      (const float& SumChargedHadronPt)       { SumChargedHadronPt_ = SumChargedHadronPt            ; }
      void setSumNeutralHadronPt      (const float& SumNeutralHadronPt)       { SumNeutralHadronPt_ = SumNeutralHadronPt            ; }
      void setSumPUPt                 (const float& SumPUPt)                  { SumPUPt_ = SumPUPt                                  ; }
      void setSumPhotonPt             (const float& SumPhotonPt)              { SumPhotonPt_ = SumPhotonPt                          ; }

    protected:

      int   index_                   ;
      float Charge_                  ;
      float Dxy_                     ;
      float Dxyerr_                  ;
      float Dz_                      ;
      float Dzerr_                   ;
      float E_                       ;
      float Eta_                     ;
      float GenMuonCharge_           ;
      float GenMuonE_                ;
      float GenMuonEta_              ;
      float GenMuonPhi_              ;
      float GenMuonPt_               ;
      float GenMuonY_                ;
      float GlbTrkNormChi2_          ;
      float InTrkNormChi2_           ;
      float IsGlobalMuon_            ;
      float IsLooseMuon_             ;
      float IsPFMuon_                ;
      float IsSoftMuon_              ;
      float IsTightMuon_             ;
      float IsTrackerMuon_           ;
      float Iso04_                   ;
      float Key_                     ;
      float Mass_                    ;
      float NumberMatchedStations_   ;
      float NumberOfPixelLayers_     ;
      float NumberOfValidTrackerHits_;
      float NumberTrackerLayers_     ;
      float NumberValidMuonHits_     ;
      float NumberValidPixelHits_    ;
      float Phi_                     ;
      float Pt_                      ;
      float SumChargedHadronPt_      ;
      float SumNeutralHadronPt_      ;
      float SumPUPt_                 ;
      float SumPhotonPt_             ;
      float Y_                       ;
  }; 
}

#endif 

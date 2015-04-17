// -*- C++ -*-
//
// Package:    GenProduction/GenParticleAnalyzer
// Class:      GenParticleAnalyzer
// 
/**\class GenParticleAnalyzer GenParticleAnalyzer.cc GenProduction/GenParticleAnalyzer/plugins/GenParticleAnalyzer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  Devdatta Majumder
//         Created:  Thu, 16 Apr 2015 12:47:35 GMT
//
//


// system include files
#include <memory>
#include <map>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"


#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TLorentzVector.h>

//
// class declaration
//

class GenParticleAnalyzer : public edm::EDAnalyzer {
  public:
    explicit GenParticleAnalyzer(const edm::ParameterSet&);
    ~GenParticleAnalyzer();

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


  private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
    //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
    //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
    //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

    // ----------member data ---------------------------
    edm::Service<TFileService> fs             ; 
    std::map<std::string, TH1D*> h1_          ; 
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenParticleAnalyzer::GenParticleAnalyzer(const edm::ParameterSet& iConfig)

{
  //now do what ever initialization is needed

}


GenParticleAnalyzer::~GenParticleAnalyzer()
{

  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
  void
GenParticleAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace reco;
  using namespace edm;
  using namespace std;

  Handle<GenParticleCollection> genParticles;
  iEvent.getByLabel("genParticles", genParticles);

  for(size_t i = 0; i < genParticles->size(); ++ i) { 
    const GenParticle & part = (*genParticles)[i];
    int id = part.pdgId(), st = part.status() ; 
    if ( abs(id) == 6 && ( abs(st) >=21 && abs(st) <=29) ) {
      TLorentzVector p4l, p4n ; 
      unsigned ndau = part.numberOfDaughters() ; 
      for ( size_t idau = 0; idau < ndau; ++idau) {
        const Candidate* dau = part.daughter(idau) ; 
        int dauid = dau->pdgId() ; 
        if ( abs(dauid) != 24 ) continue ; 
        h1_["MWfromtgen"] -> Fill(dau->mass()) ; 
        TLorentzVector p4w ;
        p4w.SetPtEtaPhiM(dau->pt(), dau->eta(), dau->phi(), dau->mass()) ;
        h1_["MtWfromtgen"] -> Fill(dau->mass()) ; 
        h1_["ptWfromtgen"] -> Fill(p4w.Mt()) ; 
        unsigned ngdau = dau->numberOfDaughters() ; 
        if ( ngdau == 1 && abs(dau->daughter(0)->pdgId()) == 24 ) {
          const Candidate* gdau = dau->daughter(0) ; 
          unsigned nggdau = gdau->numberOfDaughters() ; 
          if ( nggdau != 2 ) continue ; 
          for ( size_t iggdau = 0; iggdau < nggdau; ++iggdau ) {
            const Candidate* ggdau = gdau->daughter(iggdau) ; 
            if ( abs(ggdau->pdgId()) == 11 || abs(ggdau->pdgId()) == 13 || abs(ggdau->pdgId()) == 15 ) 
              p4l.SetPtEtaPhiM(ggdau->pt(), ggdau->eta(), ggdau->phi(), ggdau->mass()) ; 
            if ( abs(ggdau->pdgId()) == 12 || abs(ggdau->pdgId()) == 14 || abs(ggdau->pdgId()) == 16 ) 
              p4n.SetPtEtaPhiM(ggdau->pt(), ggdau->eta(), ggdau->phi(), ggdau->mass()) ; 
          } //// Loop over W daughters 
        } //// W -> W
        else {
          for ( size_t igdau = 0; igdau < ngdau; ++igdau ) {
            const Candidate* gdau = dau->daughter(igdau) ; 
            if ( abs(gdau->pdgId()) == 11 || abs(gdau->pdgId()) == 13 || abs(gdau->pdgId()) == 15 ) 
              p4l.SetPtEtaPhiM(gdau->pt(), gdau->eta(), gdau->phi(), gdau->mass()) ; 
            if ( abs(gdau->pdgId()) == 12 || abs(gdau->pdgId()) == 14 || abs(gdau->pdgId()) == 16 ) 
              p4n.SetPtEtaPhiM(gdau->pt(), gdau->eta(), gdau->phi(), gdau->mass()) ; 
          }
        } //// W -> ff
        if ( p4l.Pt() > 0 && p4n.Pt() > 0  ) {
          h1_["ptlgen"]->Fill(p4l.Pt()) ; 
          h1_["ptnugen"]->Fill(p4n.Pt()) ; 
          h1_["ptlnugen"]->Fill( (p4l+p4n).Pt() ) ; 
          h1_["Mlnugen"]->Fill( (p4l+p4n).Mag() ) ; 
          h1_["Mtlnugen"]->Fill( (p4l+p4n).Mt() ) ;
        }
      } //// looping over top daughters
    } //// top quark found 
  } //// particle loop


  /*
     for(size_t i = 0; i < genParticles->size(); ++ i) {
     const GenParticle & p = (*genParticles)[i];
     int id = p.pdgId();
     int st = p.status();  
  //double pt = p.pt(), eta = p.eta(), phi = p.phi(), mass = p.mass();
  //double vx = p.vx(), vy = p.vy(), vz = p.vz();
  //int charge = p.charge();

  if ( abs(id) == 25 && ( st >= 21 && st <= 29) ) {
  unsigned n = p.numberOfDaughters();
  for(size_t j = 0; j < n; ++ j) {
  const Candidate * d = p.daughter( j );
  int dauId = d->pdgId();
  if ( abs(dauId) == 24 ) {
  h1_["MWfromHgen"]->Fill(d->mass()) ;
  }
  }
  }

  if ( abs(id) == 6 && ( st >= 21 && st <= 29) ) {
  unsigned n = p.numberOfDaughters();
  for(size_t j = 0; j < n; ++ j) {
  const Candidate * d = p.daughter( j );
  int dauId = d->pdgId();
  if ( abs(dauId) == 24 ) {
  h1_["MWfromtgen"]->Fill(d->mass()) ;
  unsigned ngd = d->numberOfDaughters() ;

  TLorentzVector p4l, p4n ; 

  if ( ngd == 1 && abs(d->daughter( 0 )->pdgId() == 24) )  {
  const Candidate *dau = d->daughter(0) ; 
  unsigned nggd = dau->numberOfDaughters() ;
  if ( nggd == 1 && abs(dau->daughter( 0 )->pdgId() == 24) )  {
  cout << "W undecayed\n" ; 
  }
  else {
  for ( size_t iggd = 0; iggd < nggd; ++iggd ) {
  const Candidate* ggdau = dau->daughter( iggd ) ; 
  int ggdauid = ggdau->pdgId() ; 
  if ( abs(ggdauid) == 11 || abs(ggdauid) == 13 || abs(ggdauid) == 15 ) {
  p4l.SetPtEtaPhiM( ggdau->pt(), ggdau->eta(), ggdau->phi(), ggdau->mass() ) ; 
  }
  if ( abs(ggdauid) == 12 || abs(ggdauid) == 14 || abs(ggdauid) == 16 ) {
  p4l.SetPtEtaPhiM( ggdau->pt(), ggdau->eta(), ggdau->phi(), ggdau->mass() ) ; 
  }
  }
  }
  }
  else {
  for ( size_t i = 0; i < ngd; ++i ) {
  const Candidate * gd = d->daughter( i );
  int gdid = gd->pdgId() ; 
  cout << " W dau id " << gdid << " status " << gd->status() << endl ; 
  if ( abs(gdid) == 11 || abs(gdid) == 13 || abs(gdid) == 15 ) {
  p4l.SetPtEtaPhiM( gd->pt(), gd->eta(), gd->phi(), gd->mass() ) ; 
  }
  if ( abs(gdid) == 12 || abs(gdid) == 14 || abs(gdid) == 16 ) {
  p4l.SetPtEtaPhiM( gd->pt(), gd->eta(), gd->phi(), gd->mass() ) ; 
  }
  }
  }
  cout << " ptl " << p4l.Pt() << " ptn " << p4n.Pt() << " Mlnugen " << (p4l+p4n).Mag() << " Mtlnugen " << (p4l+p4n).Mt() << endl ; 
  if (p4l.Pt() > 0 && p4n.Pt() > 0) {
  h1_["Mtlnugen"] -> Fill( (p4l+p4n).Mt() ) ; 
  h1_["Mlnugen"]->Fill( (p4l+p4n).Mag() ) ;
  }
  }
  }
  }

  //if ( abs(id) == 24 && ( st >= 21 && st <= 29) ) {
  //  p4w.SetPtEtaPhiM(pt, eta, phi, mass) ;
  //  h1_["MWgen"]->Fill(p4w.Mag()) ; 
  //  bool lepw(false) ; 
  //  unsigned n = p.numberOfDaughters();
  //  for(size_t j = 0; j < n; ++ j) {
  //    const Candidate * d = p.daughter( j );
  //    int dauId = d->pdgId();
  //    //int daust = d->status() ; 

  //    //if ( abs(dauId) == 24 && daust == 52)

  //    double daupt = d->pt(), daueta = d->eta(), dauphi = d->phi(), daumass = d->mass() ; 
  //    if ( abs(dauId) == 11 || abs(dauId) == 13 || abs(dauId) == 15 ) { lepw = true ; p4l.SetPtEtaPhiM(daupt, daueta, dauphi, daumass) ; } 
  //    if ( abs(dauId) == 12 || abs(dauId) == 14 || abs(dauId) == 16 ) { lepw = true ; p4nu.SetPtEtaPhiM(daupt, daueta, dauphi, daumass) ; } 
  //  }
  //  if ( lepw ) {
  //    p4lnu = p4l+p4nu ; 
  //    h1_["Mlnugen"]->Fill(p4lnu.Mag()) ;
  //  }
  //} // W particle

  //const Candidate * mom = p.mother();
  //const Candidate * grandmom = mom->mother();
}
*/


}


// ------------ method called once each job just before starting event loop  ------------
  void 
GenParticleAnalyzer::beginJob()
{
  TFileDirectory results = TFileDirectory( fs->mkdir("results") );
  h1_["ptWfromtgen"] = fs->make<TH1D>("ptWfromtgen", ";p_{T}(W);;", 200, 0., 1000.) ;  
  h1_["MtWfromtgen"] = fs->make<TH1D>("MtWfromtgen", ";M_{T}(W);;", 200, 0., 1000.) ;  
  h1_["MWfromtgen"] = fs->make<TH1D>("MWfromtgen", ";M(W);;", 100, 0., 100.) ;  
  h1_["Mlnugen"] = fs->make<TH1D>("Mlnugen", ";M(l#nu);;", 100, 0., 100.) ;  
  h1_["ptlnugen"] = fs->make<TH1D>("ptlnugen", ";p_{T}(l#nu);;", 200, 0., 1000.) ;  
  h1_["Mtlnugen"] = fs->make<TH1D>("Mtlnugen", ";M_{T}(l#nu);;", 200, 0., 1000.) ;  
  h1_["ptlgen"] = fs->make<TH1D>("ptlgen", ";p_{T}(l) [GeV]", 200, 0., 1000.) ; 
  h1_["ptnugen"] = fs->make<TH1D>("ptnugen", ";p_{T}(#nu) [GeV]", 200, 0., 1000.) ; 

  h1_["MWfromHgen"] = fs->make<TH1D>("MWfromHgen", ";M(W);;", 100, 0., 100.) ;  
  h1_["Mlnust1gen"] = fs->make<TH1D>("Mlnust1gen", ";M(l#nu);;", 100, 0., 100.) ;  

}

// ------------ method called once each job just after ending the event loop  ------------
  void 
GenParticleAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
   void 
   GenParticleAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
   {
   }
   */

// ------------ method called when ending the processing of a run  ------------
/*
   void 
   GenParticleAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
   {
   }
   */

// ------------ method called when starting to processes a luminosity block  ------------
/*
   void 
   GenParticleAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
   {
   }
   */

// ------------ method called when ending the processing of a luminosity block  ------------
/*
   void 
   GenParticleAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
   {
   }
   */

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GenParticleAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GenParticleAnalyzer);

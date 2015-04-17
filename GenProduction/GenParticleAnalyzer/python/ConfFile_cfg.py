import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/work/d/devdatta/CMSREL/CMSSW_7_1_14/src/Configuration/Generator/test/TptTotH_LH_narrow_M1200_TuneCUETP8M1_13TeV_GEN.root'
    )
)

process.TFileService = cms.Service("TFileService",
       fileName = cms.string("GenWCands.root")
       )

process.demo = cms.EDAnalyzer('GenParticleAnalyzer'
)


process.p = cms.Path(process.demo)

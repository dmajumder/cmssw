import FWCore.ParameterSet.Config as cms

from TrackingTools.TransientTrack.TransientTrackBuilder_cfi import *
from RecoBTau.JetTagComputer.jetTagRecord_cfi import *
from RecoBTag.SecondaryVertex.secondaryVertexTagInfos_cfi import *
from RecoBTag.SecondaryVertex.simpleSecondaryVertex2TrkComputer_cfi import *
from RecoBTag.SecondaryVertex.simpleSecondaryVertex3TrkComputer_cfi import *
from RecoBTag.SecondaryVertex.simpleSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.simpleSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.ghostTrackVertexTagInfos_cfi import *
from RecoBTag.SecondaryVertex.ghostTrackComputer_cfi import *
from RecoBTag.SecondaryVertex.ghostTrackBJetTags_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexSoftLeptonComputer_cfi import *
from RecoBTag.SecondaryVertex.combinedSecondaryVertexSoftLeptonBJetTags_cfi import *

# IVF
from RecoBTag.SecondaryVertex.inclusiveSecondaryVertexFinderTagInfos_cfi import *
from RecoBTag.SecondaryVertex.combinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.combinedInclusiveSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.bVertexFilter_cfi import *
inclusiveSecondaryVerticesFiltered = bVertexFilter.clone()
inclusiveSecondaryVerticesFiltered.vertexFilter.multiplicityMin = 2
inclusiveSecondaryVerticesFiltered.secondaryVertices = cms.InputTag("inclusiveSecondaryVertices")
from RecoBTag.SecondaryVertex.bToCharmDecayVertexMerger_cfi import *
from RecoBTag.SecondaryVertex.inclusiveSecondaryVertexFinderFilteredTagInfos_cfi import *
from RecoBTag.SecondaryVertex.simpleInclusiveSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.simpleInclusiveSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.doubleVertex2TrkComputer_cfi import *
from RecoBTag.SecondaryVertex.doubleSecondaryVertexHighEffBJetTags_cfi import *

# Negative taggers
from RecoBTag.SecondaryVertex.secondaryVertexNegativeTagInfos_cfi import *
from RecoBTag.SecondaryVertex.inclusiveSecondaryVertexFinderNegativeTagInfos_cfi import *
from RecoBTag.SecondaryVertex.inclusiveSecondaryVertexFinderFilteredNegativeTagInfos_cfi import *
from RecoBTag.SecondaryVertex.negativeSimpleSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeSimpleSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeSimpleInclusiveSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeSimpleInclusiveSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.negativeCombinedInclusiveSecondaryVertexV2BJetTags_cfi import *

# Positive taggers
from RecoBTag.SecondaryVertex.positiveCombinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.positiveCombinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.positiveCombinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.positiveCombinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.positiveCombinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.positiveCombinedInclusiveSecondaryVertexV2BJetTags_cfi import *

# New candidate based fwk
from RecoBTag.SecondaryVertex.candidateSimpleSecondaryVertex2TrkComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateSimpleSecondaryVertex3TrkComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateCombinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateCombinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.candidateCombinedSecondaryVertexSoftLeptonComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateCombinedSecondaryVertexSoftLeptonCtagLComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateBoostedDoubleSecondaryVertexAK8Computer_cfi import *
from RecoBTag.SecondaryVertex.candidateBoostedDoubleSecondaryVertexCA15Computer_cfi import *
from RecoBTag.SecondaryVertex.pfSecondaryVertexTagInfos_cfi import *
from RecoBTag.SecondaryVertex.pfSimpleSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfSimpleSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderTagInfos_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedInclusiveSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedSecondaryVertexSoftLeptonBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderCtagLTagInfos_cfi import *
from RecoBTag.SecondaryVertex.pfCombinedSecondaryVertexSoftLeptonCtagLJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderTagInfosAK8_cfi import *
from RecoBTag.SecondaryVertex.pfBoostedDoubleSecondaryVertexAK8BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderTagInfosCA15_cfi import *
from RecoBTag.SecondaryVertex.pfBoostedDoubleSecondaryVertexCA15BJetTags_cfi import *

# Negative taggers
from RecoBTag.SecondaryVertex.pfSecondaryVertexNegativeTagInfos_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderNegativeTagInfos_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeSimpleSecondaryVertexHighEffBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeSimpleSecondaryVertexHighPurBJetTags_cfi import *
from RecoBTag.SecondaryVertex.candidateNegativeCombinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateNegativeCombinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.candidateNegativeCombinedSecondaryVertexSoftLeptonComputer_cfi import *
from RecoBTag.SecondaryVertex.candidateNegativeCombinedSecondaryVertexSoftLeptonCtagLComputer_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedSecondaryVertexSoftLeptonCtagLJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedInclusiveSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfNegativeCombinedSecondaryVertexSoftLeptonBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfInclusiveSecondaryVertexFinderNegativeCtagLTagInfos_cfi import *

# Positive taggers
from RecoBTag.SecondaryVertex.candidatePositiveCombinedSecondaryVertexComputer_cfi import *
from RecoBTag.SecondaryVertex.candidatePositiveCombinedSecondaryVertexV2Computer_cfi import *
from RecoBTag.SecondaryVertex.candidatePositiveCombinedSecondaryVertexSoftLeptonComputer_cfi import *
from RecoBTag.SecondaryVertex.candidatePositiveCombinedSecondaryVertexSoftLeptonCtagLComputer_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedInclusiveSecondaryVertexBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedInclusiveSecondaryVertexV2BJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedSecondaryVertexSoftLeptonBJetTags_cfi import *
from RecoBTag.SecondaryVertex.pfPositiveCombinedSecondaryVertexSoftLeptonCtagLJetTags_cfi import *

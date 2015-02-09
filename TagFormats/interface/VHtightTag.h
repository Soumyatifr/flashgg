#ifndef FLASHgg_VHtightTag_h
#define FLASHgg_VHtightTag_h

#include "flashgg/TagFormats/interface/DiPhotonTagBase.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "flashgg/MicroAODFormats/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "flashgg/MicroAODFormats/interface/Electron.h"

namespace flashgg {

	class VHtightTag: public DiPhotonTagBase {
		public:
			VHtightTag();
                        VHtightTag(edm::Ptr<DiPhotonCandidate>,edm::Ptr<DiPhotonMVAResult>);
			VHtightTag(edm::Ptr<DiPhotonCandidate>,DiPhotonMVAResult);
			~VHtightTag();

                const edm::PtrVector<pat::Muon> getMuons() const { return Muons_;} 
		const edm::PtrVector<flashgg::Electron> getElectrons() const {return Electrons_;}
		const edm::PtrVector<Jet> getJets() const { return Jets_;}
		const edm::PtrVector<pat::MET> getMET() const { return MET_;} 

		void setJets(edm::PtrVector<Jet> Jets) { Jets_ = Jets; }
		void setMuons(edm::PtrVector<pat::Muon> Muons) {Muons_ = Muons;}
		void setMET(edm::PtrVector<pat::MET> MET) {MET_ = MET;}
	        void setElectrons(edm::PtrVector<Electron> Electrons) {Electrons_ = Electrons;}

		VHtightTag* clone() const;

                private:
                edm::PtrVector<pat::Muon> Muons_;  
 		edm::PtrVector<Electron> Electrons_;
		edm::PtrVector<Jet> Jets_;
		edm::PtrVector<pat::MET> MET_;
	};
} 

#endif 

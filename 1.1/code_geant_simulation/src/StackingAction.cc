
#include "StackingAction.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
//#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4VProcess.hh"

#include "G4ParticleTypes.hh"
#include "G4ios.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "G4PhysicalConstants.hh"
#include "RunAction.hh"

#include <G4Step.hh>
//#include <fstream>
#include <iostream>
#include "PhysicsList.hh"
#include "G4ThreeVector.hh"
//#include "G4SDManager.hh"
#include "globals.hh"

//#include "G4VVisManager.hh"
//#include "G4UnitsTable.hh"
#include <time.h>
#include "G4EventManager.hh"
//#include "G4Trajectory.hh"
//#include "G4VHitsCollection.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
//#include <G4ParticleGunMessenger.hh>
//#include <G4ParticleGun.hh>

#include "Analysis.hh"

//#include "G4EmCalculator.hh"
#include "constant.hh"
//#include "Randomize.hh"
//#include <iomanip>

using namespace std;

StackingAction::StackingAction(EventAction* EA)
:G4UserStackingAction(),  fEventAction(EA)
{
}

StackingAction::~StackingAction()
{
}

G4ClassificationOfNewTrack
StackingAction::ClassifyNewTrack(const G4Track* aTrack)
{
   
    
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
   
    
    G4ThreeVector direction = aTrack->GetMomentumDirection();
    G4ThreeVector position =  aTrack -> GetPosition();
    G4double energy = aTrack->GetKineticEnergy();
    

    G4int trackID  = aTrack->GetTrackID();
    G4int parentID = aTrack->GetParentID();
    G4String name = aTrack->GetDefinition()->GetParticleName();
    
   // cout << name << " trackID " << trackID << " parentID " <<  parentID<< G4endl;
     
    if (name == "gamma"){
        cout << name << "  energy/Mev " << energy/CLHEP::MeV << " position/m " << position/CLHEP::m << endl;
        out_gamma  << name << "  energy/Mev " << energy/CLHEP::MeV << " position/m " << position/CLHEP::m << " direction " << direction <<endl;
    }else if (name == "e-"){
        cout << name << "  energy/Mev " << energy/CLHEP::MeV<< " position " << position/CLHEP::m << endl;
        out_elect  << name << "  energy/Mev " << energy/CLHEP::MeV << " position/m " << position/CLHEP::m << " direction " << direction<< endl;
    }else if (name == "e+"){
        cout << name << "  energy/Mev " << energy/CLHEP::MeV << " position " << position/CLHEP::m << endl;
        out_pos  << name << "  energy/Mev " << energy/CLHEP::MeV << " position/m " << position/CLHEP::m << " direction " << direction << endl;
    }
    
   return fUrgent;
 
}

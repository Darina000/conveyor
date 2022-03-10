//
//  PrimaryGeneratorAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

#include <G4Event.hh>
#include "EventAction.hh"
#include <G4ParticleGun.hh>
#include <G4ParticleTable.hh>
#include <G4ParticleDefinition.hh>
#include <globals.hh>
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4RunManager.hh"
#include "G4IonTable.hh"
#include "G4ChargedGeantino.hh"
#include "Randomize.hh"


#include "ener.hh"

int Event_Number;

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction* det)
:G4VUserPrimaryGeneratorAction(),fParticleGun(0),fDetector(det)
{
    
    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);
    
    
    //Event_Number = anEvent->GetEventID();
    G4ParticleTable* particleTable1 = G4ParticleTable::GetParticleTable();
    
    G4ParticleDefinition* particle
             = G4ParticleTable::GetParticleTable()->FindParticle("e-");
    
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(ener);
    
    
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete  fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    G4double envSizeXY = 1*cm;
   // fParticleGun->GeneratePrimaryVertex(anEvent);
    G4double size = 0.8;
  //  G4double x0 = size * envSizeXY * (G4UniformRand()-0.5);
 //   G4double y0 = size * envSizeXY * (G4UniformRand()-0.5);
   // G4double envSizeXY = 0.3*km;
   // G4double size = 2;
  //  G4double x0 = size * envSizeXY * (G4UniformRand()-0.5);
   // G4double y0 = size * envSizeXY * (G4UniformRand()-0.5);

    fParticleGun->SetParticlePosition(G4ThreeVector(0.0*cm,0.0*cm, 0.0*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
       
    fParticleGun->GeneratePrimaryVertex(anEvent);

}

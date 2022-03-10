//
//  RunAction.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef ExN03RunAction_h
#define ExN03RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4VProcess.hh"
#include "globals.hh"
#include <map>

#include "Gamma_c.hh"


class G4Run;
class G4ParticleDefinition;
class G4Material;

class DetectorConstruction;
class PrimaryGeneratorAction;


class RunAction : public G4UserRunAction
{
  public:

    RunAction(DetectorConstruction*, PrimaryGeneratorAction*);
  ~RunAction();

  public:
    virtual void BeginOfRunAction(const G4Run*);
    virtual void  EndOfRunAction(const G4Run*);
    

    Gamma_c Peter;
    Gamma_c* Pt = &Peter;
  
    private:

        DetectorConstruction*   fDetector;
        PrimaryGeneratorAction* fPrimary;
    
      // G4long   fNbSteps;
       //G4double fTrackLength, fStepMin, fStepMax;
    
};

#endif



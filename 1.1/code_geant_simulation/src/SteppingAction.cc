//
//  SteppingAction.cpp
//  
//
//  Created by Дарья Землянская on 24.07.2020.
//

    #include "G4Step.hh"
    #include "G4ParticleTypes.hh"
    #include "G4RunManager.hh"
    #include "G4Run.hh"
    #include <G4ParticleGunMessenger.hh>
    #include <G4ParticleGun.hh>

    #include "SteppingAction.hh"
    #include "RunAction.hh"
    #include "EventAction.hh"


    #include "Analysis.hh"

   // #include "G4EmCalculator.hh"

   // #include "Randomize.hh"
    #include <iomanip>

    using namespace std;

    SteppingAction::SteppingAction(RunAction* RA, EventAction* EA)
    :G4UserSteppingAction(),fRunaction(RA), fEventaction(EA)
    { }

    SteppingAction::~SteppingAction()
    { }


    void SteppingAction::UserSteppingAction(const G4Step* step)
    {

        }

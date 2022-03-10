
#include "G4UserStackingAction.hh"
#include "globals.hh"

#include "G4UserEventAction.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include <vector>
#include <map>
#include <string>
#include <G4ParticleGunMessenger.hh>

class G4Track;
class G4VProcess;
class RunAction;
class G4ParticleDefinition;
class EventAction;


class StackingAction : public G4UserStackingAction
{
  public:
    StackingAction(EventAction*);
   ~StackingAction();
    
   virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);

  private:
   EventAction*        fEventAction;
    G4bool              fTrackSecondaries;
 //   G4bool              fKillSecondary;
    const G4ParticleDefinition* fParticle;
    RunAction*    fRunAction;
    PrimaryGeneratorAction* primary;
    
    
    
 //   G4double      fEdepPrimary, fEdepSecondary;
};


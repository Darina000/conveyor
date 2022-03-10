
#include "G4UserSteppingAction.hh"
#include "globals.hh"

class DetectorConstruction;
class EventAction;
class RunAction;


class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(RunAction*, EventAction* );
  ~SteppingAction();

   virtual void UserSteppingAction(const G4Step*);
    
private:
    RunAction*            fRunaction;
    EventAction*          fEventaction;
    G4LogicalVolume* fScoringVolume;
   // int ener = 0;
};


#include "G4UserEventAction.hh"
#include "globals.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include <vector>
#include <map>


class G4VProcess;
class RunAction;
class EventAction : public G4UserEventAction
{
public:
  EventAction(RunAction*, PrimaryGeneratorAction*);
  ~EventAction();

public:
  virtual void  BeginOfEventAction(const G4Event*);
  virtual void    EndOfEventAction(const G4Event*);
    
    RunAction* fRunAct(){return fRunAction;};
    
private:
    PrimaryGeneratorAction* primary;
    G4double      fEdepPrimary, fEdepSecondary;
    RunAction* fRunAction;

};


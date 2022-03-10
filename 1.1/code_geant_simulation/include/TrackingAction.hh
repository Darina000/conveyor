
#ifndef TrackingAction_h
#define TrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "globals.hh"

class RunAction;

class TrackingAction : public G4UserTrackingAction {

  public:
    TrackingAction(RunAction*);
   ~TrackingAction() {};

    virtual void  PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);

  private:
    RunAction* fRunAction;

};

#endif

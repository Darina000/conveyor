
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "Randomize.hh"
#include "PhysicsList.hh"
#include "globals.hh"
#include "G4ProcessManager.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

#include "EventAction.hh"
#include "SteppingAction.hh"
#include "StackingAction.hh"
#include "TrackingAction.hh"

#include "G4Types.hh"
//#include "G4EmPenelopePhysics.hh";


#include<G4UIterminal.hh>
#include<G4VisExecutive.hh>
#include<G4UserRunAction.hh>
#include<G4Run.hh>
#include<iostream>
#include<string>
#include<CLHEP/Random/Random.h>
#include<unistd.h>
#include<time.h>
#include "QGSP_BERT.hh"
#include "PhysicsList.hh"
//#include "G4EmStandardPhysics_option4.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "QBBC.hh"
#include "G4UImanager.hh"
//#include "FTFP_BERT_HP.hh"
//#include "FTFP_BERT.hh"


//#include “G4EmStandardPhysics.hh”;
//#include "G4EmStandartPhysics_option4"
//#include "QGSP_FTFP_BERT.hh"
#include "G4UIExecutive.hh"

//#include "G4PenelopeComptonModel.hh";
//#include "G4ComptonScattering.hh";
#include "G4OpticalPhysics.hh";
//#include "G4PenelopeIonisationModel.hh";
//#include "G4eIonisation.hh";
using namespace std;
ofstream outfile;

const char macros[]="vis.mac";

int main(int argc,char** argv)
{
    
    
    
    
    
    G4UIExecutive* ui = 0;
     if ( argc == 1 ) {
       ui = new G4UIExecutive(argc, argv);
     }
    
    #ifdef G4MULTITHREADED
      G4MTRunManager* runManager = new G4MTRunManager;
    #else
      G4RunManager* runManager = new G4RunManager;
    #endif
    
    
    

outfile.open("outfile.dat");

CLHEP::HepRandom::setTheSeed(time(0)+getpid());
    
    
     G4VModularPhysicsList* physicsList = new PhysicsList;
    
    /*
    
     physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
    
     G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
     opticalPhysics->SetWLSTimeProfile("delta");

     opticalPhysics->SetScintillationYieldFactor(1.0);
     opticalPhysics->SetScintillationExcitationRatio(0.0);

     opticalPhysics->SetMaxNumPhotonsPerStep(100);
     opticalPhysics->SetMaxBetaChangePerStep(10.0);

     opticalPhysics->SetTrackSecondariesFirst(kCerenkov, true);
     opticalPhysics->SetTrackSecondariesFirst(kScintillation, true);

     physicsList->RegisterPhysics(opticalPhysics);
    */
     runManager->SetUserInitialization(physicsList);

    /*
    G4VUserPhysicsList* physicsList = new PhysicsList;
   // physicsList->SetVerboseLevel(1);
    G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
    opticalPhysics->SetWLSTimeProfile("delta");
    opticalPhysics->SetScintillationYieldFactor(1.0);
    opticalPhysics->SetScintillationExcitationRatio(0.0);
    opticalPhysics->SetMaxNumPhotonsPerStep(100);
    opticalPhysics->SetMaxBetaChangePerStep(10.0);
    opticalPhysics->SetTrackSecondariesFirst(kCerenkov, true);
    opticalPhysics->SetTrackSecondariesFirst(kScintillation, true);
    physicsList->RegisterPhysics(opticalPhysics);
    
    runManager->SetUserInitialization(physicsList);
*/
    // set mandatory initialization classes
    DetectorConstruction* detector;
    detector = new DetectorConstruction;
    runManager->SetUserInitialization(detector);

    // set user action classes
    //
    //primaryGenerator
    PrimaryGeneratorAction* primary = new PrimaryGeneratorAction(detector);
    runManager->SetUserAction(primary);

    //runAction
    RunAction* runaction = new RunAction(detector,primary);
    runManager->SetUserAction(runaction);

    //eventAction
    EventAction* eventaction = new EventAction(runaction, primary);
    runManager->SetUserAction(eventaction);

    //TrackingAction
    TrackingAction* trackingaction = new TrackingAction(runaction);
    runManager->SetUserAction(trackingaction);

    //stepAction
    SteppingAction* steppingaction = new SteppingAction(runaction, eventaction);
    runManager->SetUserAction(steppingaction);

    //stackAction
    StackingAction* stackingaction = new StackingAction(eventaction);
    runManager->SetUserAction(stackingaction);

  
G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();
    
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // Process macro or start UI session
    //
    /*
    if ( ! ui ) {
      // batch mode
      G4String command = "/control/execute  run1.mac";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }
    else {
     */
      // interactive mode
       UImanager->ApplyCommand("/control/execute init_vis.mac");
        
      //ui->SessionStart();
      delete ui;
   // }

    // Job termination
    // Free the store: user actions, physics_list and detector_description are
    // owned and deleted by the run manager, so they should not be deleted
    // in the main() program !
    
    delete visManager;
    delete runManager;
  }

//  DetectorConstruction.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4EqMagElectricField.hh"
#include "G4UniformElectricField.hh"
#include <G4MagIntegratorStepper.hh>
#include <G4FieldManager.hh>
#include <G4ChordFinder.hh>
#include <G4MagIntegratorDriver.hh>
#include <G4VSolid.hh>
#include <G4LogicalVolume.hh>
#include <G4VPhysicalVolume.hh>
#include <G4Material.hh>


class G4VPhysicalVolume;
class G4LogicalVolume;






class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
    
    
    G4ElectricField*        fEMfield;
    G4EqMagElectricField*   fEquation;
    G4MagIntegratorStepper* fStepper;
    G4FieldManager*         fFieldMgr;
    G4double                fMinStep ;
    G4ChordFinder*          fChordFinder ;
    G4MagInt_Driver*        fIntgrDriver;

  protected:
    G4LogicalVolume*  fScoringVolume;
};






 
#endif

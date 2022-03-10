



#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include <G4UniformMagField.hh>
#include <G4ClassicalRK4.hh>
#include <G4TransportationManager.hh>
#include <G4EqMagElectricField.hh>
#include "G4EquationOfMotion.hh"

#include "G4ChargeState.hh"
#include "G4EquationOfMotion.hh"
#include "G4ElectroMagneticField.hh"

#include "globals.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4EqEMFieldWithSpin.hh"
#include "G4PropagatorInField.hh"

#include "field.hh"

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

DetectorConstruction::~DetectorConstruction()
{ }

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
    
    G4String name, symbol;
    G4double density, fractionmass;
    G4int nel, ncomponents;
    
    G4NistManager* nist = G4NistManager::Instance();
    G4int nvar = 8;
    fMinStep = 0.01*mm ;
    G4bool isotopes = true;
    
    G4bool checkOverlaps = true;
    auto nistManager = G4NistManager::Instance();
      
    density = dencity_air;
    auto AirDensity = nistManager ->BuildMaterialWithNewDensity("AirDensity", "G4_AIR", density);

  // World
  
  G4double world_sizeXY = half_volume; //половина
  G4double world_sizeZ  = half_volume;

    G4Box* solidWorld =
    new G4Box("World",
              2.0*world_sizeXY, 2.0*world_sizeXY, 2.0*world_sizeZ);
      
  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,
                        AirDensity,
                        "World");
                                   
  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,
                      G4ThreeVector(0, 0, 0),
                      logicWorld,
                      "World",
                      0,
                      false,
                      0,
                      checkOverlaps);

    
    
    //first part
    
        G4Box* solidShape2_1 =
          new G4Box("Shape2_1",                      //its name
                    half_volume, half_volume, half_volume); //its size
                      
        G4LogicalVolume* logicShape2_1 =
          new G4LogicalVolume(solidShape2_1,         //its solid
                              AirDensity,          //its material
                              "Shape2_1");           //its name
                     
        new G4PVPlacement(0,                       //no rotation
                          G4ThreeVector(0*cm, 0, half_volume*m),                    //at position
                          logicShape2_1,             //its logical volume
                          "Shape2_1",                //its name
                          logicWorld,                //its mother  volume
                          false,                   //no boolean operation
                          0,                       //copy number
                          checkOverlaps);          //overlaps
      
    

    G4ElectricField* magField_5 = new G4UniformElectricField( G4ThreeVector(0.0,0.0, field_value));
    G4EqMagElectricField* fEquation1_5 = new G4EqMagElectricField(magField_5);
    G4MagIntegratorStepper* fStepper1_5 = new G4ClassicalRK4( fEquation1_5, nvar );
    G4FieldManager* localFieldMgr1_5
            = new G4FieldManager(magField_5);
    logicShape2_1->SetFieldManager(localFieldMgr1_5, true);
    G4MagInt_Driver* fIntgrDriver1_5 = new G4MagInt_Driver(fMinStep,
                                     fStepper1_5,
                                     fStepper1_5->GetNumberOfVariables() );
    G4ChordFinder* fChordFinder1_5 = new G4ChordFinder(fIntgrDriver1_5);
       localFieldMgr1_5->SetChordFinder( fChordFinder1_5 );
    
    
    
  fScoringVolume = logicWorld;

  return physWorld;
}


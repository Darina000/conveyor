
#include <vector>

#include "globals.hh"
#include "G4SystemOfUnits.hh"

class Electron_o{
public:
    ~Electron_o(){}
    Electron_o(const G4ThreeVector& dir, const G4ThreeVector& pos, const G4double& ener): direction(dir), position(pos), energy(ener)
    {}
    
    
    void Write_in_mac(){
        
        std::ofstream outf("/Users/darazemlanskaa/Documents/Geant4_pr/snow/reactor_simple/run1.mac", std::ios::app);
        outf << "/gun/particle e-"  << std::endl;
        outf << "/gun/energy " << energy << " keV"<< std::endl;
        outf << "/gun/position " << position.x() << " "<<  position.y() <<  " " << position.z() << " mm"  <<std::endl;
        outf << "/gun/direction " << direction.x() << " "<<  direction.y() <<  " " << direction.z()  <<std::endl;
        outf << "/run/beamOn 1"<< std::endl;
        
    }
    
    
private:
    
    G4ThreeVector direction;
    G4ThreeVector position;
    G4double energy;
};




class Gamma_c{
public:
    Gamma_c():gamma_trackID{}, parametrs{}{
    }

~Gamma_c(){
}

//Gamma_c(const std::vector<G4int>& n, const std::vector <Electron_o>& s): gamma_trackID(n), parametrs(s)
//{}
    
    
    //сохраняем номер гаммы для проверки
    
    void save_gamma(const G4int& a){
       // gamma_trackID.push_back(a);
        
       // std::ofstream pok("gamma_character.txt", std::ios::app);
       // pok << "energy "  << energy << " x " << << <<  endl;
    }
    
    void save_elect_param(const Electron_o& a){
      //  parametrs.push_back(a);
    }
    
    std::vector<G4int>& return_tarck_gamma(){
        return gamma_trackID;
    }
    
    void out_number_electron(){
        /*
        std::ofstream pok("pokolenia.txt", std::ios::app);
        pok << parametrs.size()  << ", ";
        
        std::cout << "Count electron in pokolen " <<  parametrs.size()<< std::endl;
         */
    }
    
    void clear_gamma_trackID(){
        gamma_trackID.clear();
    }
    
    void print_in_mac(){
        //clear run1 for next generation
        /*
        std::ofstream ofs ("/Users/darazemlanskaa/Documents/Geant4_pr/snow/reactor_simple/run1.mac", std::ios::out | std::ios::trunc); // clear contents
        ofs.close ();
        
        for (auto i: parametrs){
            i.Write_in_mac();
        }
         */
    }
    
    
    
private:


std::vector<G4int> gamma_trackID; // save GammaID
std::vector <Electron_o> parametrs; // save parametr e-

};

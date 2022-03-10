import numpy as np
import matplotlib.pyplot as plt


def make_hist(array, name):
    plt.hist(array, 20)
    plt.yscale('log')
    plt.xlabel("energy")
    plt.ylabel("N, 20 bins, log")
    plt.savefig('energy_' + name + '.png')
    plt.gcf().clear()
    
    

def main(adress, name):
    f = open(adress, 'r')
    lines = f.readlines()
    energy = []
    for line in lines:
        lst = line.split()
        print(lst ) # all data
        print(lst[2]) #print energy (MeV)
        energy.append(float(lst[2])) # add energy to array
    make_hist(energy, name)
        
        
        
        
        
if __name__ == "__main__":
    r = '.csv'
    name = 'doc_elect_5-170volume250_denc06_cut50'
    adress = name + r
    main(adress, name)

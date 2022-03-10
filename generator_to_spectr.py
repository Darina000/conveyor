import xml.etree.ElementTree as ET
from string import Template
import os
import shutil
import subprocess
from multiprocessing import Pool

energy_MeV = '5'
field_value = [ '-140', '-150', '-160', '-170', '-180', '-190', '-200', '-210', '-220','-230', '-240', '-250' ] 
half_volume = '500'
#dencity_air = ['0.2', '0.3' ,'0.4', '0.5', '0.6', '0.7', '0.8', '0.9']
dencity_air = [ '0.3' ,'0.4', '0.5', '0.6', '0.7']




    

if __name__ == "__main__":
    r = '.csv'
    for dencity_i in dencity_air:
        for field_i in field_value:
            name = 'stan_doc_elect_' + energy_MeV + field_i+ 'volume' + half_volume + '_denc' + dencity_i + '_cut40' #name of the file to process
            adress = name + r
            f = open(adress, 'r')
            name_write = 'half_v'+ half_volume + 'field' + field_i+ '_denc' + dencity_i + r
            f_write = open(name_write, 'w')
            lines = f.readlines()
            for line in lines:
                lst = line.split()
                print(lst[2]) #print energy (MeV)
                f_write.write(lst[2] + '\n') # add energy to array

                

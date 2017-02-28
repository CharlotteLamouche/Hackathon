
import sys
import time

import pigpio

import vw


def transmit(transfer):
    TX=25
        
    BPS=2000
            
    pi = pigpio.pi()
                
    tx = vw.tx(pi, TX, BPS)
                    
    start = time.time()
                        
    print transfer
                            
    while not tx.ready():
        time.sleep(0.1)
        tx.put(transfer)
        time.sleep(0.2)
        tx.put(transfer)
        tx.cancel()
        pi.stop()
 

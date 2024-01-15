#!/usr/bin/env python3

import time
import logging
import sys
import os
from RPC.src.RPC_server_manager import RPCServerManager

# code for solving issues with linking modules
parent_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(parent_dir)


from database.sqllite_manager import DB_manager

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("temp_monitor")
buffer = []
dbpath = "/home/luky/Desktop/Projects/system_manager/system_manager/database/"
dbname = "temperatures"
database_manager = DB_manager(dbpath,dbname)
database_manager.create_table('''CREATE TABLE IF NOT EXISTS temperatures (
                     timestamp TEXT,
                     temperature REAL
                 )''')


def read_cpu_temperature()-> float:
    with open("/sys/class/thermal/thermal_zone0/temp",'r') as file:
        temp = file.read().strip()
        temp = float(temp) / 1000
        logger.info(f"Actual temperature of processor is: {temp:.2f} °C")
        return temp


def fill_buffer(timestamp,temp):
    buffer.append((timestamp,temp))
    if len(buffer) == 10:
        store_data()
   
    
def store_data():
        database_manager.insert_data("INSERT INTO temperatures (timestamp, temperature) VALUES (?, ?)",buffer)
        buffer.clear()
    
    
def main():
    server = RPCServerManager()
    server.start_server()
    while True:
        try:
            timestamp = time.time()
            temp = read_cpu_temperature()
            fill_buffer(timestamp,temp)
            server.add_data(temperature=temp,timestamp=timestamp)
        except Exception as e:
            logger.error(str(e))
        time.sleep(1)


if __name__ == "__main__":
    main()
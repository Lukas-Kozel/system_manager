import sqlite3

class DB_manager:
    
    def __init__(self,dbpath,dbname):
        self.connection = sqlite3.connect(dbpath+f"{dbname}.db")
        self.cursor = self.connection.cursor()
      
    def __enter__(self):
        return self
    
    def __exit__(self,exec_type, exec_val, exec_tb):
        self.cursor.close()
        self.connection.close()

    def create_table(self,sql_command):
        self.cursor.execute(sql_command)
        self.connection.commit()
         
    def insert_data(self,sql_command, parameters):
        self.cursor.executemany(sql_command, parameters)
        self.connection.commit()
    
    def get_all_data_from_table(self,table)->list:
        self.cursor.execute(f"SELECT * FROM {table}")
        return self.cursor.fetchall()
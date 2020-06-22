import mysql.connector
mydb = mysql.connector.connect(host="localhost",user="root",passwd="")

print(mydb)
if(mydb):
    print("Connection successful")
else:
    print("Connection not successful")

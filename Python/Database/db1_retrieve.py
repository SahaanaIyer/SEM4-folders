import mysql.connector
mydb = mysql.connector.connect(host="localhost",user="root",passwd="",database="sahaana")

mycursor = mydb.cursor()
mycursor.execute("SELECT * FROM person")

result =mycursor.fetchall();

for row in result:
    print(row)

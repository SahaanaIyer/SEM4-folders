import mysql.connector
mydb = mysql.connector.connect(host="localhost",user="root",passwd="",database="sahaana")

mycursor = mydb.cursor()

query="Update person set age=150 where firstName='sahaana'"

mycursor.execute(query)
mydb.commit()
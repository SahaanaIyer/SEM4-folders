import mysql.connector
mydb = mysql.connector.connect(host="localhost",user="root",passwd="",database="sahaana")

mycursor = mydb.cursor()

query="Delete from person where firstName='sahaana'"

mycursor.execute(query)
mydb.commit()
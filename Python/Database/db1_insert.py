import mysql.connector
mydb = mysql.connector.connect(host="localhost",user="root",passwd="",database="sahaana")

mycursor = mydb.cursor()
sqlform = "Insert into person(firstName,lastName,age,address) values(%s,%s,%s,%s)"

persons =[("sahaana","iyer",19, "matunga")]

mycursor.executemany(sqlform,persons)
mydb.commit()
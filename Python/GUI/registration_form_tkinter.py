import tkinter as tk
from tkinter import ttk
from tkinter import *

window = Tk()
window.title("REGISTERATION FORM")
window.geometry('350x320')       #widthxheight
window.configure(background = "#dce6f5")

l1 = Label(window ,width=15,bg='#ffffff', text = "First Name")
l1.grid(row = 0,column = 0, padx=10, pady=10)
txt1 = Entry(window,width=20)
txt1.grid(column=2, row=0, padx=10, pady=10)
l2 = Label(window ,width=15,bg='#ffffff',text = "Last Name")
l2.grid(row = 5,column = 0, padx=10, pady=10)
txt2 = Entry(window,width=20)
txt2.grid(column=2, row=5, padx=10, pady=10)
l3 = Label(window ,width=15,bg='#ffffff',text = "Email Id")
l3.grid(row = 10,column = 0, padx=10, pady=10)
txt3 = Entry(window,width=20)
txt3.grid(column=2, row=10, padx=10, pady=10)
l4 = Label(window ,width=13,bg='#ffffff',text ="Age")
l4.grid(row = 15,column = 0, padx=10, pady=10)
txt4 = Entry(window,width=20)
txt4.grid(column=2, row=15, padx=10, pady=10)
l5 = Label(window ,width=14,bg='#ffffff',text = "Gender")
l5.grid(row = 20,column = 0, padx=10, pady=10)
var1 = IntVar() 
Checkbutton (window,bg='#ffffff', text='Male', variable=var1).grid(column=2,row=20, sticky=W)
var2 = IntVar() 
Checkbutton(window,bg='#ffffff', text='Female', variable=var2).grid(column=2,row=22, sticky=W)
l7= Label(window ,width=10,bg='#ffffff',text = "Blood Group")
l7.grid(row =25,column = 0, padx=10, pady=10)

n = tk.StringVar() 
bg = ttk.Combobox(window, width = 20,textvariable = n) 
# Adding combo- box drop down list 
bg['values'] = ('A+',
                'A-',
                'B+',
                'B-',
                'O+',
                'O-',
                'AB+',
                'AB-')
bg.grid(column =2, row = 25)  
bg.current(0) 
btn = Button(window, text='Submit', bd = '5',command = window.destroy) 
btn.grid(row=32, column=2)
window.mainloop()


# Import libraries
from tkinter import *
import time
import random
import sys, os

# Set initial variables
win_height = 900
win_width = 1200
pile_a = []
pile_b = []
mod = 2
speed = 0
start = 0

def create_piles(nb_datas):
    
    while nb_datas >= 0 : 
        pile_a.append(w.create_rectangle(0, 0, 0, 0, fill="blue", outline="blue"))
        pile_b.append(w.create_rectangle(0, 0, 0, 0, fill="red", outline="red"))
        nb_datas -= 1

def update_pile_a(pile, data_height, data_width_ratio, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 150
    # The while loop is used to undisplayed some datas
    while (size_pile < size) :
        y1 = y0 + data_height
        w.coords(pile_a[obj - 1], 0, 0, 0, 0)
        obj += 1
        y0 = y1
        size_pile += 1
    for data in pile :
        if data > 0 :
            w.itemconfig(pile_a[obj-1], fill="#EBE100", outline="#EBE100")
        if data < 0 :
            w.itemconfig(pile_a[obj-1], fill="#A09900", outline="#A09900")
            data = -data
        y1 = y0 + data_height
        x0 = 50
        x1 = x0 + data * data_width_ratio
        w.coords(pile_a[obj - 1], x0, y0, x1, y1)
        y0 = y1
        obj += 1

def update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size) :    

    obj = 1
    size_pile = len(pile)
    y0 = 150
    while (size_pile < size) :
        y1 = y0 + data_height
        w.coords(pile_b[obj - 1], 0, 0, 0, 0)
        obj += 1
        y0 = y1
        size_pile += 1
    for data in pile :
        if data > 0 :
            w.itemconfig(pile_b[obj-1], fill="#EB0000", outline="#EB0000")
        if data < 0 :
            w.itemconfig(pile_b[obj-1], fill="#A60000", outline="#A60000")
            data = -data
        y1 = y0 + data_height
        x0 = max_x1_a + 150
        x1 = x0 + data * data_width_ratio
        w.coords(pile_b[obj - 1], x0, y0, x1, y1)
        y0 = y1
        obj += 1

def Speed_up() :
    
    global speed
    global mod
    speed += 2
    mod = speed
    if mod <= 0 :
        mod = 2
    print("speed =", speed)

def Slow_down() :
    
    global speed
    global mod
    speed -= 2
    mod = speed
    if mod <= 0 :
        mod = 2
    print("speed = ", speed)

def Start() :
    
    global start
    if start == 0 :
        start = 1
        Pause.set("Stop")
    elif start == 1 :
        start = 0
        Pause.set("Start")
    elif start == 2 :
        start = 0
        Pause.set("Start")
        display(lines)

def update_piles(pile, i) :
    
    # Mod is always pair. Can be greater than 2 to skip some actions and have a faster display
    if i % mod == 1 :
        update_pile_a(pile, data_height, data_width_ratio, size)
    elif i % mod == 0 :
        update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
        w.update()
    if speed < 0 :
        time.sleep((-speed)/50)

def display(lines) :
    
    i = 1
    global start
    
    for line in lines :
        pile = list(map(int,line.split())) 
        # While loop for the "Stop" function
        while start == 0 :
            if i == 1 :
                update_pile_a(pile, data_height, data_width_ratio, size)
            w.update()
        update_piles(pile, i)
        i += 1
    
    # Print last state of the piles when mod > 2
    pile = list(map(int,lines[i - 3].split())) 
    update_pile_a(pile, data_height, data_width_ratio, size)
    pile = list(map(int,lines[i - 2].split())) 
    update_pile_b(pile, data_height, data_width_ratio, max_x1_a, size)
    # Pile is sorted : get ready for the reset
    start = 2
    Pause.set("Reset")

def Set_variables(lines):
    global size
    global data_height
    global data_width_ratio
    global max_x1_a
    global max
    global min

    initial_pile = list(map(int,lines[0].split())) 
    max = max(initial_pile)
    min = min(initial_pile)
    if -min > max :
        max = -min
    size = len(initial_pile)
    data_height = (win_height - 200) / size
    data_width_ratio = (win_width - 200) / max / 2
    max_x1_a = data_width_ratio * max

def Set_buttons() :
    
    # Set the "Start/Stop/Reset button"
    global Pause
    Pause = StringVar()
    Pause.set("Start")
    go = Button(master, width=20, textvariable = Pause, highlightbackground="black", command = Start) #command = start
    go.place(x=500, y=25)

    # Set the "Speed up" and "Slow down" buttons
    slow_down_button = Button(master, width=10, text = "Speed Up", highlightbackground="black", command = Speed_up)
    slow_down_button.place(x=485, y=50)
    speed_up_button = Button(master, width=10, text = "Slow Down", highlightbackground="black", command = Slow_down)
    speed_up_button.place(x=605, y=50)
    

def Set_nb_datas() :
    global max
    global lines
    nb_datas = int(entry_datas.get())
    range_max = int(entry_max.get())
    range_min = int(entry_min.get())
    pile = str(random.sample(range(range_min, range_max), nb_datas))
    pile = (pile.replace(",", "")
            .replace("[", "")
            .replace("]", ""))
    cmd = './push_swap %s | ./checker %s' % (pile, pile)
    label_datas.destroy()
    entry_datas.destroy()
    label_max.destroy()
    entry_max.destroy()
    label_min.destroy()
    entry_min.destroy()
    label_19.destroy()
    label_best.destroy()
    label_descri.destroy()
    ok_button.destroy()
    os.system(cmd)
    
    lines = [line.rstrip('\n') for line in open('piles')]
    Set_variables(lines)
    Set_buttons()
    
    create_piles(nb_datas)
    display(lines)
    print(nb_datas)

# Set the window
master = Tk()
title = "VISU PUSH_SWAP     \u00A9jfinet"
master.title(title)
w = Canvas(master, height=win_height, width=win_width, bg='black')
w.pack()
# Nb datas
label_datas = Label(master, bg="black", fg="white", text="Number of datas")
label_datas.place(relx=0.5, rely=0.5, anchor=CENTER)
entry_datas = Entry(master)
entry_datas.place(relx= 0.5, rely= 0.53, anchor=CENTER)
# Max
label_max = Label(master, bg="black", fg="white", text="Max")
label_max.place(relx=0.55, rely=0.57, anchor=CENTER)
entry_max = Entry(master, width=10)
entry_max.place(relx= 0.55, rely= 0.60, anchor=CENTER)
# Min
entry_min = Entry(master, width=10)
entry_min.place(relx= 0.45, rely= 0.60, anchor=CENTER)
label_min = Label(master, bg="black", fg="white", text="Min")
label_min.place(relx=0.45, rely=0.57, anchor=CENTER)
# Text
label_19 = Label(master, bg="black", fg="white", text="- 19 -", font="Verdana 80 bold")
label_19.place(relx=0.5, rely=0.1, anchor=CENTER)
label_best = Label(master, bg="black", fg="white", text="The Best Coding School", font="Verdana 30 bold")
label_best.place(relx=0.5, rely=0.2, anchor=CENTER)
label_descri = Label(master, bg="black", fg="white", text="The program will generate a random unsorted pile\n with the number of datas you entered (< 1000),\n within the range you decided (> number datas),\n and will sort it.", font="Verdana 14")
label_descri.place(relx=0.5, rely=0.35, anchor=CENTER)
# Ok button
ok_button = Button(master,text="Ok", width=5, highlightbackground="black", command=Set_nb_datas)
ok_button.place(relx=0.5, rely=0.65, anchor=CENTER)


master.mainloop()

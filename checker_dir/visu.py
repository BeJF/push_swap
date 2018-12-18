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

#pile = str(random.sample(range(1, 10), 5))
#pile = (pile.replace(",", "")
 #           .replace("[", "")
  #          .replace("]", ""))
#print(pile)

# Get initial data
# We read the file line by line and store them inside a list.
# We take the first line (the initial pile), to know the number of datas we will have to sort

#cmd = './push_swap %s | ./checker %s' % (pile, pile)
#os.system(cmd)

#lines = [line.rstrip('\n') for line in open('piles')]
#initial_pile = list(map(int,lines[0].split())) 
#size = len(initial_pile)

# Set other variable for the size of the datas
#max = max(initial_pile)
#data_height = (win_height - 200) / size
#data_width_ratio = (win_width - 200) / max / 2
#max_x1_a = data_width_ratio * max


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

    initial_pile = list(map(int,lines[0].split())) 
    max = max(initial_pile)
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
    nb_datas = int(E1.get())
    range_data = int(E2.get())
    pile = str(random.sample(range(1, 1000), nb_datas))
    pile = (pile.replace(",", "")
            .replace("[", "")
            .replace("]", ""))
    cmd = './push_swap %s | ./checker %s' % (pile, pile)
    L1.destroy()
    E1.destroy()
    L2.destroy()
    E2.destroy()
    L3.destroy()
    L4.destroy()
    L5.destroy()
    ok_button.destroy()
    os.system(cmd)
    
    lines = [line.rstrip('\n') for line in open('piles')]
    Set_variables(lines)
    Set_buttons()
    '''initial_pile = list(map(int,lines[0].split())) 
    max = max(initial_pile)
    size = len(initial_pile)
    data_height = (win_height - 200) / size
    data_width_ratio = (win_width - 200) / max / 2
    max_x1_a = data_width_ratio * max'''
    
    create_piles(nb_datas)
    #create_piles(size)
    display(lines)
    print(nb_datas)

# Set the window
master = Tk()
title = "VISU PUSH_SWAP     \u00A9jfinet"
master.title(title)
w = Canvas(master, height=win_height, width=win_width, bg='black')
w.pack()

L1 = Label(master, bg="black", fg="white", text="Number of datas")
L1.place(relx=0.5, rely=0.5, anchor=CENTER)

E1 = Entry(master)
E1.place(relx= 0.5, rely= 0.53, anchor=CENTER)

L2 = Label(master, bg="black", fg="white", text="Range")
L2.place(relx=0.5, rely=0.57, anchor=CENTER)

E2 = Entry(master)
E2.place(relx= 0.5, rely= 0.60, anchor=CENTER)

L3 = Label(master, bg="black", fg="white", text="- 19 -", font="Verdana 80 bold")
L3.place(relx=0.5, rely=0.1, anchor=CENTER)
L4 = Label(master, bg="black", fg="white", text="The Best Coding School - Asgard", font="Verdana 30 bold")
L4.place(relx=0.5, rely=0.2, anchor=CENTER)
L5 = Label(master, bg="black", fg="white", text="The program will generate a random unsorted pile\n with the number of datas you entered (< 1000),\n within the range you decided (< number datas),\n and will sort it.", font="Verdana 14")
L5.place(relx=0.5, rely=0.35, anchor=CENTER)

ok_button = Button(master,text="Ok", width=5, highlightbackground="black", command=Set_nb_datas)
ok_button.place(relx=0.5, rely=0.65, anchor=CENTER)


'''# Set the "Start/Stop/Reset button"
Pause = StringVar()
Pause.set("Start")
go = Button(master, width=20, textvariable = Pause, highlightbackground="black", command = Start) #command = start
go.place(x=500, y=25)

# Set the "Speed up" and "Slow down" buttons
slow_down_button = Button(master, width=10, text = "Speed Up", highlightbackground="black", command = Speed_up)
slow_down_button.place(x=485, y=50)
speed_up_button = Button(master, width=10, text = "Slow Down", highlightbackground="black", command = Slow_down)
speed_up_button.place(x=605, y=50)'''

# Launch the fcking algo to display the piles being sorted
#create_piles(size)
#display()

master.mainloop()

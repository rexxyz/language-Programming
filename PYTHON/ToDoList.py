#Importing tkinter library
from  tkinter import * 
import tkinter.messagebox

#Add a task to the list
def add():
    
    #New window to add task
    input_text=""
    def add():
        input_text=entry_task.get(1.0, "end-1c")
        if input_text=="":
            tkinter.messagebox.showwarning(title="Error!",message="Add an input") #User did not add anything
        else:
            listbox_task.insert(END,input_text) #User add something
            rootadd.destroy() #Close window after the user pressed add task button
            
    #Defining the add task window with some styling    
    rootadd=Tk()
    rootadd.geometry("360x320")
    rootadd.config(bg="gray39")
    rootadd.title("Add task")
    entry_task=Text(rootadd,width=30,height=3, font=('Arial', 14))
    entry_task.pack()
    button_temp=Button(rootadd,text="Add task",command=add)
    button_temp.pack()
    rootadd.mainloop()   

#Delete Task to list
def delete():
    
    selected =listbox_task.curselection() #Select task to delete
    listbox_task.delete(selected[0]) #Deletes selected task

#Task is completed
def completed():
    complete=listbox_task.curselection()
    temp=complete[0]
    temp_marked=listbox_task.get(complete) 
    temp_marked=temp_marked+" ✔" #When task is marked as complete, add a tick
    #delete it then insert it 
    listbox_task.delete(temp)
    listbox_task.insert(temp,temp_marked)
    

#Initial Wind0w with styling
window=Tk()
window.geometry("480x440")
window.config(bg="dark gray")
window.title("To-Do List")
#Frame widget to hold the listbox and the scrollbar
frame_task=Frame(window)
frame_task.pack()

#to hold items in a listbox
listbox_task=Listbox(frame_task,bg="gray30",fg="white",height=12,width=30,font = "Courier")  
listbox_task.pack(side=tkinter.LEFT)

#Scrolldown in case the total list exceeds the size of the given window 
scrollbar_task=Scrollbar(frame_task)
scrollbar_task.pack(side=tkinter.RIGHT,fill=tkinter.Y)
listbox_task.config(yscrollcommand=scrollbar_task.set)
scrollbar_task.config(command=listbox_task.yview)
#Button sytling in initial window

add_button=Button(window,text="Add task",width=30,command=add)
add_button.pack(pady=3)

delete_button=Button(window,text="Delete selected task",width=30,command=delete)
delete_button.pack(pady=3)

completed_button=Button(window,text="Mark as completed ",width=30,command=completed)
completed_button.pack(pady=3)

window.mainloop()
from pytube import YouTube
import tkinter
from tkinter import filedialog
import os

root = tkinter.Tk()
root.withdraw()


def search_for_file_path():
    currdir = os.getcwd()
    tempdir = filedialog.askdirectory(
        parent=root, initialdir=currdir, title='Please select a directory to save the video to ')
    if len(tempdir) > 0:
        print("The video destination file is: %s" % tempdir)
    return tempdir


file_path_variable = search_for_file_path()

# Save location
SAVE_PATH = file_path_variable

path = input("Paste YouTube video link here: ")

try:
    yt = YouTube(path)
except:
    print("Download Error")  # to handle exception

# User input to name the saved video
yt.title = input("Save Video as: ")

stream = yt.streams.get_highest_resolution()
stream.download(SAVE_PATH)
print('------------------')
print('The Video "' + yt.title + '" was succesfully downloaded to: ' + SAVE_PATH)

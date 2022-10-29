# PROBLEM STATEMENT:
# A Formula 1 racing took place. You are supposed to help in publishing the race results of the cars in the
# race. The annoucer can give you only certain inputs. He an tell you the order of the racers in the beginning of the 
# race. Also he can tell you the overtakes that take place during the race. This information shall be sufficient for
# you to keep track of the racers till the end of the race. Can you automate the task of giving us the final result?
#  
# INPUT:
# The input format is as follows:
# The first line consists of the list of the racers in the order of their initial position. Only the first name of the
# racers shall be used. 
# The following lines contain the overtakes that occur over the course of the race. All the announcements will consist
# one car taking the position of the car that was immediately ahead of it. Consider this as a one lap race only.
#
# OUTPUT:
# The output consists of the list of racers, one in each line, in the order they finish the race.
#
# EXAMPLE:
# Input:
# Ash Brian Carol David Finn
# Finn overtakes David
# Carol overtakes Brian
# Carol overtakes Ash
# Brian overtakes Ash
# David overtakes Finn
# 
# Output:
# Carol
# Brian
# Ash
# David
# Finn

racer = input().split()
check = 1
while(check == 1):
  line = ""
  try:
    line = input()
  except:
    check = 0
  if(line == ""):
    check = 0
  else:
    [racer2, overtake, racer1] = line.split()
    pos = racer.index(racer1)
    temp = racer[pos]
    racer[pos] = racer[pos+1]
    racer[pos+1] = temp
for i in racer:
  print(i)
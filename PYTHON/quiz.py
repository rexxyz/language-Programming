print('Welcome to a Soccer Quiz')
answer=input('Are you ready to play the Quiz ? (yes/no) :')
score=0
total_questions=3
 
if answer.lower()=='yes':
    answer=input('Question 1: Who are the reigning Premier League Champions?')
    if answer.lower()=='Manchester City':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
 
    answer=input('Question 2: Who has the most Premier League goals? ')
    if answer.lower()=='Alan Shearer':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
    answer=input('Question 3: What team does Cristiano Ronaldo play for?')
    if answer.lower()=='Manchester United':
        score += 1
        print('correct')
    else:
        print('Wrong Answer :(')
 
print('Thank you for Playing this short quiz, you answered',score,"questions correctly!")
mark=(score/total_questions)*100
print('Marks obtained:',mark)
print('Goodbye!')
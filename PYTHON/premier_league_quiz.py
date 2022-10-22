class Question:
    def __init__(self, questionText, answer, multipleChoiceOptions=None, alternateAnswers=None):
        self.questionText = questionText
        self.answer = answer
        self.multipleChoiceOptions = multipleChoiceOptions
        self.alternateAnswers = alternateAnswers
 
    def __repr__(self):
        return '{'+ self.questionText +', '+ self.answer +', '+ str(self.multipleChoiceOptions) +', '+ str(self.alternateAnswers) +'}'


quizQuestions = [
    Question("In which year did the Premier League Start", "d", ["(a) 1956", "(b) 1967", "(c) 1996", "(d) 1992"], ["1992", "(d) 1992"]),
    Question("Who scored the first Premier League goal", "b", ["(a) Paul Scholes", "(b) Brian Deane", "(c) Robbie Fowler", "(d) Roy Keane"], ["Brian Deane", "(b) Brian Dean"]),
    Question("How many different teams have played in the Premier League", "a", ["(a) 50", "(b) 47", "(c) 20", "(d) 32"], ["50", "(a) 50"]),
    Question("How many teams have never been relegated from the Premier League", "d", ["(a) 8", "(b) 1", "(c) 4", "(d) 6"], ["6", "(d) 6"]),
    Question("Which team has won the Premier League the most number of times", "c", ["(a) Liverpool", "(b) Manchester City", "(c) Manchester United", "(d) Arsenal"], ["Manchester United", "(c) Manchester United"]),
    Question("Who has scored the most number of Premier League goals", "b", ["(a) Wayne Rooney", "(b) Alan Shearer", "(c) Sergio Aguero", "(d) Cristiano Ronaldo"], ["Alan Shearer", "(b) Alan Shearer"]),
    Question("Who has made the most number of Premier League Appearances", "a", ["(a) Gareth Barry", "(b) James Milner", "(c) Ryan Giggs", "(d) Frank Lampard"], ["Gareth Barry", "(a) Gareth Barry"]),
    Question("Who has kept the most number of Premier League Clean Sheets", "c", ["(a) Pepe Reina", "(b) Edwin van der Sar", "(c) Petr Cech", "(d) David James"], ["Petr Cech", "(c) Petr Cech"]),
    Question("Which team has won the most Premier League points in a single season", "d", ["(a) Newcastle United", "(b) Liverpool", "(c) Manchester United", "(d) Manchester City"], ["Manchester City", "(d) Manchester City"]),
    Question("Which team has won the fewest Premier League points in a single season", "a", ["(a) Derby County", "(b) Aston Villa", "(c) Tottenham Hotspur", "(d) Fulham"], ["Derby County", "(a) Derby County"]),
] 

score = 0
total_questions= 10
question_num = 1

print("Welcome to the Englsih Premier League Quiz!")
print("Answer the questions as they are presented.")
print('')

for question in quizQuestions:
    if (question.multipleChoiceOptions != None): 
        x = "Question: " + str(question_num)
        print("\033[4m" + x + "\033[0m")
        print('')
        print(f"{question.questionText}?")
        for option in question.multipleChoiceOptions:
          print(option)
        userInput = input('Your answer: ')  
    else:
        x = "Question: " + str(question_num)
        print("\033[4m" + x + "\033[0m")
        print('')

        print(f"{question.questionText}?")
        userInput = input('Your answer: ')
        
    if (userInput.lower() == question.answer.lower()):
        print("Correct "+"✅")
        score += 1
        question_num +=1
        print('')
    elif (question.alternateAnswers != None and userInput.lower() in question.alternateAnswers):
        print("Correct "+"✅")
        score += 1
        question_num +=1
        print('')
    else:
        print("Incorrect "+"❌")
        print("The correct answer was: "+f"({question.answer})")
        print('')
        question_num +=1

mark = (score/total_questions)*100
print("---------------------------")
print('You got '+ f"{mark}" + '% for this quiz')
print('')
print('Thank you for playing!')
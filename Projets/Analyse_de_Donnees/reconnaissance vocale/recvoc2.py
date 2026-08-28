from gtts import gTTS
import pyjokes
import subprocess
import time
import os
import datetime
import shutil
import speech_recognition as sr



def speak(text):
    tts = gTTS(text=text, lang='fr')
    tts.save("output.mp3")
    os.system("open output.mp3")
	
	

def wish():
    print("Wishing.")
    time = datetime.datetime.now().hour
    global uname, asname
    if 0 <= time < 12:
        speak("Good Morning sir or madam!")

    elif 12 <= time < 18:
        speak("Good Afternoon sir or madam!")

    else:
        speak("Good Evening sir or madam!")

    asname = "Topitop"
    speak("I am your Voice Assistant from DataFlair,")
    speak(asname)
    print("I am your Voice Assistant,", asname)

def getName():
    global uname
    speak("Can I please know your name?")
    uname = takeCommand()
    print("Name:", uname)
    speak("I am glad to know you!")
    columns = shutil.get_terminal_size().columns
    speak("How can I help you, ")
    speak(uname)

def takeCommand():
    recog = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening to the user")
        recog.pause_threshold = 1
        userInput = recog.listen(source)

    try:
        print("Recognizing the command")
        # Remplacez 'en-in' par 'fr-FR' pour la reconnaissance vocale en français
        command = recog.recognize_google(userInput, language='fr-FR')
        print(f"Command is: {command}\n")
    except Exception as e:
        print(e)
        print("Unable to Recognize the voice.")
        return "None"

    return command


# Appel de la fonction wish et getName pour tester
#wish()
#getName()
#takeCommand()




from gtts import gTTS
import os
import datetime
import shutil
import speech_recognition as sr
import smtplib
import requests
from bs4 import BeautifulSoup

# ... (votre code existant)
#def sendEmail(to, content):
    #speak(f"Sending mail to {to}")
    #server = smtplib.SMTP('smtp.gmail.com', 587)
   # server.ehlo()
   # server.starttls()
    # Remplacez 'your email id' et 'password' par vos informations de connexion
    #server.login('polytech899@gmail.com', 'PolytechMAM2') 
    #server.sendmail('polytech899@gmail.com', to, content)
    #server.close()


def getWeather(city_name):
    baseUrl = "http://api.openweathermap.org/data/2.5/weather?"
    url = baseUrl + "appid=" + 'd850f7f52bf19300a9eb4b0aa6b80f0d' + "&q=" + city_name
    response = requests.get(url)
    x = response.json()

    if x["cod"] != "404":
        y = x["main"]
        temp = y["temp"]
        temp -= 273 
        pressure = y["pressure"]
        humidity = y["humidity"]
        desc = x["weather"]
        description = desc[0]["description"]
        info = (
            f" Temperature= {temp}°C\n atmospheric pressure (hPa) ={pressure}\n humidity = {humidity}%\n description = {description}"
        )
        print(info)
        speak("Voici le rapport météo à")
        speak(city_name)
        speak(info)
    else:
        speak("Ville non trouvée")


def getNews():
    try:
        response = requests.get('https://www.bbc.com/news')
        b4soup = BeautifulSoup(response.text, 'html.parser')
        headLines = b4soup.find('body').find_all('h3')
        unwantedLines = ['BBC World News TV', 'BBC World Service Radio',
                         'News daily newsletter', 'Mobile app', 'Get in touch']

        for x in list(dict.fromkeys(headLines)):
            if x.text.strip() not in unwantedLines:
                speak(x.text.strip())
    except Exception as e:
        print(str(e))

# Appel de la fonction sendEmail et getWeather pour tester
#sendEmail('recipient@example.com', 'This is a test email.')
getWeather('CityName')






if __name__ == '__main__':
    uname = ''
    asname = ''
    os.system('cls')
    wish()
    getName()
    print(uname)

    while True:
        command = takeCommand().lower()
        print(command)

        if "jarvis" in command:
            wish()

        elif 'how are you' in command:
            speak("I am fine, Thank you")
            speak("How are you, ")
            speak(uname)

        elif "good morning" in command or "good afternoon" in command or "good evening" in command:
            speak("A very" + command)
            speak("Thank you for wishing me! Hope you are doing well!")

        # ... (autres conditions existantes)

        elif 'weather' in command:
            speak("Please tell your city name ")
            print("City name : ")
            cityName = takeCommand()
            getWeather(cityName)

        elif 'news' in command:
            getNews()

        elif "don't listen" in command or "stop listening" in command:
            speak("For how much time you want to stop me from listening commands?")
            stop_time = int(takeCommand())
            time.sleep(stop_time)

        elif "camera" in command or "take a photo" in command:
            ec.capture(0, "Jarvis Camera ", "img.jpg")

        elif 'shutdown system' in command:
            speak("Hold On a Sec! Your system is on its way to shut down")
            subprocess.call('shutdown / p /f')

        elif "restart" in command:
            subprocess.call(["shutdown", "/r"])

        elif "sleep" in command:
            speak("Setting in sleep mode")
            subprocess.call("shutdown / h")

        elif "write a note" in command:
            speak("What should I write, sir")
            note = takeCommand()
            file = open('jarvis.txt', 'w')
            speak("Sir, Should I include date and time")
            snfm = takeCommand()
            if 'yes' in snfm or 'sure' in snfm:
                strTime = datetime.datetime.now().strftime("%H:%M:%S")
                file.write(strTime)
                file.write(" :- ")
                file.write(note)
            else:
                file.write(note)
        
        # Ajout des nouvelles fonctionnalités
        #elif 'send email' in command:
            #try:
                #speak("Whom should I send the mail?")
                #to = takeCommand()
                #speak("What is the body?")
                #content = takeCommand()
                #sendEmail(to, content)
                #speak("Email has been sent successfully!")
            #except Exception as e:
                #print(e)
                #speak("I am sorry, not able to send this email")

        elif 'play music' in command or "play song" in command:
            speak("Enjoy the music!")
            music_dir = "C:\\Users\\Gayathri\\Music"
            songs = os.listdir(music_dir)
            print(songs)
            random = os.startfile(os.path.join(music_dir, songs[1]))

        elif 'joke' in command:
            speak(pyjokes.get_joke())

        else:
            speak("Sorry, I am not able to understand you")



import tkinter
from tkinter import Label, Button, StringVar
import os
from gtts import gTTS
import speech_recognition as sr
import datetime
import shutil

def speak(text):
    tts = gTTS(text=text, lang='en')
    tts.save("output.mp3")
    os.system("open output.mp3")

def wish():
    print("Wishing.")
    time = datetime.datetime.now().hour
    global uname, asname
    if 0 <= time < 12:
        speak("Good Morning sir or madam!")
    elif 12 <= time < 18:
        speak("Good Afternoon sir or madam!")
    else:
        speak("Good Evening sir or madam!")

    asname = "Jasper 1 point o"
    speak("I am your Voice Assistant from DataFlair,")
    speak(asname)
    print("I am your Voice Assistant,", asname)

def getName():
    global uname
    speak("Can I please know your name?")
    uname = takeCommand()
    print("Name:", uname)
    speak("I am glad to know you!")
    columns = shutil.get_terminal_size().columns
    speak("How can I help you, ")
    speak(uname)

def takeCommand():
    recog = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening to the user")
        recog.pause_threshold = 1
        userInput = recog.listen(source)

    try:
        print("Recognizing the command")
        command = recog.recognize_google(userInput, language='en-in')
        print(f"Command is: {command}\n")
    except Exception as e:
        print(e)
        print("Unable to Recognize the voice.")
        return "None"

    return command

def callVoiceAssistant():
    wish()
    getName()

# Creating the main window
wn = tkinter.Tk()
wn.title("DataFlair Voice Assistant")
wn.geometry('700x300')
wn.config(bg='LightBlue1')

Label(wn, text='Welcome to meet the Voice Assistant by DataFlair', bg='LightBlue1',
      fg='black', font=('Courier', 15)).place(x=50, y=10)

# Button to convert PDF to Audio form
Button(wn, text="Start", bg='gray', font=('Courier', 15),
       command=callVoiceAssistant).place(x=290, y=100)

showCommand = StringVar()
cmdLabel = Label(wn, textvariable=showCommand, bg='LightBlue1',
                 fg='black', font=('Courier', 15))
cmdLabel.place(x=250, y=150)

# Runs the window until it is closed
wn.mainloop()
















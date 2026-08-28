import speech_recognition as sr
import os
from gtts import gTTS
import os
import datetime
import shutil
import speech_recognition as sr
import smtplib
import requests
from bs4 import BeautifulSoup
import pyjokes
import subprocess
import time
import pyttsx3


def wish():
    print("Wishing.")
    time = datetime.datetime.now().hour
    global uname, asname
    if 0 <= time < 12:
        speak("Bonjour Monsieur ou Madame!")
    elif 12 <= time < 18:
        speak("Bonjour Monsieur ou Madame!")
    else:
        speak("Bonsoir Monsieur ou Madame!")

    asname = "Topitop"
    speak("Je suis votre assistant vocal")
    speak(asname)
    print("Je suis votre assistant vocal,", asname)
    
    
    
def getName():
    global uname
    speak("salut! puis-je connaître votre nom s'il vous plaît?")
    uname = listen()
    while uname == None:
        speak("Pardon ? Redites moi votre nom.")
        uname = listen()
    
        
    speak("Ravi de vous connaître!")
    speak(uname)
    #speak("Puis-je connaître votre nom, s'il vous plaît?")
    #uname = listen()
    #speak("Ravi de vous connaître!")
    #columns = shutil.get_terminal_size().columns
    #speak("Comment puis-je vous aider, ")
    #speak(uname)


def listen():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Dites quelque chose...")
        audio = r.listen(source)
    
    try:
        text = r.recognize_google(audio, language='fr-FR')
        print("Vous avez dit: ", text)
        return text
    except sr.UnknownValueError:
        print("Je n'ai pas pu comprendre l'audio.")
        return None
    except sr.RequestError as e:
        print("Une erreur s'est produite lors de la demande à Google Speech Recognition: {0}".format(e))
        return None
        

     


def speak(text):
    os.system("say '{0}'".format(text))

            
                        
            
if __name__ == '__main__':
    uname = ' '
    asname = ' '
    os.system('clear')
    
    
    while True:
        command = listen()
        if command:
            if "bonjour" in command:
                getName()
            if "quitter" in command:
                break

        
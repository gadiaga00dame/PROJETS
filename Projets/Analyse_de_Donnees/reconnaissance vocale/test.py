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

def speak(text):
    os.system("say '{0}'".format(text))

#def speak(text):
    #tts = gTTS(text=text, lang='fr')
    #tts.save("output.mp3")
    #os.system("open output.mp3")

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
        print("Je nai pas pu comprendre laudio.")
        return None
    except sr.RequestError as e:
        print("Une erreur sest produite lors de la demande à Google Speech Recognition: {0}".format(e))
        return None

def getName():
    global uname
    speak("Puis-je connaître votre nom, sil vous plaît?")
    uname = listen()
    print("Nom:", uname)
    speak("Ravi de vous connaître!")
    columns = shutil.get_terminal_size().columns
    speak("Comment puis-je vous aider, ")
    speak(uname)


def sendEmail(to, content):
    speak(f"Envoi du courriel à {to}")
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    # Remplacez 'your_email@gmail.com' et 'your_password' par vos informations de connexion
    server.login('your_email@gmail.com', 'your_password')
    server.sendmail('your_email@gmail.com', to, content)
    server.close()

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
            f" Température= {temp}°C\n Pression atmosphérique (hPa) ={pressure}\n Humidité = {humidity}%\n Description = {description}"
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

if __name__ == '__main__':
    uname = ' '
    asname = ' '
    os.system('clear')

    while True:
        command = str(listen()).lower()
        print(command)

        if "salut" in command:
            wish()
            getName()
            print(uname)

        elif 'comment vous allez' in command:
            speak("Je vais bien, merci")
            speak("Comment ça va, ")
            speak(uname)

        elif "bonjour" in command or "bonsoir" in command:
            speak(f"Très {command}")
            speak("Merci de me le demander ! Jespère que vous allez bien!")

        # ... (autres conditions existantes)

        elif 'température' in command:
            speak("Veuillez indiquer le nom de votre ville ")
            print("Nom de la ville : ")
            cityName = listen()
            getWeather(cityName)

        elif 'news' in command:
            getNews()

        elif "ne mécoute pas" in command or "arrête découter" in command:
            speak("Pendant combien de temps souhaitez-vous que je cesse découter les commandes?")
            stop_time = int(listen())
            time.sleep(stop_time)

        elif "appareil photo" in command or "prendre une photo" in command:
            ec.capture(0, "Jarvis Camera ", "img.jpg")

        elif 'éteins le système' in command:
            speak("Attendez une seconde ! Votre système est en cours dextinction")
            subprocess.run(["sudo", "shutdown", "-h", "now"])

        elif "redémarre" in command:
            subprocess.run(["osascript", "-e", 'tell app "System Events" to restart'])

        elif "dormir" in command:
            speak("Passage en mode veille")
            subprocess.run(["pmset", "sleepnow"])

        elif "écrire une note" in command:
            speak("Que devrais-je écrire, monsieur")
            note = listen()
            file = open('jarvis.txt', 'w')
            speak("Monsieur, dois-je inclure la date et lheure")
            snfm = listen()
            if 'oui' in snfm or 'bien sûr' in snfm:
                strTime = datetime.datetime.now().strftime("%H:%M:%S")
                file.write(strTime)
                file.write(" :- ")
                file.write(note)
            else:
                file.write(note)

        elif 'blague' in command:
            speak(pyjokes.get_joke())

        else:
            speak("Désolé, je ne suis pas en mesure de vous comprendre")
            time.sleep(3)

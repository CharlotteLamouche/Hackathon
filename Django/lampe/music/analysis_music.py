from wave import *
from tinytag import TinyTag
from emit import transmit



def couleur(fichier):
    tag = TinyTag.get("/home/pi//Documents/Hackaton/website/Hackaton/Serveur_Django/lampe/music/static/music/"+fichier);
    genre = tag.genre
    if genre == "Jazz":
        hexa = "FE00E8";
    elif genre == "Gospel" :
        hexa = "D200F7";
    elif genre == "Blues" :
        hexa = "9900F7";
    elif genre == "Metal" :
        hexa = "0020B3";
    elif genre == "Rock" :
        hexa = "0C00E1";
    elif genre == "Variete" :
        hexa = "00B1E3";
    elif genre == "Pop" :
        hexa = "00F8EC";
    elif genre == "Disco" :
        hexa = "00F8BB";
    elif genre == "Funk" :
        hexa = "00F89A";
    elif genre == "Soul" :
        hexa = "00F81E";
    elif genre == "Reggae" :
        hexa = "5DFE41";
    elif genre == "Folk" :
        hexa = "ADFE00";
    elif genre == "Hip-Hop" :
        hexa = "E5FB00";
    elif genre == "Classique":
        hexa = "FE8C00";
    elif genre == "Latino" :
        hexa = "FE5A00";
    elif genre == "Electro" :
        hexa = "FE0500";
    elif genre == "Rap" :
        hexa = "FE003F";
    elif genre == "R&B" :
        hexa = "F8007F";
    else:
        hexa = "FEFEFE";
    transmit("COLOR_"+hexa)
    transmit("MUSIC_"+fichier)
    return("COLOR_"+hexa)

 

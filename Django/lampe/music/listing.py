def listing():
    import os
    path = "/home/pi//Documents/Hackaton/website/Hackaton/Serveur_Django/lampe/music/static/music"
    dirs = os.listdir(path)
    list = []
    for file in dirs:
        list.append(file)
    return(list)
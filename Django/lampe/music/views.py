#-*- coding: utf-8 -*-
from django.http import HttpResponse
from django.shortcuts import render
import listing
import analysis_music

# Create your views here.

def home(request):
    return render(request, 'music/accueil.html')


def date_actuelle(request):
    return render(request, 'music/date.html', {'list': listing.listing() })

def profile_page(request):
    return render(request, 'music/resultat.html', {'retour': analysis_music.couleur(request.GET["searchbox"])})



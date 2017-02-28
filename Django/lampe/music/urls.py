from django.conf.urls import url

from . import views


urlpatterns = [
               url(r'^accueil$', views.home),
               url(r'^date$', views.date_actuelle),
               url(r'^analysis_music.py.{0,50}$', views.profile_page),
               ]

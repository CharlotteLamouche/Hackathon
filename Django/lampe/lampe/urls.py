from django.conf.urls import include, url
from django.contrib import admin
from music import views


urlpatterns = [
               url(r'^music/', include('music.urls')),
]

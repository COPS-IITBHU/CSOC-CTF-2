import os
from django.shortcuts import render
from django.http import HttpResponse
import time
# Create your views here.
flag = os.environ['FLAG']
def index(request):
  # return HttpResponse("Ready")
  cur_time=int(time.time())
  if request.COOKIES:
    # return HttpResponse(cur_time-int(request.COOKIES['time']))
    if int(request.COOKIES['time'])==1639506600 :
      return HttpResponse(flag)
  # else:
  response=render(request,'index.html')
  response.set_cookie('time',value=cur_time-60)
  return response
  
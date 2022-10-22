import cv2
import cv2.aruco as aruco
import numpy as np
import os
import math
info={}
ArUco_details_dict={}
sort_key1={}
sort_key2={}
corners={}
cr=[]

ArUco_corners = {}
img=cv2.imread("Path_to_image")
grey_scale=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
key=getattr(aruco, f'DICT_5X5_250')#The dimensions can vary.
arucoDict=aruco.Dictionary_get(key)
arucoParam=aruco.DetectorParameters_create()
aruco_found=aruco.detectMarkers(grey_scale,arucoDict,parameters=arucoParam)

if len(aruco_found[0])!=0:
  for box ,Id in zip(aruco_found[0],aruco_found[1]):
   cr=[[box[0][0][0],box[0][0][1]],[box[0][1][0],box[0][1][1]],[box[0][2][0],box[0][2][1]],[box[0][3][0],box[0][3][1]]]
   corners[Id[0]]=cr
   x=int((box[0][0][0] + box[0][2][0]) / 2)
   y=int((box[0][0][1] + box[0][2][1]) / 2)
   center_x = ((box[0][0][0] + box[0][1][0]) / 2)
   center_y = ((box[0][0][1] + box[0][1][1]) / 2)
   vector_1 = [0,-1]
   vector_2 = [center_x-x, center_y-y]
   unit_vector_1 = vector_1 / np.linalg.norm(vector_1)
   unit_vector_2 = vector_2 / np.linalg.norm(vector_2)
   dot_product =np.dot(unit_vector_1, unit_vector_2)
   angle = np.arccos(dot_product)
   angle=int(angle*180/3.14)
   info[Id[0]]=[[x,y],angle]
    

sort_key1= sorted(info.keys())
sort_key2= sorted(corners.keys())
ArUco_details_dict = {key:info[key] for key in sort_key1 }
ArUco_corners= {key:corners[key] for key in sort_key2 }




print(ArUco_details_dict)


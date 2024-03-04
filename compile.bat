path=c:\windows;c:\windows\system32;c:\opencv4cpp\mingw64\bin;c:\opencv4cpp\opencv4\dll

g++   %1    -Ic:\opencv4cpp\opencv4\include    -Lc:\opencv4cpp\opencv4\lib   -lopencv_calib3d400.dll   -lopencv_core400.dll     -lopencv_dnn400.dll   -lopencv_features2d400.dll  -lopencv_flann400.dll    -lopencv_gapi400.dll    -lopencv_highgui400.dll    -lopencv_imgcodecs400.dll    -lopencv_imgproc400.dll      -lopencv_ml400.dll    -lopencv_objdetect400.dll     -lopencv_photo400.dll    -lopencv_stitching400.dll     -lopencv_video400.dll    -lopencv_videoio400.dll  -o  %2


import numpy as np
import cv2
 
 
def angle_cos(p0, p1, p2):
    d1, d2 = (p0-p1).astype('float'), (p2-p1).astype('float')
    return abs( np.dot(d1, d2) / np.sqrt( np.dot(d1, d1)*np.dot(d2, d2) ) )
 
def find_squares(img):
    img = cv2.GaussianBlur(img, (5, 5), 0)
    squares = []
    for gray in cv2.split(img):
        for thrs in xrange(0, 255, 50):
            if thrs == 0:
                bin = cv2.Canny(gray, 0, 50, apertureSize=5)
                bin = cv2.dilate(bin, None)
            else:
                 retval, bin = cv2.threshold(gray, thrs, 255, cv2.THRESH_BINARY)
            contours, hierarchy = cv2.findContours(bin, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
            for cnt in contours:
                cnt_len = cv2.arcLength(cnt, True)
                cnt = cv2.approxPolyDP(cnt, 0.02*cnt_len, True)
                if len(cnt) == 4 and cv2.contourArea(cnt) > 400 and cv2.contourArea(cnt) < 4000 and cv2.isContourConvex(cnt):
                    cnt = cnt.reshape(-1, 2)
                    x=True
                    for i in xrange(4):
                        if( not (angle_cos(cnt[(i)%4],cnt[(i+1)%4],cnt[(i+2)%4])<0.1777 )):
                            x = False
                           
                    if(x==True):                                        
                        squares.append(cnt)
               
    return squares
 
if __name__ == '__main__':
    from glob import glob
    #template = cv2.imread('../base_numer.jpg')
    list = []
    for i in xrange(10):
        for j in xrange(10):
            fn="test_0%s%s.jpg" % (str(i),str(j))
            img = cv2.imread(fn)
            img_grey = cv2.imread(fn,0)
            squares = find_squares(img_grey)
               
            cv2.drawContours( img, squares, -1, (0,255, 0), 3 )
 
            img_grey = cv2.GaussianBlur(img_grey, (3, 3), 0)
            img_grey = cv2.adaptiveThreshold(img_grey,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,7,2)
            #cv2.imshow('threshold', img_grey)
            squares = find_squares(img_grey)
            cv2.drawContours( img, squares, -1, (0, 255, 0), 3 )
           
            fnout="testout_0%s%s.jpg" % (str(i),str(j))
            cv2.imwrite(fnout, img)
            ch = 0xFF & cv2.waitKey()
            if ch == 27:
                break
    cv2.destroyAllWindows()

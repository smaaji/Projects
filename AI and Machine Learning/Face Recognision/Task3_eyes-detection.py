# -*- coding: utf-8 -*-
from __future__ import print_function

from time import time
import logging
import matplotlib.pyplot as plt
import scipy
import numpy as np
from sklearn.cross_validation import train_test_split
from sklearn.datasets import fetch_lfw_people
from sklearn.grid_search import GridSearchCV
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.decomposition import RandomizedPCA
from sklearn.svm import SVC
from scipy.stats import sem
from skimage.feature import canny
from skimage.transform import hough_circle, hough_circle_peaks
from skimage import color
from skimage.draw import circle_perimeter

print(__doc__)

# Display progress logs on stdout
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(message)s')


###############################################################################
# Download the data, if not already on disk and load it as numpy arrays

lfw_people = fetch_lfw_people(min_faces_per_person=70, resize=0.4)

# introspect the images arrays to find the shapes (for plotting)
n_samples, h, w = lfw_people.images.shape

# for machine learning we use the 2 data directly (as relative pixel
# positions info is ignored by this model)
X = lfw_people.data
n_features = X.shape[1]
Images = X.reshape(len(X), h, w)
# the label to predict is the id of the person
y = lfw_people.target
target_names = lfw_people.target_names
n_classes = target_names.shape[0]

print("Total dataset size:")
print("n_samples: %d" % n_samples)
print("n_features: %d" % n_features)
print("n_classes: %d" % n_classes)


def plot_gallery(images,  h, w, n_row=2, n_col=7):
    """Helper function to plot a gallery of portraits"""
    plt.figure(figsize=(1.8 * n_col, 2.4 * n_row))
    plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
    for i in range(n_row * n_col):
        plt.subplot(n_row, n_col, i + 1)
        plt.imshow(images[i].reshape((h, w)), cmap=plt.cm.gray)
        #plt.title(titles[i], size=12)
        plt.xticks(())
        plt.yticks(())


i=0
xx = []
yy = []


# Load picture
for i in range(n_classes):
    count = 0
    for j  in range(len(X)):
        if (count<2):
            if (lfw_people.target[j] ==i):
                xx.append(lfw_people.data[j])
                yy.append(lfw_people.target[j])
                count = count+1

Images=np.reshape(xx,[-1,h,w])
                     
    
##        def plot_gallery(images,  h, w, n_row=2, n_col=7):
##            """Helper function to plot a gallery of portraits"""
##            plt.figure(figsize=(1.8 * n_col, 2.4 * n_row))
##            plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
##            for i in range(n_row * n_col):
##                plt.subplot(n_row, n_col, i + 1)

hough_radii = np.arange(2, 9, 1)
edge = []
for j in range(len(Images)):
    edge = canny(Images[i], sigma=4, low_threshold=20, high_threshold=50)
    hough = hough_circle(edge, hough_radii)
    accums, cx, cy, radii = hough_circle_peaks(hough, hough_radii, total_num_peaks=3)
    for center_y, center_x, radius in zip(cy, cx, radii):
        circy, circx = circle_perimeter(center_y, center_x, radius)
        z = Images[j]
        z[circy, circx] = 255
        Images[j] = z


plot_gallery(Images, h, w)
plt.show()
    
    





# -*- coding: utf-8 -*-
from __future__ import print_function

from time import time
import logging
import matplotlib.pyplot as plt
import scipy

from sklearn.cross_validation import train_test_split
from sklearn.datasets import fetch_lfw_people
from sklearn.grid_search import GridSearchCV
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from scipy.stats import sem
from sklearn.neural_network import MLPClassifier

from sklearn.metrics.cluster import homogeneity_score
from sklearn.metrics.cluster import v_measure_score
import numpy as np
from sklearn.cluster import KMeans
from sklearn import metrics
print(__doc__)

# Display progress logs on stdout
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(message)s')


# Download the data and load it as numpy arrays

lfw_people = fetch_lfw_people(min_faces_per_person=70, resize=0.4)

# introspect the images arrays to find the shapes (for plotting)
n_samples, h, w = lfw_people.images.shape


# positions info is ignored by this model)
X = lfw_people.data
n_features = X.shape[1]

# the label to predict is the id of the person
y = lfw_people.target
target_names = lfw_people.target_names
n_classes = target_names.shape[0]



print("Total dataset size:")
print("n_samples: %d" % n_samples)
print("n_features: %d" % n_features)
print("n_classes: %d" % n_classes)


# split into a training and testing set
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25)



##############################################################################
# Train a K- Means clustering model
print("Fitting the K Means clustering to the training set")

clf = KMeans(init = 'k-means++', n_clusters=n_classes, n_init=30).fit(X_train, y_train)
#clf = KMeans(n_clusters=n_classes, init='k-means++', random_state=0).fit(X_train, y_train)
#clf = KMeans(n_clusters=n_classes, init='random', random_state=0).fit(X_train, y_train)



###############################################################################
# Quantitative evaluation of the model quality on the test set
print("Predicting people's names on the test set")
t0 = time()
y_pred = clf.fit_predict(X_test, y_test)
print("done in %0.3fs" % (time() - t0))
print("Unique labels: {}".format(np.unique(y_pred)))
print("Number of points per cluster = {}".format(np.bincount(y_pred+1)))
print("Homogeneity score = {}".format(homogeneity_score(y_pred, y_test)))
print("V-Measure score = {}".format(v_measure_score(y_pred, y_test)))



def plot_gallery(images, titles, h, w, n_row=3, n_col=4):
    """Helper function to plot a gallery of portraits"""
    plt.figure(figsize=(1.8 * n_col, 2.4 * n_row))
    plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
    for i in range(n_row * n_col):
        plt.subplot(n_row, n_col, i + 1)
        plt.imshow(images[i].reshape((h, w)), cmap=plt.cm.gray)
        plt.title(titles[i], size=12)
        plt.xticks(())
        plt.yticks(())
        




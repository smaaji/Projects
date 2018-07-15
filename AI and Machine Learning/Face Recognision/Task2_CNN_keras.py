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
from sklearn.decomposition import RandomizedPCA
from sklearn.svm import SVC
from scipy.stats import sem

#%%
print(__doc__)

# Display progress logs on stdout
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(message)s')


###############################################################################
# Download the data, if not already on disk and load it as numpy arrays

lfw_people = fetch_lfw_people(min_faces_per_person=70, resize=0.4)

# introspect the images arrays to find the shapes (for plotting)
n_samples, h, w = lfw_people.images.shape
#%%
# for machine learning we use the 2 data directly (as relative pixel
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
#%%
X_2 = X.reshape(X.shape[0], 50, 37).astype('int64')
plt.imshow(X_2[50], cmap=plt.cm.gray, interpolation='none')

#%%
###############################################################################
# Split into a training set and a test set using a stratified k fold

# split into a training and testing set
trainX, testX, trainY, testY = train_test_split(
    X, y, test_size=0.25)
#%%
# import the necessary packages to build the CNN model
from keras.utils import np_utils
import numpy as np
import matplotlib.pyplot as plt
import os
# SKLEARN
# import the necessary packages for CNN model 
from sklearn.cross_validation import train_test_split
from sklearn.metrics import classification_report
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from keras.layers import Flatten
from keras.layers.convolutional import Conv2D
from keras.layers.convolutional import MaxPooling2D
from keras import backend as K
K.set_image_dim_ordering('th')
import itertools
#%%
# reshape to be [samples][pixels][width][height]
trainX = trainX.reshape(trainX.shape[0], 1, 50, 37).astype('float32')
testX = testX.reshape(testX.shape[0], 1, 50, 37).astype('float32')

# one hot encode outputs
trainY = np_utils.to_categorical(trainY)
testY = np_utils.to_categorical(testY)
num_classes = testY.shape[1]
#%%
#biuld the CNN Model
def baseline_model():
	# create model
    model = Sequential()
    model.add(Conv2D(32, 5, 5, border_mode='valid', 
             input_shape=(1, 50, 37), activation='tanh'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.2))
    model.add(Conv2D(32, 3, 3, border_mode='valid', activation='tanh'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Flatten())
    model.add(Dense(128, activation='tanh'))
    model.add(Dense(num_classes, activation='softmax'))
	# Compile model
    model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])
    return model
# build the model
model = baseline_model()
model.summary()
model.get_config()
model.get_weights()
model.output_shape
#%%
import time
start_time = time.clock()
# Fit the model
hist1 = model.fit(trainX, trainY, validation_data=(testX, testY), nb_epoch=1000, batch_size=200, verbose=2)

end_time = time.clock()
pretraining_time = (end_time - start_time)
print ('Training took %f minutes' % (pretraining_time / 60.))
#%%
# Final evaluation of the model
loss, accuracy = model.evaluate(testX, testY)
print("\nLoss: %.2f, Accuracy: %.2f%%" % (loss, accuracy*100))
#%%
from sklearn.metrics import confusion_matrix
y_pred = model.predict_classes(testX)
print(y_pred)
p=model.predict_proba(testX) # to predict probability
target_names = ['class 0(zero)', 'class 1(one)', 'class 2(two)', 'class three(two)', 'class 4(four)', 'class 5(five)', 'class 6(six)']
print(classification_report(np.argmax(testY,axis=1), y_pred,target_names=target_names))
confusion_matrix=confusion_matrix(np.argmax(testY,axis=1), y_pred)

target_names1 = ['0', '1', '2',' 3', '4', '5', '6']
plt.imshow(confusion_matrix, interpolation='nearest')
plt.title('Confusion matrix')
plt.colorbar()
tick_marks = np.arange(len(target_names))
plt.xticks(tick_marks, target_names, rotation=45)
plt.yticks(tick_marks, target_names1, rotation=45)
thresh = confusion_matrix.max() / 2.
for i, j in itertools.product(range(confusion_matrix.shape[0]), range(confusion_matrix.shape[1])):
        plt.text(j, i, confusion_matrix[i, j],
                 horizontalalignment="center",
                 color="white" if confusion_matrix[i, j] > thresh else "orange")
plt.tight_layout()
plt.title('Confusion Matrix', fontsize='12')
plt.ylabel('True label', fontsize='12')
plt.xlabel('Predicted label', fontsize='12')
plt.show()

#%%
print(hist1.history.keys())
# summarize history for accuracy
#plt.style.use('seaborn-notebook')
#plt.subplot(2, 1, 1)
plt.plot(hist1.history['acc'], color='red')
plt.plot(hist1.history['val_acc'])
plt.title('Model Accuracy')
plt.ylabel('Accuracy (%)')
plt.xlabel('Epoch')
plt.legend(['Traning', 'Test'], loc='upper left')
plt.grid(True)
plt.show()

# summarize history for loss
#plt.subplot(2, 1, 2)
plt.style.use('seaborn-notebook')
plt.plot(hist1.history['loss'], color='orange')
#plt.plot(history.history['val_loss'])
plt.title('Model Traning Loss')
plt.ylabel('Traning Error Rate (%)')
plt.xlabel('Epoch')
plt.legend(['Train'], loc='upper left')
plt.grid(True)
plt.show()
#%%

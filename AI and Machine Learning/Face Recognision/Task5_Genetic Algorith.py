from __future__ import print_function


from time import time
import operator
import logging
import matplotlib.pyplot as plt
import scipy
import numpy

from sklearn.model_selection import train_test_split
from sklearn.datasets import fetch_lfw_people
from sklearn import decomposition
#from sklearn.decomposition import RandomizedPCA

import deap
from deap import creator, base, tools, gp, algorithms

#set the random seed
#numpy.random.seed(0)

print(__doc__)

# Display progress logs on stdout
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(message)s')


###############################################################################
# Download the data, if not already on disk and load it as numpy arrays

lfw_people = fetch_lfw_people(min_faces_per_person=70, resize=0.4, color = False)
#lfw_people = fetch_lfw_people(min_faces_per_person=70, resize=0.4)

# introspect the images arrays to find the shapes (for plotting)
n_samples, h, w = lfw_people.images.shape

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
print("image dimension(H,W): %d, %d" % (h,w))
#########################
### select one image per person
newdata   =[]
ndata = []
newtarget =[]
count = 0
opt = [0,1]
for j in range(len(opt)):
     count = 0
     for i in range(len(lfw_people.target)):
         if (count ==0) :  ##<1 ):
             if (lfw_people.target[i]== opt[j]):  #(j+1)):
                 newdata.append(lfw_people.data[i])
                 ndata.append(lfw_people.data[i])
                 newtarget.append(lfw_people.target[i])
                 #count = 1+count

print('selected %d  samples'% len(newdata))

#####################
## perform PCA reduction to reduce the total number of components
## from 1850 to number denoted by keepComponents
## and whiten to ensure uncorrelated outputs  
keepComponents = 10

pca = decomposition.RandomizedPCA(n_components = keepComponents,
                                  whiten=True)#.fit(newdata)

## reduce the components
newdata1 = pca.fit_transform(newdata)

####################
#k = [0,236]

##########################   Genetic Programming Components    ##########################
###create GP components

def evalconditional(individual):

     func = toolbox.compile(expr=individual)
     #func = gp.compile(individual, pset)
     #r = (individual) ##unpack the list
     result = 0
     for i in range(len(newdata1)):
          ##compare the result          
          val = newdata1[i]   #unpack
          act = 0
          ## loop through the array elements and apply the activation function
          
          if (func(*val)>0) and newtarget[i] == 1: result = result +1
          if (func(*val)<0) and newtarget[i] == 0: result = result +1
     #operator.gt(func(*val) , y): result = 1
     return result,


#########define the evaluation function

##fitness function
 ## it is a maximizing function so weight is  positive
creator.create("FitnessMax", base.Fitness, weights=(1.0,))
                     
##indivduals
 ##individuals to which the fitness function above is applied
creator.create("Individuals", gp.PrimitiveTree, fitness = creator.FitnessMax)

## create the primitive sets
pset = gp.PrimitiveSet("MAIN", 10) 
pset.addPrimitive(operator.sub, 2)
pset.addPrimitive(operator.add, 2)
pset.addPrimitive(operator.mul, 2)

## create a toolbox
toolbox = base.Toolbox()
toolbox.register("expr",  gp.genHalfAndHalf, pset=pset, min_=1, max_=2)
toolbox.register("individual", tools.initIterate, creator.Individuals, toolbox.expr)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)
toolbox.register("compile", gp.compile, pset=pset)

toolbox.register("evaluate", evalconditional)   ##
toolbox.register("select", tools.selTournament, tournsize=7)
toolbox.register("mate", gp.cxOnePoint)
toolbox.register("expr_mut", gp.genFull, min_=0, max_=2)
toolbox.register("mutate", gp.mutUniform, expr=toolbox.expr_mut, pset=pset)


toolbox.decorate("mate", gp.staticLimit(key=operator.attrgetter("height"), max_value=10))
toolbox.decorate("mutate", gp.staticLimit(key=operator.attrgetter("height"), max_value=10))
####
pop = toolbox.population(n=300)
hof = tools.HallOfFame(1)

 ### statistics
stats_fit = tools.Statistics(lambda ind: ind.fitness.values)
stats_size = tools.Statistics(len)
mstats = tools.MultiStatistics(fitness=stats_fit, size=stats_size)

mstats.register("avg", numpy.mean)
mstats.register("std", numpy.std)
mstats.register("min", numpy.min)
mstats.register("max", numpy.max)

## launching the  evolution

pop, log = algorithms.eaSimple(pop, toolbox,
                               cxpb= 0.5, # crossover propability
                               mutpb=0.1, # mutation propability
                               ngen = 40, # number of generations
                               stats=mstats, # the statistical metrics
                               halloffame=hof, verbose=True)



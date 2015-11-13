import tensorflow as tf
import numpy as np

#create data model
samples = tf.placeholder("float", [None, 32]) # 32 bit depth, variable # of samples
labels = tf.Variable(tf.zeros([10])) #start with 10 different genres, one_hot




#init
init = tf.initialize_all_variables()
sess = tf.Session()
sess.run(init)



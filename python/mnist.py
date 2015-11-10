import input_data
import tensorflow as tf

#one_hot means labels (1-9) are one hot vectors. 0 is stored as [1,0,0,0,0,0,0,0,0,0,0]
#pulls mnist data
mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

#Create Placeholder, allows us to input any number of images.
x = tf.placeholder("float", [None, 784])

#Next, we need pixel weights and biases for our model
#TensorFlow handles these in Variables, a modifiable tensor

#both initialize as tensors full of zeros.
#need to understand this more....
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

#implement data model

#run softmax algorithm, y is the guess
y = tf.nn.softmax(tf.matmul(x, W) + b)

#placeholders to input the correct answers
y_ = tf.placeholder("float", [None, 10])

#cross entropy is a cost function/algorithm
#cost is what it means for our model to be bad
cross_entropy = -tf.reduce_sum(y_ * tf.log(y))
train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)

#not that data model is laid out, we can initialize a tf session.
init = tf.initialize_all_variables()
sess = tf.Session()
sess.run(init)

for i in range(1000):
	batch_xs, batch_ys = mnist.train.next_batch(100)
	sess.run(train_step, feed_dict = {x: batch_xs, y_: batch_ys})


correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1)) #outputs array of bools
accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))  #turns array of bools into %

print sess.run(accuracy, feed_dict={x: mnist.test.images, y_:mnist.test.labels})

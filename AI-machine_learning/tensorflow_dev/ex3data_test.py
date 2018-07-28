#!/usr/bin/env python3

#######################################
# Configure imports and eager execution
#######################################
from __future__ import absolute_import, division, print_function

try:
    from setuptools import setup, find_packages
except AttributeError:
    from setuptools import setup, find_packages

import os
import matplotlib.pyplot as plt

import tensorflow as tf
import tensorflow.contrib.eager as tfe

tf.enable_eager_execution()

print("TensorFlow version: {}".format(tf.VERSION))
print("Eager execution: {}".format(tf.executing_eagerly()))

config = tf.ConfigProto(device_count={"CPU": 4},
inter_op_parallelism_threads = 1,
intra_op_parallelism_threads = 4,
log_device_placement=True)

######################
# Download the dataset
######################
#train_dataset_url = "http://download.tensorflow.org/data/iris_training.csv"
#train_dataset_url = "/home/ubuntu/.keras/datasets/iris_training.csv"

#train_dataset_fp = tf.keras.utils.get_file(fname=os.path.basename(train_dataset_url),
#                                           origin=train_dataset_url)
#train_dataset_fp = "/home/ubuntu/workspace/AI-machine_learning/tests/ex3data1.csv"
train_dataset_fp = "/src/TravelOptimizer/AI-machine_learning/tests/ex3data1.csv"

print("Local copy of the dataset file: {}".format(train_dataset_fp))

# Parse the dataset
def parse_csv(line):
  #example_defaults = [[0.], [0.], [0.], [0.], [0]]  # sets field types
  example_defaults = [[0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],
  [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.], [0.],[0.]
  ]
  parsed_line = tf.decode_csv(line, example_defaults)
  # First 400 fields are features, combine into single tensor
  features = tf.reshape(parsed_line[:-1], shape=(400,))
  # Last field is the label
  label = tf.reshape(parsed_line[-1], shape=())
  label = tf.cast(label, tf.int32) # mandatory in case of float labels
  label = label - 1 # convert it to 0 based
  return features, label

#####################################
# Create the training tf.data.Dataset
#####################################
train_dataset = tf.data.TextLineDataset(train_dataset_fp)
train_dataset = train_dataset.skip(1)             # skip the first header row
train_dataset = train_dataset.map(parse_csv)      # parse each row
train_dataset = train_dataset.shuffle(buffer_size=1000)  # randomize
train_dataset = train_dataset.batch(64)

# View a single example entry from a batch
features, label = iter(train_dataset).next()
#print("example features:", features[0])
#print("example label:", label[0])

model = tf.keras.Sequential([
  tf.keras.layers.Dense(10, activation="relu", input_shape=(400,)),  # input shape required
  tf.keras.layers.Dense(20, activation="relu"),
  tf.keras.layers.Dense(10)
])
#print( model.weights )

#######################################
# Define the loss and gradient function
#######################################
def loss(model, x, y):
  y_ = model(x)
  return tf.losses.sparse_softmax_cross_entropy(labels=y, logits=y_)


def grad(model, inputs, targets):
  with tf.GradientTape() as tape:
    loss_value = loss(model, inputs, targets)
  return tape.gradient(loss_value, model.variables)

def minibatch():
    #####################
    # Create an optimizer
    #####################
    optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
    #optimizer = tf.train.AdamOptimizer(learning_rate=0.01)


    ###############
    # Training loop
    ###############
    ## Note: Rerunning this cell uses the same model variables

    # keep results for plotting
    train_loss_results = []
    train_accuracy_results = []

    num_epochs = 201

#    g = tf.Graph()
#    with g.as_default():

    init = tf.global_variables_initializer()
    sess = tf.Session()
    #sess.run(init)

    for epoch in range(num_epochs):
      epoch_loss_avg = tfe.metrics.Mean()
      epoch_accuracy = tfe.metrics.Accuracy()

      # Training loop - using batches of 32
      for x, y in train_dataset:
        # Optimize the model
        grads = grad(model, x, y)
        train_step = optimizer.apply_gradients(zip(grads, model.variables),
                                  global_step=tf.train.get_or_create_global_step())

        #sess.run([train_step])
        # Track progress
        epoch_loss_avg(loss(model, x, y))  # add current batch loss
        # compare predicted label to actual label
        epoch_accuracy(tf.argmax(model(x), axis=1, output_type=tf.int32), y)

      # end epoch
      train_loss_results.append(epoch_loss_avg.result())
      train_accuracy_results.append(epoch_accuracy.result())

      if epoch % 50 == 0:
        print("Epoch {:03d}: Loss: {:.3f}, Accuracy: {:.3%}".format(epoch,
                                                                    epoch_loss_avg.result(),
                                                                    epoch_accuracy.result()))
minibatch()
#w = tf.Variable([0],dtype=tf.float32)
#init = tf.global_variables_initializer()
#sess = tf.Session()
#sess.run(init)
#sess.run(minibatch)

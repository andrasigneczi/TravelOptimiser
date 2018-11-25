# Python
try:
    from setuptools import setup, find_packages
except AttributeError:
    from setuptools import setup, find_packages

import tensorflow as tf
hello = tf.constant('Hello, TensorFlow!')
sess = tf.Session()
print(sess.run(hello))

#!/usr/bin/env python3

from relu import *
from sigmoid import *
from softmax import *
import numpy as np

def sigmoidTest():
    sigmoid = SIGMOID_LAYER()
    X = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]])
    result = sigmoid.forward(X)
    print("Sigmoid result:\n{}".format(result))
    backresult = sigmoid.backward(result)
    print("\nSigmoid backward result:\n{}".format(backresult))

def reluTest():
    relu = RELU_LAYER()
    X = np.array([[-1, -2, 3], [4, -5, -6], [7, -8, 9], [-10, 11, 12]])
    result = relu.forward(X)
    print("Relu result:\n{}".format(result))
    backresult = relu.backward(result)
    print("\nRelu backward result:\n{}".format(backresult))

def softmaxTest():
    softmax = SOFTMAX_LAYER()
    X = np.array([[-1, -2, 3], [4, -5, -6], [7, -8, 9], [-10, 11, 12]])
    result = softmax.forward(X)
    print("Softmax result:\n{}".format(result))
    backresult = softmax.backward(result)
    print("\nSoftmax backward result:\n{}".format(backresult))

#sigmoidTest()
#reluTest()
softmaxTest()

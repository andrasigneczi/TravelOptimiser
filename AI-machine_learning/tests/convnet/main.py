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

def anyTest1():
    dW = np.zeros((2,2,3,8))
    val = np.ones((2,2,3))
    dW[:,:,:,1] += val
    print("\nany test result:\n{}".format(dW))

def anyTest2():
    x = np.array([[1, 2, 3], [4,5,6]])
    print("mask:{}\n".format(x == np.max(x)))



#sigmoidTest()
#reluTest()
#softmaxTest()
anyTest2()

#!/usr/bin/env python3

from relu import *
from lrelu import *
from sigmoid import *
from softmax import *
from tanh import *
import numpy as np

def initTestValue():
    X = np.zeros((5,4,3,2))
    x = -2.5
    for i in range(5):
        for j in range(4):
            for k in range(3):
                for l in range(2):
                    X[i, j, k, l] = x
                    x += 0.07
    return X

def sigmoidTest():
    sigmoid = SIGMOID_LAYER()
    X = initTestValue()
    result = sigmoid.forward(X)
    print("Sigmoid forward result:\n{}".format(result))
    backresult = sigmoid.backward(result)
    print("\nSigmoid backward result:\n{}\n".format(backresult))

def reluTest():
    relu = RELU_LAYER()
    X = initTestValue()
    result = relu.forward(X)
    print("Relu forward result:\n{}".format(result))
    backresult = relu.backward(result)
    print("\nRelu backward result:\n{}\n".format(backresult))

def tanhTest():
    tanh = TANH_LAYER()
    X = initTestValue()
    result = tanh.forward(X)
    print("Tanh forward result:\n{}".format(result))
    backresult = tanh.backward(result)
    print("\nTanh backward result:\n{}\n".format(backresult))

def lreluTest():
    relu = LRELU_LAYER()
    X = initTestValue()
    result = relu.forward(X)
    print("Leaky Relu forward result:\n{}".format(result))
    backresult = relu.backward(result)
    print("\nLeaky Relu backward result:\n{}\n".format(backresult))

def softmaxTest():
    softmax = SOFTMAX_LAYER()
    X = np.array([[-0.1, -0.7, 0.1, 0.7], [-0.51, -0.49, 0.51, 0.49]]);
    result = softmax.forward(X)
    print("Softmax forward result:\n{}".format(result))
    backresult = softmax.backward(result)
    print("\nSoftmax backward result:\n{}\n".format(backresult))

def anyTest1():
    dW = np.zeros((2,2,3,8))
    val = np.ones((2,2,3))
    dW[:,:,:,1] += val
    print("\nany test result:\n{}".format(dW))

def anyTest2():
    x = np.array([[1, 2, 3], [4,5,6]])
    print("mask:{}\n".format(x == np.max(x)))



sigmoidTest()
reluTest()
tanhTest()
lreluTest()
softmaxTest()
#anyTest2()

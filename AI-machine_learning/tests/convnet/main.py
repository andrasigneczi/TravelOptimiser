#!/usr/bin/env python3

from relu import *
from lrelu import *
from sigmoid import *
from softmax import *
from tanh import *
from fc import *
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

def fullyConnectedTest():
    # input: 20
    # output 11
    fc = FC_LAYER(11, (20, 11))
    X = np.array([[-10.5, -5.1, -3.1, -0.5, -0.1, 0, 0.1, 0.5, 3.1, 5.1, 10.6, -10.5, -5.1, -3.1, -0.5, -0.1, 0, 0.1, 0.5, 3.1],
                    [-10.5, -5.1, -3.1, -0.5, -0.1, 0, 0.1, -10.5, -5.1, -3.1, -0.5, -0.1, 0.5, 3.1, 5.1, 10.6, 0, 0.1, 0.5, 3.1]], dtype=float)
    fc.kernel.fill(0.13)
    fc.bias.fill(0.1)
    result = fc.forward(X)
    print("FC forward result:\n{}".format(result))
    backresult = fc.backward(result)
    print("\nFC backward result:\n{}\n".format(backresult))

def anyTest1():
    dW = np.zeros((2,2,3,8))
    val = np.ones((2,2,3))
    dW[:,:,:,1] += val
    print("\nany test result:\n{}".format(dW))

def anyTest2():
    x = np.array([[1, 2, 3], [4,5,6]])
    print("mask:{}\n".format(x == np.max(x)))

def meanTest():
    X = np.random.randn(2,2,3,4)
    print("X:{}\n".format(X))
    print("mean1:{}\n".format(np.mean(X, axis=(0)).shape))
    # output: mean1:(2, 3, 4)
    print("mean1:{}\n".format(np.mean(X, axis=(0))))
    print("mean2:{}\n".format(np.mean(X, axis=(0,2)).shape))
    # output: mean2:(2, 4)
    print("mean2:{}\n".format(np.mean(X, axis=(0,2))))
    print("mean3:{}\n".format(np.mean(X, axis=(0,2,3)).shape))
    # output: mean3:(2,)
    print("mean3:{}\n".format(np.mean(X, axis=(0,2,3))))

#sigmoidTest()
#reluTest()
#tanhTest()
#lreluTest()
#softmaxTest()
#fullyConnectedTest()
#anyTest2()
meanTest()

import numpy as np

class LRELU_LAYER:
    def __init__(self):
        pass

    def forward(self, X, a=1e-3):
        """
        Computes the forward pass of Leaky Relu Layer.
        Input:
            X: Input data of any shape
        """
        self.cache = (X, a)
        self.feature_map = np.maximum(a * X, X)
        return self.feature_map

    def backward(self, delta):
        """
        Computes the backward pass of Leaky Relu Layer.
        Input:
            delta: Shape of delta values should be same as of X in cache
        """
        X, a = self.cache
        dX = delta.copy()
        dX[X < 0] *= a
        return dX

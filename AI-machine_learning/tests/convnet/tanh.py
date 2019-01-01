import numpy as np

class TANH_LAYER:
    def __init__(self):
        pass

    def forward(self, X):
        """
        Computes the forward pass of Tanh Layer.
        Input:
            X: Input data of any shape
        """
        self.cache = np.tanh(X)
        return self.cache

    def backward(self, delta):
        """
        Computes the backward pass of Tanh Layer.
        Input:
            delta: Shape of delta values should be same as of X in cache
        """
        dX = (1 - self.cache**2) * delta
        return dX

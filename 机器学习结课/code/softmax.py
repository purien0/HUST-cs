import numpy as np
import math
import random

class Softmax:
    def __init__(self, batch_size=50, iters=1000, learning_rate=1e-2, lamda=1e-5, update_func='sgd_with_momentum'):
        self.W = None
        self.batch_size = batch_size
        self.iters = iters
        #给出的初始学习率
        self.learning_rate_given = learning_rate
        #学习过程中不断变化的学习率
        self.learning_rate = learning_rate
        self.lamda = lamda
        self.update_func = update_func
        self.momentum = 0.9
        self.velocity = None

    def fit(self, X, y):
        n_features = X.shape[1]
        n_classes = y.max() + 1
        #随机初始化
        self.W = np.random.randn(n_features, n_classes)
        self.velocity = np.zeros(self.W.shape)
        c = globals()['Softmax']
        for i in range(self.iters):
            loss = getattr(c, self.update_func)(self, X, y)
            #使得学习率在前500次回归中逐渐缩小,500次回归后学习率保持在给出的百分之1
            if(i <= 500):
                self.learning_rate = self.learning_rate_given*(1-i/500.0)+i/500.0*0.01*self.learning_rate_given
            # print ("Epoch: %s, Loss: %s" % (epoch, loss))
            if(loss==0):
                break

    def predict(self, X):
        return np.argmax(X.dot(self.W), 1)

    def loss(self, X, y):
        sample_size = X.shape[0]
        predictions = X.dot(self.W)

        # 提高数值稳定性
        predictions -= predictions.max(axis=1).reshape([-1, 1])

        # softmax中放置每个样本被分类为各属性的概率
        softmax = math.e**predictions
        softmax /= softmax.sum(axis=1).reshape([-1, 1])

        #交叉熵损失
        loss = 0  # 初始化损失

        # 遍历每个样本
        for i in range(len(softmax)):
            # 计算当前样本的预测概率向量中真实标签对应的概率，并取其对数
            log_prob = -np.log(np.clip(softmax[i, y[i]], 1e-50, None))
            # 将该损失累加到总损失中
            loss += log_prob

        # 计算平均损失
        loss /= sample_size
        loss += 0.5 * self.lamda * (self.W**2).sum()
        
        softmax[np.arange(len(softmax)), y] -= 1
        dW = (X.T.dot(softmax) / sample_size) + (self.lamda * self.W)
        return loss, dW
    
    def bgd(self, X, y):
        #batch gradient descent
        loss, dW = self.loss(X, y)
        self.W -= self.learning_rate * dW
        return loss
    
    def sgd(self, X, y):
        #随机梯度下降，mini-batch
        X_batch,y_batch = self.sample(X, y)
        loss, dW = self.loss(X_batch,y_batch)
        self.W -= self.learning_rate * dW
        return loss

    def sgd_with_momentum(self, X, y):
        #随机梯度下降+momentum
        X_batch,y_batch = self.sample(X, y)
        loss, dW = self.loss(X_batch,y_batch)
        self.velocity = self.momentum*self.velocity - self.learning_rate*dW
        self.W += self.velocity
        return loss

    def sample(self, X, y):
        #随机取样
        random_indices = random.sample(range(X.shape[0]), self.batch_size)
        X_batch = X[random_indices]
        y_batch = y[random_indices]
        return X_batch,y_batch

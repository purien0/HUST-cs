from collections import Counter  # 为了做投票
import numpy as np
import time
#kdtree结点定义
class Treenode:
    def __init__(self,data=None,label=None,i=None,v=None,left=None,right=None):
        #结点数据/一个样本
        self.data = data
        #标签
        self.label = label
        #结点分隔坐标的编号（第i个坐标）
        self.i = i
        #第i个坐标的值
        self.v = v
        #左子树与右子树
        self.left = left
        self.right = right
class KNN:
    def __init__(self,k = 1,algorithm = 'brute'):
        self.k = k
        self.tree = None
        #算法可选'brute','kdtree'
        self.algorithm = algorithm
        #将训练数据直接存在模型内
        self.x = None
        self.y = None

    def fit(self,X,y):
        #使用x和y作为训练数据集训练模型
        #将输入的x和y存在self.x，self.y中
        #若使用算法为kdtree时执行buildTree，并输出建树时间
        self.x = X
        self.y = y
        if(self.algorithm=='kdtree'):
            time_start = time.time()
            self.tree = self.buildTree(X,y,0)
            time_end = time.time()
            print("kdtree building complete!Run time:")
            print(time_end-time_start)
    
    def buildTree(self,X,y,depth):
        size = X.shape[0]
        feature_count = X.shape[1]
        #若数据个数小于等于1(此处只可能出现等于1的情况，等于0时不会执行buildTree)
        if size <= 1:
            tree = Treenode(data = X[0],label = y[0])
            return tree
        #选择第i个坐标进行划分
        i = depth%feature_count
        #按第i个坐标排序，得到中位数
        arg = np.argsort(X[:,i])
        mid = arg[size//2]

        left_idx = arg[:size//2]
        right_idx = arg[size//2+1:]
        #在该结点的坐标值，数据点的信息
        v = X[mid,i]
        data = X[mid]
        label = y[mid]
        left = right = None
        #左右递归建树
        if len(left_idx)>0:
            left = self.buildTree(X[left_idx],y[left_idx],depth+1)
        if len(right_idx)>0:
            right = self.buildTree(X[right_idx],y[right_idx],depth+1)
        tree = Treenode(data,label,i,v,left,right)
        return tree
    
    def isin(self,x,finded):
        #判断x是否在finded内
        for f in finded:
            if KNN.euc_dis(x,f) < 1e-8: return True
        return False

    def predict(self,test):
        #对给定的测试集进行预测，并输出运行时间
        time_start = time.time()
        predictions = []
        for x in test:
            if(self.algorithm=='kdtree'):
                #已找到的最近点
                finded = []
                #已找到的最近标签
                labels = []
                for i in range(self.k):
                    nearest_point,nearest_dis,nearest_label = self.find_nearest(x,finded)
                    finded.append(nearest_point)
                    labels.append(nearest_label)
                predictions.append(Counter(labels).most_common(1)[0][0])
            else:
                dists=[KNN.euc_dis(x,X) for X in self.x]
                # 找出最近的K个元素的idx
                idxknn= np.argsort(dists)[:self.k] #将dists从小到大排序，返回排序后的元素indices
                # 找出KNN对应的n个y值
                labels=self.y[idxknn]
                # 给出投票结果
                predictions.append(Counter(labels).most_common(1)[0][0])
        time_end = time.time()
        #给出运行时间
        print("Predict complete!Run time:")
        print(time_end-time_start)
        return predictions
        
    def euc_dis(a,b):
        #计算两点之间的欧式距离
        #a,b：ndarray
        return np.sqrt(((a-b)**2).sum())
    
    def find_nearest(self,x,finded):
        #寻找不在finded内的距离x最近点
        nearest_point = None
        nearest_dis = np.inf
        nearest_label = None
        def travel(kdtree,x):
            nonlocal nearest_dis,nearest_point,nearest_label
            if kdtree == None:
                return

            #如果根节点到目标点的距离小于最近距离，则更新nearest_point和nearest_dis
            if KNN.euc_dis(kdtree.data,x) < nearest_dis and not self.isin(kdtree.data,finded) :
                nearest_dis = KNN.euc_dis(kdtree.data,x)
                
                nearest_point = kdtree.data
                nearest_label = kdtree.label

            if kdtree.i == None or kdtree.v == None:
                return

            #进入下一个相应的子节点
            if x[kdtree.i] < kdtree.v:
                travel(kdtree.left,x)
                if x[kdtree.i] + nearest_dis > kdtree.v:
                    #若在右结点可能存在距离更近的点
                    travel(kdtree.right,x)
            elif x[kdtree.i] > kdtree.v:
                travel(kdtree.right,x)
                if x[kdtree.i] - nearest_dis < kdtree.v:
                    #若在左结点可能存在距离更近的点
                    travel(kdtree.left,x)
            else:
                #若目标结点的某坐标值与该结点相等，说明在目标结点在分割超平面上，左右结点都可能存在距离目标结点更近的点
                travel(kdtree.left,x)
                travel(kdtree.right,x)

        travel(self.tree,x)
        return nearest_point,nearest_dis,nearest_label


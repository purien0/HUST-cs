import numpy as np
import pandas as pd
import csv
from softmax import Softmax
from knn import KNN
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import time
import os
#输出当前工作目录，期望为X:\xxxx\code
print(os.getcwd())

#数据读入
train = pd.read_csv("../data/train.csv")
test = pd.read_csv("../data/test.csv")

#将两者拼接得到
train_test_concat = pd.concat([train,test],keys=['train','test'])

#onehot编码，但将k类别编码为k-1列，可以减少计算量
train_test_x = train_test_concat.drop(columns=['NObeyesdad', 'id'])
train_test_onehot = pd.get_dummies(train_test_x,drop_first=True)
x_train = train_test_onehot.loc['train'].values
x_test = train_test_onehot.loc['test'].values
label_encoder = LabelEncoder()
y_train = label_encoder.fit_transform(train['NObeyesdad'])

#命名规则：形如train_x的是用于模型训练、调参和验证的数据，形如x_train是用于给出预测的数据。
#将训练数据分隔为训练集和验证集
train_data,validate_data = train_test_split(np.concatenate((x_train,y_train.reshape(y_train.shape[0],1)),axis=1), test_size=1.0/5, random_state=42)
train_x = train_data[:,:train_data.shape[1]-2]
train_y = train_data[:,train_data.shape[1]-1].flatten().astype('int64')

validate_x = validate_data[:,:validate_data.shape[1]-2]
validate_y = validate_data[:,validate_data.shape[1]-1].flatten().astype('int64')

#对数据进行归一化
scaler = StandardScaler()
train_x_scaled = scaler.fit_transform(train_x)
validate_x_scaled = scaler.transform(validate_x)
train_x_scaled_inserted = np.insert(train_x_scaled, 1, 1, axis=1)#加入一列全为1，作为常数项
validate_x_scaled_inserted = np.insert(validate_x_scaled, 1, 1, axis=1)#加入一列全为1，作为常数项


#softmax回归模型的参数
#lamda：正则项参数
lamda = 1e-4
#随机的mini—batch大小
batch_size = 40
#训练次数
iters = 3500 #3500
#学习率
learning_rate = 0.738 #0.738
#使用的训练函数
update_func = 'sgd_with_momentum'
max_test = 0.0
max_learning = 0.0
max_iters = 0
sm = Softmax(batch_size=batch_size, iters=iters, learning_rate=learning_rate, lamda=lamda, update_func=update_func)
#网格法搜索，进行参数调优
# for k in range(5):
#     iters = 2500+k*500
#     for i in range(200):
#         learning_rate = 0.597+0.001*i
#         average = 0.0
#         for j in range(5):
#             sm = Softmax(batch_size=batch_size, iters=iters, learning_rate=learning_rate, lamda=lamda, update_func=update_func)
#             train_data,test_data = train_test_split(train_data_ori, test_size=1.0/5, random_state=42)
#             x_train,y_train,x_test,y_test=preprocessing(train_data,test_data)
#             sm.train(x_train, y_train)
#             pred = sm.predict(x_test)
#             average+=np.mean(np.equal(y_test, pred))
#         average = average/5.0
#         print(average)
#         if(average>max_test):
#             max_test = average
#             max_learn = learning_rate
#             max_iters = iters
#             print("acc:%f learning_rate:%f iters:%d",max_test,max_learn,max_iters)
# print("acc:%f learning_rate:%f iters:%d",max_test,max_learn,max_iters)

# 在训练集上的表现
# softmax算法
time_start = time.time()
sm.fit(train_x_scaled_inserted, train_y)
pred = sm.predict(validate_x_scaled_inserted)
time_end = time.time()
print("softmax regression complete!Run time:")
print(time_end-time_start)
tot_acc = np.mean(np.equal(validate_y, pred))
print(tot_acc)
accuracy = accuracy_score(validate_y, pred)
print("\nAccuracy:", accuracy)

print("\nClassification Report:")
print(classification_report(validate_y,pred))

print("\nConfusion Matrix:")
conf_matrix = confusion_matrix(validate_y,pred)
print(conf_matrix)

#KNN算法
#使用brute和kdtree策略分别实现
#brute
knn_brute = KNN(5,algorithm='brute')
knn_brute.fit(train_x,train_y)
pred = knn_brute.predict(validate_x)
correct = np.count_nonzero((pred==validate_y)==True)
print ("Accuracy is: %.3f" %(correct/len(validate_y)))
accuracy = accuracy_score(validate_y, pred)
print("\nAccuracy:", accuracy)


print("\nClassification Report:")
print(classification_report(validate_y,pred))

print("\nConfusion Matrix:")
conf_matrix = confusion_matrix(validate_y,pred)
print(conf_matrix)
#kdtree
knn_kdtree = KNN(5,algorithm='kdtree')
knn_kdtree.fit(train_x,train_y)
pred = knn_kdtree.predict(validate_x)
correct = np.count_nonzero((pred==validate_y)==True)
print ("Accuracy is: %.3f" %(correct/len(validate_y)))
accuracy = accuracy_score(validate_y, pred)
print("\nAccuracy:", accuracy)

# Generate classification report and confusion matrix
print("\nClassification Report:")
print(classification_report(validate_y,pred))

print("\nConfusion Matrix:")
conf_matrix = confusion_matrix(validate_y,pred)
print(conf_matrix)

#对整个训练集和测试集数据处理
scaler = StandardScaler()
x_train_scaled = scaler.fit_transform(x_train)
x_test_scaled = scaler.transform(x_test)
x_train_scaled_inserted = np.insert(x_train_scaled, 1, 1, axis=1)#加入一列全为1，作为常数项
x_test_scaled_inserted = np.insert(x_test_scaled, 1, 1, axis=1)#加入一列全为1，作为常数项

# 用整个训练集测试模型并给出预测
# softmax
sm.fit(x_train_scaled_inserted, y_train)
pred = sm.predict(x_test_scaled_inserted)
test['NObeyesdad'] = pred
out = test[['id','NObeyesdad']]
out.NObeyesdad = label_encoder.inverse_transform(out.NObeyesdad)
out.to_csv("../submission/submission_softmax.csv",index=False)

#KNN
knn_brute = KNN(5,algorithm='brute')
knn_brute.fit(x_train, y_train)
pred = knn_brute.predict(x_test)
test['NObeyesdad'] = pred
out = test[['id','NObeyesdad']]
out.NObeyesdad = label_encoder.inverse_transform(out.NObeyesdad)
out.to_csv("../submission/submission_knn.csv",index=False)



# from sklearn.neighbors import KNeighborsClassifier
# acc = []
# x_axis_data = []
# knn = KNeighborsClassifier(n_neighbors=5,weights='uniform',p = 2)
# knn.fit(train_x,train_y)
# pred = knn.predict(validate_x)
# correct = np.count_nonzero((pred==validate_y)==True)
# print ("Accuracy is: %.3f" %(correct/len(validate_y)))
# accuracy = accuracy_score(validate_y, pred)
# print("\nAccuracy:", accuracy)
# print("\nClassification Report:")
# print(classification_report(validate_y,pred))

# print("\nConfusion Matrix:")
# conf_matrix = confusion_matrix(validate_y,pred)
# print(conf_matrix)


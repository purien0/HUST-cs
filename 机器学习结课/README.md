# 机器学习结课大作业
此为cs2208班田清林的机器学习结课大作业，学号为U202215642。
## 选题

2. 参考选题二：[肥胖风险的多类别预测 Multi-Class Prediction of Obesity Risk](https://www.kaggle.com/competitions/playground-series-s4e2)

## 实验要求
1.文件夹obesity_risk中有三个文件夹，code、data和submission，分别放置代码文件，数据集和预测结果。
2.code文件夹内含有main.py,softmax.py和knn.py三个代码文件，分别是主程序、softman算法实现和knn算法实现。
3.data文件夹内为kaggle obesity_risk的train.csv、test.csv和sample_submission.csv。
4.submission文件夹内为submission_knn.csv和submission_softmax.csv，分别为knn模型和softmax模型的预测结果。
5.使用时，用vscode打开code文件夹，运行main.py中的代码。程序会先在训练集依次执行softmax和KNN，输出模型在训练集上的表现情况，包括runtime、accuracy、precision、recall、f1-score等，以及混淆矩阵，之后再用整个训练集训练softmax和KNN模型并给出预测结果。
6.注意：KNN算法时间效率较低，运行时间较长，尤其在给出预测结果阶段，在本机上运行需要1800s。


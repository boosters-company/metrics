from sklearn.metrics import log_loss
import pandas as pd
import numpy as np
import sys

"""
example of usage:

python mlogloss.py ./input/test_target.csv ./input/sample_submission.csv

"""

def mlogloss(true_file="./input/test_target.csv", pred_file="./input/sample_submission.csv"):
    """
    This function get path to true target and submission file
    return: one value - score
    """
    y_true = pd.read_csv(true_file, header=None)
    y_pred = pd.read_csv(pred_file, index_col=0)
    return log_loss(np.array(y_true), np.array(y_pred))

def __main__():
    print(mlogloss(sys.argv[1], sys.argv[2]))

__main__()

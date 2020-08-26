import pandas as pd
import numpy as np
import sys


def chi_square_dist(hist_true, hist_pred):
    v = np.nanmean((hist_true - hist_pred)**2/(hist_true + hist_pred), axis=1)
    return np.nanmean(v)

def mape(y_true, y_pred):
    return (abs(y_true - y_pred)/y_true).mean()

def score(data, sub, idx):
    tmp = data.loc[idx]
    sub_tmp = sub.loc[idx]
    chi_score = chi_square_dist(tmp.iloc[:, :19].values, sub_tmp.iloc[:, :19].values)
    
    mape_part = tmp[~tmp.prop_count.isnull()]
    idx2 = mape_part.index.values
    mape_score = mape(mape_part.prop_count, sub_tmp.loc[idx2].prop_count)
    #print(chi_score, mape_score)
    return 0.6*chi_score + 0.4*mape_score


ans = pd.read_csv(sys.argv[1])

user = pd.read_csv(sys.argv[2])


idx = pd.read_csv(sys.argv[3])

user = user.set_index('ImageId')
ans = ans.set_index('ImageId')

res = score(ans, user, idx['ImageId'].values)

print("ok: {}".format(res))

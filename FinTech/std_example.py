import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt

tsmc = yf.Ticker("2330.TW")
history = tsmc.history(period="5y")  

last_250_days = history.tail(250).copy()

last_250_days['DailyReturn'] = last_250_days['Close'].pct_change()
last_250_days = last_250_days.dropna()  # remove NaN fields
last_250_days.index = pd.DatetimeIndex(last_250_days.index).normalize() + pd.Timedelta(hours=13, minutes=30)

std_dev = last_250_days['DailyReturn'].std()

#pd.set_option('display.max_rows', None)
#pd.set_option('display.max_columns', None)
print(last_250_days[['Close', 'DailyReturn']])
print(f"DailyStd: {std_dev:.4f}")

window_size = 2
last_250_days['RollingStd'] = last_250_days['DailyReturn'].rolling(window=window_size).std()

max_std = last_250_days['RollingStd'].max()
max_std_date = last_250_days['RollingStd'].idxmax()

print(f"Max Std {max_std:.4f}  on  {max_std_date}   (compare with previos trading day)")  # {prev_max_idx_position} and

# Draw the result
plt.figure(figsize=(12, 6))
plt.plot(last_250_days['RollingStd'], label='Rolling Standard Deviation')
plt.axhline(max_std, color='red', linestyle='--', label='Max Std Dev')
plt.title(f'Rolling Standard Deviation of Daily Returns    (max_std:{max_std:.4f}  std_dev:{std_dev:.4f})')
plt.xlabel('Date')
plt.ylabel('Standard Deviation')
plt.show()


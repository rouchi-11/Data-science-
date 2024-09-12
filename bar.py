import matplotlib.pyplot as plt
import numpy as np


flavors = np.array(["Vanilla", "Chocolate", "Strawberry", "Mint"])
sales = np.array([50, 30, 20, 15])


plt.figure(figsize=(12, 6))


plt.subplot(1, 3, 1) 
bars = plt.bar(flavors, sales, color='skyblue', width=0.5)
plt.title('Bar Chart')


for bar in bars:
    bar.set_color('lightcoral')
    bar.set_edgecolor('black')


plt.subplot(1, 3, 2)  
plt.barh(flavors, sales, color='lightgreen')
plt.title('Horizontal Bar Chart')


plt.subplot(1, 3, 3)  
plt.pie(sales, labels=flavors, autopct='%1.1f%%', startangle=140, colors=['#ff9999','#66b3ff','#99ff99','#ffcc99'])
plt.title('Pie Chart')


plt.tight_layout()
plt.show()

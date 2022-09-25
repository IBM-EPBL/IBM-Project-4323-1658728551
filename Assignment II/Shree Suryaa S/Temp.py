import random

temp = random.randint(1,1000)
hum = random.randint(1,1000)
if temp > 500:
  print("Threshold Reached")
else:
  print("Threshold Not Reached")

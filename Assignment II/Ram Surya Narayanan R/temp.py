import random

temp = random.randint(1,800)
hum = random.randint(1,800)
if temp > 500:
  print("Threshold Reached")
else:
  print("Threshold Not Reached")
